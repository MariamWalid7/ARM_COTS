/*
 * ***************************************** RCC_program.c *****************************************
 *  Driver : RCC
 *  Author: maria
 *  Layer: MCAL
 */
 
 #include "../../LIB/STD_TYPES.h"
 #include "../../LIB/BIT_MATH.h"
 
 #include "RCC_config.h"
 #include "RCC_interface.h"
 #include "RCC_private.h"
 
 /*
 * description: function initializes RCC peripheral 
 * parameters : void
 * return : void
 */
 
void RCC_voidInitSysClc(void)
 {
	#if RCC_CLK_SEL == HSI
		SET_BIT(RCC_CR   , RCC_CR_HSION);
		CLR_BIT(RCC_CFGR , RCC_CFGR_SW0);
		CLR_BIT(RCC_CFGR , RCC_CFGR_SW1);
	
	#elif RCC_CLK_SEL == HSE
		SET_BIT(RCC_CR   , RCC_CR_HSEON);
		SET_BIT(RCC_CFGR , RCC_CFGR_SW0);
		CLR_BIT(RCC_CFGR , RCC_CFGR_SW1);

	
	#elif RCC_CLK_SEL == PLL
	    SET_BIT(RCC_CR   , RCC_CR_PLLON);
		CLR_BIT(RCC_CFGR , RCC_CFGR_SW0);
		SET_BIT(RCC_CFGR , RCC_CFGR_SW1);
		
	#elif RCC_CLK_SEL == LSI
	    SET_BIT(RCC_CSR , RCC_CSR_LSION);
		
	#elif RCC_CLK_SEL == LSE
        SET_BIT(RCC_BDCR , RCC_BDCR_LSEON);	
		  
	
	#else
		#error "Wrong Input"	 
 }
 
 
  /*
 * description:    function enables RCC for each peripheral 
 * parameters :     Copy_u8BusId , Copy_u8PeripheralId
 * return     :     error state
 */
RCC_errorState RCC_enumEnablePerpheralClk (u8 Copy_u8BusId ,u8 Copy_u8PeripheralId)
 {
	 RCC_errorState LOC_enumState = OK;
	 
       switch(Copy_u8BusId)
	   {
		   default: RCC_errorState = NotOk;
		   break;
		   
		   case AHB1:
		   switch (Copy_u8PeripheralId)
		   {
			   default: RCC_errorState = NotOk;
			   break;
			   
			   case copy_u8_AHB1_DMA2EN:
			   SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA2EN);
			   break;
			   
			   case copy_u8_AHB1_DMA1EN:
			   SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA1EN);
			   break;
			   
               case copy_u8_AHB1_CRCREN:
			   SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_CRCREN);
			   break;
			   
               case copy_u8_AHB1_GPIOHEN:
			   SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOHEN);
			   break;
			   
			   case copy_u8_AHB1_GPIOEEN:
			   SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOEEN);
			   break;
			   
			   case copy_u8_AHB1_GPIODEN:
			   SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIODEN);
			   break;
			   
			   case copy_u8_AHB1_GPIOCEN:
			   SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOCEN);
			   break; 

			   case copy_u8_AHB1_GPIOBEN:
			   SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOBEN);
			   break;   
			   
			   case copy_u8_AHB1_GPIOAEN:
			   SET_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOAEN);
			   break;   
		    } break;
             
            case AHB2:
              switch(Copy_u8PeripheralId)
			  {
				  default: RCC_errorState = NotOk;
				  break;
				  
				  case copy_u8_AHB2_OTGFSEN:
				  SET_BIT(RCC_AHB2ENR, RCC_AHB2ENR_OTGFSEN);
			       break; 
			  }	break;		  
			   
			 case APB1:
                switch(Copy_u8PeripheralId) 
				{
					default: RCC_errorState = NotOk;
					break;
					
					case copy_u8_APB1_I2C3EN:
					SET_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C3EN);
					break;
					
				    case copy_u8_APB1_I2C2EN:
					SET_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C2EN);
					break;

                    case copy_u8_APB1_I2C1EN:
					SET_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C1EN);
					break;
					
					case copy_u8_APB1_USART2EN:
					SET_BIT(RCC_APB1ENR, RCC_APB1ENR_USART2EN);
					break;
					
					case copy_u8_APB1_SPI3EN:
					SET_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI3EN);
					break;
					
					case copy_u8_APB1_SPI2EN:
					SET_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI2EN);
					break;
					
					case copy_u8_APB1_WWDGEN:
					SET_BIT(RCC_APB1ENR, RCC_APB1ENR_WWDGEN);
					break;
					
					case copy_u8_APB1_TIM5EN:
					SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM5EN);
					break;
					
					case copy_u8_APB1_TIM4EN:
					SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM4EN);
					break;
                					
					case copy_u8_APB1_TIM3EN:
					SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM3EN);
					break;
					
					case copy_u8_APB1_TIM2EN:
					SET_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM2EN);
					break;	
				} break;

             case APB2:
			  switch(Copy_u8PeripheralId)
			  {
				  default:RCC_errorState = NotOk;
				  break;
				  
				  case copy_u8_APB2_TIM11EN:
				  SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM11EN);
				  break;
				  
				  case copy_u8_APB2_TIM10EN:
				  SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM10EN);
				  break;
				  
				  case copy_u8_APB2_TIM9EN:
				  SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM9EN);
				  break;
				  
				  case copy_u8_APB2_SPI4EN:
				  SET_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI4EN);
				  break;
				  
				  case copy_u8_APB2_SPI1EN:
				  SET_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI1EN);
				  break;
				  
				  case copy_u8_APB2_SDIOEN:
				  SET_BIT(RCC_APB2ENR, RCC_APB2ENR_SDIOEN);
				  break;
				  
				  case copy_u8_APB2_ADC1EN:
				  SET_BIT(RCC_APB2ENR, RCC_APB2ENR_ADC1EN);
				  break;
				  
				  case copy_u8_APB2_USART6EN:
				  SET_BIT(RCC_APB2ENR, RCC_APB2ENR_USART6EN);
				  break;
				  
				  case copy_u8_APB2_USART1EN:
				  SET_BIT(RCC_APB2ENR, RCC_APB2ENR_USART1EN);
				  break;
				  
				  case copy_u8_APB2_TIM1EN:
				  SET_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM1EN);
				  break;
				  
			  } break;
				
			   
		   }
	   
	
 }


  /*
 * description:    function disables RCC for each peripheral 
 * parameters :      Copy_u8BusId , Copy_u8PeripheralId
 * return     :     error state
 */
