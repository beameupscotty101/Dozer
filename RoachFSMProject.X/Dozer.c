#include <BOARD.h>
#include <xc.h>

#include <pwm.h>
#include <serial.h>
#include <AD.h>
#include <RC_Servo.h>
#include <IO_Ports.h>
#include "Dozer.h"
#include <stdio.h>


/*******************************************************************************
 * private #DEFINES                                                             *
 ******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
//Helper Defines                                                              //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                           *
 ******************************************************************************/

/**
 * @Function Boulder_Init(void)
 * @param None.
 * @return None.
 * @brief  Performs all the initialization necessary for the Boulder. this includes initializing
 * the PWM module,  the data directions on some pins, and
 * setting the initial motor directions.
 * @note  None.
 * @author Scott rad */
void Boulder_Init(void) {
    //CHECK SYSTEMS
    PWM_Init();
    PWM_SetFrequency(1000);
    AD_Init();
    RC_Init();

    //Tape Sensor
    IO_PortsSetPortOutputs(MUX_PORT, MUX_S0 | MUX_S1 | MUX_S2);
    IO_PortsSetPortOutputs(TAPESENSORLEDPORT, TAPESENSORLEDPIN);
    AD_AddPins(MUX_OUTPT | FSR1 | FSR2);

    //Bump Sensor
    IO_PortsSetPortInputs(BUMP_PORT, BUMP1 | BUMP2);

    //Track Sensor
    IO_PortsSetPortInputs(TRACk_PORT, TRACK1 | TRACK2);

    //Launch Mechanism
    PWM_AddPins(LAUNCH_MOTOR);
    RC_AddPins(LOADER);

    //Beacon Detector
    IO_PortsSetPortInputs(BEACON_PORT, BACK_BEACON | FRONT_BEACON);

    //Range Sensor
    IO_PortsSetPortInputs(RANGE_PORT, RANGE_SENSOR);

    //Drive Motor
    IO_PortsSetPortOutputs(DIR_PORT, DIR_LEFT | DIR_RIGHT);
    PWM_AddPins(LEFT_MOTOR | RIGHT_MOTOR);

}

/*Tape Sensor******************************************************************/
uint8_t BoulderTapeSensor(int sensor_select) {
    switch (sensor_select) {
        case 0:
        {
            IO_PortsClearPortBits(MUX_PORT, MUX_S0);
            IO_PortsClearPortBits(MUX_PORT, MUX_S1);
            IO_PortsClearPortBits(MUX_PORT, MUX_S2);
            return AD_ReadADPin(MUX_OUTPT);
            break;
        }

        case 1:
        {
            IO_PortsSetPortBits(MUX_PORT, MUX_S0);
            IO_PortsClearPortBits(MUX_PORT, MUX_S1);
            IO_PortsClearPortBits(MUX_PORT, MUX_S2);
            return AD_ReadADPin(MUX_OUTPT);
            break;
        }

        case 2:
        {
            IO_PortsClearPortBits(MUX_PORT, MUX_S0);
            IO_PortsSetPortBits(MUX_PORT, MUX_S1);
            IO_PortsClearPortBits(MUX_PORT, MUX_S2);
            return AD_ReadADPin(MUX_OUTPT);
            break;
        }

        case 3:
        {
            IO_PortsSetPortBits(MUX_PORT, MUX_S0);
            IO_PortsSetPortBits(MUX_PORT, MUX_S1);
            IO_PortsClearPortBits(MUX_PORT, MUX_S2);
            return AD_ReadADPin(MUX_OUTPT);
            break;
        }

        case 4:
        {
            IO_PortsClearPortBits(MUX_PORT, MUX_S0);
            IO_PortsClearPortBits(MUX_PORT, MUX_S1);
            IO_PortsSetPortBits(MUX_PORT, MUX_S2);
            return AD_ReadADPin(MUX_OUTPT);
            break;
        }

        case 5:
        {
            IO_PortsSetPortBits(MUX_PORT, MUX_S0);
            IO_PortsClearPortBits(MUX_PORT, MUX_S1);
            IO_PortsSetPortBits(MUX_PORT, MUX_S2);
            return AD_ReadADPin(MUX_OUTPT);
            break;
        }

        case 6:
        {
            IO_PortsClearPortBits(MUX_PORT, MUX_S0);
            IO_PortsSetPortBits(MUX_PORT, MUX_S1);
            IO_PortsSetPortBits(MUX_PORT, MUX_S2);
            return AD_ReadADPin(MUX_OUTPT);
            break;
        }
    }
}

