/*
 * TIMER1_private.h
 *
 * Created: 9/30/2023 4:46:10 PM
 *  Author: Khaled AbdLdayem
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A_REG    *((volatile u8*)0x4F)
#define TCCR1B_REG    *((volatile u8*)0x4E)

#define TCNT1_REG     *((volatile u16*)0x4C)
#define OCR1A_REG     *((volatile u16*)0x4A)

#define OCR1B_REG     *((volatile u16*)0x48)
#define ICR1_REG      *((volatile u16*)0x46)

#define TIMSK_REG     *((volatile u8*)0X59)
#define TIFR_REG      *((volatile u8*)0X58)

#endif /* TIMER1_PRIVATE_H_ */