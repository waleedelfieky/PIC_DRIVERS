/*
 * File:   main.c
 * Author: Waleed
 * Created on March 5, 2025, 11:02 AM
 */

#include "LIB/STD_TYPES.h"
#include "LIB/LBITMATH.h"
#include "MCAL_LAYER/MDIO_Interface.h"

// Simple delay function (adjust based on clock speed)
void delay_ms(uint32 ms) {
    volatile uint32 i, j;
    for(i = 0; i < ms; i++) {
        for(j = 0; j < 600; j++); // Adjust this value as needed for your MCU
    }
}

int main(void) {
    ANSELA = ANSELB = ANSELC = ANSELD = ANSELE = ANSELG = 0x0000;
    // Configure LED as output
    MDIO_vSetPinDirection(DIO_PORTA, PIN0, DIO_OUTPUT);
    
    // Configure Button as input
    MDIO_vSetPinDirection(DIO_PORTE, PIN9, DIO_INPUT);
    
    // Initialize LED OFF
    MDIO_vSetPinValue(DIO_PORTA, PIN0, DIO_LOW);
    
    while(1) {
        // Read the state of the button
        uint8 buttonState = MDIO_u8GetPinValue(DIO_PORTE, PIN9);
        
        // If the button is pressed (assuming active low, i.e., buttonState == 0)
        if (buttonState == 0) {
            // Turn ON the LED
            MDIO_vSetPinValue(DIO_PORTA, PIN0, DIO_HIGH);
        } else {
            // Turn OFF the LED
            MDIO_vSetPinValue(DIO_PORTA, PIN0, DIO_LOW);
        }
        
        // Small delay to debounce the button (optional but recommended)
        delay_ms(50);
    }

    return 0;
}