/* ***************************************RCC_interface.h*********************************************
 *  Created on: Oct 19, 2023
 *  Author: maria
 *  SWC: RCC
 *  Layer: MCAL
 * ****************************************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/*************************************************************
 * Description: RCC Error Status.
 *
 *************************************************************/
typedef enum
{
 RCC_NOK,
 RCC_OK
} RCC_enumErrorState;


/*************************************************************
 * Description: System Clk Source.
 *
 *************************************************************/
typedef enum
{
 RCC_SYSCLK_SRC_HSI,
 RCC_SYSCLK_SRC_HSE,
 RCC_SYSCLK_SRC_PLL
} RCC_enumSysClkSrc;


/*************************************************************
 * Description: Bus type.
 *
 *************************************************************/
typedef enum
{
	RCC_BUS_AHB1,
	RCC_BUS_AHB2,
	RCC_BUS_APB1,
	RCC_BUS_APB2
} RCC_enumBusType;


/*************************************************************
 * Description: Peripherals ID.
 *
 *************************************************************/
typedef enum
{
	  RCC_AHB1_GPIOA=0,
	  RCC_AHB1_GPIOB,
	  RCC_AHB1_GPIOC,
	  RCC_AHB1_GPIOD,
	  RCC_AHB1_GPIOE,
	  RCC_AHB1_GPIOH=7,
	  RCC_AHB1_CRC=12,
	  RCC_AHB1_DMA1=21,
	  RCC_AHB1_DMA2
}RCC_enumAHB1Peripherals;

typedef enum
{
	  RCC_APB1_TIM2=0,
	  RCC_APB1_TIM3,
	  RCC_APB1_TIM4,
	  RCC_APB1_TIM5,
	  RCC_APB1_WWDG=11,
	  RCC_APB1_SPI2=14,
	  RCC_APB1_SPI3,
	  RCC_APB1_USART2=17,
	  RCC_APB1_I2C1=21,
	  RCC_APB1_I2C2,
	  RCC_APB1_I2C3,
	  RCC_APB1_PWR=28
}RCC_enumAPB1Peripherals;

typedef enum
{
	  RCC_APB2_TIM1=0,
	  RCC_APB2_USART1=4,
	  RCC_APB2_USART6,
	  RCC_APB2_ADC1=8,
	  RCC_APB2_SDIO=11,
	  RCC_APB2_SPI1,
	  RCC_APB2_SPI4,
	  RCC_APB2_SYSCFG,
	  RCC_APB2_TIM9=16,
	  RCC_APB2_TIM10,
	  RCC_APB2_TIM11
}RCC_enumAPB2Peripherals;

/*************************************************************
 * Description: AHB Prescalers.
 *
 *************************************************************/
typedef enum
{
   AHB_NOT_DIVIDED=0,
   AHB_DIVIIDED_2=8,
   AHB_DIVIIDED_4,
   AHB_DIVIIDED_8,
   AHB_DIVIIDED_16,
   AHB_DIVIIDED_64,
   AHB_DIVIIDED_128,
   AHB_DIVIIDED_256,
   AHB_DIVIIDED_512
}RCC_enumAHBPrescaler;


/*************************************************************
 * Description: APB Prescalers.
 *
 *************************************************************/
typedef enum
{
  AHB_NOT_DIV=0,
  AHB_DIV_2=4,
  AHB_DIV_4,
  AHB_DIV_8,
  AHB_DIV_16
}RCC_enumAPBPrescaler;


/*************************************************************
 * Description: configurations defines.
 *
 *************************************************************/
#define RCC_HSE_NOT_BYPASSED                  0
#define RCC_HSE_BYPASSED                      1

#define RCC_MAIN_PLL_SRC_HSI                  0
#define RCC_MAIN_PLL_SRC_HSE                  1

/*************************************************************
 * Description: Function Prototypes.
 *
 *************************************************************/


/* Func name: RCC_enumInitClk
 * Description: Initializes system clock
 * I/P arguments: Copy_enumClkSource:
 *                RCC_SYSCLK_SRC_HSI
 *                RCC_SYSCLK_SRC_HSE
 *                RCC_SYSCLK_SRC_PLL
 * return: RCC_enumErrorState
 *
 *
 */
RCC_enumErrorState RCC_enumInitClk(RCC_enumSysClkSrc Copy_enumClkSource);


/* Func name: RCC_enumEnablePeripheralClk
 * Description:  Enables clock for a certain peripheral
 * I/P arguments:
 * Copy_enumBusID: specifies the Bus ID to which the peripheral's connected:
 * 				                         RCC_BUS_AHB1
 *	                                     RCC_BUS_AHB2
 *                                       RCC_BUS_APB1
 *	                                     RCC_BUS_APB2
 *
 * Copy_u8Peripheral: specifies the peripheral ID to be enabled
 * return:RCC_enumErrorState
 */
RCC_enumErrorState RCC_enumEnablePeripheralClk (RCC_enumBusType Copy_enumBusID, u8 Copy_u8Peripheral);


/* Func name:  RCC_enumSetAHBPrescaler
 * Description: Sets the prescaler of AHB Bus
 * I/P arguments: Copy_u8Prescaler:
 *                   AHB_NOT_DIVIDED,
 *                   AHB_DIVIIDED_2,
 *                   AHB_DIVIIDED_4,
 *                   AHB_DIVIIDED_8,
 *                   AHB_DIVIIDED_16,
 *                   AHB_DIVIIDED_64,
 *                   AHB_DIVIIDED_128,
 *                   AHB_DIVIIDED_256,
 *                   AHB_DIVIIDED_512
 * return: RCC_enumErrorState
 */
RCC_enumErrorState RCC_enumSetAHBPrescaler (u8 Copy_u8Prescaler);



/* Func name: RCC_enumSetAPB1Prescaler
 * Description: Sets the prescaler of APB1 Bus
 * I/P arguments: Copy_u8Prescaler:
 *                   AHB_NOT_DIV,
 *                   AHB_DIV_2,
 *                   AHB_DIV_4,
 *                   AHB_DIV_8,
 *                   AHB_DIV_16,
 * return: RCC_enumErrorState
 */
RCC_enumErrorState RCC_enumSetAPB1Prescaler (u8 Copy_u8Prescaler);


/* Func name: RCC_enumSetAPB2Prescaler
 * Description: Sets the prescaler of APB2 Bus
 * I/P arguments: Copy_u8Prescaler
 *                   AHB_NOT_DIVIDED,
 *                   AHB_DIV_2,
 *                   AHB_DIV_4,
 *                   AHB_DIV_8,
 *                   AHB_DIV_16,
 * return: RCC_enumErrorState
 */
RCC_enumErrorState RCC_enumSetAPB2Prescaler (u8 Copy_u8Prescaler);

#endif /* RCC_INTERFACE_H_ */
