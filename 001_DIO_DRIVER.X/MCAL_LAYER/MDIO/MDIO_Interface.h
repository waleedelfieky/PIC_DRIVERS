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
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/LBITMATH.h"
/*=================================================*/

/*=================================================*/
//defined macros
#define SET_DIR_OUTPUT(port, pin)    TRIS##port##bits.TRIS##port##pin = 0
#define SET_DIR_INPUT(port, pin)     TRIS##port##bits.TRIS##port##pin = 1
#define SET_VAL_HIGH(port, pin)      LAT##port##bits.LAT##port##pin = 1
#define SET_VAL_LOW(port, pin)       LAT##port##bits.LAT##port##pin = 0
#define GET_VAL(port, pin)           PORT##port##bits.R##port##pin

#endif /* DIO_INTERFACE_H_ */