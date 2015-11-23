#ifndef Dozer_H
#define Dozer_H

void Boulder_Init(void);

/*Tape Sensor******************************************************************/
uint8_t BoulderTapeSensor(void);

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