void TapeSensorLed(int active) {
    if (active > 1 || active < 0) {
        return;
    }

    if (active == 1) {
        IO_PortsSetPortBits(TAPESENSORLEDPORT, TAPESENSORLEDPIN);
    } else if (active == 0) {
        IO_PortsClearPortBits(TAPESENSORLEDPORT, TAPESENSORLEDPIN);
    }
}

/*Motor Driving****************************************************************/

/**
 * @Function Boulder_LeftMtrSpeed(char newSpeed)
 * @param newSpeed - A value between -10 and 10 which is the new speed
 * @param of the motor. 0 stops the motor. A negative value is reverse.
 * @return SUCCESS or ERROR
 * @brief  This function is used to set the speed and direction of the left motor.
 * @author Max Dunne, 2012.01.06 */
char Boulder_LeftMtrSpeed(char newSpeed) {
    if ((newSpeed < -10) || (newSpeed > 10)) {
        return (ERROR);
    }

    if (IO_PortsWritePort(DIR_PORT, newSpeed < 0 ? 0 : DIR_LEFT) == ERROR) {
        return ERROR;
    }

    if (newSpeed == 0) {
        PWM_SetDutyCycle(LEFT_MOTOR, 0);
    } else {
        PWM_SetDutyCycle(LEFT_MOTOR, abs(1000 / newSpeed));
    }

    return SUCCESS;
}

/**
 * @Function Boulder_RightMtrSpeed(char newSpeed)
 * @param newSpeed - A value between -10 and 10 which is the new speed
 * @param of the motor. 0 stops the motor. A negative value is reverse.
 * @return SUCCESS or ERROR
 * @brief  This function is used to set the speed and direction of the Right Motor.
 * @author Scott Rad*/
char Boulder_RightMtrSpeed(char newSpeed) {
    if ((newSpeed < -10) || (newSpeed > 10)) {
        return (ERROR);
    }

    IO_PortsWritePort(DIR_PORT, newSpeed < 0 ? 0 : DIR_RIGHT);

    if (newSpeed == 0) {
        PWM_SetDutyCycle(RIGHT_MOTOR, 0);
    } else {
        PWM_SetDutyCycle(RIGHT_MOTOR, abs(1000 / newSpeed));
    }

    return SUCCESS;
}

/**
 * @Function Roach_RightMtrSpeed(char newSpeed)
 * @param newSpeed - A value between -10 and 10 which is the new speed
 * @param of the motor. 0 stops the motor. A negative value is reverse.
 * @return SUCCESS or ERROR
 * @brief  This function is used to set the speed and direction of the left motor.
 * @author Max Dunne, 2012.01.06 */
char Boulder_Drive(int speed) {
    if (speed < -10 || speed > 10) {
        return ERROR;
    }

    Boulder_LeftMtrSpeed(speed);
    Boulder_RightMtrSpeed(speed);

    return SUCCESS;
}

char Boulder_TankTurn(int turn_speed) {
    if (turn_speed > 0) {
        Boulder_LeftMtrSpeed(turn_speed);
        Boulder_RightMtrSpeed((10 - turn_speed) * -1);
        return SUCCESS;
    } else if (turn_speed < 0) {
        Boulder_LeftMtrSpeed((10 - abs(turn_speed)) * -1);
        ;
        Boulder_RightMtrSpeed(abs(turn_speed));
        return SUCCESS;
    } else {
        return ERROR;
    }
}

/*FSR**************************************************************************/
unsigned int Boulder_FSR_Left(void) {
    return AD_ReadADPin(FSR1);
}

unsigned int Boulder_FSR_Right(void) {
    return AD_ReadADPin(FSR2);
}

/*Switches*********************************************************************/

