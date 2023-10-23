/* ***************************************RCC_program.c*********************************************
 *  Created on: Oct 19, 2023
 *  Author: maria
 *  SWC: RCC
 *  Layer: MCAL
 * ****************************************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_private.h"
#include "RCC_interface.h"
#include "RCC_config.h"

/*************************************************************
 * Description: Functions Implementations.
 *
 *************************************************************/

/* Func name: RCC_enumInitClk
 * Description: Initializes system clock
 * I/P arguments: Copy_enumClkSource
 * return: RCC_enumErrorState
 *
 *
 */
RCC_enumErrorState RCC_enumInitClk(RCC_enumSysClkSrc Copy_enumClkSource)
{
	RCC_enumErrorState LOC_u8ErrorState = RCC_OK;

	/* Set system clock source */
	switch(Copy_enumClkSource)
	{
	case RCC_SYSCLK_SRC_HSI:
		/* Enable HSI RC oscillator */
		SET_BIT(RCC->RCC_CR, RCC_CR_enumHSION);

		/* Wait until HSI oscillator is ready */
		while(GET_BIT(RCC->RCC_CR,RCC_CR_enumHSIRDY)==0);

		/* Select HSI as clk source */
		CLR_BIT(RCC->RCC_CFGR, RCC_CFGR_enumSW0);
		CLR_BIT(RCC->RCC_CFGR, RCC_CFGR_enumSW1);
		break;

	case RCC_SYSCLK_SRC_HSE:
		/* Enable HSE clock source */
		SET_BIT(RCC->RCC_CR, RCC_CR_enumHSEON);

		/* Set HSE configuration */
		if(RCC_HSE_CONFIGURATION == RCC_HSE_NOT_BYPASSED)
		{
			CLR_BIT(RCC->RCC_CR, RCC_CR_enumHSEBYP);
		}
		else if(RCC_HSE_CONFIGURATION == RCC_HSE_BYPASSED)
		{
			SET_BIT(RCC->RCC_CR, RCC_CR_enumHSEBYP);
		}
		else
			LOC_u8ErrorState = RCC_NOK;

		/* Wait until HSI oscillator is ready */
		while(GET_BIT(RCC->RCC_CR,RCC_CR_enumHSERDY)==0);

		/* Select HSE as clk source */
		SET_BIT(RCC->RCC_CFGR, RCC_CFGR_enumSW0);
		CLR_BIT(RCC->RCC_CFGR, RCC_CFGR_enumSW1);
		break;

	case RCC_SYSCLK_SRC_PLL:
		/* Enable PLL clock source */
		SET_BIT(RCC->RCC_CR, RCC_CR_enumPLLON);

		/* Select PLL source */
		if(RCC_MAIN_PLL_SRC == RCC_MAIN_PLL_SRC_HSI)
		{
			CLR_BIT(RCC->RCC_PLLCFGR, RCC_PLLCFGR_enumPLLSRC);
		}
		else if(RCC_MAIN_PLL_SRC == RCC_MAIN_PLL_SRC_HSE)
		{
			SET_BIT(RCC->RCC_PLLCFGR, RCC_PLLCFGR_enumPLLSRC);
		}
		else
			LOC_u8ErrorState = RCC_NOK;

		/* Wait until HSI oscillator is ready */
		while(GET_BIT(RCC->RCC_CR,RCC_CR_enumPLLRDY)==0);

		/* Select main PLL as clk Source*/
		CLR_BIT(RCC->RCC_CFGR, RCC_CFGR_enumSW0);
		SET_BIT(RCC->RCC_CFGR, RCC_CFGR_enumSW1);
		break;

	default:
		LOC_u8ErrorState = RCC_NOK;
		break;
	}

	return LOC_u8ErrorState;
}



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
RCC_enumErrorState RCC_enumEnablePeripheralClk (RCC_enumBusType Copy_enumBusID, u8 Copy_u8Peripheral)
{
	RCC_enumErrorState LOC_u8ErrorState = RCC_OK;

	switch(Copy_enumBusID)
	{
	case RCC_BUS_AHB1:
		SET_BIT(RCC->RCC_AHB1ENR,Copy_u8Peripheral);
		break;

	case RCC_BUS_AHB2:
		SET_BIT(RCC->RCC_AHB2ENR,7);
		break;

	case RCC_BUS_APB1:
		SET_BIT(RCC->RCC_APB1ENR,Copy_u8Peripheral);
		break;

	case RCC_BUS_APB2:
		SET_BIT(RCC->RCC_APB2ENR,Copy_u8Peripheral);
		break;

	default:
		LOC_u8ErrorState = RCC_NOK;
		break;
	}

	return LOC_u8ErrorState;
}


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
 *
 *
 */
RCC_enumErrorState RCC_enumSetAHBPrescaler (u8 Copy_u8Prescaler)
{
	RCC_enumErrorState LOC_u8ErrorState = RCC_OK;

    if((Copy_u8Prescaler==0) || (Copy_u8Prescaler>=8 && Copy_u8Prescaler<=15))
    {
    RCC->RCC_CFGR &= ~(MASK_4_BITS<<RCC_CFGR_enumHPRE_0);
    RCC->RCC_CFGR |= (Copy_u8Prescaler<<RCC_CFGR_enumHPRE_0);
    }
    else
    {
    	LOC_u8ErrorState = RCC_NOK;
    }

	return LOC_u8ErrorState;
}



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
RCC_enumErrorState RCC_enumSetAPB1Prescaler (u8 Copy_u8Prescaler)
{
	RCC_enumErrorState LOC_u8ErrorState = RCC_OK;

    if((Copy_u8Prescaler==0) || (Copy_u8Prescaler>=4 && Copy_u8Prescaler<=7))
    {
    RCC->RCC_CFGR &= ~(MASK_3_BITS<<RCC_CFGR_enumPPRE1_0);
    RCC->RCC_CFGR |= (Copy_u8Prescaler<<RCC_CFGR_enumPPRE1_0);
    }
    else
    {
    	LOC_u8ErrorState = RCC_NOK;
    }

	return LOC_u8ErrorState;
}


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
RCC_enumErrorState RCC_enumSetAPB2Prescaler (u8 Copy_u8Prescaler)
{
	RCC_enumErrorState LOC_u8ErrorState = RCC_OK;

    if((Copy_u8Prescaler==0) || (Copy_u8Prescaler>=4 && Copy_u8Prescaler<=7))
    {
    RCC->RCC_CFGR &= ~(MASK_3_BITS<<RCC_CFGR_enumPPRE2_0);
    RCC->RCC_CFGR |= (Copy_u8Prescaler<<RCC_CFGR_enumPPRE2_0);
    }
    else
    {
    	LOC_u8ErrorState = RCC_NOK;
    }

	return LOC_u8ErrorState;
}
 
 
 
	
	
 
 
 
