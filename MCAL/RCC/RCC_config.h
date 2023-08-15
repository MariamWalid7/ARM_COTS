/*
 * ***************************************** RCC_config.h *****************************************
 * Driver : RCC
 *  Author: maria
 *  Layer: MCAL
 */
 
 #ifndef RCC_CONFIG_H
 #define RCC_CONFIG_H
 
 /* Clk Source selections
 Options:
   HSE
   LSE
   PLL
   LSI
   LSE
 */
 #define RCC_CLK_SEL                  HSE
 
 
 
 /*select Prescaler value for AHB
 Options:
NOT_DIVIDED
 2
 4
 8
 16
 64
 128
 256
 512
 */
 #define PPESCALER_VALUE_AHB           2
 
 
 /* Select Prescaler value for APB1
 Options:
 NOT_DIVIDED
 2
 4
 8
 16
 */
 #define PRESCALER_VALUE_APB1          0
 
 
 /* Select Prescaler value for APB2
 Options:
 NOT_DIVIDED
 2
 4
 8
 16
 */
 #define PRESCALER_VALUE_APB2          0
 
 
 /* Select main PLL clk src
   Options:
   HSI
   HSE */
#define PLL_MAIN_CLK_SRC               HSE 


  
 
 
 #endif