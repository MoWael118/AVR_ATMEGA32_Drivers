/*
 * LCD_Program.c
 *
 *  Created on: Apr 23, 2022
 *      Author: MoWael
 */

#include "../../../LIBRARY/stdtype.h"
#include "../../../LIBRARY/BitMath.h"

#include "../../../MCAL/DIO/Header/DIO_Private.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../MCAL/DIO/Header/DIO_Register.h"


#include "../Header/LCD_Private.h"
#include "../Header/LCD_Interface.h"
#include "../Header/LCD_Configuration.h"

#include <util/delay.h>

void LCD_VoidSendCom(u8 Local_Command)
{
	/*Step 1 -> SELECT RS=0 To Send COMMAND*/
	DIO_VoidSetPinValue(LCD_PORT_Control,LCD_PIN_RS,DIO_LOW);
	/*Step 2 -> R/W (Zero because writing)*/
	DIO_VoidSetPinValue(LCD_PORT_Control,LCD_PIN_RW,DIO_LOW);
	/*Step3 -> SET Enable Pin (HIGH)*/
	DIO_VoidSetPinValue(LCD_PORT_Control,LCD_PIN_E,DIO_HIGH);
	/*Step 4 -> SEND Data*/
	DIO_VoidSetPortValue (LCD_PORT_Data, Local_Command);
	/*Step 5 -> Close Enable*/
	DIO_VoidSetPinValue(LCD_PORT_Control,LCD_PIN_E,DIO_LOW);
}
void LCD_VoidSendChar(u8 Local_Char)
{
	/*Step 1 -> SELECT RS=1 To Send Character*/
	DIO_VoidSetPinValue(LCD_PORT_Control,LCD_PIN_RS,DIO_HIGH);
	/*Step 2 -> R/W (Zero because writing)*/
	DIO_VoidSetPinValue(LCD_PORT_Control,LCD_PIN_RW,DIO_LOW);
	//Step3 -> SET Enable Pin (HIGH)
	DIO_VoidSetPinValue(LCD_PORT_Control,LCD_PIN_E,DIO_HIGH);
	//Step 4 -> SEND Data
	DIO_VoidSetPortValue (LCD_PORT_Data, Local_Char);
	//Step 5 -> Close Enable
	DIO_VoidSetPinValue(LCD_PORT_Control,LCD_PIN_E,DIO_LOW);

}

void LCD_VoidInit(void)
{
#if LCD_Module	==	LCD_16X2
	DIO_VoidSetPortDir(LCD_PORT_Data,DIO_OUTPUT);
	DIO_VoidSetPinDir(LCD_PORT_Control,LCD_PIN_E, DIO_OUTPUT);
	DIO_VoidSetPinDir(LCD_PORT_Control,LCD_PIN_RW,DIO_OUTPUT);
	DIO_VoidSetPinDir(LCD_PORT_Control,LCD_PIN_RS,DIO_OUTPUT);

	/*Initializations Steps From Data Sheet Page 13*/
	_delay_ms(30);
	LCD_VoidSendCom(Function_Set);
	_delay_ms(2);
	LCD_VoidSendCom(Display_Control);
	_delay_ms(2);
	LCD_VoidSendCom(Clear_MODE);
	_delay_ms(2);
	LCD_VoidSendCom(Entry_Mode);
#elif LCD_Module	== LCD_20X4
	DIO_VoidSetPortDir(LCD_PORT_Data,DIO_OUTPUT);
	DIO_VoidSetPinDir(LCD_PORT_Control,LCD_PIN_E, DIO_OUTPUT);
	DIO_VoidSetPinDir(LCD_PORT_Control,LCD_PIN_RW,DIO_OUTPUT);
	DIO_VoidSetPinDir(LCD_PORT_Control,LCD_PIN_RS,DIO_OUTPUT);
	/*Initialization from Data Sheet*/
	_delay_ms(16);
	LCD_VoidSendCom(0b00110000);
	_delay_ms(5);
	LCD_VoidSendCom(0b00110000);
	_delay_us(120);
	LCD_VoidSendCom(0b00110000);

	LCD_VoidSendCom(0b00111000);
	LCD_VoidSendCom(0b00001100);
	LCD_VoidSendCom(0b00000001);
	LCD_VoidSendCom(0b00000110);




#endif
}
void LCD_VoidSendString(u8 * String)
{
	u8 Local_Counter	=	0	;
	while(String[Local_Counter] != '\0')
	{
		LCD_VoidSendChar(String[Local_Counter]);
		Local_Counter++;
	}

}

void LCD_VoidGoToXY(u8 X_Position,u8 Y_Position)
{
#if LCD_Module	==	LCD_16X2

	u8 Local_Addres=0 ;

	if (X_Position==0)
	{
		Local_Addres= Y_Position;
	}
	else if (X_Position==1)
	{
		Local_Addres = Y_Position + 0x40 ;
	}
	LCD_VoidSendCom(Local_Addres + 128);
#elif LCD_Module	== LCD_20X4
	if (Y_Position<20 	&& X_Position<4)
	{
		u8 Local_Addres=0 ;
		switch(X_Position)
		{
		case 0 : Local_Addres	= 0x00;	 break;
		case 1 : Local_Addres	= 0x40;	 break;
		case 2 : Local_Addres	= 0x14;	 break;
		case 3 : Local_Addres	= 0x54;	 break;
		}
		LCD_VoidSendCom(Local_Addres +128+Y_Position);
	}


#endif
}
void LCD_VoidSendSpecialChar(u8* Local_Pattern , u8 Local_BlockNo,u8 X_Pos,u8 Y_Pos)
{
	u8 Local_CGRAMAddress =0,Local_Iterator;
	/*Calculate CGRAM ADDRESS*/
	Local_CGRAMAddress = Local_BlockNo*8 ;
	/*Send CGRAM Address command to LCD & set bit 6*/
	LCD_VoidSendCom(Local_CGRAMAddress+64);
	/*Write pattern on CGRAM*/
	for (Local_Iterator=0 ; Local_Iterator<8 ;Local_Iterator++)
	{
		LCD_VoidSendChar(Local_Pattern[Local_Iterator]);

	}
	/*GO back to DDRAM TO display the pattern*/
	LCD_VoidGoToXY(X_Pos,Y_Pos);
	/*Display the pattern written in CGRAM*/
	LCD_VoidSendChar(Local_BlockNo);
}
void LCD_VoidSendNumber(s32 local_U32Number)
{
	s32 Local_S32Num = 1;

	if(local_U32Number == 0 )
	{
		LCD_VoidSendChar('0');
	}
	else if (local_U32Number < 0)
	{
		LCD_VoidSendChar('-');
		local_U32Number *= -1;
	}
	while (local_U32Number != 0)
	{
		Local_S32Num = ((Local_S32Num * 10) + (local_U32Number % 10));
		local_U32Number = (local_U32Number / 10);
	}
	while (Local_S32Num != 1)
	{
		LCD_VoidSendChar((Local_S32Num % 10) + 48);
		Local_S32Num = (Local_S32Num / 10);
	}

}
void LCD_VoidShiftRight(void)
{
	LCD_VoidSendCom(SHIFT_RIGHT);
}
void LCD_VoidShiftLeft(void)
{
	LCD_VoidSendCom(SHIFT_LEFT);
}


