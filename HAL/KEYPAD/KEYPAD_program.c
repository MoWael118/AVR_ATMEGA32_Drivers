#include "../../LIBRARY/stdtype.h"
#include "../../LIBRARY/BitMath.h"

#include "../../MCAL/DIO/Header/DIO_Interface.h"

#include "KEYPAD_Configuration.h"

#include "KEYPAD_Interface.h"

#include "KEYPAD_Private.h"

u8 Local_u8KPDRowArr[4]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
u8 Local_u8KPDColumnArr[4]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};

void KPD_VoidInit(void)
{

	u8 Local_Counter=0;
	/*SET Rows Pins to input And activate PULLUP*/
	for( Local_Counter=0;Local_Counter<Row_Num;Local_Counter++)
	{
		DIO_VoidSetPinDir(KPD_PORT,Local_u8KPDRowArr[Local_Counter],DIO_INPUT);
		DIO_VoidSetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_Counter],DIO_HIGH);
	}
	/* Set COLUMN PINS AS OUTPUT HIGH */
	for( Local_Counter=0;Local_Counter<Column_Num;Local_Counter++)
	{
		DIO_VoidSetPinDir(KPD_PORT,Local_u8KPDColumnArr[Local_Counter],DIO_OUTPUT);
		DIO_VoidSetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_Counter],DIO_HIGH);
	}

}

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey= KPD_NO_PRESSED_KEY,Local_u8ColumnIndex,Local_u8RowIndex;
	static u8 Local_KPDArr[Row_Num][Column_Num]=KPD_ARR;
	for (Local_u8ColumnIndex=0;Local_u8ColumnIndex<Column_Num;Local_u8ColumnIndex++)
	{
		/*Activate Current Column*/
		DIO_VoidSetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIndex],DIO_LOW);
		for (Local_u8RowIndex=0;Local_u8RowIndex<Row_Num;Local_u8RowIndex++)
		{
			/*Read Current ROW*/
			u8 Local_u8PIN_State = DIO_u8GetValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex]);
			/*Check PIN STATE if pressed or not*/
			if (Local_u8PIN_State==DIO_LOW)
			{
				Local_u8PressedKey = Local_KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
				/*Polling (Busy waiting) until the key is released*/
				while (Local_u8PIN_State==DIO_LOW)
				{
					DIO_VoidSetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIndex],DIO_LOW);
				}
				return Local_u8PressedKey;
			}
		}
		/*Deactivate The Current Column*/
		DIO_VoidSetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIndex],DIO_HIGH);
	}




	return Local_u8PressedKey;
}

