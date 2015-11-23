
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

#define TAPE_TIMER 3
#define TIMER_LENGTH 5 //in milliseconds

#define DARK_THRESHOLD 800
#define LIGHT_THRESHOLD 500

#define ON 1
#define OFF 0

typedef union BOULDER {
    int Tapeled;
} BOULDER;

static BOULDER boulder;
static uint8_t tapeSensorLedData_ON[6];

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

    //Init the timer for 5ms
    ES_Timer_InitTimer(TAPE_TIMER, TIMER_LENGTH);
    boulder.Tapeled = ON;

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


    if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
    {
        // No hardware initialization or single time setups, those
        // go in the init function above.
        //
        // This section is used to reset service for some reason
    }

    if (ThisEvent.EventType == ES_TIMEOUT) {
        if (boulder.Tapeled == ON) {
            TapeSensorLed(ON);
            BoulderTapeSensor(tapeSensorLedData_ON);
            boulder.Tapeled = OFF;
        } else if (boulder.Tapeled == OFF) {
            uint8_t tapeSensorLedData_OFF[6];
            uint8_t tapeSensorFinalReading[6];

            TapeSensorLed(OFF);
            BoulderTapeSensor(tapeSensorLedData_OFF);

            //subtract the two readings
            int i = 0;
            for (; i < 7; i++) {
                tapeSensorFinalReading[i] = tapeSensorLedData_ON[i] - tapeSensorLedData_OFF[i];
            }

            //do event checking with hysterisis element wise through the array
            i = 0;
            for (; i < 7; i++) {
                if ( == SUCCESS) {

                }
            }
            boulder.Tapeled = ON;
        }

        if (event == SUCCESS) {
            ReturnEvent.EventType = TAPESENSOR;
            ReturnEvent.EventParam = (uint16_t) LIGHT_TO_DARK;
        }


        ES_Timer_InitTimer(TAPE_TIMER, TIMER_LENGTH);
    }

    return ReturnEvent;
}

/*******************************************************************************
 * PRIVATE FUNCTIONs                                                           *
 ******************************************************************************/
char CheckLightLevel(int currentLightLevel, int lastLightEvent) {
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;

    currentLightLevel = Roach_LightLevel();
    if ((currentLightLevel > DARK_THRESHOLD) && (lastLightEvent != DARK_TO_LIGHT)) {
        thisEvent.EventType = LIGHTLEVEL;
        thisEvent.EventParam = (uint16_t) DARK_TO_LIGHT;
        PostRoachFSM(thisEvent);
        returnVal = TRUE;
        lastLightEvent = DARK_TO_LIGHT;

    } else if ((currentLightLevel < LIGHT_THRESHOLD) && (lastLightEvent != LIGHT_TO_DARK)) {
        thisEvent.EventType = LIGHTLEVEL;
        thisEvent.EventParam = (uint16_t) LIGHT_TO_DARK;
        returnVal = TRUE;
        lastLightEvent = LIGHT_TO_DARK;
    }

    return returnVal;
}