#ifndef _MATH_H_
#define _MATH_H_
#define SET_BIT(REG,BIT) REG |=(1<<BIT)         //set bit in register
#define TOGGLE_BIT(REG,BIT) REG ^= (1<<BIT)     //toggle bit in register
#define CLR_BIT(REG,BIT) REG &= (~(1<<BIT))   //clear bit in register
#define GET_BIT(REG,BIT) ((REG>>BIT)&0x01)      //get bit value in register
#endif