/*
 * TIMER0_private.h
 *
 * Created: 9/23/2023 2:39:05 PM
 *  Author: Khaled AbdLdayem
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0_REG  *((volatile u8*)0X53)
#define TCNT0_REG  *((volatile u8*)0X52)
#define OCR0_REG   *((volatile u8*)0X5C)
#define TIMSK_REG  *((volatile u8*)0X59)
#define TIFR_REG   *((volatile u8*)0X58)





#endif /* TIMER0_PRIVATE_H_ */