/*
 * ADC_Configuration.h
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */

#ifndef MCAL_ADC_HEADER_ADC_CONFIGURATION_H_
#define MCAL_ADC_HEADER_ADC_CONFIGURATION_H_

/******************	SET PRESCALER	*******************/
/****	Options
		 * 1- Divide by 2               ADC_PRESCALER2
		 * 2- Divide by 4               ADC_PRESCALER4
		 * 3- Divide by 8               ADC_PRESCALER8
		 * 4- Divide by 16              ADC_PRESCALER16
		 * 5- Divide by 32              ADC_PRESCALER32
		 * 6- Divide by 64              ADC_PRESCALER64
		 * 7- Divide by 128           	ADC_PRESCALER128  ****/

#define ADC_PRESCALER_MODE		ADC_PRESCALER8
/******************************************************************/
/******************	SELECT Voltage Reference	*******************/
/****	Options
		 * 1- Reference voltage from pin AREF       AREF
		 * 2- Vcc Voltage from pin AVCC				AVCC
		 * 3- Internal 2.56 Voltage                 Internal_Volt     ****/
#define Voltage_Reference		AVCC
/*******************************************************************/
#endif /* MCAL_ADC_HEADER_ADC_CONFIGURATION_H_ */