RCC_errorState RCC_enumDisablePerpheralClk (u8 Copy_u8BusId ,u8 Copy_u8PeripheralId)
 {
	 RCC_errorState LOC_enumState = OK;
	 
       switch(Copy_u8BusId)
	   {
		   default: RCC_errorState = NotOk; 
		   break;
		   
		   case AHB1:
		   switch (Copy_u8PeripheralId)
		   {
			   default: RCC_errorState = NotOk;
			   break;
			   
			   case copy_u8_AHB1_DMA2EN:
			   CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA2EN);
			   break;
			   
			   case copy_u8_AHB1_DMA1EN:
			   CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_DMA1EN);
			   break;
			   
               case copy_u8_AHB1_CRCREN:
			   CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_CRCREN);
			   break;
			   
               case copy_u8_AHB1_GPIOHEN:
			   CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOHEN);
			   break;
			   
			   case copy_u8_AHB1_GPIOEEN:
			   CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOEEN);
			   break;
			   
			   case copy_u8_AHB1_GPIODEN:
			   CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIODEN);
			   break;
			   
			   case copy_u8_AHB1_GPIOCEN:
			   CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOCEN);
			   break; 

			   case copy_u8_AHB1_GPIOBEN:
			   CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOBEN);
			   break;   
			   
			   case copy_u8_AHB1_GPIOAEN:
			   CLR_BIT(RCC_AHB1ENR, RCC_AHB1ENR_GPIOAEN);
			   break;   
		    } break;
             
            case AHB2:
              switch(Copy_u8PeripheralId)
			  {
				  default: RCC_errorState = NotOk;
				  break;
				  
				  case copy_u8_AHB2_OTGFSEN:
				  CLR_BIT(RCC_AHB2ENR, RCC_AHB2ENR_OTGFSEN);
			       break; 
			  }	break;		  
			   
			 case APB1:
                switch(Copy_u8PeripheralId) 
				{
					default: RCC_errorState = NotOk;
					break;
					
					case copy_u8_APB1_I2C3EN:
					CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C3EN);
					break;
					
				    case copy_u8_APB1_I2C2EN:
					CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C2EN);
					break;

                    case copy_u8_APB1_I2C1EN:
					CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_I2C1EN);
					break;
					
					case copy_u8_APB1_USART2EN:
					CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_USART2EN);
					break;
					
					case copy_u8_APB1_SPI3EN:
					CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI3EN);
					break;
					
					case copy_u8_APB1_SPI2EN:
					CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_SPI2EN);
					break;
					
					case copy_u8_APB1_WWDGEN:
					CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_WWDGEN);
					break;
					
					case copy_u8_APB1_TIM5EN:
					CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM5EN);
					break;
					
					case copy_u8_APB1_TIM4EN:
					CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM4EN);
					break;
                					
					case copy_u8_APB1_TIM3EN:
					CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM3EN);
					break;
					
					case copy_u8_APB1_TIM2EN:
					CLR_BIT(RCC_APB1ENR, RCC_APB1ENR_TIM2EN);
					break;	
				} break;

             case APB2:
			  switch(Copy_u8PeripheralId)
			  {
				  default: RCC_errorState = NotOk;
				  break;
				  
				  case copy_u8_APB2_TIM11EN:
				  CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM11EN);
				  break;
				  
				  case copy_u8_APB2_TIM10EN:
				  CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM10EN);
				  break;
				  
				  case copy_u8_APB2_TIM9EN:
				  CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM9EN);
				  break;
				  
				  case copy_u8_APB2_SPI4EN:
				  CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI4EN);
				  break;
				  
				  case copy_u8_APB2_SPI1EN:
				  CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_SPI1EN);
				  break;
				  
				  case copy_u8_APB2_SDIOEN:
				  CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_SDIOEN);
				  break;
				  
				  case copy_u8_APB2_ADC1EN:
				  CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_ADC1EN);
				  break;
				  
				  case copy_u8_APB2_USART6EN:
				  CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_USART6EN);
				  break;
				  
				  case copy_u8_APB2_USART1EN:
				  CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_USART1EN);
				  break;
				  
				  case copy_u8_APB2_TIM1EN:
				  CLR_BIT(RCC_APB2ENR, RCC_APB2ENR_TIM1EN);
				  break;
				  
			  } break;
				
			   
		   }	 
 return LOC_enumState;
 }
 
 
  /*
 * description:    function sets prescaller for AHB 
 * parameters :      void
 * return     :      void
 */ 
 void RCC_voidPrescalerAHB (void)
 {
	  #if PRESCALER_VALUE == NOT_DIVIDED
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE0);
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE1);
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE2);
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE3);
	  
	  #elif PRESCALER_VALUE == 2
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE0);
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE1);
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE2);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE3);

	  #elif PRESCALER_VALUE == 4
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE0);
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE1);
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE2);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE3);
      
      #elif PRESCALER_VALUE == 8
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE0);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE1);
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE2);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE3);

      #elif PRESCALER_VALUE == 16
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE0);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE1);
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE2);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE3);
      
      #elif PRESCALER_VALUE == 64
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE0);
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE1);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE2);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE3);

      #elif PRESCALER_VALUE == 128
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE0);
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE1);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE2);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE3);

      #elif PRESCALER_VALUE == 256
	  CLR_BIT(RCC_CFGR , RCC_CFGR_HPRE0);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE1);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE2);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE3);

      #elif PRESCALER_VALUE == 512
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE0);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE1);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE2);
	  SET_BIT(RCC_CFGR , RCC_CFGR_HPRE3);

      #else
        #error "This prescaler value isn't supported"		   
 }
 
