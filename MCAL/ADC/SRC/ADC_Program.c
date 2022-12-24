/*
 * ADC_Program.c
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */
#include "../../../LIBRARY/BitMath.h"
#include "../../../LIBRARY/stdtype.h"

#include "../Header/ADC_Configuration.h"
#include "../Header/ADC_Register.h"
#include "../Header/ADC_Private.h"
#include "../Header/ADC_Interface.h"


static 	void(*ADC_pvCallBackNotifyFunc)(void)	= NULL	;
static	u16* ADC_pu16READ=NULL;
u8 ADC_State = IDLE;
static u16* ADC_ChainResultArr;
static u8	ADC_ChainSize;
static u8   ADC_ChannelIndex=0;
static u8*	ADC_ChannelsArr;
static u8 ADC_ISRSource=0;

void ADC_VoidInit(void)
{
	/*Setting Voltage reference*/
#if Voltage_Reference ==	AVCC
	SET_BIT(ADC_ADMUX,ADC_REFS0);
	CLR_BIT(ADC_ADMUX,ADC_REFS1);
#elif Voltage_Reference ==	AREF
	CLR_BIT(ADC_ADMUX,ADC_REFS0);
	CLR_BIT(ADC_ADMUX,ADC_REFS1);
#elif Voltage_Reference ==	Internal_Volt
	SET_BIT(ADC_ADMUX,ADC_REFS0);
	SET_BIT(ADC_ADMUX,ADC_REFS1);
#endif
	/*STEP 2) ADC LEFT ADJUST RESULT*/
	CLR_BIT(ADC_ADMUX,ADC_ADLAR);

	/*Step 3) ADC ENABLE*/
	SET_BIT(ADC_ADCSRA,ADC_ADEN);
	/*Step 4) ADC Prescaler Select*/
	/*To Avoid Prescaler ERROR (Bit Masking)*/
	ADC_ADCSRA 	&=	 Prescaler_Mask;
	ADC_ADCSRA 	|= 	 ADC_PRESCALER_MODE;
}
u16  ADC_u16GetSyncReading(u8 ADC_Channel)
{
	u32 Local_u32Counter=0;
	//Avoiding Error in Channel Number
	ADC_ADMUX &= Channel_Mask ;
	ADC_ADMUX |= ADC_Channel ;
	//START Conversion
	ADC_ADCSRA |= (1<<ADC_ADSC);
	//Wait Until Conversion Done
	while  (	(GET_BIT(ADC_ADCSRA,ADC_ADIF)	==	0)	&& (Local_u32Counter	 <	Time_OUT) )
	{
		Local_u32Counter++ ;
	}
	if (GET_BIT(ADC_ADCSRA,ADC_ADIF)	==	1)
	{
		//SET Flag again
		SET_BIT(ADC_ADCSRA,ADC_ADIF);
		//Store Data
		return ADC_DATA;
	}
	else
	{
		//Do Nothing
	}
	//Store Data
	return ADC_DATA;

}
/* With interrupt*/

void ADC_VoidGetAsyncReading(u8 ADC_Channel,void(*CopyNotifyFunc)(void),u16*CopyADC_Read)
{
	if(ADC_State == IDLE)
	{
		if (((CopyNotifyFunc)!= NULL)	&&	(CopyADC_Read!=NULL) )
		{
			/*Set ISR Source to Single Async*/
			ADC_ISRSource = SingleAsync;
			/*Set State to busy*/
			ADC_State = Busy;
			/*Set Global Pointer to point to the Notification Function*/
			ADC_pvCallBackNotifyFunc	= CopyNotifyFunc ;
			/*Initializing Reading variable globally*/
			ADC_pu16READ	= CopyADC_Read	;
			/*Avoiding Error in Channel Number*/
			ADC_ADMUX &= Channel_Mask ;
			ADC_ADMUX |= ADC_Channel ;
			/*START Conversion*/
			SET_BIT(ADC_ADCSRA,ADC_ADSC);
			/*Enable Interrupt*/
			SET_BIT(ADC_ADCSRA,ADC_ADIE);
		}
		else
		{
			//Do Nothing
		}
	}

}
void ADC_VoidGetChainAsyncReading(Chain_t * Copy_Chain)
{
	if (Copy_Chain != NULL)
	{
		/*Set ADC state to busy*/
		ADC_State	=	Busy	;
		/*Make ISR Source Chain Conversion*/
		ADC_ISRSource = ChainAsync;
		/*Initialize Size of Chain Globally*/
		ADC_ChainSize = Copy_Chain->Size;
		/*Initialize Result array Globally*/
		ADC_ChainResultArr = Copy_Chain->Result;
		/*Initialize Result array Globally*/
		ADC_ChannelsArr = Copy_Chain->Channel;
		/*Initialize Notification Function globally*/
		ADC_pvCallBackNotifyFunc = Copy_Chain->NotificationFunc;
		/*Initialize Current Conversion INDEX*/
		ADC_ChannelIndex=0;
		/*Start Conversion of first channel*/
		ADC_ADMUX &= Channel_Mask;
		ADC_ADMUX |= ADC_ChannelsArr[ADC_ChannelIndex];
		SET_BIT(ADC_ADCSRA,ADC_ADSC);
		/*Enable PIE*/
		SET_BIT(ADC_ADCSRA,ADC_ADIE);
	}
}

void __vector_16(void)	__attribute__((signal));
void __vector_16(void)
{
	if (ADC_ISRSource == SingleAsync)
	{
		/*	READ ADC	*/
		*ADC_pu16READ	= 	ADC_DATA	;
		/*Make ADC State IDLE*/
		ADC_State	= IDLE 	;
		/*	Call The Notify	Function*/
		ADC_pvCallBackNotifyFunc();
		/*Disable Interrupt*/
		CLR_BIT(ADC_ADCSRA,ADC_ADIE);
	}


	else if (ADC_ISRSource 	==	ChainAsync)
	{
		/*Store First Value of conversion*/
		ADC_ChainResultArr[ADC_ChannelIndex] = ADC_DATA;
		/* Increament Index*/
		ADC_ChannelIndex++;
		/*Check chain is finished or not*/
		if(ADC_ChannelIndex	== ADC_ChainSize)	/*Chain is finished*/
		{
			/*SET ADC state to IDLE */
			ADC_State=IDLE;
			/*Call Notification Function*/
			ADC_pvCallBackNotifyFunc();
			/*Disable PIE*/
			CLR_BIT(ADC_ADCSRA,ADC_ADIE);
		}
		else	/*Chain is not finished*/
		{
			/*Set New Channel*/
			ADC_ADMUX &= Channel_Mask;
			ADC_ADMUX |= ADC_ChannelsArr[ADC_ChannelIndex];
			/*Start Conversion*/
			SET_BIT(ADC_ADCSRA,ADC_ADSC);

		}
	}

}
