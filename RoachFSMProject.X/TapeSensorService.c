
/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "AD.h"
#include "BOARD.h"
#include "TapeSensorService.h"
#include "IO_Ports.h"
#include <stdio.h>
#include "Dozer.h"
/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/

#define DARK_THRESHOLD 450
#define LIGHT_THRESHOLD 750

unsigned tapeSensorLedData_ON[NUMBEROFTAPESENSORS];
unsigned tapeSensorLedData_OFF[NUMBEROFTAPESENSORS];


/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                    *
 ******************************************************************************/
/* You will need MyPriority and maybe a state variable; you may need others
 * as well. */


static uint8_t MyPriority;


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitRoachBumperService(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunRoachBumperService function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitTapeSensorService(uint8_t Priority) {
    ES_Event ThisEvent;
    MyPriority = Priority;

    // ES_Timer_InitTimer(3, TIMER_LENGTH);

    // post the initial transition event
    ThisEvent.EventType = ES_INIT;
    if (ES_PostToService(MyPriority, ThisEvent) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostRoachBumperService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t PostTapeSensorService(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function RunRoachBumperService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue.
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed."
 * @author J. Edward Carryer, 2011.10.23 19:25 */
ES_Event RunTapeSensorService(ES_Event ThisEvent) {
    ES_Event ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

    //this is used as a flag
    char event = ERROR;
    uint16_t tapeSensorFinalReading[6];
    static int prevEvent[NUMBEROFTAPESENSORS];


    if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
    {
        
    }

    if (ThisEvent.EventType == TAPESENSOR) {

        typedef enum state_t {
            first_reading,
            second_reading,
            third_reading,
            fourth_reading,
            fifth_reading,
            check_event,
        } state_t;

        static state_t state = first_reading;
        static int readings[NUMBEROFTAPESENSORS];

        int i = 0;
        for (; i < 7; i++) {
            tapeSensorFinalReading[i] = tapeSensorLedData_ON[i] - tapeSensorLedData_OFF[i];
            if (tapeSensorFinalReading[i] > 32768) {
                tapeSensorFinalReading[i] = 0;
            }
        }

        switch (state) {
            case first_reading:
            {
                i = 0;
                for (; i < NUMBEROFTAPESENSORS; i++) {
                    readings[i] = 0;
                    if (tapeSensorFinalReading[i] > DARK_THRESHOLD) {
                        readings[i] += 1;
                    } else if (tapeSensorFinalReading[i] < LIGHT_THRESHOLD) {
                        readings[i] -= 1;
                    }
                }
                state = second_reading;
                break;
            }

            case second_reading:
            {
                i = 0;
                for (; i < NUMBEROFTAPESENSORS; i++) {
                    if (tapeSensorFinalReading[i] > DARK_THRESHOLD) {
                        readings[i] += 1;
                    } else if (tapeSensorFinalReading[i] < LIGHT_THRESHOLD) {
                        readings[i] -= 1;
                    }
                }
                state = third_reading;
                break;
            }

            case third_reading:
            {
                i = 0;
                for (; i < NUMBEROFTAPESENSORS; i++) {
                    if (tapeSensorFinalReading[i] > DARK_THRESHOLD) {
                        readings[i] += 1;
                    } else if (tapeSensorFinalReading[i] < LIGHT_THRESHOLD) {
                        readings[i] -= 1;
                    }
                }
                state = fourth_reading;
                break;
            }

            case fourth_reading:
            {
                i = 0;
                for (; i < NUMBEROFTAPESENSORS; i++) {
                    if (tapeSensorFinalReading[i] > DARK_THRESHOLD) {
                        readings[i] += 1;
                    } else if (tapeSensorFinalReading[i] < LIGHT_THRESHOLD) {
                        readings[i] -= 1;
                    }
                }
                state = check_event;
                break;
            }


            case check_event:
            {
                static char first_time = 0;
                if (first_time != 0) {
                    i = 0;
                    for (; i < NUMBEROFTAPESENSORS; i++) {
                        if (readings[i] >= 2 && prevEvent[i] == 0) {
                            prevEvent[i] = 1;
                            printf("%d: Event Detected Low to High\n", i);
                        } else if (readings[i] <= -2 && prevEvent[i] == 1) {
                            printf("%d: Event Detected High to LOW\n", i);
                            prevEvent[i] = 0;
                        }
                    }
                    state = first_reading;
                    break;
                } else {
                    i = 0;
                    for (; i < NUMBEROFTAPESENSORS; i++) {
                        if (readings[i] >= 2) {
                            prevEvent[i] = 1;
                        } else if (readings[i] <= -2) {
                            prevEvent[i] = 0;
                        }
                    }
                    first_time = 1;
                    state = first_reading;
                    break;
                }
            }
        }
    }


    return ReturnEvent;
}

/*******************************************************************************
 * PRIVATE FUNCTIONs                                                           *
 ******************************************************************************/
