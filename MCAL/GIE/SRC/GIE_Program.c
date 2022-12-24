/*
 * GIE_Program.c
 *
 *  Created on: May 6, 2022
 *      Author: MoWael
 */
#include "../../../LIBRARY/BitMath.h"
#include "../../../LIBRARY/stdtype.h"
#include "../Header/GIE_Register.h"
#include "../Header/GIE_Interface.h"


void GIE_VoidEnable(void)
{
	SET_BIT(SREG,I);
}


void GIE_VoidDisable(void)
{
	CLR_BIT(SREG,I);
}

