#ifndef Dozer_H
#define Dozer_H

#define NUMBEROFTAPESENSORS 7

//Tape Sensors
#define MUX_S0 PIN5
#define MUX_S1 PIN4
#define MUX_S2 PIN3
#define MUX_OUTPT AD_PORTV6
#define MUX_PORT PORTV

#define TAPESENSORLEDPIN PIN7
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

void Boulder_Init(void);

/*Tape Sensor******************************************************************/
uint8_t BoulderTapeSensor(int sensor_select);
void TapeSensorLed(int active);

extern unsigned tapeSensorLedData_ON[NUMBEROFTAPESENSORS];
extern unsigned tapeSensorLedData_OFF[NUMBEROFTAPESENSORS];

/*Motor Driving****************************************************************/


char Boulder_LeftMtrSpeed(char newSpeed);

/**
 * @Function Boulder_RightMtrSpeed(char newSpeed)
 * @param newSpeed - A value between -10 and 10 which is the new speed
 * @param of the motor. 0 stops the motor. A negative value is reverse.
 * @return SUCCESS or ERROR
 * @brief  This function is used to set the speed and direction of the Right Motor.
 * @author Scott Rad*/
char Boulder_RightMtrSpeed(char newSpeed);
/**
 * @Function Roach_RightMtrSpeed(char newSpeed)
 * @param newSpeed - A value between -10 and 10 which is the new speed
 * @param of the motor. 0 stops the motor. A negative value is reverse.
 * @return SUCCESS or ERROR
 * @brief  This function is used to set the speed and direction of the left motor.
 * @author Max Dunne, 2012.01.06 */
char Boulder_Drive(int speed);

char Boulder_TankTurn(int turn_speed);

/*FSR**************************************************************************/
unsigned int Boulder_FSR_Left(void);

unsigned int Boulder_FSR_Right(void);

/*Switches*********************************************************************/

/*Beacon Sensor*****************************************************************/
int16_t Boulder_Beacon_Detector_Front(void);

int16_t Boulder_Beacon_Detector_Back(void);

/*Track Sensor*****************************************************************/

/*Ball Launch Mechanism********************************************************/
char Boulder_Activate_Shooting_Motor(int speed);

#endif

