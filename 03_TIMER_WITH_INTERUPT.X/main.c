/*
 * File:   main.c
 * Author: waleed
 *
 * Created on March 10, 2025, 10:15 AM
 */


#include "xc.h"
#define TIMER1 1
#define TIMER2 2
#define LED1 LATAbits.LATA0
#define LED2 LATGbits.LATG9


void tmr_setup_period(int timer, int ms);
void tmr_wait_period(int timer);



void tmr_setup_period(int timer, int ms) {
    if (ms > 200) {
        ms = 200;
    }

    // Calculate the value for PRx based on the clock frequency
    // Assuming a clock frequency of 1 MHz (1 tick = 1 microsecond)
    unsigned int pr_value = ms * 1000; // Convert milliseconds to microseconds

    switch (timer) {
        case 1:
            //PR1 = pr_value; // Set the period register

            TMR1 = 0; // Reset the timer
            PR1 = 50000; // Set the period register

            IFS0bits.T1IF = 0; // Clear the interrupt flag
            T1CONbits.TCKPS = 3; // prescaler 1:8
            T1CONbits.TON = 1; // starts the timer!
            break;
        default:
            break;

    }
}

void tmr_wait_period(int timer) {
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

// Timer2 Configuration
void Timer2_WITH_INTERRUPT(int value) {
    T2CONbits.TON = 0;        // Disable Timer
    T2CONbits.TGATE = 0;      // Disable Gated Timer mode
    
    T2CONbits.TCKPS = 3;   // Select 1:1 Prescaler
    
    TMR2 = 0x00;              // Clear timer register
    PR2 = value;              // Load the period value

    IPC1bits.T2IP = 0x01; // Set Timer2 Interrupt Priority Level
    IFS0bits.T2IF = 0;    // Clear Timer2 Interrupt Flag
    IEC0bits.T2IE = 1;    // Enable Timer2 Interrupt

    T2CONbits.TON = 1;    // Start Timer
}




int main(void) {
    ANSELA = ANSELB = ANSELC = ANSELD = ANSELE = ANSELG = 0x0000;
    //

    TRISAbits.TRISA0 = 0;
    
    TRISGbits.TRISG9 = 0;
    LED2 = 1;
   
    tmr_setup_period(TIMER1, 200);
    LED1 = 1;
    
    Timer2_WITH_INTERRUPT(30000);
    
    
    while (1) {
        if (LED1 == 1) {
            LED1 = 0;
        } else {
            LED1 = 1;
        }

        // Wait for 200ms
        tmr_wait_period(1);
    }

    return 0;
}



// Timer2 Interrupt Service Routine (ISR)
void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void) {
    /* Interrupt Service Routine code goes here */
    LED2 = !LED2;
    IFS0bits.T2IF = 0; // Clear Timer2 Interrupt Flag
}
