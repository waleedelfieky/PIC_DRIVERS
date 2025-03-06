/**
 * author: Waleed Elfieky
 * date: 5,3,2025
 */

/*====================================================*/
#include "xc.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/LBITMATH.h"
#include "MDIO_Interface.h"

/*====================================================*/

/*====================================================*/
// Function to set the pin direction (input/output)
void MDIO_vSetPinDirection(uint8 A_uint8PortNum, uint8 A_uint8PinNum, uint8 A_uint8Dir ) {
    if (A_uint8Dir == DIO_OUTPUT) {
        switch (A_uint8PortNum) {
            case DIO_PORTA: CLR_BIT(TRISA, A_uint8PinNum); break;  
            case DIO_PORTB: CLR_BIT(TRISB, A_uint8PinNum); break;
            case DIO_PORTC: CLR_BIT(TRISC, A_uint8PinNum); break;
            case DIO_PORTD: CLR_BIT(TRISD, A_uint8PinNum); break;
            case DIO_PORTE: CLR_BIT(TRISE, A_uint8PinNum); break;
            case DIO_PORTF: CLR_BIT(TRISF, A_uint8PinNum); break;
            case DIO_PORTG: CLR_BIT(TRISG, A_uint8PinNum); break;
        }
    } else {
        switch (A_uint8PortNum) {
            case DIO_PORTA: SET_BIT(TRISA, A_uint8PinNum); break;  
            case DIO_PORTB: SET_BIT(TRISB, A_uint8PinNum); break;
            case DIO_PORTC: SET_BIT(TRISC, A_uint8PinNum); break;
            case DIO_PORTD: SET_BIT(TRISD, A_uint8PinNum); break;
            case DIO_PORTE: SET_BIT(TRISE, A_uint8PinNum); break;
            case DIO_PORTF: SET_BIT(TRISF, A_uint8PinNum); break;
            case DIO_PORTG: SET_BIT(TRISG, A_uint8PinNum); break;
        }
    }
}
/*====================================================*/

/*====================================================*/
// Function to set a pin's value (HIGH/LOW)
void MDIO_vSetPinValue(uint8 A_uint8PortNum, uint8 A_uint8PinNum, uint8 A_uint8Val) {
    if (A_uint8Val) {
        switch (A_uint8PortNum) {
            case DIO_PORTA: SET_BIT(LATA, A_uint8PinNum); break;  
            case DIO_PORTB: SET_BIT(LATB, A_uint8PinNum); break;
            case DIO_PORTC: SET_BIT(LATC, A_uint8PinNum); break;
            case DIO_PORTD: SET_BIT(LATD, A_uint8PinNum); break;
            case DIO_PORTE: SET_BIT(LATE, A_uint8PinNum); break;
            case DIO_PORTF: SET_BIT(LATF, A_uint8PinNum); break;
            case DIO_PORTG: SET_BIT(LATG, A_uint8PinNum); break;
        }
    } else {
        switch (A_uint8PortNum) {
            case DIO_PORTA: CLR_BIT(LATA, A_uint8PinNum); break;  
            case DIO_PORTB: CLR_BIT(LATB, A_uint8PinNum); break;
            case DIO_PORTC: CLR_BIT(LATC, A_uint8PinNum); break;
            case DIO_PORTD: CLR_BIT(LATD, A_uint8PinNum); break;
            case DIO_PORTE: CLR_BIT(LATE, A_uint8PinNum); break;
            case DIO_PORTF: CLR_BIT(LATF, A_uint8PinNum); break;
            case DIO_PORTG: CLR_BIT(LATG, A_uint8PinNum); break;
        }
    }
}
/*====================================================*/

/*====================================================*/
// Function to read a pin's value
uint8 MDIO_u8GetPinValue(uint8 A_uint8PortNum, uint8 A_uint8PinNum) {
    switch (A_uint8PortNum) {
        case DIO_PORTA: return GET_BIT(PORTA, A_uint8PinNum);
        case DIO_PORTB: return GET_BIT(PORTB, A_uint8PinNum);
        case DIO_PORTC: return GET_BIT(PORTC, A_uint8PinNum);
        case DIO_PORTD: return GET_BIT(PORTD, A_uint8PinNum);
        case DIO_PORTE: return GET_BIT(PORTE, A_uint8PinNum);
        case DIO_PORTF: return GET_BIT(PORTF, A_uint8PinNum);
        case DIO_PORTG: return GET_BIT(PORTG, A_uint8PinNum);
        default: return 0; // Invalid port
    }
}
/*====================================================*/

/*====================================================*/
// Function to toggle a pin's value
void MDIO_vTogglePinValue(uint8 A_uint8PortNum, uint8 A_uint8PinNum){
    switch (A_uint8PortNum) {
        case DIO_PORTA: TOGGLE_BIT(LATA, A_uint8PinNum); break;  
        case DIO_PORTB: TOGGLE_BIT(LATB, A_uint8PinNum); break;
        case DIO_PORTC: TOGGLE_BIT(LATC, A_uint8PinNum); break;
        case DIO_PORTD: TOGGLE_BIT(LATD, A_uint8PinNum); break;
        case DIO_PORTE: TOGGLE_BIT(LATE, A_uint8PinNum); break;
        case DIO_PORTF: TOGGLE_BIT(LATF, A_uint8PinNum); break;
        case DIO_PORTG: TOGGLE_BIT(LATG, A_uint8PinNum); break;
    }
}
/*====================================================*/
