/************************************************************/
/**********    Author      : Waleed Eflieky       **********/
/**********    Date        : 6/3/2025            **********/
/**********    Description : BITMATH library    **********/
/**********    Version     : 1.0 V             **********/
/*******************************************************/




/*******************************************************************/
/****   Gaurd file that will be called one time in file.c      ****/
/*****************************************************************/


#ifndef BITMATH_H
#define BITMATH_H


#define SET_BIT(Reg,bitnum)     (Reg) |= ( 1<<(bitnum) )

#define CLR_BIT(Reg,bitnum)     (Reg) &= ~( 1<<(bitnum) )

#define TOGGLE_BIT(Reg,bitnum)  (Reg) ^= ( 1<<(bitnum) )  

#define GET_BIT(Reg,bitnum)     ( ( (Reg)>>(bitnum) ) & 1 ) 



#endif