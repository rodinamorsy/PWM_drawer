/*
 * TIMER1_interface.c
 *
 * Created: 9/30/2023 4:45:37 PM
 *  Author: Khaled AbdLdayem
 */ 
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "GIE_interface.h"
#include "Vector_num.h"

void (*TIM1_1_CAPT)(void);


void TIM1_Vid_Start(u8 copy_u8_prescaler)
{
	TCCR1B_REG &= 0b11111000;
	TCCR1B_REG |= copy_u8_prescaler;
}
void TIM1_Vid_Stop(void)
{
	TCCR1B_REG | 0x00;
}
u32 TIM1_u32_GetCount(void)
{
	return TCNT1_REG;
}
void TIM1_Vid_Set_Count(u16 copy_u16_preload)
{
	TCNT1_REG = 0x00;
}
void TIM1_Vid_FastPWM_Init(u8 copy_u8_dutycycle)
{
	/* SETTING RESLOUTION BIT MODE */
	#if BIT_MODE == EIGHT_BIT
		SET_BIT(TCCR1A_REG,0);
		CLR_BIT(TCCR1A_REG,1);
		SET_BIT(TCCR1B_REG,3);
		CLR_BIT(TCCR1B_REG,4);
		OCR1A_REG = copy_u8_dutycycle*2.65;
		OCR1B_REG = copy_u8_dutycycle*2.65;
	#elif BIT_MODE == NINE_BIT
		CLR_BIT(TCCR1A_REG,0);
		SET_BIT(TCCR1A_REG,1);
		SET_BIT(TCCR1B_REG,3);
		CLR_BIT(TCCR1B_REG,4);
		OCR1A_REG = copy_u8_dutycycle*5.11;
		OCR1B_REG = copy_u8_dutycycle*5.11;
	#elif BIT_MODE == TEN_BIT
		SET_BIT(TCCR1A_REG,0);
		SET_BIT(TCCR1A_REG,1);
		SET_BIT(TCCR1B_REG,3);
		CLR_BIT(TCCR1B_REG,4);
		OCR1A_REG = copy_u8_dutycycle*10.23;
		OCR1B_REG = copy_u8_dutycycle*10.23;
	#endif
	/* SETTING PWM MODE */
	#if PWM_MODE == INVERTING
		SET_BIT(TCCR1A_REG,5);
		SET_BIT(TCCR1A_REG,7);
		SET_BIT(TCCR1A_REG,4);
		SET_BIT(TCCR1A_REG,6);
	#elif PWM_MODE == NON_INVERTING
		SET_BIT(TCCR1A_REG,5);
		SET_BIT(TCCR1A_REG,7);
		CLR_BIT(TCCR1A_REG,4);
		CLR_BIT(TCCR1A_REG,6);
	#endif
	
	/* Clear the First 3 bits */
	TCCR1B_REG &= 0b11111000;
	/* Set the pre scaler */
	TCCR1B_REG |= TIM1_PRESCALER;
	
	while(GET_BIT(TIFR_REG,4)==0);
	SET_BIT(TIFR_REG,4);
	
}
void TIM1_Vid_ICU_Init(u8 copy_u8_mode)
{
	if (copy_u8_mode == _FALLINGEDGE)
	{
		CLR_BIT(TCCR1B_REG,6);

	}
	else if (copy_u8_mode == _RAISINGEDGE)
	{
		SET_BIT(TCCR1B_REG,6);
	}
}
u16 TIM1_u16_ICU_GetCount(void)
{
	return ICR1_REG;
}
void TIM1_Vid_ICU_InterruptEnable(void)
{
	GIE_Vid_Enable();
	SET_BIT(TIMSK_REG,5);
}
void TIM1_Vid_CAPT_SetCallBack(void (*fun)(void))
{
	TIM1_1_CAPT = fun;
}
ISR(TIM1_CAPT)
{
	TIM1_1_CAPT();
}