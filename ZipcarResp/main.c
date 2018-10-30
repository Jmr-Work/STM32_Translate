/******************************************************************************/
/** @file		main.c
 * 	@brief		Zipcar coding task response
 * 	@env		Eclipse CDT (v4.80), MinGW (v6.3.0)
 * 	@repo		https://github.com/Jmr-Work/STM32_Translate
 *
 * 	@author		Justin Reina, Firmware Engineer
 * 	@created	10/30/18
 * 	@last rev	10/30/18
 *
 * 	@section 	Keys
 * 		From scratch
 *		Translates words sent over UART (STM32L011)
 *		Power consumption is important
 *		Able to run alongside other modules
 *		All assumptions valid
 *
 * 	@section	Opens
 * 		Implement Example Dev Stubs
 * 		Deployment
 * 		Compilation
 *
 * 	@section	Legal Disclaimer
 * 		Justin Reina 2018, All rights reserved.
 */
/******************************************************************************/

//Library
#include <stdlib.h>
#include <string.h>

//STM32
#include "stm32l0xx_hal_uart.h"


//Definitions
#define 	RX_BUF_SIZE		(100)
#define 	TX_BUF_SIZE	 	(100)
#define 	MAX_STR_SIZE 	(100)				/* Max string length supported*/
#define 	LUT_SIZE     	(100)				/* Max count of LUT values	  */

//Typedefs
typedef struct lut_value {						/* lookup rx->tx responses	  */
	char rx[MAX_STR_SIZE];
	char tx[MAX_STR_SIZE];
} LUT_Value;


//Local Functions
void sys_init(void);							/* System boot initialisation */
void isr_uart_rx(void);							/* Uart Rx ISR handle 		  */
void tx_msg(void);								/* Uart Tx routine 			  */
char * translate_msg(char *message);			/* Lookup tx resp to rx msg   */

//Local Variables
UART_HandleTypeDef uart_cfg;					/* UART handle for HAL api 	  */
char tx_buffer[TX_BUF_SIZE];					/* Transmit buffer 			  */
int  tx_buffer_end;								/* String length in buffer 	  */


//Lookup Table
LUT_Value lut[LUT_SIZE] = {						/* LUT values				  */
		{"Hello","Bonjour"},
		{"Goodbye","Au revoir"},
		{"Ok", "D'accord"}
};


//<Example Dev Stubs>
void HAL_Init(void) { }							/* Stm32 api				  */
void HAL_Resume(void) { }						/* Stm32 example api		  */
void sleep(void) { }							/* Proc to sleep		  	  */
void __HAL_RCC_GPIOA_CLK_ENABLE(void) { }		/* Recmd boot config for gpio */
void HAL_UART_RxIsr(void *rx_isr) { }			/* Set the uart receive isr	  */
void sys_check(void) { }						/* Check cfg valid			  */
void int_enable(void) { }						/* Enable interrupts 		  */


/******************************************************************************/
/**	@fcn		int main(void)
 *  @brief		x
 *  @details	x
 *
 *  @section 	Tasks
 *  	System Init		(sys_init)
 *		UART Rx			(isr_uart_rx)
 *		UART Tx 		(tx_msg)
 *
 *	@section 	Considerations
 *		Low power
 *		Non-blocking
 *
 *	@section 	Assumptions (@assum?)
 *		x
 */
/******************************************************************************/
int main(void) {

	//Init
	sys_init();									/* Init sys & uart for use 	  */

	//Run
	for(;;) {
		sleep();								/* Wait & respond to uart msg */
		tx_msg();								/* Perform tx response 		  */
	}

	return EXIT_FAILURE;						/* Error, reset & restart 	  */
}


/******************************************************************************/
/**	@fcn		void sys_init(void)
 *  @brief		initialize mcu & peripherals
 *  @details	a brief review and examination of reference indicated the
 *  			following content in multiple locations
 *
 *  @pre		any
 *  @post		system ready for operation
 *
 *  @return 	on success
 *
 *  @note 		DRM not recommended, STM HAL used here
 */
/******************************************************************************/
void sys_init(void) {

	//Init Locals
	uart_cfg.Instance = USART2;					/* UART configuration		  */
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
	__HAL_RCC_GPIOA_CLK_ENABLE();				/* GPIO Ports Clock Enable	  */

	//Init Clocks
	//<Clocks -  HAL_RCC_OscConfig(),
	//			 HAL_RCC_ClockConfig(),
	//			 HAL_RCCEx_PeriphCLKConfig()>
	//<Systick - HAL_SYSTICK_Config(),
	//			 HAL_SYSTICK_CLKSourceConfig(),
	//			 HAL_NVIC_SetPriority()>

	//Init UART
	HAL_UART_Init(&uart_cfg);					/* Init						  */
	HAL_UART_RxIsr(&isr_uart_rx);				/* Assign Receive ISR 		  */

	//Post
	sys_check();
	int_enable();

	return;
}


/******************************************************************************/
/**	@fcn		void isr_uart_rx(void)
 *  @brief		receive interrupt handler for uart
 *  @details	x
 *
 *  @assum		no rx overflow
 */
/******************************************************************************/
void isr_uart_rx(void) {

	//Locals
	char rx_buffer[RX_BUF_SIZE];
	int  rx_count;

	//Init
	rx_count = 0;

	//Grab Rx Message
	while(uart_cfg.RxXferCount> 0) {
		rx_buffer[rx_count++] = USART2->RDR;	/* Grab receive data register */
		uart_timeout_wait();					/* Wait for next rx byte 	  */
	}
	rx_buffer[rx_count] = '\0';					/* Place EOS for parse 		  */

	//Lookup Response
	char *resp = translate_msg(rx_buffer);

	//Load Response
	tx_buffer_end = sizeof(resp);				/* Capture message size */
	memcpy(tx_buffer, resp, tx_buffer_end);		/* Load value */

	//Send Response
	HAL_Resume();								/* Resume main thread */

	return;
}


/******************************************************************************/
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
/******************************************************************************/
void tx_msg(void) {

	//Load
//	load tx_buffer
//	send over uart

	return;
}


/******************************************************************************/
/**	@fcn		char * translate_msg(char *message)
 *  @brief		translate inbound msg to specified response
 *  @details	string values
 *
 *  @param		[in] (char *) message - received message to use for lookup
 *  @return		(char *) pointer to response message, 0 for failure
 *
 *  @assum		no rx overflow
 *
 *  @section 	Opens
 *  	Code
 */
/******************************************************************************/
char * translate_msg(char *message) {

	//Find LUT value
//	for(each LUT value)
//		if found return LUT response value

	return (char*)0;							/* Return 0 on failure 		  */
}


/******************************** End of File *********************************/
