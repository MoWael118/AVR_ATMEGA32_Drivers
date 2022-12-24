
#include "../../../LIBRARY/stdtype.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../MCAL/TIMER/Header/Timer_Interface.h"
#include "../HEADER/SERVO_Interface.h"

void Servo_VoidInit(void)
{
	/*Notes To use this function :
	 * 1- Timer1 Compare output mode must be set in non inverted pwm channel A or B According to Servo pin
	 * 2- Timer1 Prescaler Must be Divided by 8
	 **********************************************/
	DIO_VoidSetPinDir(PORT_D,Servo_Pin,DIO_OUTPUT);
	TIMER1_VoidInit(TIMER1_FastPWMOnICR1Mode);
	TIMER1_VoidSetICRValue(Servo_PeriodTime);

}

void Servo_VoidRotateAngle(u8 Local_u8Angle)
{
	u16 Local_u16OCRValue=0;
	Local_u16OCRValue	=	((5.55555*Local_u8Angle)+1000)	;
#if Servo_Pin	==	PIN_D5
	TIMER_VoidSetCompareMatchValue(TIMER1A,Local_u16OCRValue);
#elif	Servo_Pin	==	PIN_D4
	TIMER_VoidSetCompareMatchValue(TIMER1B,Local_u16OCRValue);
#endif
}

