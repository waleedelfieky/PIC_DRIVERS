/*
 * File:   main.c
 * Author: waleed
 *
 * Created on March 16, 2025, 3:07 PM
 */


/*=============================================================*/ 
#include "xc.h"
#include "LIB/STD_TYPES.h"
#include "MCAL_LAYER/MDIO/MDIO_Interface.h"
#include "MCAL_LAYER/MTIMER/TIMER_interface.h"
/*=============================================================*/ 
#define LED1 LATAbits.LATA0
#define LED2 LATGbits.LATG9
/*=============================================================*/ 

/*=============================================================*/ 
void init(void);
void blinkled (void);
/*=============================================================*/ 


int main(void) {
    //initlize funciton call
    init();
    
    //Timer period setup
    tmr_setup_period(TIMER1, 200);
    tmr_setup_period(TIMER2, 200);
    
    //Start Timer2 Asynchronus
    Timer_ASYNCHRONOUS(TIMER2, 200);
    
    
    while (1) {
        if (GET_VAL(A,0) == 1) {
            SET_VAL_LOW(A,0);
        } 
        else if(GET_VAL(A,0) == 0)
        {
            SET_VAL_HIGH(A,0);
        }

        // Wait for 200ms
        tmr_wait_period(1);
    }
    
    
    return 0; 

}


/*=============================================================*/ 
void init(void){
    /*
     inside this fucntion we are going to define the initilization for DIO
     driver and ADC then we will implement a simple application for test 
     purpose only
     */
    // let all pins in Digital input/output mood
    ANSELA = ANSELB = ANSELC = ANSELD = ANSELE = ANSELG = 0x0000;
    //define leds as output
    SET_DIR_OUTPUT(A,0);
    SET_DIR_OUTPUT(G,9);
    //let two leds blink on
    SET_VAL_HIGH(A,0);
    SET_VAL_HIGH(G,9);
}
/*=============================================================*/ 



//    
//    
//// Timer1 Interrupt Service Routine (ISR)
//void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void) {
//    /* Interrupt Service Routine code goes here */
//
//    IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag
//}


/*=============================================================*/ 
// Timer2 Interrupt Service Routine (ISR)
void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void) {
    /* Interrupt Service Routine code goes here */
    uint8 pin_val= GET_VAL(G,9);
    if (pin_val==1){
        //turn off the led
        SET_VAL_LOW(G,9);
    }
    else if(pin_val==0)
    {
        //set on the led
        SET_VAL_HIGH(G,9);
    }
    IFS0bits.T2IF = 0; // Clear Timer2 Interrupt Flag
}
/*=============================================================*/ 
