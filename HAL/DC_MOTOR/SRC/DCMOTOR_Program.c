/*
 * DCMOTOR_Program.c
 *
 *  Created on: Apr 30, 2022
 *      Author: MoWael
 */

#include "../Header/DCMOTOR_Configuration.h"
#include "../Header/DCMOTOR_Interface.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../MCAL/DIO/Header/DIO_Private.h"
#include "../../../LIBRARY/BitMath.h"
#include "../../../MCAL/DIO/Header/DIO_Register.h"


void DCMOTOR_VoidInit(void)
{
	DIO_VoidSetPortDir(DC_MOTOR_PORT,DC_MOTOR_OUTPUT);
}
void DCMotor_VoidDirCW(void)
{
	DIO_VoidSetPinValue(DC_MOTOR_PORT,CW_Switches_Pin,DIO_HIGH);
	DIO_VoidSetPinValue(DC_MOTOR_PORT,CCW_Switches_Pin,DIO_LOW);
}
void DCMotorDir_VoidDirCCW(void)
{
	DIO_VoidSetPinValue(DC_MOTOR_PORT,CW_Switches_Pin,DIO_LOW);
	DIO_VoidSetPinValue(DC_MOTOR_PORT,CCW_Switches_Pin,DIO_HIGH);
}

