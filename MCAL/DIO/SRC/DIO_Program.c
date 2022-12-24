/*
 * DIO_Program.c
 *
 *  Created on: Apr 22, 2022
 *      Author: MoWael
 */

#include "../../../LIBRARY/stdtype.h"
#include "../../../LIBRARY/BitMath.h"
#include "../Header/DIO_Register.h"
#include "../Header/DIO_Interface.h"
#include "../Header/DIO_Private.h"
void DIO_VoidSetPinDir (u8 Local_PortName, u8 Local_PinNumber,u8 Local_state)
{
	if (Local_PortName <= PORT_D && Local_PinNumber<=PIN_D7)
	{
		if (Local_state == DIO_OUTPUT)
		{
			switch (Local_PortName)
			{
			case PORT_A :    SET_BIT(DDRA_REG,Local_PinNumber); break;
			case PORT_B :    SET_BIT(DDRB_REG,Local_PinNumber); break;
			case PORT_C :    SET_BIT(DDRC_REG,Local_PinNumber); break;
			case PORT_D :    SET_BIT(DDRD_REG,Local_PinNumber); break;
			}
		}
		else if (Local_state == DIO_INPUT)
		{
			switch (Local_PortName)
			{
			case PORT_A :    CLR_BIT(DDRA_REG,Local_PinNumber); break;
			case PORT_B :    CLR_BIT(DDRB_REG,Local_PinNumber); break;
			case PORT_C :    CLR_BIT(DDRC_REG,Local_PinNumber); break;
			case PORT_D :    CLR_BIT(DDRD_REG,Local_PinNumber); break;
			}
		}
	}
}

void DIO_VoidSetPortDir (u8 Local_PortName, u8 Local_state)
{
	if (Local_PortName <= PORT_D)
	{
		if (Local_state == DIO_OUTPUT)
		{
			switch (Local_PortName)
			{
			case PORT_A :    DDRA_REG= 0xff; break;
			case PORT_B :    DDRB_REG= 0xff; break;
			case PORT_C :    DDRC_REG= 0xff; break;
			case PORT_D :    DDRD_REG= 0xff; break;
			}
		}
		else if (Local_state == DIO_INPUT)
		{
			switch (Local_PortName)
			{
			case PORT_A :   DDRA_REG= 0 ; break;
			case PORT_B :   DDRB_REG= 0 ; break;
			case PORT_C :   DDRC_REG= 0 ; break;
			case PORT_D :   DDRD_REG= 0 ; break;
			}
		}
	}
}
void DIO_VoidSetPinValue (u8 Local_PortName, u8 Local_PinNumber,u8 Local_Value)
{
	if (Local_PortName <= PORT_D && Local_PinNumber<=PIN_D7)
	{
		if (Local_Value == DIO_HIGH)
		{
			switch (Local_PortName)
			{
			case PORT_A :   SET_BIT(PORTA_REG,Local_PinNumber); break;
			case PORT_B :   SET_BIT(PORTB_REG,Local_PinNumber); break;
			case PORT_C :   SET_BIT(PORTC_REG,Local_PinNumber); break;
			case PORT_D :   SET_BIT(PORTD_REG,Local_PinNumber); break;
			}
		}
		else if (Local_Value == DIO_LOW)
		{
			switch (Local_PortName)
			{
			case PORT_A :   CLR_BIT(PORTA_REG,Local_PinNumber); break;
			case PORT_B :   CLR_BIT(PORTB_REG,Local_PinNumber); break;
			case PORT_C :   CLR_BIT(PORTC_REG,Local_PinNumber); break;
			case PORT_D :   CLR_BIT(PORTD_REG,Local_PinNumber); break;
			}
		}
	}
}
void DIO_VoidSetPortValue (u8 Local_PortName, u8 Local_Value)
{
	if (Local_PortName <= PORT_D)
	{

		switch (Local_PortName)
		{
		case PORT_A :   PORTA_REG =Local_Value; break;
		case PORT_B :   PORTB_REG =Local_Value; break;
		case PORT_C :   PORTC_REG =Local_Value; break;
		case PORT_D :   PORTD_REG =Local_Value; break;
		}

	}
}

u8 DIO_u8GetValue (u8 Local_PortName , u8 Local_PinNumber)
{
	u8 Local_Read = 8;
	if (Local_PortName <= PORT_D && Local_PinNumber<= PIN_D7)
	{

		switch (Local_PortName)
		{
		case PORT_A : Local_Read = GET_BIT(PINA_REG,Local_PinNumber);break;
		case PORT_B : Local_Read = GET_BIT(PINB_REG,Local_PinNumber);break;
		case PORT_C : Local_Read = GET_BIT(PINC_REG,Local_PinNumber);break;
		case PORT_D : Local_Read = GET_BIT(PIND_REG,Local_PinNumber);break;

		}

	}
	return Local_Read ;

}













