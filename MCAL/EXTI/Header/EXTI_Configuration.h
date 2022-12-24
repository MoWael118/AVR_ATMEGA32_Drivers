/*
 * EXTI_Configuration.h
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */

#ifndef MCAL_EXTI_HEADER_EXTI_CONFIGURATION_H_
#define MCAL_EXTI_HEADER_EXTI_CONFIGURATION_H_

/*Select Trigger Mode*/
/*Options For trigger mode*/
/*
 * 1) EXTI_FallingEdge
 * 2) EXTI_RisingEdge
 * 3) EXTI_OnChangeEdge
 * 4) EXTI_LowLevel
 */
#define EXTI0_TriggerMode                        EXTI_RisingEdge
/*----------------------------------------*/
/*Select Trigger Mode*/
/*Options For trigger mode*/
/*
 * 1) EXTI_FallingEdge
 * 2) EXTI_RisingEdge
 * 3) EXTI_OnChangeEdge
 * 4) EXTI_LowLevel
 */
#define EXTI1_TriggerMode                         EXTI_FallingEdge
/*-----------------------------------------------*/
/*Select Trigger Mode*/
/*Options For trigger mode*/
/*
 * 1) EXTI_FallingEdge
 * 2) EXTI_RisingEdge
 */
#define EXTI2_TriggerMode                          EXTI_RisingEdge




#endif /* MCAL_EXTI_HEADER_EXTI_CONFIGURATION_H_ */
