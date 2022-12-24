/*
 * DIO_Register.h
 *
 *  Created on: Apr 22, 2022
 *      Author: MoWael
 */

#ifndef MCAL_DIO_HEADER_DIO_REGISTER_H_
#define MCAL_DIO_HEADER_DIO_REGISTER_H_

/*Group -A*/
#define DDRA_REG     (*(volatile u8*)0x3A)
#define PINA_REG     (*(volatile u8*)0x39)
#define PORTA_REG    (*(volatile u8*)0x3B)
/*Group -B*/
#define DDRB_REG     (*(volatile u8*)0x37)
#define PINB_REG     (*(volatile u8*)0x36)
#define PORTB_REG    (*(volatile u8*)0x38)
/*Group -C*/
#define DDRC_REG     (*(volatile u8*)0x34)
#define PINC_REG     (*(volatile u8*)0x33)
#define PORTC_REG    (*(volatile u8*)0x35)
/*Group -D*/
#define DDRD_REG     (*(volatile u8*)0x31)
#define PIND_REG     (*(volatile u8*)0x30)
#define PORTD_REG    (*(volatile u8*)0x32)

#endif /* MCAL_DIO_HEADER_DIO_REGISTER_H_  */
