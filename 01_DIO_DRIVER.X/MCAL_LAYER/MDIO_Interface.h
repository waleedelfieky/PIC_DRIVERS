/*
 * DIO_Interface.h
 *
 *  Created on: 5, 3, 2025
 *      Author: Waleed Efieky
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/*=================================================*/
//include headers
#include "xc.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/LBITMATH.h"
/*=================================================*/

/*=================================================*/
//defined macros
#define DIO_OUTPUT  1
#define DIO_INPUT   0

#define DIO_HIGH    1    
#define DIO_LOW     0

#define DIO_PORTA       0
#define DIO_PORTB       1
#define DIO_PORTC       2
#define DIO_PORTD       3
#define DIO_PORTE       4
#define DIO_PORTF       5
#define DIO_PORTG       6

#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15


/*=================================================*/

//function to set the pin direction to be output or input
void MDIO_vSetPinDirection(uint8 A_u8PortNum, uint8 A_uint8PinNum, uint8 A_uint8Dir );

void MDIO_vSetPinValue(uint8 A_uint8PortNum, uint8 A_uint8PinNum, uint8 A_uint8Val);

uint8 MDIO_u8GetPinValue(uint8 A_uint8PortNum, uint8 A_uint8PinNum);

void MDIO_vTogglePinValue(uint8 A_uint8PortNum, uint8 A_uint8PinNum);



#endif /* DIO_INTERFACE_H_ */