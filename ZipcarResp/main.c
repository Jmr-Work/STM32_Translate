/************************************************************************************************************************************/
/** @file		main.c
 * 	@brief		Zipcar coding task response
 * 	@details	x
 *
 * 	@author		Justin Reina, Firmware Engineer
 * 	@created	10/30/18
 * 	@last rev	10/30/18
 *
 *	@env		Eclipse CDT (v4.80), MinGW (v6.3.0)
 *
 * 	@section 	Keys
 * 		From scratch
 *		Translates words sent over UART (STM32L011)
 *		Power consumption is important
 *		Able to run alongside other modules
 *		All assumptions valid
 *
 * 	@section	Opens
 * 		Init
 * 		ISR
 * 		Translate
 * 		Tx
 * 		...
 * 		Reduce to 80 chars wide
 * 		...
 * 		Deployment
 * 		Compilation
 *
 * 	@section	Legal Disclaimer
 * 		Justin Reina 2018, All rights reserved. All contents of this source file and/or any other related source
 *		files are the explicit property of Justin Reina. Do not distribute. Do not copy.
 */
/************************************************************************************************************************************/

//Library
#include <stdlib.h>

//Local Functions
void sys_init(void);

//<Dev Stubs>
void HAL_Init(void) { }
void sleep(void) { }


/************************************************************************************************************************************/
/**	@fcn		int main(void)
 *  @brief		x
 *  @details	x
 *
 *  @section 	Tasks
 *  	System Init		(sys_init)
 *		UART Rx			()
 *		UART Tx 		()
 *
 *	@section 	Considerations
 *		Low power
 *		Non-blocking
 *
 *	@section 	Assumptions (@assum?)
 *		x
 */
/************************************************************************************************************************************/
int main(void) {

	//Init
	sys_init();																/* initialize sys & uart for use						*/

	//Run
	sleep();																/* wait & respond to uart msg							*/

	return EXIT_FAILURE;													/* should never reach, reset & restart					*/
}

/************************************************************************************************************************************/
/**	@fcn		void sys_init(void)
 *  @brief		initialize mcu & peripherals
 *  @details	x
 *
 *  @pre		any
 *  @post		system ready for operation
 *
 *  @return 	on success
 */
/************************************************************************************************************************************/
void sys_init(void) {

	//(Pre) System Check

	//HAL
	HAL_Init();

	//Init Core

	//Init GPIO
		//Set all to inputs

	//Stabilize

	//Init Clocks

	//Init Periphs
		//Init UART
		//Assign Receive ISR

	//(Post) System Check

	return;
}


//@todo
void isr_resp(void) {

}


/************************************************************ End of File ***********************************************************/
