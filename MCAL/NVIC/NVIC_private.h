/*
 * ***************************************** NVIC_private.h *****************************************
 * Driver : NVIC
 *  Author: maria
 *  Layer: MCAL
 */

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H



/******************************* NVIC_registers ******************************/

                   /* NVIC base Address */
#define NVIC_BASE_ADDRESS		0xE000E100


#define NVIC_ISER0    *((volatile u32 *) NVIC_BASE_ADDRESS+0x0)
#define NVIC_ISER1    *((volatile u32 *) NVIC_BASE_ADDRESS+0x4)
#define NVIC_ISER2    *((volatile u32 *) NVIC_BASE_ADDRESS+0x8)


#define NVIC_ICER0    *((volatile u32 *) NVIC_BASE_ADDRESS+0x80)
#define NVIC_ICER0    *((volatile u32 *) NVIC_BASE_ADDRESS+0x84)
#define NVIC_ICER0    *((volatile u32 *) NVIC_BASE_ADDRESS+0x88)


#define NVIC_ISPR0    *((volatile u32 *) NVIC_BASE_ADDRESS+0x100)
#define NVIC_ISPR1    *((volatile u32 *) NVIC_BASE_ADDRESS+0x104)
#define NVIC_ISPR2    *((volatile u32 *) NVIC_BASE_ADDRESS+0x108)


#define NVIC_ICPR0    *((volatile u32 *) NVIC_BASE_ADDRESS+0x180)
#define NVIC_ICPR1    *((volatile u32 *) NVIC_BASE_ADDRESS+0x184)
#define NVIC_ICPR2    *((volatile u32 *) NVIC_BASE_ADDRESS+0x188)


#define NVIC_IABR0    *((volatile u32 *) NVIC_BASE_ADDRESS+0x200)
#define NVIC_IABR1    *((volatile u32 *) NVIC_BASE_ADDRESS+0x204)
#define NVIC_IABR2    *((volatile u32 *) NVIC_BASE_ADDRESS+0x208)


typedef struct {
	volatile u32 IPR[22];
}NVIC_IPR_T;

#define NVIC_IPRx	(( NVIC_IPR_T *) (NVIC_BASE_ADDRESS + 0x300))


#define NVIC_STIR   *((volatile u32 *) NVIC_BASE_ADDRESS+0xD00)


#define SCB_AIRCR   *((volatile u32 *) 0xE000ED0C)



#define AIRCR_VECTKEY             0x5FA

























#endif
