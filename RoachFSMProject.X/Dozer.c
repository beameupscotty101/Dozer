#include <Roach.h>
#include <BOARD.h>
#include <xc.h>

#include <pwm.h>
#include <serial.h>
#include <AD.h>
#include <RC_Servo.h>
#include <IO_Ports.h>


/*******************************************************************************
 * private #DEFINES                                                             *
 ******************************************************************************/
//Tape Sensors
#define MUX_S0 PIN5
#define MUX_S1 PIN4
#define MUX_S2 PIN3
#define MUX_OUTPT AD_PORTV6
#define MUX_PORT PORTV

#define TAPESENSORLEDPIN PIN5
#define TAPESENSORLEDPORT PORTV

//FSR's
#define FSR1 AD_PORTW3
#define FSR2 AD_PORTW4

//Bump Sensor
#define BUMP1 PIN5
#define BUMP2 PIN6
#define BUMP_PORT PORTW

//Track Sensors
#define TRACK1 PIN7
#define TRACK2 PIN8
#define TRACk_PORT PORTW

//Ball Launch Mechanism
#define LOADER RC_PORTX03
#define LAUNCH_MOTOR PWM_PORTX11

//Beacon Detector
#define FRONT_BEACON PIN4
#define BACK_BEACON PIN5
#define BEACON_PORT PORTX

//Range Sensor
#define RANGE_SENSOR PIN6
#define RANGE_PORT PORTX

//Drive Motors
#define DIR_LEFT PIN6
#define DIR_RIGHT PIN4
#define DIR_PORT PORTY
#define LEFT_MOTOR PWM_PORTY10
#define RIGHT_MOTOR PWM_PORTY12

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
    if (PWM_Init() == ERROR) {
        printf("PWM SUBSYSTEM FAILED!");
    }
    PWM_SetFrequency(1000);

    if (AD_Init() == ERROR) {
        printf("AD SUBSYSTEM FAILED!");
    }

    if (RC_Init() == ERROR) {
        printf("RC SUBSYSTEM FAILED");
    }

    //Tape Sensor
    IO_PortsSetPortOutputs(MUX_PORT, MUX_S0 | MUX_S1 | MUX_S2);
    AD_AddPins(MUX_OUTPT);

    //FSR's
    AD_AddPins(FSR1 | FSR2);

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
uint8_t * BoulderTapeSensor(void) {
    uint8_t tapesensordata[6];
    int sensor_select = 0;
    for (; sensor_select < 6; sensor_select++) {
        switch (sensor_select) {
            case 0:
            {
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                tapesensordata[sensor_select] = AD_ReadADPin(MUX_OUTPT);
                break;
            }

            case 1:
            {
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                tapesensordata[sensor_select] = AD_ReadADPin(MUX_OUTPT);
                break;
            }

            case 2:
            {
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsSetPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                tapesensordata[sensor_select] = AD_ReadADPin(MUX_OUTPT);
                break;
            }

            case 3:
            {
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsSetPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                tapesensordata[sensor_select] = AD_ReadADPin(MUX_OUTPT);
                break;
            }

            case 4:
            {
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsSetPortBits(MUX_PORT, MUX_S2);
                tapesensordata[sensor_select] = AD_ReadADPin(MUX_OUTPT);
                break;
            }

            case 5:
            {
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsSetPortBits(MUX_PORT, MUX_S2);
                tapesensordata[sensor_select] = AD_ReadADPin(MUX_OUTPT);
                break;
            }
        }
    }

    return tapesensordata;
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

