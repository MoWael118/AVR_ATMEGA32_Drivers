/*
 * ADC_Interface.h
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */

#ifndef MCAL_ADC_HEADER_ADC_INTERFACE_H_
#define MCAL_ADC_HEADER_ADC_INTERFACE_H_

#include "ADC_Configuration.h"
#include "ADC_Private.h"
#include "ADC_Register.h"

typedef struct
{
	u8 Size;
	u16* Result;
	u8* Channel;
	void (*NotificationFunc)(void);
}Chain_t;
/*********************************************************************
 * Description :	INITIALIZATION FOR ADC
 * INPUTS : 		VOID
 * RETURN :			VOID
 *********************************************************************/
void ADC_VoidInit(void);
/*********************************************************************/
/*********************************************************************
 * Description :	Getting Synchronized Reading (Busy Wait until Conversion done)
 * INPUTS : 		u8 		ADC_Channel
 * RETURN :			u16		Read Value
 *********************************************************************/
/*********************************************************************/
u16  ADC_u16GetSyncReading(u8 ADC_Channel);
/*********************************************************************/
/*********************************************************************
 * Description :	Getting Asynchronized Reading	(using interrupt and End Of Job Notification Concept)
 * INPUTS : 		1- u8 Channel Number
 * 					2- Pointer To The Notification Function
 * 					3- Pointer To The Varible to hold The Reading
 * RETURN :			VOID
 *
 * NOTE :	To Use This Function The GIE (Global Interrupt Enable) Must be Enabled
 *********************************************************************/
void ADC_VoidGetAsyncReading(u8 ADC_Channel,void(*NotifyFunc)(void),u16*ADC_Read);
/*********************************************************************
 * Description :	Getting Asynchoronized Chain Readings
 * INPUTS : 		1- Pointer To structure Chain_t {
 * 														1- Size of Chain
 * 														2- Array of u16 To save results from readings
 * 														3- Array of u8 to save channels of the chain
 * 														4- pointer to notify function
 * 													}
 * RETURN :			VOID
 *
 * NOTE :	To Use This Function The GIE (Global Interrupt Enable) Must be Enabled
 *********************************************************************/
void ADC_VoidGetChainAsyncReading(Chain_t * Copy_Chain);


#endif /* MCAL_ADC_HEADER_ADC_INTERFACE_H_ */
