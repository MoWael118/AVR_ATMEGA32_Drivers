/*
 * USART_Program.c
 *
 *  Created on: Oct 1, 2022
 *      Author: mhmd wael
 */

#include "../../../LIBRARY/stdtype.h"
#include "../../../LIBRARY/BitMath.h"
#include "../Header/USART_Interface.h"

u8 * pu8_Recevied_Data = NULL;
void (*PFCallBackNotifyFunc)(void)=NULL;
u8 Sent_Data	=0;
void USART_VoidInit(void)
{
	u8 Local_u8UCRSCValue	=0;
	/*Set URSEL bit To Access UCSRC*/
	SET_BIT(Local_u8UCRSCValue,UCSRC_URSEL);
	/*Clear UMSEL To select Asynchronous mode*/
	CLR_BIT(Local_u8UCRSCValue,UCSRC_UMSEL);

	/*Check Parity Mode*/
	#if PARITY_MODE == DISABLED
	CLR_BIT(Local_u8UCRSCValue,UCSRC_UPM0);//Clear Parity bit 0
	CLR_BIT(Local_u8UCRSCValue,UCSRC_UPM1);//Clear Parity bit 1
	#elif PARITY_MODE	== EVEN_PARITY
	CLR_BIT(Local_u8UCRSCValue,UCSRC_UPM0);//Clear Parity bit 0
	SET_BIT(Local_u8UCRSCValue,UCSRC_UPM1);//SET Parity bit 1
	#elif PARITY_MODE	== ODD_PARITY
	SET_BIT(Local_u8UCRSCValue,UCSRC_UPM0);//SET Parity bit 0
	SET_BIT(Local_u8UCRSCValue,UCSRC_UPM1);//SET Parity bit 1
	#endif

	/*Check Stop Bits Number*/
	#if STOP_BitsNumber 	==	1
	CLR_BIT(Local_u8UCRSCValue,UCSRC_USBS);
	#elif STOP_BitsNumber ==  2
	SET_BIT(Local_u8UCRSCValue,UCSRC_USBS);
	#endif

	/*Check DATA Size*/
	#if DATA_SIZE	==	FIVE_BITS
	CLR_BIT(Local_u8UCRSCValue,UCSRC_UCSZ0);
    CLR_BIT(Local_u8UCRSCValue,UCSRC_UCSZ1);
	#elif DATA_SIZE	==	SIX_BITS
    SET_BIT(Local_u8UCRSCValue,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCRSCValue,UCSRC_UCSZ1);
    #elif DATA_SIZE	==	SEVEN_BITS
    CLR_BIT(Local_u8UCRSCValue,UCSRC_UCSZ0);
    SET_BIT(Local_u8UCRSCValue,UCSRC_UCSZ1);
	#elif DATA_SIZE	==	EIGHT_BITS
    SET_BIT(Local_u8UCRSCValue,UCSRC_UCSZ0);
    SET_BIT(Local_u8UCRSCValue,UCSRC_UCSZ1);
    #endif
    /*Assign All These states to the UCSRC Register*/
    USART_UCSRC	=	Local_u8UCRSCValue	;
    /*SELECT BAUD RATE*/
	#if BaudRate_Value == 2400
    USART_UBRRL	=207 ;
    #elif BaudRate_Value	== 4800
    USART_UBRRL	=103 ;
	#elif BaudRate_Value	== 9600
    USART_UBRRL	=51 ;

	#elif BaudRate_Value	== 14400
    USART_UBRRL	=34 ;

	#elif BaudRate_Value	== 19200
    USART_UBRRL	=25 ;

    #elif BaudRate_Value	== 28800
    USART_UBRRL	=16 ;

    #elif BaudRate_Value	== 38400
    USART_UBRRL	=12 ;

    #elif BaudRate_Value	== 57600
    USART_UBRRL	=8 ;

    #elif BaudRate_Value	== 76800
    USART_UBRRL	=6 ;

    #elif BaudRate_Value	== 115200
    USART_UBRRL	=3 ;

    #elif BaudRate_Value	== 230400
    USART_UBRRL	=1 ;

    #elif BaudRate_Value	== 250000
    USART_UBRRL	=1 ;

    #elif BaudRate_Value	== 500000
    USART_UBRRL	=0 ;
    #endif

    /*Enable TX*/
	SET_BIT(USART_UCSRB,UCSRB_TXEN);
	/*Enable RX*/
	SET_BIT(USART_UCSRB,UCSRB_RXEN);
}

u8 USART_u8ReceiveDataSync(void)
{
	u32 Local_u32TimeCounter=0;
	/*Wait until Receive done*/
	while (	(GET_BIT(USART_UCSRA,UCSRA_RXC)==0)	&& (Local_u32TimeCounter<Time_Out))
	{
		Local_u32TimeCounter++;
	}
	if (GET_BIT(USART_UCSRA,UCSRA_RXC)==1)
	{
		/*Return Received data*/
		return USART_UDR;
	}
	else if (Local_u32TimeCounter == Time_Out)
	{
		//Do Nothing
	}
	return USART_UDR;
}

void USART_VoidSendDataSync(u8 Local_u8Data)
{
	u32 Local_u32TimeCounter=0;
	/*Wait until transmit buffer is empty*/
	while (	(GET_BIT(USART_UCSRA,UCSRA_UDRE)==0)	&& (Local_u32TimeCounter<Time_Out)	)
	{
		Local_u32TimeCounter++;
	}
	if(GET_BIT(USART_UCSRA,UCSRA_UDRE)==1)
	{
	/*Send data*/
	USART_UDR = Local_u8Data;
	}
	else if (Local_u32TimeCounter == Time_Out)
	{
		//Do Nothing
	}
}
void USART_VoidReceiveDataAsync(u8*Data_Variable ,void(*NotifyFunc)(void))
{
	if (	(Data_Variable!=NULL)	&&		(NotifyFunc!=NULL)	)
	{
	/*Set variables Globally to be used in ISR*/
	pu8_Recevied_Data	=	Data_Variable	;
	PFCallBackNotifyFunc	=	NotifyFunc	;
	/*Enable PIE*/
	SET_BIT(USART_UCSRB,UCSRB_RXCIE);
	}
}

void USART_VoidSendDataAsync(u8 Copy_u8Data ,void(*NotifyFunc)(void))
{
	if(	NotifyFunc != NULL	)
	{
		/*Set variables Globally to be used in ISR*/
		PFCallBackNotifyFunc	=	NotifyFunc	;
		Sent_Data	= Copy_u8Data;
		/*Enable Interrupt */
		SET_BIT(USART_UCSRB,UCSRB_UDRIE);
	}
}


void __vector_13(void) 	__attribute__((signal));
void __vector_13(void)
{
	/*Store Data*/
	*pu8_Recevied_Data	=	USART_UDR	;
	/*Call Notify Function*/
	PFCallBackNotifyFunc();
	/*Disable PIE*/
	CLR_BIT(USART_UCSRB,UCSRB_RXCIE);

}
void __vector_14(void) 	__attribute__((signal));
void __vector_14(void)
{
	/*Send Data*/
	USART_UDR	= Sent_Data	;
	/*Call Notify Function*/
	PFCallBackNotifyFunc();
	/*Disable PIE*/
	CLR_BIT(USART_UCSRB,UCSRB_UDRIE);

}


