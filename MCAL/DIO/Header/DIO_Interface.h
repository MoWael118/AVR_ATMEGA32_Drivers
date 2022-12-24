/*
 * DIO_Interface.h
 *
 *  Created on: Apr 22, 2022
 *      Author: MoWael
 */

#ifndef MCAL_DIO_HEADER_DIO_INTERFACE_H_
#define MCAL_DIO_HEADER_DIO_INTERFACE_H_

#include "../../../LIBRARY/stdtype.h"
#include "../Header/DIO_Private.h"
#include "../Header/DIO_Configuration.h"
#include "../Header/DIO_Register.h"

void DIO_VoidSetPinDir (u8 Local_PortName, u8 Local_PinNumber,u8 Local_state);

void DIO_VoidSetPortDir (u8 Local_PortName, u8 Local_state);

void DIO_VoidSetPinValue (u8 Local_PortName, u8 Local_PinNumber,u8 Local_Value);

void DIO_VoidSetPortValue (u8 Local_PortName, u8 Local_Value);

u8 DIO_u8GetValue (u8 Local_PortName , u8 Local_PinNumber);

#endif /* MCAL_DIO_HEADER_DIO_INTERFACE_H_ */
