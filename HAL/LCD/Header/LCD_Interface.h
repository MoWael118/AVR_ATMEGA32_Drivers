/*
 * LCD_Interface.h
 *
 *  Created on: Apr 23, 2022
 *      Author: MoWael
 */

#ifndef HAL_LCD_HEADER_LCD_INTERFACE_H_
#define HAL_LCD_HEADER_LCD_INTERFACE_H_
#include "LCD_Configuration.h"
#include "LCD_Private.h"
#include "../../../LIBRARY/stdtype.h"
/*Send Command*/
void LCD_VoidSendCom(u8 Local_Command);
/*SEND DATA*/
void LCD_VoidSendChar(u8 Local_Char);
/*LCD INITialization*/
void LCD_VoidInit(void);
/*Send String*/
void LCD_VoidSendString(u8 * String);
/*Start Position (X,Y)	*/
void LCD_VoidGoToXY(u8 X_Position,u8 Y_Position);
void LCD_VoidSendSpecialChar(u8* Local_Pattern , u8 Local_BlockNo,u8 X_Pos,u8 Y_Pos);
void LCD_VoidSendNumber(s32 local_U32Number);
void LCD_VoidShiftRight(void);
void LCD_VoidShiftLeft(void);



#endif /* HAL_LCD_HEADER_LCD_INTERFACE_H_ */
