/*
 * USART_Interface.h
 *
 *  Created on: Oct 1, 2022
 *      Author: mhmd wael
 */

#ifndef MCAL_USART_HEADER_USART_INTERFACE_H_
#define MCAL_USART_HEADER_USART_INTERFACE_H_

#include "USART_Config.h"
#include "USART_Register.h"
#include "USART_Private.h"



void USART_VoidInit(void);

u8 USART_u8ReceiveDataSync(void);

void USART_VoidSendDataSync(u8 Local_u8Data);

void USART_VoidReceiveDataAsync(u8*Data_Variable ,void(*NotifyFunc)(void));

void USART_VoidSendDataAsync(u8 Data ,void(*NotifyFunc)(void));



#endif /* MCAL_USART_HEADER_USART_INTERFACE_H_ */