/*
 * description:    function sets prescaler for APB1 
 * parameters :      void
 * return     :      void
 */
void RCC_voidPrescalerAPB1(void)
{
	#if PRESCALER_VALUE_APB1 == NOT_DIVIDED
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE10);
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE11);
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE12);
	
	
	#elif PRESCALER_VALUE_APB1 == 2
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE10);
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE11);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE12);
	
	#elif PRESCALER_VALUE_APB1 == 4
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE10);
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE11);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE12);
	
	#elif PRESCALER_VALUE_APB1 == 8
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE10);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE11);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE12);
	
	#elif PRESCALER_VALUE_APB1 == 16
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE10);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE11);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE12);
	
	#else
		#error "This prescaler value isn't supported"
	
} 


/*
 * description:    function sets prescaler for APB2 
 * parameters :      void
 * return     :      void
 */
void RCC_voidPrescalerAPB2(void)
{
	#if PRESCALER_VALUE_APB2 == NOT_DIVIDED
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE20);
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE21);
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE22);
	
	
	#elif PRESCALER_VALUE_APB2 == 2
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE20);
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE21);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE22);
	
	#elif PRESCALER_VALUE_APB2 == 4
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE20);
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE21);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE22);
	
	#elif PRESCALER_VALUE_APB2 == 8
	CLR_BIT(RCC_CFGR , RCC_CFGR_PPRE20);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE21);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE22);
	
	#elif PRESCALER_VALUE_APB2 == 16
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE20);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE21);
	SET_BIT(RCC_CFGR , RCC_CFGR_PPRE22);
	
	#else
		#error "This prescaler value isn't supported"
	
} 



/*
 * description:    function selects the source clk of main PLL 
 * parameters :      void
 * return     :      void
 */
void RCC_voidConfigureMainPLLSrc(void)
{
	#if PLL_MAIN_CLK_SRC == HSE
	SET_BIT(RCC_PLLCFGR , RCC_PLLCFGR_PLLSRC);
	
	#elif PLL_MAIN_CLK_SRC == HSI
	CLR_BIT(RCC_PLLCFGR , RCC_PLLCFGR_PLLSRC);
	
}







/*
 * description:    function sets prescaler for APB1 
 * parameters :      void
 * return     :      void
 */
void RCC_voidEnableRTC(void)
{
	
 SET_BIT(RCC_BDCR , RCC_BDCR_RTCEN); 
	
}
 
 
 
	
	
 
 
 