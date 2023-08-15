/*
 * ***************************************** RCC_interface.h *****************************************
 * Driver : RCC
 *  Author: maria
 *  Layer: MCAL
 */
 
 #ifndef RCC_INTERFACE_H
 #define RCC_INTERFACE_H
 
 typedef enum 
 {
	 NotOK,
	 OK
	 
 }RCC_errorState;
 
              /* Bus_macros */
#define AHB1                                    0
#define AHB2                                    1
#define APB1                                    2
#define APB1                                    3

              /* AHB1_peripheral_IDs */
#define copy_u8_AHB1_DMA2EN                    22
#define copy_u8_AHB1_DMA1EN 	               21
#define copy_u8_AHB1_CRCREN		               12
#define copy_u8_AHB1_GPIOHEN	                7
#define copy_u8_AHB1_GPIOEEN	                4
#define copy_u8_AHB1_GPIODEN	                3
#define copy_u8_AHB1_GPIOCEN	                2
#define copy_u8_AHB1_GPIOBEN	                1
#define copy_u8_AHB1_GPIOAEN	                0

              
		     /* AHB1_peripheral_IDs */
#define copy_u8_AHB2_OTGFSEN                   7	




              /* APB1_peripheral_IDs */		  
#define copy_u8_APB1_I2C3EN				      23			  
#define copy_u8_APB1_I2C2EN                   22			  
#define copy_u8_APB1_I2C1EN                   21			  
#define copy_u8_APB1_USART2EN                 17			  
#define copy_u8_APB1_SPI3EN                   15			  
#define copy_u8_APB1_SPI2EN                   14			  
#define copy_u8_APB1_WWDGEN                   11
#define copy_u8_APB1_TIM5EN                    3
#define copy_u8_APB1_TIM4EN                    2
#define copy_u8_APB1_TIM3EN                    1
#define copy_u8_APB1_TIM2EN                    0


               /* APB2_peripheral_IDs */
			   
#define copy_u8_APB2_TIM11EN                   18                   
#define copy_u8_APB2_TIM10EN                   17
#define copy_u8_APB2_TIM9EN                    16
#define copy_u8_APB2_SPI4EN                    13
#define copy_u8_APB2_SPI1EN                    12
#define copy_u8_APB2_SDIOEN                    11
#define copy_u8_APB2_ADC1EN                     8
#define copy_u8_APB2_USART6EN                   5
#define copy_u8_APB2_USART1EN                   4
#define copy_u8_APB2_TIM1EN                     0

                
              /* CLK_SRC selection */
#define HSI                                    0
#define HSE                                    1
#define PLL                                    2
#define LSI                                    3
#define LSE                                    4
 
 
 /* Function prototypes */
void RCC_voidInitSysClc(void);
RCC_errorState RCC_enumEnablePerpheralClk (u8 Copy_u8BusId ,u8 Copy_u8PeripheralId);
RCC_errorState RCC_enumDisablePerpheralClk(u8 Copy_u8BusId ,u8 Copy_u8PeripheralId);
void RCC_voidPrescalerAHB(void);
void RCC_voidPrescalerAPB1(void);
void RCC_voidPrescalerAPB2(void);
void RCC_voidEnableRTC(void);
void RCC_voidConfigureMainPLLSrc(void);

 
 
 
 #endif