/*
 * LCD_Private.h
 *
 *  Created on: Apr 23, 2022
 *      Author: MoWael
 */

#ifndef HAL_LCD_HEADER_LCD_PRIVATE_H_
#define HAL_LCD_HEADER_LCD_PRIVATE_H_
/*******************Commands From DATA SHEET***************************/
#define 	Clear_MODE 		0b00000001  //from data sheet -> Clear
#define 	Function_Set    0b00111000  //from data sheet -> 8bits/2line/5*8
#define  	Entry_Mode		0b00000110
#define 	Display_Control	0b00001100
#define 	SHIFT_RIGHT		0b00011100
#define 	SHIFT_LEFT		0b00011000

#define 	LCD_20X4		1
#define 	LCD_16X2		2

#endif /* HAL_LCD_HEADER_LCD_PRIVATE_H_ */
