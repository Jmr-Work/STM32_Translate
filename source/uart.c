/************************************************************************************************************************************/
/** @file		uart.c
 * 	@brief		x
 * 	@details	x
 *
 * 	@author		Justin Reina, Firmware Engineer, Company Name
 * 	@created	10/23/18
 * 	@last rev	x
 *
 * 	@section	Opens
 * 			x
 *
 * 	@section	Legal Disclaimer
 * 			© 2018 Company Name, All rights reserved. All contents of this source file and/or any other related source
 *			files are the explicit property of Company Name. Do not distribute. Do not copy.
 */
/************************************************************************************************************************************/
#include "uart.h"

//Buffers
uint8_t aTxBuffer[TXBUFFERSIZE];
uint8_t aRxBuffer[RXBUFFERSIZE];


/************************************************************************************************************************************/
/**	@fcn		void uart_init(void)
 *  @brief		uart initialization
 *  @details	x
 *
 *  @pre		system prepared for uart config
 *  @post		uart ready for use
 */
/************************************************************************************************************************************/
void uart_init(void) {

//	/*##-1- Configure the UART peripheral ######################################*/
//	/* Put the USART peripheral in the Asynchronous mode (UART Mode) */
//	/* UART1 configured as follow:
//	  - Word Length = 8 Bits
//	  - Stop Bit = One Stop bit
//	  - Parity = None
//	  - BaudRate = 9600 baud
//	  - Hardware flow control disabled (RTS and CTS signals) */
//	UartHandle.Instance        = USARTx;
//	UartHandle.Init.BaudRate   = 9600;
//	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
//	UartHandle.Init.StopBits   = UART_STOPBITS_1;
//	UartHandle.Init.Parity     = UART_PARITY_NONE;
//	UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
//	UartHandle.Init.Mode       = UART_MODE_TX_RX;
//
//	if(HAL_UART_Init(&UartHandle) != HAL_OK) {
//	Error_Handler();
//	}
//
//
//	/* The board receives the message and sends it back */
//
//	/*##-2- Put UART peripheral in reception process ###########################*/
//	if(HAL_UART_Receive_IT(&UartHandle, (uint8_t *)aRxBuffer, RXBUFFERSIZE) != HAL_OK) {
//		Error_Handler();
//	}
//
//	/*##-3- Wait for the end of the transfer ###################################*/
//	while (UartReady != SET);
//
//	/* Reset transmission flag */
//	UartReady = RESET;
//
//	/*##-4- Start the transmission process #####################################*/
//	/* While the UART in reception process, user can transmit data through
//	"aTxBuffer" buffer */
//	if(HAL_UART_Transmit_IT(&UartHandle, (uint8_t*)aTxBuffer, TXBUFFERSIZE)!= HAL_OK) {
//		Error_Handler();
//	}
//
//
//	/*##-5- Wait for the end of the transfer ###################################*/
//	while (UartReady != SET);
//
//	/* Reset transmission flag */
//	UartReady = RESET;
//
//	/*##-6- Compare the sent and received buffers ##############################*/
//	if(Buffercmp((uint8_t*)aTxBuffer,(uint8_t*)aRxBuffer,RXBUFFERSIZE)) {
//		Error_Handler();
//	}

	return;
}


/************************************************************************************************************************************/
/**	@fcn		static void _Error_Handler(char *file, int line)
 *  @brief		This function is executed in case of error occurrence.
 *  @details	x
 *
 *  @param		[in] (char *) file - x
 *  @param		[in] (int) line - x
 *
 */
/************************************************************************************************************************************/
static void _Error_Handler(char *file, int line) {

	  /* USER CODE BEGIN Error_Handler_Debug */
	  /* User can add his own implementation to report the HAL error return state */
	  for(;;);

	  /* USER CODE END Error_Handler_Debug */
}

