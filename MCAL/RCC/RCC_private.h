/* ***************************************RCC_private.h*********************************************
 *  Created on: Oct 19, 2023
 *  Author: maria
 *  SWC: RCC
 *  Layer: MCAL
 * ****************************************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/*************************************************************
 * Description: RCC Base Address.
 *
 *************************************************************/
#define RCC_BASE_ADDRESS                   0x40023800



/*************************************************************
 * Description: RCC Registers.
 *
 *************************************************************/
typedef struct
{
	volatile u32 RCC_CR;
	volatile u32 RCC_PLLCFGR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_AHB1RST;
	volatile u32 RCC_AHB2RST;
	volatile u32 Reserved1;
	volatile u32 Reserved2;
	volatile u32 RCC_APB1RST;
	volatile u32 RCC_APB2RST;
	volatile u32 Reserved3;
	volatile u32 Reserved4;
	volatile u32 RCC_AHB1ENR;
	volatile u32 RCC_AHB2ENR;
	volatile u32 Reserved5;
	volatile u32 Reserved6;
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 Reserved7;
	volatile u32 Reserved8;
	volatile u32 RCC_AHB1LPENR;
	volatile u32 RCC_AHB2LPENR;
	volatile u32 Reserved9;
	volatile u32 Reserved10;
	volatile u32 RCC_APB1LPENR;
	volatile u32 RCC_APB2LPENR;
	volatile u32 Reserved11;
	volatile u32 Reserved12;
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 Reserved13;
	volatile u32 Reserved14;
	volatile u32 RCC_SSCGR;
	volatile u32 RCC_PLLI2SCFGR;
	volatile u32 Reserved15;
	volatile u32 RCC_DCKCFGR;

}RCC_registers;

#define RCC                               ((RCC_registers *)RCC_BASE_ADDRESS)


/*************************************************************
 * Description: RCC Register Pins.
 *
 *************************************************************/
typedef enum
{
  RCC_CR_enumHSION=0,
  RCC_CR_enumHSIRDY,
  RCC_CR_enumHSITRIM_0=3,
  RCC_CR_enumHSITRIM_1,
  RCC_CR_enumHSITRIM_2,
  RCC_CR_enumHSITRIM_3,
  RCC_CR_enumHSITRIM_4,
  RCC_CR_enumHSICAL_0,
  RCC_CR_enumHSICAL_1,
  RCC_CR_enumHSICAL_2,
  RCC_CR_enumHSICAL_3,
  RCC_CR_enumHSICAL_4,
  RCC_CR_enumHSICAL_5,
  RCC_CR_enumHSICAL_6,
  RCC_CR_enumHSICAL_7,
  RCC_CR_enumHSEON,
  RCC_CR_enumHSERDY,
  RCC_CR_enumHSEBYP,
  RCC_CR_enumCSSON,
  RCC_CR_enumPLLON=24,
  RCC_CR_enumPLLRDY,
  RCC_CR_enumPLLI2SON,
  RCC_CR_enumPLLI2SRDY

}RCC_CR_enumPins;


typedef enum{
  RCC_PLLCFGR_enumPLLM0=0,
  RCC_PLLCFGR_enumPLLM1,
  RCC_PLLCFGR_enumPLLM2,
  RCC_PLLCFGR_enumPLLM3,
  RCC_PLLCFGR_enumPLLM4,
  RCC_PLLCFGR_enumPLLM5,
  RCC_PLLCFGR_enumPLLN_0,
  RCC_PLLCFGR_enumPLLN_1,
  RCC_PLLCFGR_enumPLLN_2,
  RCC_PLLCFGR_enumPLLN_3,
  RCC_PLLCFGR_enumPLLN_4,
  RCC_PLLCFGR_enumPLLN_5,
  RCC_PLLCFGR_enumPLLN_6,
  RCC_PLLCFGR_enumPLLN_7,
  RCC_PLLCFGR_enumPLLN_8,
  RCC_PLLCFGR_enumPLLP0=16,
  RCC_PLLCFGR_enumPLLP1,
  RCC_PLLCFGR_enumPLLSRC=22,
  RCC_PLLCFGR_enumPLLQ0=24,
  RCC_PLLCFGR_enumPLLQ1,
  RCC_PLLCFGR_enumPLLQ2,
  RCC_PLLCFGR_enumPLLQ3

}RCC_PLLCFGR_enumPins;

typedef enum{
  RCC_CFGR_enumSW0=0,
  RCC_CFGR_enumSW1,
  RCC_CFGR_enumSWS0,
  RCC_CFGR_enumSWS1,
  RCC_CFGR_enumHPRE_0,
  RCC_CFGR_enumHPRE_1,
  RCC_CFGR_enumHPRE_2,
  RCC_CFGR_enumHPRE_3,
  RCC_CFGR_enumPPRE1_0=10,
  RCC_CFGR_enumPPRE1_1,
  RCC_CFGR_enumPPRE1_2,
  RCC_CFGR_enumPPRE2_0,
  RCC_CFGR_enumPPRE2_1,
  RCC_CFGR_enumPPRE2_2,
  RCC_CFGR_enumRTCPRE_0,
  RCC_CFGR_enumRTCPRE_1,
  RCC_CFGR_enumRTCPRE_2,
  RCC_CFGR_enumRTCPRE_3,
  RCC_CFGR_enumRTCPRE_4,
  RCC_CFGR_enumMCO1_0,
  RCC_CFGR_enumMCO1_1,
  RCC_CFGR_enumI2SSCR,
  RCC_CFGR_enumMCO1PRE_0,
  RCC_CFGR_enumMCO1PRE_1,
  RCC_CFGR_enumMCO1PRE_2,
  RCC_CFGR_enumMCO2PRE_0,
  RCC_CFGR_enumMCO2PRE_1,
  RCC_CFGR_enumMCO2PRE_2,
  RCC_CFGR_enumMCO2_0,
  RCC_CFGR_enumMCO2_1

}RCC_CFGR_enumPins;


