/*
 * File:   main.c
 * Author: Waleed
 * Created on March 5, 2025, 11:02 AM
 */

#include "xc.h"
#include "LIB/STD_TYPES.h"
#include "MCAL_LAYER/MDIO/MDIO_Interface.h"

// Simple delay function (adjust based on clock speed)
void delay_ms(uint32 ms) 
{
    volatile uint32 i, j;
    for(i = 0; i < ms; i++) {
        for(j = 0; j < 600; j++); // Adjust this value as needed for your MCU
    }
}

int main(void) {
    ANSELA = ANSELB = ANSELC = ANSELD = ANSELE = ANSELG = 0x0000;
    // Configure LED as output
    SET_DIR_OUTPUT(A,0);
    
    // Configure Button as input
    SET_DIR_INPUT(E,9);
    
    // Initialize LED OFF
    SET_VAL_LOW(A,0);
    
    while(1) {
        // Read the state of the button
        uint8 buttonState = GET_VAL(E, 9);
        
        // If the button is pressed (assuming active low, i.e., buttonState == 0)
        if (buttonState == 0) {
            // Turn ON the LED
            SET_VAL_HIGH(A,0);

        } else {
            // Turn OFF the LED
            SET_VAL_LOW(A,0);

        }
        
        // Small delay to debounce the button (optional but recommended)
        delay_ms(50);
    }
    

    return 0;
}