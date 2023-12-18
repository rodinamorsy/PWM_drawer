/*
 * TIMER1_interface.h
 *
 * Created: 9/30/2023 4:45:53 PM
 *  Author: Khaled AbdLdayem
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define BIT_MODE          TEN_BIT
#define EIGHT_BIT         1
#define NINE_BIT          2
#define TEN_BIT           3

#define PWM_MODE          INVERTING
#define INVERTING         1
#define NON_INVERTING     2

#define TIM1_PRESCALER     _64_PRESCALING
#define _TIMER_STOP        0
#define _NO_PRESCALING     1
#define _8_PRESCALING      2
#define _64_PRESCALING     3
#define _256_PRESCALING    4
#define _1024_PRESCALING   5

#define  _RAISINGEDGE  1
#define  _FALLINGEDGE  0


void TIM1_Vid_FastPWM_Init(u8 copy_u8_dutycycle);
void TIM1_Vid_Start(u8 copy_u8_prescaler);
void TIM1_Vid_Stop(void);
u32 TIM1_u32_GetCount(void);
void TIM1_Vid_Set_Count(u16 copy_u16_preload);
u16 TIM1_u16_ICU_GetCount(void);
void TIM1_Vid_ICU_InterruptEnable(void);
void TIM1_Vid_CAPT_SetCallBack(void (*fun)(void));
void TIM1_Vid_ICU_Init(u8 copy_u8_modeid);


#endif /* TIMER1_INTERFACE_H_ */