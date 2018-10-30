/************************************************************************************************************************************/
/** @file		uart.h
 * 	@brief		x
 * 	@details	x
 *
 * 	@author		Justin Reina, Firmware Engineer, Company Name
 * 	@created	Oct 23, 2018
 * 	@last rev	x
 *
 *
 * 	@notes		x
 *
 * 	@section	Opens
 * 			none current
 *
 * 	@section	Legal Disclaimer
 * 			© Year Company Name, All rights reserved. All contents of this source file and/or any other related source
 *			files are the explicit property of Company Name. Do not distribute. Do not copy.
 */
/************************************************************************************************************************************/
#ifndef UART_H_
#define UART_H_

//Lib

//Project

//Definitions
#define 	TXBUFFERSIZE 	(100)
#define 	RXBUFFERSIZE 	(100)

//Typedefs

//Globals
extern void uart_init(void);

//Locals

//Private
static void _Error_Handler(char *file, int line);

#endif /* UART_H_ */

