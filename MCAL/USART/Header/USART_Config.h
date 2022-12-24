/*
 * USART_Config.h
 *
 *  Created on: Oct 1, 2022
 *      Author: mhmd wael
 */

#ifndef MCAL_USART_HEADER_USART_CONFIG_H_
#define MCAL_USART_HEADER_USART_CONFIG_H_

#define DATA_SIZE 			EIGHT_BITS			/*Options :
 	 	 	 	 	 	 	 	 	 	 	 	 1-FIVE_BITS
 	 	 	 	 	 	 	 	 	 	 	 	 2-SIX_BITS
 	 	 	 	 	 	 	 	 	 	 	 	 3-SEVEN_BITS
 	 	 	 	 	 	 	 	 	 	 	 	 4-EIGHT_BITS
 	 	 	 	 	 	 	 	 	 	 	 	 */

#define PARITY_MODE         DISABLED			/*Options :
                                                 1-DISABLED
                                                 2-ODD_PARITY
                                                 3-EVEN_PARITY
                                                 */
#define STOP_BitsNumber 	1					/*Options :
												1- 1 BIT
												2- 2 BITS
												*/

#define BaudRate_Value		9600				/*Options :
                                                1-  2400 BIT/Second
                                                2-  4800 BIT/Second
                                                3-  9600 BIT/Second
                                                4-  14400 BIT/Second
                                                5-  19200 BIT/Second
                                                6-  28800 BIT/Second
                                                7-  38400 BIT/Second
                                                8-  57600 BIT/Second
                                                9-  76800 BIT/Second
                                                10- 115200 BIT/Second
                                                11- 230400 BIT/Second
                                                12- 250000 BIT/Second
                                                13- 500000 BIT/Second
                                                */
#endif /* MCAL_USART_HEADER_USART_CONFIG_H_ */
