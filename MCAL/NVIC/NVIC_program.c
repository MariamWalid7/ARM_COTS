/*
 * ***************************************** NVIC_program.c *****************************************
 * Driver : NVIC
 *  Author: maria
 *  Layer: MCAL
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_private.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"

static u8 StaticGlobal_u8_PriorityConfig;



NVIC_errorState NVIC_enumEnableInterrupt(u8 Copy_u8_InterruptNo)
{
	NVIC_errorState LOC_u8_State = OK;

 if ((Copy_u8_InterruptNo >= 0) && ((Copy_u8_InterruptNo <= 31))
		{
	 SET_BIT(NVIC_ISER0, Copy_u8_InterruptNo);
		}

 else if ((Copy_u8_InterruptNo >= 32) && ((Copy_u8_InterruptNo <= 63))
			{
		 SET_BIT(NVIC_ISER1,(Copy_u8_InterruptNo%32));
			}

 else if ((Copy_u8_InterruptNo >= 64) && ((Copy_u8_InterruptNo <= 84))
 			{
 		 SET_BIT(NVIC_ISER2, (Copy_u8_InterruptNo%32));
 			}

 else
	 {
	 LOC_u8_State = NOK;
	 }
 return LOC_u8_State;
}


NVIC_errorState NVIC_enumDisableInterrupt(u8 Copy_u8_InterruptNo)
{

	NVIC_errorState LOC_u8_State = OK;

 if ((Copy_u8_InterruptNo >= 0) && ((Copy_u8_InterruptNo <= 31))
		{
	 CLR_BIT(NVIC_ISER0, Copy_u8_InterruptNo);
		}

 else if ((Copy_u8_InterruptNo >= 32) && ((Copy_u8_InterruptNo <= 63))
			{
		 CLR_BIT(NVIC_ISER1, (Copy_u8_InterruptNo%32));
			}

 else if ((Copy_u8_InterruptNo >= 64) && ((Copy_u8_InterruptNo <= 84))
 			{
 		 CLR_BIT(NVIC_ISER2, (Copy_u8_InterruptNo%32));
 			}

 else
	 {
	 LOC_u8_State = NOK;
	 }

 return LOC_u8_State;
}


NVIC_errorState NVIC_enumSetPendingFlag(u8 Copy_u8_InterruptNo)
{
	NVIC_errorState LOC_u8_State = OK;

 if ((Copy_u8_InterruptNo >= 0) && ((Copy_u8_InterruptNo <= 31))
		{
	 SET_BIT(NVIC_ISPR0, Copy_u8_InterruptNo);
		}

 else if ((Copy_u8_InterruptNo >= 32) && ((Copy_u8_InterruptNo <= 63))
			{
		 SET_BIT(NVIC_ISPR1,(Copy_u8_InterruptNo%32));
			}

 else if ((Copy_u8_InterruptNo >= 64) && ((Copy_u8_InterruptNo <= 84))
 			{
 		 SET_BIT(NVIC_ISPR2, (Copy_u8_InterruptNo%32));
 			}

 else
	 {
	 LOC_u8_State = NOK;
	 }
 return LOC_u8_State;
}


NVIC_errorState NVIC_enumClearPendingFlag   (u8 Copy_u8_InterruptNo)
{
	NVIC_errorState LOC_u8_State = OK;

 if ((Copy_u8_InterruptNo >= 0) && ((Copy_u8_InterruptNo <= 31))
		{
	 CLR_BIT(NVIC_ISPR0, Copy_u8_InterruptNo);
		}

 else if ((Copy_u8_InterruptNo >= 32) && ((Copy_u8_InterruptNo <= 63))
			{
		 CLR_BIT(NVIC_ISPR1, (Copy_u8_InterruptNo%32));
			}

 else if ((Copy_u8_InterruptNo >= 64) && ((Copy_u8_InterruptNo <= 84))
 			{
 		 CLR_BIT(NVIC_ISPR2, (Copy_u8_InterruptNo%32));
 			}

 else
	 {
	 LOC_u8_State = NOK;
	 }

 return LOC_u8_State;

}



void NVIC_voidConfigurePriority(void)
{
u32 LOC_u32_TempRegValue ;

LOC_u32_TempRegValue = ((AIRCR_VECTKEY<<16)|(INTERRUPT_PRIORITY_CONFIG<<8));

SCB_AIRCR = LOC_u32_TempRegValue;

}


void NVIC_voidSetInterruptPriority (u8 Copy_u8_InterruptNo, u8 Copy_u8_GroupID, u8 Copy_u8_SubGroupID)
{
switch(INTERRUPT_PRIORITY_CONFIG)
{
case NVIC_G4_BITS_S0_BITS:
	NVIC_IPR_T -> NVIC_IPRx [Copy_u8_InterruptNo] = (Copy_u8_GroupID<<4);
	break;

case NVIC_G3_BITS_S1_BITS:
	NVIC_IPR_T -> NVIC_IPRx [Copy_u8_InterruptNo] = ((Copy_u8_GroupID<<5)|(Copy_u8_SubGroupID<<4));
	break;

case NVIC_G2_BITS_S2_BITS:
	NVIC_IPR_T -> NVIC_IPRx [Copy_u8_InterruptNo] = ((Copy_u8_GroupID<<6)|(Copy_u8_SubGroupID<<4));
	break;

case NVIC_G1_BITS_S3_BITS:
	NVIC_IPR_T -> NVIC_IPRx [Copy_u8_InterruptNo] = ((Copy_u8_GroupID<<7)|(Copy_u8_SubGroupID<<4));
	break;

case NVIC_G0_BITS_S4_BITS:
	NVIC_IPR_T -> NVIC_IPRx [Copy_u8_InterruptNo] = (Copy_u8_SubGroupID<<4);
	break;

default :
	break;

}


}


