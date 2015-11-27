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
#include "TapeSensorService.h"
#include "AD.h"
#include "Dozer.h"
#include "IO_Ports.h"

#define LED_ON_TIME 9
#define LED_OFF_TIME 9

uint8_t CheckTapeSensors() {

    typedef enum {
        WAKEUP,
        TAPE_ON,
        READ_ON_0,
        READ_ON_1,
        READ_ON_2,
        READ_ON_3,
        READ_ON_4,
        READ_ON_5,
        READ_ON_6,
        TAPE_OFF,
        READ_OFF_0,
        READ_OFF_1,
        READ_OFF_2,
        READ_OFF_3,
        READ_OFF_4,
        READ_OFF_5,
        READ_OFF_6,
        POST_EVENT,
    } state_t;

    static state_t state = WAKEUP;
    static uint32_t tapeTime = 0;
    uint32_t newTime;
    ES_Event thisEvent;

    uint16_t Event = 0;

    //printf("Hi from CheckTapeSensors! %d\n", state);

    switch (state) {
        case WAKEUP:
            tapeTime = ES_Timer_GetTime();
            state = TAPE_ON;
            break;

        case TAPE_ON:
            // LED On
            TapeSensorLed(1);
            // Set Port
            IO_PortsClearPortBits(MUX_PORT, MUX_S0);
            IO_PortsClearPortBits(MUX_PORT, MUX_S1);
            IO_PortsClearPortBits(MUX_PORT, MUX_S2);
            // Next State
            newTime = ES_Timer_GetTime();
            if (newTime > tapeTime + LED_ON_TIME) {
                tapeTime = newTime;
                state = READ_ON_0;
            }
            break;

        case READ_ON_0:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_ON[0] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_ON_1;
            }
            break;

        case READ_ON_1:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_ON[1] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsSetPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_ON_2;
            }
            break;

        case READ_ON_2:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_ON[2] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsSetPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_ON_3;
            }
            break;

        case READ_ON_3:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_ON[3] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsSetPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_ON_4;
            }
            break;

        case READ_ON_4:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_ON[4] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsSetPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_ON_5;
            }
            break;

        case READ_ON_5:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_ON[5] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsSetPortBits(MUX_PORT, MUX_S1);
                IO_PortsSetPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_ON_6;
            }
            break;

        case READ_ON_6:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_ON[6] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = TAPE_OFF;
            }
            break;

        case TAPE_OFF:
            TapeSensorLed(0);
            newTime = ES_Timer_GetTime();
            if (newTime > tapeTime + LED_OFF_TIME) {
                tapeTime = newTime;
                state = READ_OFF_0;
            }
            break;

        case READ_OFF_0:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_OFF[0] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_OFF_1;
            }
            break;

        case READ_OFF_1:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_OFF[1] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsSetPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_OFF_2;
            }
            break;

        case READ_OFF_2:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_OFF[2] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsSetPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_OFF_3;
            }
            break;

        case READ_OFF_3:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_OFF[3] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsSetPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_OFF_4;
            }
            break;

        case READ_OFF_4:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_OFF[4] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsSetPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsSetPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_OFF_5;
            }
            break;

        case READ_OFF_5:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_OFF[5] = AD_ReadADPin(MUX_OUTPT);
                // Set Port
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsSetPortBits(MUX_PORT, MUX_S1);
                IO_PortsSetPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = READ_OFF_6;
            }
            break;

        case READ_OFF_6:
            if (AD_IsNewDataReady()) {
                // Get Data
                tapeSensorLedData_OFF[6] = AD_ReadADPin(MUX_OUTPT);

                // Set Port
                IO_PortsClearPortBits(MUX_PORT, MUX_S0);
                IO_PortsClearPortBits(MUX_PORT, MUX_S1);
                IO_PortsClearPortBits(MUX_PORT, MUX_S2);
                // Next State
                state = POST_EVENT;
            }
            break;

        case POST_EVENT:
            thisEvent.EventType = TAPESENSOR;
            PostTapeSensorService(thisEvent);
            state = TAPE_ON;
            return TRUE;
            break;
    }

    return FALSE;
}

/*
uint8_t CheckFSR() {

    typedef enum event_t {
        FSR_1_reading,
        FSR_2_reading,
        FSR_Check_event,
    } event_t;

    static event_t state = FSR_1_reading;
    static int FSR1ReadValue = 0;
    static int FSR2ReadValue = 0;


    switch (state) {
        case FSR_1_reading:
        {
            if (AD_IsNewDataReady()) {
                state = FSR_2_reading;
                FSR1ReadValue = Boulder_FSR_Left();
            }
            break;
        }

        case FSR_2_reading:
        {
            if (AD_IsNewDataReady()) {
                state = FSR_Check_event;
                FSR2ReadValue = Boulder_FSR_Right();
            }
            break;
        }

        case():
        {
            if (FSR2ReadValue < 400 && FSR2prevEvent == 1) {
                FSR2prevEvent = 0;

            } else if (FSR2ReadValue > 400 && FSR2prevEvent == 0) {
                FSR2prevEvent = 1;

            }

            if (FSR1ReadValue < 400 && FSR1prevEvent == 1) {
                FSR2prevEvent = 0;
                return true;
            } else if (FSR1ReadValue > 400 && FSR1prevEvent == 0) {
                FSR2prevEvent = 1;
                return TRUE;
            }

            break;
        }
            return FALSE;
    }

}
 */