/*Beacon Sensor*****************************************************************/
int16_t Boulder_Beacon_Detector_Front(void) {
    return ((IO_PortsReadPort(BEACON_PORT) & FRONT_BEACON) == FRONT_BEACON ? 1 : 0);
}

int16_t Boulder_Beacon_Detector_Back(void) {
    return ((IO_PortsReadPort(BEACON_PORT) & BACK_BEACON) == BACK_BEACON ? 1 : 0);
}

/*Track Sensor*****************************************************************/

/*Ball Launch Mechanism********************************************************/
char Boulder_Activate_Shooting_Motor(int speed) {
    return PWM_SetDutyCycle(LAUNCH_MOTOR, speed);
}


#ifdef NASTY_BLOCKING_TEST

int main(int nargs, char** args) {
    BOARD_Init();
    //Boulder_Init();
    SERIAL_Init();
    IO_PortsSetPortOutputs(MUX_PORT, MUX_S0 | MUX_S1 | MUX_S2);
    IO_PortsSetPortOutputs(TAPESENSORLEDPORT, TAPESENSORLEDPIN);
    AD_AddPins(MUX_OUTPT | FSR1 | FSR2);
    PWM_Init();
    PWM_SetFrequency(1000);
    IO_PortsSetPortOutputs(DIR_PORT, DIR_LEFT | DIR_RIGHT);
    PWM_AddPins(LEFT_MOTOR | RIGHT_MOTOR);
    TapeSensorLed(1);

    printf("Nasty Blocking Test Harness. Make it so...\n");

    uint8_t tapeData[NUMBEROFTAPESENSORS];
    char in;
    int i;

    for (;;) {
        while (IsReceiveEmpty()) {
        }
        in = GetChar();
        switch (in) {
            case '-':
                //                BoulderTapeSensor(tapeData);
                //                printf("Tape Sensor Data: ");
                //                for (i = 0; i < NUMBEROFTAPESENSORS; i++)
                //                    printf("\t[%d]: %d ", i, tapeData[i]);
                //                printf("\n");
                printf("LED: Off\n");
                TapeSensorLed(0);
                break;

            case '=':
                printf("LED: Engage\n");
                TapeSensorLed(1);
                break;

            case '1':
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                while (!AD_IsNewDataReady());
                printf("Tape 0: %u\n", AD_ReadADPin(MUX_OUTPT));
                break;

            case '2':
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                while (!AD_IsNewDataReady());
                printf("Tape 1: %u\n", AD_ReadADPin(MUX_OUTPT));
                break;

            case '3':
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsSetPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                while (!AD_IsNewDataReady());
                printf("Tape 2: %u\n", AD_ReadADPin(MUX_OUTPT));
                break;

            case '4':
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsSetPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                while (!AD_IsNewDataReady());
                printf("Tape 3: %u\n", AD_ReadADPin(MUX_OUTPT));
                break;

            case '5':
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsSetPortBits(MUX_PORT, MUX_S2);
                while (!AD_IsNewDataReady());
                printf("Tape 4: %u\n", AD_ReadADPin(MUX_OUTPT));
                break;

            case '6':
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsSetPortBits(MUX_PORT, MUX_S2);
                while (!AD_IsNewDataReady());
                printf("Tape 5: %u\n", AD_ReadADPin(MUX_OUTPT));
                break;


            case '7':
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsSetPortBits(MUX_PORT, MUX_S1);
                IO_PortsSetPortBits(MUX_PORT, MUX_S2);
                printf("Tape 6: %u\n", AD_ReadADPin(MUX_OUTPT));
                break;

            case 'q':
                break;

            case 'w':
                break;

            case 'e':
                break;

            case 'r':
                break;

            case 't':
                while (!AD_IsNewDataReady());
                printf("FSR1: %d\n", AD_ReadADPin(FSR1));
                break;

            case 'y':
                while (!AD_IsNewDataReady());
                printf("FSR2: %d\n", AD_ReadADPin(FSR2));
                break;

            case ',':
                Boulder_TankTurn(-9);
                break;

            case '.':
                Boulder_TankTurn(9);
                break;
        }
    }

}

#endif//NASTY_BLOCKING_TEST

