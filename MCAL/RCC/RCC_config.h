/* ***************************************RCC_config.h*********************************************
 *  Created on: Oct 19, 2023
 *  Author: maria
 *  SWC: RCC
 *  Layer: MCAL
 * ****************************************************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/*************************************************************
 * Select HSE external clock circuit (if HSE is selected as system clock):
 * Options:
 * 1- RCC_HSE_NOT_BYPASSED --> External Crystal/Ceramic Oscillator
 * 2- RCC_HSE_BYPASSED  --> Other External clock circuits
 *
 *************************************************************/
#define RCC_HSE_CONFIGURATION        RCC_HSE_NOT_BYPASSED



/*************************************************************
 * Select main PLL source (if PLL is selected as system clock):
 * Options:
 * 1- RCC_MAIN_PLL_SRC_HSI
 * 2- RCC_MAIN_PLL_SRC_HSE
 *
 *************************************************************/
#define RCC_MAIN_PLL_SRC             RCC_MAIN_PLL_SRC_HSI

#endif /* RCC_CONFIG_H_ */
