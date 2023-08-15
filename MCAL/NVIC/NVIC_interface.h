/*
 * ***************************************** NVIC_interface.h *****************************************
 * Driver : NVIC
 *  Author: maria
 *  Layer: MCAL
 */

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

typedef enum{
	NOK,
	OK
}NVIC_errorState;


#define NVIC_G4_BITS_S0_BITS           0b000
#define NVIC_G3_BITS_S1_BITS           0b100
#define NVIC_G2_BITS_S2_BITS           0b101
#define NVIC_G1_BITS_S3_BITS           0b110
#define NVIC_G0_BITS_S4_BITS           0b111



/********* functions prototypes ********/
NVIC_errorState NVIC_enumEnableInterrupt    (u8 Copy_u8_InterruptNo);
NVIC_errorState NVIC_enumDisableInterrupt   (u8 Copy_u8_InterruptNo);
NVIC_errorState NVIC_enumSetPendingFlag     (u8 Copy_u8_InterruptNo);
NVIC_errorState NVIC_enumClearPendingFlag   (u8 Copy_u8_InterruptNo);
void NVIC_voidSetInterruptPriority          (u8 Copy_u8_InterruptNo, u8 Copy_u8_GroupID, u8 Copy_u8_SubGroupID);
void NVIC_voidConfigurePriority             (void);






#endif
