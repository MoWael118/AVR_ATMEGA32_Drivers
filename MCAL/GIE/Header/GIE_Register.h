/*
 * GIE_Register.h
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */

#ifndef MCAL_GIE_HEADER_GIE_REGISTER_H_
#define MCAL_GIE_HEADER_GIE_REGISTER_H_

#define		SREG 	*((volatile u8 *)0x5f)
#define 	I		7	/*Global Interrupt Enable		      */
#define 	T		6	/*Bit Copy Storage				      */
#define 	H		5	/*Half Carry Flag				      */
#define 	S		4	/*Sign Flag						      */
#define 	V		3	/*Two's Complement OverFlow Flag      */
#define 	N		2	/*Negative Flag					      */
#define 	Z		1	/*Zero Flag						      */
#define 	C		0	/*Carry Flag					      */



#endif /* MCAL_GIE_HEADER_GIE_REGISTER_H_ */
