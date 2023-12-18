/*
 * TIMER0_interface.c
 *
 * Created: 9/23/2023 2:38:33 PM
 *  Author: Khaled AbdLdayem
 */ 
#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "Vector_num.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"
#include "GIE_interface.h"


void(*TIM0_ISR_OVF)(void)=0;
void(*TIM0_ISR_CTC)(void)=0;
void TIM0_Vid_Delay_Ms(u32 copy_u32_ms)
{
	u32 count=0;
	u32 Loc_u32_DT = copy_u32_ms/1.024;
	while(count<Loc_u32_DT)
	{
		TCCR0_REG=0x03;
		count++;
		while(GET_BIT(TIFR_REG,0)==0);
		SET_BIT(TIFR_REG,0);
		
	}
	TCCR0_REG=0x00;
}
void TIM0_Vid_Delay_Us(u32 copy_u32_Us)
{
	u32 count=0;
	u32 Loc_u32_DT = (copy_u32_Us/1000)/0.000016;
	while(count<Loc_u32_DT)
	{
		TCCR0_REG=0x01;
		count++;
		while(GET_BIT(TIFR_REG,0)==0);
		SET_BIT(TIFR_REG,0);
		
	}
	TCCR0_REG=0x00;
}
void TIM0_Vid_Start(u16 copy_u16_prescaler)
{
	/* Clear the First 3 bits */
	TCCR0_REG &= 0xF8;
	/* Set the pre-scaler */
	TCCR0_REG |= copy_u16_prescaler;
}
void TIM0_Vid_Stop(void)
{
	/* Disable the timer */
	TCCR0_REG = 0x00;
}
void TIM0_Vid_OVF_Interrupt_Enable(void)
{
	/* Enable Global interrupt */
	GIE_Vid_Enable();
	/* Enable PIE */
	SET_BIT(TIMSK_REG,0);
}
void TIM0_Vid_SetCallback(u8 cop_u8_mode , void(*fun)(void))
{
	if(cop_u8_mode == CTC_MODE)
	{
		TIM0_ISR_CTC=fun;
	}
	else if(cop_u8_mode == OVF_MODE)
	{
		TIM0_ISR_OVF=fun;
	}
}
void TIM0_Vid_CTC_Init(void)
{
	/* Select CTC mode */
	SET_BIT(TCCR0_REG,3);
	CLR_BIT(TCCR0_REG,6);
	
	/* SET OCR VALUE */
	OCR0_REG = OCR_VALUE;

	/* Enable Global interrupt */
	GIE_Vid_Enable();
	/* Enable PIE */
	SET_BIT(TIMSK_REG,1);
}
void TIM0_Vid_Fast_PWM(u8 copy_u8_dutycycle)
{
	
	TIM0_Vid_Start(_1024_PRESCALING);
	/* Select PWM mode */
	SET_BIT(TCCR0_REG,3);
	SET_BIT(TCCR0_REG,6);
	CLR_BIT(TCCR0_REG,4);
	SET_BIT(TCCR0_REG,5);
	/* Set OCR VALUE */
	OCR0_REG = copy_u8_dutycycle*2.56;
	
	while(GET_BIT(TIFR_REG,1)==0);
	SET_BIT(TIFR_REG,1);
}

ISR(TIM0_OVF)
{
	TIM0_ISR_OVF();
}

ISR(TIM0_CTC)
{
	TIM0_ISR_CTC();
}

