#ifndef SRC_AP_WATCH_WATCH_H_
#define SRC_AP_WATCH_WATCH_H_

#include "../../driver/FND/FND.h"
#include "../../common/common.h"

typedef struct {
    uint8_t msec;  //
    uint8_t  sec;   // 0~59
    uint8_t  min;   // 0~59
    uint8_t  hour;  // 0~23
} watch_time_t;

void Watch_Init();
void Watch_Excute();
void Watch_DispLoop();
void Watch_Run();

#endif /* SRC_AP_WATCH_WATCH_H_ */
