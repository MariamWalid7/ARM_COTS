/*
 * ***************************************** RCC_private.h *****************************************
 * Driver : RCC
 *  Author: maria
 *  Layer: MCAL
 */
 
 #ifndef RCC_PRIVATE_H
 #define RCC_PRIVATE_H
 
 /* ***************************************** RCC_registers *****************************************/
 
                                /* RCC Base Address: 0x4002 3800 */
#define RCC_CR               *((volatile u32 *) 0x4002 3800)								
#define RCC_PLLCFGR          *((volatile u32 *) 0x4002 3804)								
#define RCC_CFGR             *((volatile u32 *) 0x4002 3808)								
#define RCC_CIR              *((volatile u32 *) 0x4002 380C)								
#define RCC_AHB1RSTR         *((volatile u32 *) 0x4002 3810)	
#define RCC_AHB2RSTR		 *((volatile u32 *) 0x4002 3814)					 
#define RCC_APB1RSTR		 *((volatile u32 *) 0x4002 3820)
#define RCC_APB2RSTR		 *((volatile u32 *) 0x4002 3824)
#define RCC_AHB1ENR		     *((volatile u32 *) 0x4002 3830) 
#define RCC_AHB2ENR		     *((volatile u32 *) 0x4002 3834)
#define RCC_APB1ENR		     *((volatile u32 *) 0x4002 3840)
#define RCC_APB2ENR		     *((volatile u32 *) 0x4002 3844)
#define RCC_BDCR             *((volatile u32 *) 0x4002 3870) 
#define RCC_CSR              *((volatile u32 *) 0x4002 3874)

 /* ***************************************** RCC_Bits *****************************************/
 
                                            /* RCC_CR Bits */
#define RCC_CR_PLLI2SRDY                      27
#define RCC_CR_PLLI2SON                       26										
#define RCC_CR_PLLRDY						  25					
#define RCC_CR_PLLON                          24
#define RCC_CR_CSSON                          19
#define RCC_CR_HSEBYP                         18
#define RCC_CR_HSERDY                         17
#define RCC_CR_HSEON                          16
#define RCC_CR_HSIRDY                          1
#define RCC_CR_HSION                           0


 
                                            /* RCC_CFGR Bits */
#define RCC_CFGR_MCO21                        31
#define RCC_CFGR_MCO20                        30										
#define RCC_CFGR_MCO2PRE2					  29					
#define RCC_CFGR_MCO2PRE1                     28
#define RCC_CFGR_MCO2PRE0                     27
#define RCC_CFGR_MCO1PRE2                     26
#define RCC_CFGR_MCO1PRE1                     25
#define RCC_CFGR_MCO1PRE1                     24
#define RCC_CFGR_I2SSRC                       23
#define RCC_CFGR_MCO11                        22
#define RCC_CFGR_MCO10                        21
#define RCC_CFGR_RTCPRE4                      20                       
#define RCC_CFGR_RTCPRE3                      19
#define RCC_CFGR_RTCPRE2                      18
#define RCC_CFGR_RTCPRE1                      17
#define RCC_CFGR_RTCPRE0                      16
#define RCC_CFGR_PPRE22                       15
#define RCC_CFGR_PPRE21                       14
#define RCC_CFGR_PPRE20                       13
#define RCC_CFGR_PPRE12                       12
#define RCC_CFGR_PPRE11                       11
#define RCC_CFGR_PPRE10                       10
#define RCC_CFGR_HPRE3                         7
#define RCC_CFGR_HPRE2                         6
#define RCC_CFGR_HPRE1                         5 
#define RCC_CFGR_HPRE0                         4
#define RCC_CFGR_SWS1                          3
#define RCC_CFGR_SWS0                          2
#define RCC_CFGR_SW1                           1
#define RCC_CFGR_SW0                           0


                                          /* RCC_CSR Bits */
#define RCC_CSR_LPWRRSTF                      31										  
#define RCC_CSR_WWDGRSTF                      30										  
#define RCC_CSR_IWDGRSTF					  29				  
#define RCC_CSR_SFTRSTF						  28				  
#define RCC_CSR_PORRSTF                       27										  
#define RCC_CSR_PINRSTF						  26			  
#define RCC_CSR_BORRSTF                       25										  
#define RCC_CSR_RMVF						  24			  
#define RCC_CSR_LSIRDY						   1			  
#define RCC_CSR_LSION						   0


			                         /* RCC_BDCR Bits */
