/*
 * TWI_Interface.h
 *
 *  Created on: Oct 29, 2022
 *      Author: mhmd wael
 */

#ifndef MCAL_TWI_HEADER_TWI_INTERFACE_H_
#define MCAL_TWI_HEADER_TWI_INTERFACE_H_

#include "../../../LIBRARY/stdtype.h"
#include "../../../LIBRARY/BitMath.h"
#include "TWI_Register.h"
#include "TWI_Private.h"
#include "TWI_Config.h"

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr
}TWI_ErrStatus;

/*pass 0 in the slave address argument if master will not be addressed (Taking orders) */
void TWI_VoidMasterInit(u8 Local_u8SlaveAddress);

void TWI_VoidSlaveInit(u8 Local_u8SlaveAddress);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Local_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Local_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Local_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Local_pu8DataByte);

void TWI_SendStopCondition(void);


#endif /* MCAL_TWI_HEADER_TWI_INTERFACE_H_ */
