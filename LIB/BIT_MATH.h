#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(reg,bitno)   (reg |= (1<<bitno))
#define CLR_BIT(reg,bitno)   (reg &= ~(1<<bitno))
#define TOGG_BIT(reg,bitno)  (reg ^= (1<<bitno))
#define GET_BIT(reg,bitno)   ((reg >> bitno)&0x01)


#endif