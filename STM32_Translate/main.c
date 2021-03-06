/************************************************************************************************************************************/
/** @file		main.c
 * 	@brief		x
 * 	@details	x
 *
 * 	@author		Justin Reina, Firmware Engineer, Company Name
 * 	@orig		Generated by Atollic TrueSTUDIO(R) 9.0.1   2018-10-23
 * 	@url		https://github.com/Jmr-Work/STM32_Translate.git
 * 	@created	10/23/18
 * 	@last rev	x
 *
 *
 * 	@section 	Tasks
 *		UART_MOD - UART module to perform uart communication tasks
 *		OTASK    - Support for unspecified future tasks
 *		SYS      - System operations and control
 *
 * 	@section	Opens
 * 			make operational
 * 			naming standardized
 *
 *	@note	This is reference code not intended for compilation or operation
 *
 * 	@section	Legal Disclaimer
 * 			Copyright (c) 2018 STMicroelectronics
 */
/************************************************************************************************************************************/
#include "main.h"

#define NUM_MESSAGES (3)													/* @note 	an array of rx-tx structs may be cleaner,	*/
																			/*			this soln is simple and clear				*/
//Messages
char *messages[NUM_MESSAGES] = {"Hello", "Goodbye", "Ok", "TBC"};

//Responses
char *responses[NUM_MESSAGES] = {"Bonjour", "Au revoir", "D'accord", "� confirmer"};

/************************************************************************************************************************************/
/**	@fcn		int main(void)
 *  @brief		program main routine
 *  @details	x
 *
 */
/************************************************************************************************************************************/
int main(void) {

	//Init
	sys_init();

	//Run
	sleep();																/* wait for usart rx operations							*/
}


/************************************************************************************************************************************/
/**	@fcn		void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle)
 *  @brief		called on completion of uart transmission
 *  @details	report end of IT Tx transfer response
 *
 *  @param 		[in] (UART_HandleTypeDef *) UartHandle - UART handle
 *  @return		none
 *
 */
/************************************************************************************************************************************/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle) {

	//Set transmission flag: transfer complete
	UartReady = SET;

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
 *  @brief		called on reception of uart receive bytes
 *  @details	report end of IT Tx transfer response
 *
 *  @param 		[in] (UART_HandleTypeDef *) UartHandle - UART handle
 *  @return		none
 *
 */
/************************************************************************************************************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle) {

	//Grab message

	//Lookup response (use of strcmp() to find match)

	//Return response (perform transmit operation)

	/* Set transmission flag: transfer complete*/
	UartReady = SET;

	return;
}