#define RCC_BDCR_BDRST						  16				  
#define RCC_BDCR_RTCEN						  15				  
#define RCC_BDCR_RTCSEL1                       9										  
#define RCC_BDCR_RTCSEL0					   8					  
#define RCC_BDCR_LSEBYP						   2			  
#define RCC_BDCR_LSERDY						   1			  
#define RCC_BDCR_LSEON						   0

				  
										  
										  
										  
									  /* RCC_AHB1ENR Bits */
#define RCC_AHB1ENR_DMA2EN                    22										  
#define RCC_AHB1ENR_DMA1EN 				      21						  
#define RCC_AHB1ENR_CRCREN				      12				  
#define RCC_AHB1ENR_GPIOHEN	                   7									  
#define RCC_AHB1ENR_GPIOEEN					   4					  
#define RCC_AHB1ENR_GPIODEN					   3					  
#define RCC_AHB1ENR_GPIOCEN                    2										  
#define RCC_AHB1ENR_GPIOBEN					   1					  
#define RCC_AHB1ENR_GPIOAEN					   0



					                    /* RCC_AHB2ENR Bits */
#define RCC_AHB2ENR_OTGFSEN                     7


 
                                       /* RCC_APB1ENR Bits */										  
#define RCC_APB1ENR_I2C3EN				      23						  
#define RCC_APB1ENR_I2C2EN                    22				   						  
#define RCC_APB1ENR_I2C1EN                    21
#define RCC_APB1ENR_USART2EN                  17
#define RCC_APB1ENR_SPI3EN                    15
#define RCC_APB1ENR_SPI2EN                    14
#define RCC_APB1ENR_WWDGEN                    11
#define RCC_APB1ENR_TIM5EN                     3
#define RCC_APB1ENR_TIM4EN                     2
#define RCC_APB1ENR_TIM3EN                     1
#define RCC_APB1ENR_TIM2EN                     0


                                      /* RCC_APB2ENR Bits */

#define RCC_APB2ENR_TIM11EN                  18
#define RCC_APB2ENR_TIM10EN                  17
#define RCC_APB2ENR_TIM9EN                   16
#define RCC_APB2ENR_SYSCFGEN                 14
#define RCC_APB2ENR_SPI4EN                   13
#define RCC_APB2ENR_SPI1EN                   12
#define RCC_APB2ENR_SDIOEN					 11				  
#define RCC_APB2ENR_ADC1EN                    8
#define RCC_APB2ENR_USART6EN                  5
#define RCC_APB2ENR_USART1EN                  4
#define RCC_APB2ENR_TIM1EN                    0


                                    /* RCC_PLLCFGR Bits */
#define RCC_PLLCFGR_PLLQ3		             27							
#define RCC_PLLCFGR_PLLQ2                    26									
#define RCC_PLLCFGR_PLLQ1					 25				
#define RCC_PLLCFGR_PLLQ0					 24				
#define RCC_PLLCFGR_PLLSRC                   22									
#define RCC_PLLCFGR_PLLP1                    17									
#define RCC_PLLCFGR_PLLP0					 16				
#define RCC_PLLCFGR_PLLN8                    14									
#define RCC_PLLCFGR_PLLN7					 13				
#define RCC_PLLCFGR_PLLN6					 12				
#define RCC_PLLCFGR_PLLN5					 11				
#define RCC_PLLCFGR_PLLN4					 10				
#define RCC_PLLCFGR_PLLN3                     9
#define RCC_PLLCFGR_PLLN2                     8
#define RCC_PLLCFGR_PLLN1                     7
#define RCC_PLLCFGR_PLLN0                     6
#define RCC_PLLCFGR_PLLM5                     5
#define RCC_PLLCFGR_PLLM4                     4
#define RCC_PLLCFGR_PLLM3                     3
#define RCC_PLLCFGR_PLLM2                     2
#define RCC_PLLCFGR_PLLM1                     1
#define RCC_PLLCFGR_PLLM0                     0
							 

#endif