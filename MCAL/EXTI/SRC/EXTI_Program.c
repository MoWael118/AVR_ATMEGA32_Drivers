/*
 * EXTI_Program.c
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */
#include "../Header/EXTI_Configuration.h"
#include "../Header/EXTI_Private.h"
#include "../Header/EXTI_Interface.h"
#include "../Header/EXTI_Register.h"

#include "../../DIO/Header/DIO_Interface.h"


#include "../../../LIBRARY/BitMath.h"
#include "../../../LIBRARY/stdtype.h"


/*Global Pointer To Hold address of ISR INT0 function*/
void (*EXTI0_pvFunc)(void) = NULL ;
/*Global Pointer To Hold address of ISR INT1 function*/
void (*EXTI1_pvFunc)(void) = NULL ;
/*Global Pointer To Hold address of ISR INT2 function*/
void (*EXTI2_pvFunc)(void) = NULL ;
/********************************************************************/

/********************************************************************
 *******************     FUNCTIONS    *******************************
 *******************************************************************/


/*********************************************************************
 * Description :	INITIALIZATION FOR EXTI0
 * INPUTS : 		VOID
 * RETURN :			VOID
 *********************************************************************/
void EXTI0_VoidInit0(void)
{
	/*Step 1 : Select PinDir As INPUT*/
	DIO_VoidSetPinDir(EXTI0_PORT,EXTI0_PIN,DIO_INPUT);
	/* Step 2 : Set PULLUP because input will be Sensor or Button*/
	DIO_VoidSetPinValue(EXTI0_PORT,EXTI0_PIN,DIO_HIGH);
	/*Step 3 : Enable PIE (EXTI_INT0)*/
	SET_BIT(EXTI_GICR,EXTI_INT0);

	/*Check Trigger Mode By #if*/
#if EXTI0_TriggerMode == EXTI_LowLevel
	CLR_BIT(EXTI_MCUCR,EXTI_ISC00);
	CLR_BIT(EXTI_MCUCR,EXTI_ISC01);
#elif EXTI0_TriggerMode == EXTI_OnChangeEdge
	SET_BIT(EXTI_MCUCR,EXTI_ISC00);
	CLR_BIT(EXTI_MCUCR,EXTI_ISC01);
#elif EXTI0_TriggerMode == EXTI_FallingEdge
	CLR_BIT(EXTI_MCUCR,EXTI_ISC00);
	SET_BIT(EXTI_MCUCR,EXTI_ISC01);
#elif EXTI0_TriggerMode == EXTI_RisingEdge
	SET_BIT(EXTI_MCUCR,EXTI_ISC00);
	SET_BIT(EXTI_MCUCR,EXTI_ISC01);
#endif
}
/*********************************************************************
 * Description :	INITIALIZATION FOR EXTI1
 * INPUTS : 		VOID
 * RETURN :			VOID
 *********************************************************************/
void EXTI1_VoidInit1(void)
{
	/*SET INT 1 PIN AS INPUT*/
	DIO_VoidSetPinDir(EXTI1_PORT,EXTI1_PIN,DIO_INPUT);
	/*SET Internal PULLUP*/
	DIO_VoidSetPinValue(EXTI1_PORT,EXTI1_PIN,DIO_HIGH);
	/*Enable EXTI 1*/
	SET_BIT(EXTI_GICR,EXTI_INT1);
	/*Check Triggering MODE*/
#if EXTI1_TriggerMode == EXTI_FallingEdge
	SET_BIT(EXTI_MCUCR,EXTI_ISC11);
	CLR_BIT(EXTI_MCUCR,EXTI_ISC10);
#elif EXTI1_TriggerMode == EXTI_RisingEdge
	SET_BIT(EXTI_MCUCR,EXTI_ISC11);
	SET_BIT(EXTI_MCUCR,EXTI_ISC10);
#elif EXTI1_TriggerMode == 	EXTI_OnChangeEdge
	CLR_BIT(EXTI_MCUCR,EXTI_ISC11);
	SET_BIT(EXTI_MCUCR,EXTI_ISC10);
#elif EXTI1_TriggerMode == 	EXTI_LowLevel
	CLR_BIT(EXTI_MCUCR,EXTI_ISC11);
	CLR_BIT(EXTI_MCUCR,EXTI_ISC10);
#endif


}
/*********************************************************************
 * Description :	INITIALIZATION FOR EXTI2
 * INPUTS : 		VOID
 * RETURN :			VOID
 *********************************************************************/
void EXTI2_VoidInit2(void)
{
	DIO_VoidSetPinDir(EXTI2_PORT,EXTI2_PIN,DIO_INPUT);
	DIO_VoidSetPinValue(EXTI2_PORT,EXTI2_PIN,DIO_HIGH);
	SET_BIT(EXTI_GICR,EXTI_INT2);
#if EXTI2_TriggerMode == EXTI_FallingEdge
	CLR_BIT(EXTI_MCUCSR,EXTI_ISC2);
#elif EXTI2_TriggerMode == EXTI_RisingEdge
	SET_BIT(EXTI_MCUCSR,EXTI_ISC2);
#endif
}
/*********************************************************************
 * Description :	CALL BACK FUNCTION FOR EXTI0
 * INPUTS : 		POINTER TO FUNCTION (FUNCTION NAME IN MAIN)
 * RETURN :			VOID
 *********************************************************************/
void EXTI0_VoidSetCallBack(void (*Local_PVFunc)(void))
{
	if (Local_PVFunc != NULL)
	{
		EXTI0_pvFunc =Local_PVFunc ;
	}
}
/*********************************************************************
 * Description :	ISR FUNCTION FOR EXTI0
 * INPUTS : 		VOID
 * RETURN :			VOID
 *********************************************************************/

void __vector_1(void) __attribute__((signal));
void __vector_1(void)

{
	EXTI0_pvFunc();
}

/*
 * Description :	CALL BACK FUNCTION FOR EXTI1
 * INPUTS : 		POINTER TO FUNCTION (FUNCTION NAME IN MAIN)
 * RETURN :			VOID
 *
 * */
void EXTI1_VoidSetCallBack(void (*Local_PVFunc)(void))
{
	if(Local_PVFunc != NULL)
	{
		EXTI1_pvFunc = Local_PVFunc;
	}
}
/*********************************************************************
 * Description :	ISR FUNCTION FOR EXTI1
 * INPUTS : 		VOID
 * RETURN :			VOID
 *********************************************************************/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	EXTI1_pvFunc();
}

/*********************************************************************
 * Description :	CALL BACK FUNCTION FOR EXTI2
 * INPUTS : 		POINTER TO FUNCTION (FUNCTION NAME IN MAIN)
 * RETURN :			VOID
 *********************************************************************/

void EXTI2_VoidSetCallBack(void (*Local_PVFunc)(void))
{
	if(Local_PVFunc != NULL)
	{
		EXTI2_pvFunc = Local_PVFunc;
	}
}
/*********************************************************************
 * Description :	ISR FUNCTION FOR EXTI2
 * INPUTS : 		VOID
 * RETURN :			VOID
 *********************************************************************/
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	EXTI2_pvFunc();
}

