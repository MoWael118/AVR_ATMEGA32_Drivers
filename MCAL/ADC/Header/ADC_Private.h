/*
 * ADC_Private.h
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */

#ifndef MCAL_ADC_HEADER_ADC_PRIVATE_H_
#define MCAL_ADC_HEADER_ADC_PRIVATE_H_

#define ADC_PRESCALER2			(0x01)
#define ADC_PRESCALER4			(0x02)
#define ADC_PRESCALER8          (0x03)
#define ADC_PRESCALER16         (0x05)
#define ADC_PRESCALER32         (0x05)
#define ADC_PRESCALER64         (0x06)
#define ADC_PRESCALER128        (0x07)

#define ADC_CHANNEL0			(0x00)
#define ADC_CHANNEL1			(0x01)
#define ADC_CHANNEL2			(0x02)
#define ADC_CHANNEL3			(0x03)
#define ADC_CHANNEL4			(0x04)
#define ADC_CHANNEL5			(0x05)
#define ADC_CHANNEL6			(0x06)
#define ADC_CHANNEL7			(0x07)

#define AREF					1
#define AVCC         			2
#define Internal_Volt			3

#define Prescaler_Mask 			0b11111000
#define Channel_Mask			0b11100000
#define Time_OUT				50000
#define IDLE					1
#define Busy					2
#define ChainAsync				1
#define SingleAsync				2

#endif /* MCAL_ADC_HEADER_ADC_PRIVATE_H_ */
