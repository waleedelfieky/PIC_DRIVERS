 
#ifndef TIMER_INTERFACE_H
#define	TIMER_INTERFACE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "../../LIB/STD_TYPES.h"


#define TIMER1 1
#define TIMER2 2


typedef enum {
    TIMER_OK = 0,       // Success
    TIMER_ERROR = 1     // Failure (ms >= 200)
} TimerStatus;



TimerStatus tmr_setup_period(uint8 timer, uint32 ms);
void tmr_wait_period(uint8 timer);
TimerStatus Timer_ASYNCHRONOUS(uint8 timer, uint32 ms);


#endif	/* TIMER_INTERFACE */

