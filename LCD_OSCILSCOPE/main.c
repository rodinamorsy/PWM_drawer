/*
 * LCD_OSCILSCOPE.c
 *
 * Created: 10/8/2023 8:19:30 AM
 * Author : Khaled AbdLdayem
 */ 

#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER0_interface.h"
#include "Vector_num.h"
#include "EXIT_interface.h"
#define F_CPU 16000000ul
#include <util/delay.h>

/* Global Variables */
u8 duty_cycle = 50 ;
u16 T_ON;
u16 period;
u8 counter = 0;
u8 flag ;
/* Custom Characters */
u8 _HIGH[] = {
	0x1F,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00
};
u8 _LOW[] = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x1F,
	0x1F
};
u8 _HIGH_LOW[] = {
	0x1C,
	0x04,
	0x04,
	0x04,
	0x04,
	0x04,
	0x07,
	0x07
};
u8 _LOW_HIGH[] = {
	0x07,
	0x04,
	0x04,
	0x04,
	0x04,
	0x04,
	0x1C,
	0x1C
};
u8 _Clear[] = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00
};

void INT0_FUN(void)
{
	if(duty_cycle < 100)
	{
		duty_cycle +=10;
		counter = 0;
	}
}
void INT1_FUN(void)
{
	if(duty_cycle > 10)
	{
		duty_cycle -=10;
		counter = 0;
	}
}
void CAPTURE_FUN(void)
{
	counter ++;
	
	if(counter == 1)
	{
		TIM1_Vid_Set_Count(0);
	}
	else if(counter == 2)
	{
		period = TIM1_u16_ICU_GetCount();
		TIM1_Vid_Set_Count(0);
		TIM1_Vid_ICU_Init(_FALLINGEDGE);
		
	}
	else if(counter == 3)
	{
		TIM1_Vid_ICU_Init(_RAISINGEDGE);
		T_ON = TIM1_u16_ICU_GetCount();
		counter=0;
		
	}
}
int main(void)
{
	u8 j;
	/* LCD INIT */
	DIO_Vid_Set_Port_dir(LCD_DPORT,0xf0);
	DIO_Vid_Set_Pin_dir(LCD_CPORT,LCD_RS_PIN,OUTPUT);
	DIO_Vid_Set_Pin_dir(LCD_CPORT,LCD_RW_PIN,OUTPUT);
	DIO_Vid_Set_Pin_dir(LCD_CPORT,LCD_EN_PIN,OUTPUT);
	LCD_Vid_Init();
	
	/* External interrupt mode */
	EXT_Vid_Interrupt_Init();
	EXT_Vid_Interrupt0();
	EXT_Vid_Interrupt1();
	EXT_Vid_Set_Callback1(INT0_FUN);
	EXT_Vid_Set_Callback2(INT1_FUN);
	
	/* TIMER 1 PWM */
	TIM1_Vid_ICU_Init(_RAISINGEDGE);
	TIM1_Vid_ICU_InterruptEnable();
	TIM1_Vid_Start(_1024_PRESCALING);
	TIM1_Vid_CAPT_SetCallBack(CAPTURE_FUN);
	
	/* Dio Pins INIT */
	DIO_Vid_Set_Pin_dir(PORTB,PIN3,OUTPUT);
	DIO_Vid_Set_Pin_dir(PORTD,PIN6,INPUT);
	DIO_Vid_Set_Pin_dir(PORTD,PIN2,INPUT);
	DIO_Vid_Set_Pin_dir(PORTD,PIN3,INPUT);
	
	
    while (1) 
    {
		TIM0_Vid_Fast_PWM(duty_cycle);
		
		LCD_Vid_GOTOXY(0,1);
		LCD_Vid_Send_string("DC=");
		LCD_Vid_Send_Number(duty_cycle);
		LCD_Vid_Send_Data('%');
		
		LCD_Vid_GOTOXY(8,1);
		LCD_Vid_Send_string("Freq=61.34Hz");
		
		LCD_Vid_GOTOXY(21,1);
		LCD_Vid_Send_string("Ton=");
		LCD_Vid_Send_Number(T_ON);
		
		LCD_Vid_GOTOXY(29,1);
		LCD_Vid_Send_string("Toff=");
		LCD_Vid_Send_Number(256-T_ON);
		
		if(duty_cycle == 100)
		{
			LCD_Vid_draw_data(0,_LOW_HIGH,0,0);
			for(u8 z=1;z<39;z++)
			{
				LCD_Vid_draw_data(1,_HIGH,z,0);
			}
			LCD_Vid_draw_data(2,_HIGH_LOW,39,0);
		}
		else if(0 == duty_cycle)
		{
			LCD_Vid_draw_data(2,_HIGH_LOW,0,0);
			for(u8 z=1;z<39;z++)
			{
				LCD_Vid_draw_data(1,_LOW,z,0);
			}
			LCD_Vid_draw_data(0,_LOW_HIGH,39,0);
		}
		else
		{
			for(u8 i=0;i<40;i+=10)
			{
				
				LCD_Vid_draw_data(0,_LOW_HIGH,i,0);
				for(j=i+1;j<(duty_cycle/10)+i;j++)
				{
					LCD_Vid_draw_data(1,_HIGH,j,0);
				}
				LCD_Vid_draw_data(2,_HIGH_LOW,(duty_cycle/10)+i,0);
				for(j=(duty_cycle/10)+i+1;j<10+i;j++)
				{
					LCD_Vid_draw_data(3,_LOW,j,0);
				}
			}
		}
		LCD_Vid_draw_data(4,_Clear,6,1);
		LCD_Vid_draw_data(4,_Clear,27,1);
		LCD_Vid_draw_data(4,_Clear,36,1);
    }
}

