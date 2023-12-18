/*
 * TIMER0_interface.h
 *
 * Created: 9/23/2023 2:38:51 PM
 *  Author: Khaled AbdLdayem
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define _TIMER_STOP        0
#define _NO_PRESCALING     1
#define _8_PRESCALING      2
#define _64_PRESCALING     3
#define _256_PRESCALING    4
#define _1024_PRESCALING   5

#define CTC_MODE   1
#define OVF_MODE   2
#define OCR_VALUE   250



void TIM0_Vid_Delay_Ms(u32 copy_u32_ms);
void TIM0_Vid_Delay_Us(u32 copy_u32_Us);
void TIM0_Vid_Start(u16 copy_u16_prescaler);
void TIM0_Vid_Stop(void);
void TIM0_Vid_OVF_Interrupt_Enable(void);
void TIM0_Vid_CTC_Init(void);
void TIM0_Vid_SetCallback(u8 cop_u8_mode , void(*fun)(void));
void TIM0_Vid_Fast_PWM(u8 copy_u8_dutycycle);





#endif /* TIMER0_INTERFACE_H_ */