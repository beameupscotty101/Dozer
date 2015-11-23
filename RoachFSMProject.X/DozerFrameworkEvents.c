#include <BOARD.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "DozerFrameworkEvents.h"
#ifdef DEV
#include "ES_ServiceHeaders.h"
#include "ES_Events.h"
#endif
#include "Dozer.h"
#include <stdio.h>

uint8_t CheckTapeSensor(void) {
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;

    static uint8_t TapeSensorStatus = 0;
    uint8_t TapeSensorReading = BoulderTapeSensor();
    uint8_t TapeSensorEvent = 0;

    int i = 0;
    for (; i < 6; i++) {
        if ((TapeSensorReading & 0x01 << i) != (TapeSensorStatus & 0x01 << i)) {
            //if the reading is 0 but it was previously 1 set it to 0
            if ((TapeSensorReading & (0x01 << i)) == (0x01 << i)) {
                TapeSensorStatus ^= 0x01 << i;
                TapeSensorEvent ^= 0x01 << i;
            } else {
                TapeSensorStatus &= ~(0x01 << i);
            }
            returnVal = TRUE;
        }
    }

    if (returnVal == TRUE) {
        thisEvent.EventType = TAPESENSOR;
        thisEvent.EventParam = TapeSensorEvent;
        PostRoachFSM(thisEvent);
    }
}

