/*
 * EXTI_Private.h
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */

#ifndef MCAL_EXTI_HEADER_EXTI_PRIVATE_H_
#define MCAL_EXTI_HEADER_EXTI_PRIVATE_H_

/*Options For Triggering Mode*/
#define EXTI_FallingEdge			0
#define EXTI_RisingEdge  			1
#define EXTI_OnChangeEdge			2
#define EXTI_LowLevel    			3
/*---------------------------------------------*/
#define EXTI0_PORT					PORT_D
#define EXTI0_PIN					PIN_D2
/*---------------------------------------------*/
#define EXTI1_PORT					PORT_D
#define EXTI1_PIN					PIN_D3
/*---------------------------------------------*/
#define EXTI2_PORT					PORT_B
#define EXTI2_PIN					PIN_B2
/*---------------------------------------------*/

#endif /* MCAL_EXTI_HEADER_EXTI_PRIVATE_H_ */
