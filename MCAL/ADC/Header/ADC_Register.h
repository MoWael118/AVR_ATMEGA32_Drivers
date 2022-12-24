/*
 * ADC_Register.h
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */

#ifndef MCAL_ADC_HEADER_ADC_REGISTER_H_
#define MCAL_ADC_HEADER_ADC_REGISTER_H_

#define ADC_ADMUX 		    ( *(volatile u8*)0x27) 	//ADC Multiplexer Selection Register
#define ADC_ADCSRA 		    ( *(volatile u8*)0x26)	//ADC Control and status Register
#define ADC_ADCH 		    ( *(volatile u8*)0x25)	//ADC DATA Register HIGH
#define ADC_ADCL 		    ( *(volatile u8*)0x24)	//ADC DATA Register LOW
#define ADC_DATA 			( *(volatile u16*)0x24)	//ADC DATA Register
/*-----------------ADMUX PINS------------------------*/
#define ADC_MUX0			0	//ADC Multiplexer selection bit 0
#define ADC_MUX1			1   //ADC Multiplexer selection bit 1
#define ADC_MUX2			2   //ADC Multiplexer selection bit 2
#define ADC_MUX3			3   //ADC Multiplexer selection bit 3
#define ADC_MUX4			4   //ADC Multiplexer selection bit 4
#define ADC_ADLAR			5	//ADC Left Adjust result bit
#define ADC_REFS0			6	//ADC voltage reference select bit 0
#define ADC_REFS1			7	//ADC voltage reference select bit 1
/*-----------------ADCSRA PINS------------------------*/
#define ADC_ADPS0			0   //ADC PRESCALER bit 0
#define ADC_ADPS1			1   //ADC PRESCALER bit 1
#define ADC_ADPS2			2   //ADC PRESCALER bit 2
#define ADC_ADIE			3	//ADC Interrupt enable (PIE)
#define ADC_ADIF			4	//ADC Interrupt Flag
#define ADC_ADATE			5	//ADC Auto trigger enable
#define ADC_ADSC			6	//ADC start conversion bit
#define ADC_ADEN			7	//ADC Enable bit



#endif /* MCAL_ADC_HEADER_ADC_REGISTER_H_ */
