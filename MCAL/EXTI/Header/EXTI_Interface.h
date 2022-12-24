/*
 * EXTI_Interface.h
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */

#ifndef MCAL_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_HEADER_EXTI_INTERFACE_H_

#include "EXTI_Private.h"
#include "EXTI_Configuration.h"


void EXTI0_VoidInit0(void);
void EXTI1_VoidInit1(void);
void EXTI2_VoidInit2(void);

void EXTI0_VoidSetCallBack(void (*Local_PVFunc)(void));
void EXTI1_VoidSetCallBack(void (*Local_PVFunc)(void));
void EXTI2_VoidSetCallBack(void (*Local_PVFunc)(void));



#endif /* MCAL_EXTI_HEADER_EXTI_INTERFACE_H_ */
