/*
 * File:   TIMER_prg.c
 * Author: waleed
 *
 * Created on March 16, 2025, 3:09 PM
 */


#include "xc.h"
#include "../../LIB/STD_TYPES.h"
#include "TIMER_interface.h"



TimerStatus tmr_setup_period(uint8 timer, uint32 ms) {
    //check if the ms is within the range 
    if (ms > 200) {
        return TIMER_ERROR;
    }
        
    //formula to calulate the needed ticks to get the job done
    uint32 Needed_Ticks = (72000*ms) / 256;

    //now we need to setup the timer
    switch (timer) {
        case 1:
            TMR1 = 0; // Reset the timer
            PR1 = Needed_Ticks; // Set the period register
            IFS0bits.T1IF = 0; // Clear the interrupt flag
            T1CONbits.TCKPS = 3; // prescaler 1:256
            T1CONbits.TON = 1; // starts the timer!
            break;
           
        case 2:
            TMR2 = 0;               // Reset the timer
            PR2 = Needed_Ticks;     // Set the period register
            IFS0bits.T2IF = 0;      // Clear the interrupt flag
            T1CONbits.TCKPS = 3;    // prescaler 1:256
            T1CONbits.TON = 1;      // starts the timer!
            break;
        default:
            return TIMER_ERROR;
            break;

    }
    return TIMER_OK;
}




void tmr_wait_period(uint8 timer){
    switch (timer) {
        case 1:
            while (!IFS0bits.T1IF); // Wait for the flag to be set
            IFS0bits.T1IF = 0; // Clear the flag
            break;
        case 2:
            while (!IFS0bits.T2IF);
            IFS0bits.T2IF = 0;
            break;
        default:
            break;
    }
}



TimerStatus Timer_ASYNCHRONOUS(uint8 timer, uint32 ms) {
    //check if the ms is within the range 
    if (ms > 200) {
        return TIMER_ERROR;
    }
        
    //formula to calulate the needed ticks to get the job done
    uint16 Needed_Ticks = (72000*ms) / 256;

    //now we need to setup the timer
    switch (timer) {
        case 1:
            TMR1 = 0;               // Reset the timer
            PR1 = Needed_Ticks;     // Set the period register
            IFS0bits.T1IF = 0;      // Clear the interrupt flag
            T1CONbits.TCKPS = 3;    // Prescaler 1:256
            IPC0bits.T1IP = 0x01;   // set interrupt priority for timer 1
            IEC0bits.T1IE = 1;      // Enable the interrupt
            T1CONbits.TON = 1;      // starts the timer!
            break;
           
        case 2:
            T2CONbits.TON = 0;
            T2CONbits.TGATE = 0;
            T2CONbits.TCKPS = 3;    // prescaler 1:256
            TMR2 = 0;               // Reset the timer
            PR2 = Needed_Ticks;     // Set the period register
            IPC1bits.T2IP = 0x01; // Set Timer2 Interrupt Priority Level
            IFS0bits.T2IF = 0;    // Clear Timer2 Interrupt Flag
            IEC0bits.T2IE = 1;    // Enable Timer2 Interrupt
            T2CONbits.TON = 1;    // Start Timer
            break;
        default:
            return TIMER_ERROR;
            break;

    }
    return TIMER_OK;
}




