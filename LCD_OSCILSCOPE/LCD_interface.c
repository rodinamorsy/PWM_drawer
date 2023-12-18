/*
 * LCD_interface.c
 *
 * Created: 9/1/2023 5:28:47 PM
 *  Author: Khaled AbdLdayem
 */ 
#define  F_CPU  16000000ul
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include <util/delay.h>
/*=======================================================================================================*/
static void SHData(u8 copy_u8_data)
{
	u8 Loc_u8_LCD_PIN[4]={LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN};
	u8 Loc_u8_in=0;
	for(Loc_u8_in=0;Loc_u8_in<DATA_LENGTH;Loc_u8_in++)
	{
		DIO_Vid_Set_Pin_Val(LCD_DPORT,Loc_u8_LCD_PIN[Loc_u8_in],GET_BIT(copy_u8_data,Loc_u8_in));
	}
}
static void Send_Enable(void)
{
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_EN_PIN,LOW);
}
/*=======================================================================================================*/
void LCD_Vid_Send_Command(u8 copy_u8_command)
{
	/* SET RS PIN --> LOW TO PUT COMMAND */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RS_PIN,LOW);
	/* SET RW PIN --> LOW TO WRITE IN LCD */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RW_PIN,LOW);
	/*======================================= 4 BIT MODE =======================================*/
	#if LCD_MODE == FOUR_BIT
	/* SEND HIGH NIBBLE OF COMMAND */
	SHData(copy_u8_command>>4);
	Send_Enable();
	/* SEND LOW NIBBLE OF COMMAND */
	SHData(copy_u8_command);
	Send_Enable();
	/*======================================= 8 BIT MODE =======================================*/
	#elif LCD_MODE == EIGHT_BIT
	/* SEND COMMAND TO LCD */
	DIO_Vid_Set_Port_Val(LCD_DPORT,copy_u8_command);
	/* Send Enable Pulse */
	Send_Enable();
	#endif
}
void LCD_Vid_Send_Data(u8 copy_u8_data)
{
	/* SET RS PIN --> HIGH TO PUT DATA */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RS_PIN,HIGH);
	/* SET RW PIN --> LOW TO WRITE IN LCD */	
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RW_PIN,LOW);
	/*======================================= 4 BIT MODE =======================================*/
	#if LCD_MODE == FOUR_BIT
	/* SEND HIGH NIBBLE OF DATA */
	SHData(copy_u8_data>>4);
	Send_Enable();
	/* SEND LOW NIBBLE OF DATA */
	SHData(copy_u8_data);
	Send_Enable();
	/*======================================= 8 BIT MODE =======================================*/
	#elif LCD_MODE == EIGHT_BIT
	/* SEND DATA TO LCD */
	DIO_Vid_Set_Port_Val(LCD_DPORT,copy_u8_data);
	/* Send Enable Pulse */
	Send_Enable();
	#endif
}
void LCD_Vid_Init(void)
{
	_delay_ms(40);
	/*======================================= 4 BIT MODE =======================================*/
	#if LCD_MODE == FOUR_BIT
	/* Send Function Set (N->1 enable 2 Lines && F->0 font 5*7 pixel) */
	SHData(0b0010);
	Send_Enable();
	SHData(0b0010);
	Send_Enable();
	SHData(0b1000);
	Send_Enable();
	/*======================================= 8 BIT MODE =======================================*/
	#elif LCD_MODE == EIGHT_BIT
	/* Send Function Set (N->1 enable 2 Lines && F->0 font 5*7 pixel) */
	LCD_Vid_Send_Command(0b00111000);
	#endif
	
	/* Display on/off command */
	LCD_Vid_Send_Command(0b00001100);
	/* Display Clear Command */
	LCD_Vid_Send_Command(0x01);

}
void LCD_Vid_Send_string(c8 copy_u8_string[])
{
	u8 Loc_u8_itr=0;
	while(copy_u8_string[Loc_u8_itr]!='\0')
	{
		/* Send the String as indvidual characters */
		LCD_Vid_Send_Data(copy_u8_string[Loc_u8_itr]);
		Loc_u8_itr++;
	}
}
void LCD_Vid_Send_Number(u32 copy_u32_number)
{
	s8 Loc_s8_counter=0;
	u8 Loc_u8_num_string[16];
	u8 Loc_u8_digit=0;
	if(copy_u32_number==0)
	{
		/* If the Number already = 0 display it */
		LCD_Vid_Send_Data(0+'0');
	}
	while(copy_u32_number!=0)
	{
		/* Convert the integar to array of digits */
		/* Get the right most digit */
		Loc_u8_digit=(copy_u32_number%10); 
		/* Adding the digit to the array plus ASCII of 0 to convert it to Char */
		Loc_u8_num_string[Loc_s8_counter]=Loc_u8_digit+'0'; 
		Loc_s8_counter++;
		/* Removing the digit after adding it to the array */
		copy_u32_number/=10;
	}
	Loc_s8_counter-=1;
	while(Loc_s8_counter>=0)
	{
		/* Passing the array backwards to have the right coordiation on the LCD */
		LCD_Vid_Send_Data(Loc_u8_num_string[Loc_s8_counter]);
		Loc_s8_counter--;
	}
}
void LCD_Vid_GOTOXY(u8 copy_u8_x,u8 copy_u8_y)
{
	u8 Loc_u8_AddDDRAM=0;
	Loc_u8_AddDDRAM = copy_u8_x + (copy_u8_y * 0x40);
	/* Set DDRAM address (Data Sheet) */
	SET_BIT(Loc_u8_AddDDRAM,7);
	LCD_Vid_Send_Command(Loc_u8_AddDDRAM);
}
void LCD_Vid_draw_data(u8 copy_u8_pattern,u8 copy_u8_data[],u8 copy_u8_x,u8 copy_u8_y)
{
	u8 Loc_u8_itr;
	/* Get the CGRAM pattern address */
	u8 Locd_u8_AddCGRAM=copy_u8_pattern*8;
	/* Set CGRAM (Data Sheet) */
	CLR_BIT(Locd_u8_AddCGRAM,7);
	SET_BIT(Locd_u8_AddCGRAM,6);
	LCD_Vid_Send_Command(Locd_u8_AddCGRAM);
	/* Draw Data in CGRAM */
	for(Loc_u8_itr=0 ; Loc_u8_itr<8 ; Loc_u8_itr++)
	{
		LCD_Vid_Send_Data(copy_u8_data[Loc_u8_itr]);
	}
	/* SET DDRAM to display on x,y  */
	LCD_Vid_GOTOXY(copy_u8_x,copy_u8_y);
	/* Print the data from ddram */
	LCD_Vid_Send_Data(copy_u8_pattern);
}

