/*
 * TWI_Register.h
 *
 *  Created on: Oct 29, 2022
 *      Author: mhmd wael
 */

#ifndef MCAL_TWI_HEADER_TWI_REGISTER_H_
#define MCAL_TWI_HEADER_TWI_REGISTER_H_

#define TWCR			*((volatile u8*)0x56)		/*TWI CONTROL REG*/
#define TWCR_TWINT		7                           /*INTERRUPT FLAG*/
#define TWCR_TWEA		6                           /*ENABLE ACK*/
#define TWCR_TWSTA		5                           /*START CONDITION*/
#define TWCR_TWSTO		4                           /*STOP CONDITION*/
#define TWCR_TWWC		3                           /*WRITE COLLISION*/
#define TWCR_TWEN		2                           /*ENABLE TWI*/
#define TWCR_TWIE		0                           /*INTERRUPT ENABLE*/

#define TWDR 			*((volatile u8*)0x23)       /*TWI DATA REG*/

#define TWAR			*((volatile u8*)0x22)       /*TWI ADDRESS REG*/
#define TWAR_TWGCE		0                           /*GENERAL CALL ENABLE*/

#define TWSR			*((volatile u8*)0x21)       /*TWI STATUS REG*/
#define TWSR_TWPS0		0                           /*PRESCALLER BIT 0*/
#define TWSR_TWPS1		1                           /*PRESCALLER BIT 1*/

#define TWBR 			*((volatile u8*)0x20)       /*TWI BIT RATE REG*/

#endif /* MCAL_TWI_HEADER_TWI_REGISTER_H_ */