typedef enum
{
  RCC_AHB1ENR_enumGPIOAEN=0,
  RCC_AHB1ENR_enumGPIOBEN,
  RCC_AHB1ENR_enumGPIOCEN,
  RCC_AHB1ENR_enumGPIODEN,
  RCC_AHB1ENR_enumGPIOEEN,
  RCC_AHB1ENR_enumGPIOHEN=7,
  RCC_AHB1ENR_enumCRCEN=12,
  RCC_AHB1ENR_enumDMA1EN=21,
  RCC_AHB1ENR_enumDMA2EN

}RCC_AHB1ENR_enumPins;


#define  RCC_AHB2ENR_OTGFSEN        7


typedef enum
{
  RCC_APB1ENR_enumTIM2EN=0,
  RCC_APB1ENR_enumTIM3EN,
  RCC_APB1ENR_enumTIM4EN,
  RCC_APB1ENR_enumTIM5EN,
  RCC_APB1ENR_enumWWDGEN=11,
  RCC_APB1ENR_enumSPI2EN=14,
  RCC_APB1ENR_enumSPI3EN,
  RCC_APB1ENR_enumUSART2EN=17,
  RCC_APB1ENR_enumI2C1EN=21,
  RCC_APB1ENR_enumI2C2EN,
  RCC_APB1ENR_enumI2C3EN,
  RCC_APB1ENR_enumPWREN=28
}RCC_APB1ENR_enumPins;

typedef enum
{
  RCC_APB2ENR_enumTIM1EN=0,
  RCC_APB2ENR_enumUSART1EN=4,
  RCC_APB2ENR_enumUSART6EN,
  RCC_APB2ENR_enumADC1EN=8,
  RCC_APB2ENR_enumSDIOEN=11,
  RCC_APB2ENR_enumSPI1EN,
  RCC_APB2ENR_enumSPI4EN,
  RCC_APB2ENR_enumSYSCFGEN,
  RCC_APB2ENR_enumTIM9EN=16,
  RCC_APB2ENR_enumTIM10EN,
  RCC_APB2ENR_enumTIM11EN

}RCC_APB2ENR_enumPins;


typedef enum
{
  RCC_PLLI2SCFGR_enumPLLI2SN0=6,
  RCC_PLLI2SCFGR_enumPLLI2SN1,
  RCC_PLLI2SCFGR_enumPLLI2SN2,
  RCC_PLLI2SCFGR_enumPLLI2SN3,
  RCC_PLLI2SCFGR_enumPLLI2SN4,
  RCC_PLLI2SCFGR_enumPLLI2SN5,
  RCC_PLLI2SCFGR_enumPLLI2SN6,
  RCC_PLLI2SCFGR_enumPLLI2SN7,
  RCC_PLLI2SCFGR_enumPLLI2SN8,
  RCC_PLLI2SCFGR_enumPLLI2SR0=28,
  RCC_PLLI2SCFGR_enumPLLI2SR1,
  RCC_PLLI2SCFGR_enumPLLI2SR2

}RCC_PLLI2SCFGR_enumPins;

typedef enum
{
  RCC_AHB1RSTR_enumGPIOARST=0,
  RCC_AHB1RSTR_enumGPIOBRST,
  RCC_AHB1RSTR_enumGPIOCRST,
  RCC_AHB1RSTR_enumGPIODRST,
  RCC_AHB1RSTR_enumGPIOERST,
  RCC_AHB1RSTR_enumGPIOHRST=7,
  RCC_AHB1RSTR_enumCRCRST=12,
  RCC_AHB1RSTR_enumDMA1RST=21,
  RCC_AHB1RSTR_enumDMA2RST

}RCC_AHB1RSTR_enumPins;

#define  RCC_AHB2RSTR_OTGFSRST        7

typedef enum
{
  RCC_APB1RSTR_enumTIM2RST=0,
  RCC_APB1RSTR_enumTIM3RST,
  RCC_APB1RSTR_enumTIM4RST,
  RCC_APB1RSTR_enumTIM5RST,
  RCC_APB1RSTR_enumWWDGRST=11,
  RCC_APB1RSTR_enumSPI2RST=14,
  RCC_APB1RSTR_enumSPI3RST,
  RCC_APB1RSTR_enumUSART2RST=17,
  RCC_APB1RSTR_enumI2C1RST=21,
  RCC_APB1RSTR_enumI2C2RST,
  RCC_APB1RSTR_enumI2C3RST,
  RCC_APB1RSTR_enumPWRRST=28

}RCC_APB1RSTR_enumPins;

typedef enum
{
  RCC_APB2RSTR_enumTIM1RST=0,
  RCC_APB2RSTR_enumUSART1RST=4,
  RCC_APB2RSTR_enumUSART6RST,
  RCC_APB2RSTR_enumADC1RST=8,
  RCC_APB2RSTR_enumSDIORST=11,
  RCC_APB2RSTR_enumSPI1RST,
  RCC_APB2RSTR_enumSPI4RST,
  RCC_APB2RSTR_enumSYSCFGRST,
  RCC_APB2RSTR_enumTIM9RST=16,
  RCC_APB2RSTR_enumTIM10RST,
  RCC_APB2RSTR_enumTIM11RST

}RCC_APB2RSTR_enumPins;


#endif /* RCC_PRIVATE_H_ */
