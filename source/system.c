/************************************************************************************************************************************/
/** @file		system.c
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
#include "system.h"


/************************************************************************************************************************************/
/**	@fcn		void sys_init(void)
 *  @brief		system boot initialization
 *  @details	x
 *
 *  @pre		any
 *  @post		system configured for runtime operations
 */
/************************************************************************************************************************************/
void sys_init(void) {

	//System
	system_init();															/* initialize HAL on boot								*/
	system_clockConfig();													/* Configure the system clock to 32 MHz 				*/

	//GPIO
	gpio_init();

	//UART
	uart_init();

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void system_init (void)
 *  @brief		Setup the microcontroller system.
 *  @details	Reset of all peripherals, Initializes the Flash interface and the Systick.
 *
 *  @pre		any
 *  @post		HAL initialized for use
 */
/************************************************************************************************************************************/
void system_init (void) {

//	HAL_Init();
//
//	/*!< Set MSION bit */
//	RCC->CR |= (uint32_t)0x00000100;
//
//	/*!< Reset SW[1:0], HPRE[3:0], PPRE1[2:0], PPRE2[2:0], MCOSEL[2:0] and MCOPRE[2:0] bits */
//	RCC->CFGR &= (uint32_t) 0x88FF400C;
//
//	/*!< Reset HSION, HSIDIVEN, HSEON, CSSON and PLLON bits */
//	RCC->CR &= (uint32_t)0xFEF6FFF6;
//
//	/*!< Reset HSI48ON  bit */
//	RCC->CRRCR &= (uint32_t)0xFFFFFFFE;
//
//	/*!< Reset HSEBYP bit */
//	RCC->CR &= (uint32_t)0xFFFBFFFF;
//
//	/*!< Reset PLLSRC, PLLMUL[3:0] and PLLDIV[1:0] bits */
//	RCC->CFGR &= (uint32_t)0xFF02FFFF;
//
//	/*!< Disable all interrupts */
//	RCC->CIER = 0x00000000;
//
//	/* Configure the Vector Table location add offset address ------------------*/
//#ifdef VECT_TAB_SRAM
//	SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
//#else
//	SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
//#endif

  return;
}


/************************************************************************************************************************************/
/**	@fcn		void system_clockConfig(void)
 *  @brief		System Clock Configuration
 *  @details	x
 *
 *  @section 	Config
 * 		System Clock source            = PLL (HSI)
 *      SYSCLK(Hz)                     = 32000000
 *      HCLK(Hz)                       = 32000000
 *      AHB Prescaler                  = 1
 *      APB1 Prescaler                 = 1
 *      APB2 Prescaler                 = 1
 *      HSI Frequency(Hz)              = 16000000
 *      PLL_MUL                        = 4
 *      PLL_DIV                        = 2
 *      Flash Latency(WS)              = 1
 *      Main regulator output voltage  = Scale1 mode
 *
 *  @pre		x
 *  @post		x
 */
/************************************************************************************************************************************/
void system_clockConfig(void) {

//  RCC_ClkInitTypeDef RCC_ClkInitStruct;
//  RCC_OscInitTypeDef RCC_OscInitStruct;
//
//  /* Enable Power Control clock */
//  __HAL_RCC_PWR_CLK_ENABLE();
//
//  /* The voltage scaling allows optimizing the power consumption when the device is
//     clocked below the maximum system frequency, to update the voltage scaling value
//     regarding system frequency refer to product datasheet.  */
//  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
//
//  /* Enable HSI Oscillator and activate PLL with HSI as source */
//  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
//  RCC_OscInitStruct.HSEState = RCC_HSE_OFF;
//  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
//  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
//  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL4;
//  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLL_DIV2;
//  RCC_OscInitStruct.HSICalibrationValue = 0x10;
//  HAL_RCC_OscConfig(&RCC_OscInitStruct);
//
//  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
//     clocks dividers */
//  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
//  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
//  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
//  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1);

  return;
}


/************************************************************************************************************************************/
/**	@fcn		void gpio_init(void)
 *  @brief		initialize gpio for use
 *  @details	x
 *
 *  @pre		any
 *  @post		gpio initialized for use with usart
 */
/************************************************************************************************************************************/
void gpio_init(void) {

//  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOA_CLK_ENABLE();

  return;
}


