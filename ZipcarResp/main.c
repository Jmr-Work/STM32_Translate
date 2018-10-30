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
 * 		Reduce to 80 chars wide
 * 		...
 * 		Implement Example Dev Stubs
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

//STM32
#include "stm32l0xx_hal_uart.h"

//Project
#include "lut.h"

//Definitions
#define RX_BUF_SIZE		(100)
#define TX_BUF_SIZE		(100)

//Local Functions
void sys_init(void);														/* System boot initialisation							*/
void ISR_UART_RX(void);														/* Uart Rx ISR handle									*/
void tx_msg(void);															/* Uart Tx routine										*/

//Local Variables
UART_HandleTypeDef uart_cfg;												/* UART handle for HAL api								*/
char tx_buffer[TX_BUF_SIZE];												/* transmit buffer										*/
int  tx_buffer_end;															/* string length in buffer								*/


//<Example Dev Stubs>
void HAL_Init(void) { }														/* Stm32 api											*/
void HAL_Resume(void) { }													/* Stm32 example api									*/
void sleep(void) { }														/* Proc to sleep										*/
void __HAL_RCC_GPIOA_CLK_ENABLE(void) { }									/* Stm32 recommended boot config for gpio				*/
void HAL_UART_RxIsr(void *rx_isr) { }										/* Stm32 routine to set the uart receive isr			*/
void sys_check(void) { }													/* Check the system for valid configuration state		*/
void int_enable(void) { }													/* Enable interrupts									*/




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
	for(;;) {
		sleep();															/* wait & respond to uart msg							*/
		tx_msg();															/* perform tx response									*/
	}

	return EXIT_FAILURE;													/* should never reach, reset & restart					*/
}


/************************************************************************************************************************************/
/**	@fcn		void sys_init(void)
 *  @brief		initialize mcu & peripherals
 *  @details	a brief review and examination of reference indicated the following content in multiple locations
 *
 *  @pre		any
 *  @post		system ready for operation
 *
 *  @return 	on success
 */
/************************************************************************************************************************************/
void sys_init(void) {

	//Init Locals
	uart_cfg.Instance = USART2;												/* UART configuration									*/
	uart_cfg.Init.BaudRate = 115200;
	uart_cfg.Init.WordLength = UART_WORDLENGTH_8B;
	uart_cfg.Init.StopBits = UART_STOPBITS_1;
	uart_cfg.Init.Parity = UART_PARITY_NONE;
	uart_cfg.Init.Mode = UART_MODE_TX_RX;
	uart_cfg.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_cfg.Init.OverSampling = UART_OVERSAMPLING_16;
	uart_cfg.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	uart_cfg.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

	//Init Core
	HAL_Init();

	//Init GPIO
	__HAL_RCC_GPIOA_CLK_ENABLE();											/* GPIO Ports Clock Enable 								*/

	//Init Clocks
	//<Clocks - HAL_RCC_OscConfig(), HAL_RCC_ClockConfig(), HAL_RCCEx_PeriphCLKConfig()>
	//<Systick - HAL_SYSTICK_Config(), HAL_SYSTICK_CLKSourceConfig(), HAL_NVIC_SetPriority()>

	//Init UART
	HAL_UART_Init(&uart_cfg);												/* @note 	DRM not recommended, STM HAL used here		*/
	HAL_UART_RxIsr(&ISR_UART_RX);											/* Assign Receive ISR									*/

	//Post
	sys_check();
	int_enable();

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void ISR_UART_RX(void)
 *  @brief		receive interrupt handler for uart
 *  @details	x
 *
 *  @assum		no rx overflow
 */
/************************************************************************************************************************************/
void ISR_UART_RX(void) {

	//Locals
	char rx_buffer[RX_BUF_SIZE];
	int  rx_count;

	//Init
	rx_count = 0;

	//Grab Rx Message
	while(uart_cfg.RxXferCount> 0) {
		rx_buffer[rx_count++] = USART2->RDR;								/* grab receive data register							*/
		uart_timeout_wait();												/* wait specified duration for next rx byte				*/
	}
	rx_buffer[rx_count] = '\0';												/* place EOS for response parse							*/

	//Lookup Response
	char *resp = translate_msg(rx_buffer);

	//Load Response
	tx_buffer_end = sizeof(resp);											/* capture message size									*/
	memcpy(tx_buffer, resp, tx_buffer_end);									/* load value											*/

	//Send Response
	HAL_Resume();															/* resume main thread									*/

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void ISR_UART_RX(void)
 *  @brief		receive interrupt handler for uart
 *  @details	x
 *
 *  @assum		no rx overflow, called by completion of valid rx message
 *
 *	@pre		tx_buffer loaded
 *
 *  @section 	Opens
 *  	Code
 */
/************************************************************************************************************************************/
void tx_msg(void) {

	//Load
//	load tx_buffer
//	send over uart

	return;
}


/************************************************************ End of File ***********************************************************/
