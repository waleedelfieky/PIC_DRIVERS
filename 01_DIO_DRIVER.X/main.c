/*
 * File:   main.c
 * Author: waleed
 *
 * Created on March 5, 2025, 11:02 AM
 */
/*====================================*/
#include "LIB/STD_TYPES.h"
#include "LIB/LBITMATH.h"
#include "MCAL_LAYER/MDIO_Interface.h"
/*====================================*/

void delay_ms(uint32 ms) {
    volatile uint32 i, j;
    for(i = 0; i < ms; i++) {
        for(j = 0; j < 600; j++); // Adjust this for your MCU speed
    }
}



int main(void) {
    MDIO_vSetPinDirection(DIO_PORTA,PIN0,DIO_OUTPUT);
    MDIO_vSetPinValue(DIO_PORTA,PIN0, DIO_HIGH);
    while(1){
        delay_ms(10000);
        MDIO_vSetPinValue(DIO_PORTA,PIN0, DIO_HIGH);
        delay_ms(10000);
        MDIO_vSetPinValue(DIO_PORTA,PIN0, DIO_LOW);
    }
    return 0;
}
