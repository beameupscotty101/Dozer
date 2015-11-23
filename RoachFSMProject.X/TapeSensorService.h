
#ifndef TAPESENSORSERVICE_H
#define	TAPESENSORSERVICE_H

uint8_t InitTapeSensorService(uint8_t Priority);
uint8_t PostTapeSensorService(ES_Event ThisEvent);
ES_Event RunTapeSensorService(ES_Event ThisEvent);

#endif	/* TAPESENSORSERVICE_H */

