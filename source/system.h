/************************************************************************************************************************************/
/** @file		system.h
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
 * 			© 2018 Company Name, All rights reserved. All contents of this source file and/or any other related source
 *			files are the explicit property of Company Name. Do not distribute. Do not copy.
 */
/************************************************************************************************************************************/
#ifndef SYSTEM_H_
#define SYSTEM_H_

//Lib

//Project
#include "uart.h"

//Definitions

//Typedefs

//Globals
extern void sys_init(void);

//Locals
void system_init (void);
void system_clockConfig(void);
void gpio_init(void);
void _Error_Handler(char *file, int line);

#endif /* SYSTEM_H_ */

