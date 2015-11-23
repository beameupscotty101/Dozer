
#ifndef TAPESENSORSERVICE_H
#define	TAPESENSORSERVICE_H

typedef enum {
    DARK_TO_LIGHT, LIGHT_TO_DARK
} lightstate_t;

uint8_t InitTapeSensorService(uint8_t Priority);
uint8_t PostTapeSensorService(ES_Event ThisEvent);
ES_Event RunTapeSensorService(ES_Event ThisEvent);

#endif	/* TAPESENSORSERVICE_H */

