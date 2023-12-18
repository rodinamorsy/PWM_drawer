/*
 * DIO_interface.c
 * Created: 8/26/2023 4:18:11 PM
 *  Author: Khalid AbdLdayem
 */ 
/*********************************************************************************
*        FOR FUNCTION DESCRIPTION CHECK " DIO_interface.h "                      *
*********************************************************************************/
/******************************** INCLUDE SECTION *******************************/
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_interface.h"

/********************************************************************************/

void DIO_Vid_Set_Pin_dir(u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_dir)
{
	if(Copy_u8_dir==OUTPUT||Copy_u8_dir==INPUT)
	{
		/*  WRONG INPUT GUARD  */
		if(Copy_u8_dir==OUTPUT)
		{
			/*  SET DIRECTION TO OUTPUT  */
			switch(Copy_u8_port)
			{
				case PORTA : SET_BIT(DDRA_REG,Copy_u8_pin);break;
				case PORTB : SET_BIT(DDRB_REG,Copy_u8_pin);break;
				case PORTC : SET_BIT(DDRC_REG,Copy_u8_pin);break;
				case PORTD : SET_BIT(DDRD_REG,Copy_u8_pin);break;
			}
		}
		else
		{
			/*  SET DIRECTION TO INPUT  */
			switch(Copy_u8_port)
			{
				case PORTA : CLR_BIT(DDRA_REG,Copy_u8_pin);break;
				case PORTB : CLR_BIT(DDRB_REG,Copy_u8_pin);break;
				case PORTC : CLR_BIT(DDRC_REG,Copy_u8_pin);break;
				case PORTD : CLR_BIT(DDRD_REG,Copy_u8_pin);break;
			}
			
		}
		
	}
}

/********************************************************************************/

void DIO_Vid_Set_Pin_Val(u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_val)
{
	if(Copy_u8_val==HIGH||Copy_u8_val==LOW)
	{
		/*  WRONG INPUT GUARD  */
		if(Copy_u8_val==HIGH)
		{
			/*  SET VALUE TO HIGH  */
			switch(Copy_u8_port)
			{
				case PORTA : SET_BIT(PORTA_REG,Copy_u8_pin);break;
				case PORTB : SET_BIT(PORTB_REG,Copy_u8_pin);break;
				case PORTC : SET_BIT(PORTC_REG,Copy_u8_pin);break;
				case PORTD : SET_BIT(PORTD_REG,Copy_u8_pin);break;
			}
		}
	
		else
		{
			/*  SET VALUE TO LOW  */
			switch(Copy_u8_port)
			{
				case PORTA : CLR_BIT(PORTA_REG,Copy_u8_pin);break;
				case PORTB : CLR_BIT(PORTB_REG,Copy_u8_pin);break;
				case PORTC : CLR_BIT(PORTC_REG,Copy_u8_pin);break;
				case PORTD : CLR_BIT(PORTD_REG,Copy_u8_pin);break;
			}
			
		}
		
	}
}
/********************************************************************************/
void DIO_Vid_Toggle_Pin_Val(u8 Copy_u8_port,u8 Copy_u8_pin)
{
	switch(Copy_u8_port)
	{
		case PORTA : TOGGLE_BIT(PORTA_REG,Copy_u8_pin);break;
		case PORTB : TOGGLE_BIT(PORTB_REG,Copy_u8_pin);break;
		case PORTC : TOGGLE_BIT(PORTC_REG,Copy_u8_pin);break;
		case PORTD : TOGGLE_BIT(PORTD_REG,Copy_u8_pin);break;
	}
}
/********************************************************************************/
u8   DIO_u8_Get_Pin_Val (u8 Copy_u8_port,u8 Copy_u8_pin)
{
	u8 LOC_u8_Val=0;
	
	switch(Copy_u8_port)
	{
		case PORTA : LOC_u8_Val = GET_BIT(PINA_REG,Copy_u8_pin);break;
		case PORTB : LOC_u8_Val = GET_BIT(PINB_REG,Copy_u8_pin);break;
		case PORTC : LOC_u8_Val = GET_BIT(PINC_REG,Copy_u8_pin);break;
		case PORTD : LOC_u8_Val = GET_BIT(PIND_REG,Copy_u8_pin);break;
	}
	
	return LOC_u8_Val;
}

/********************************************************************************/

void DIO_Vid_Set_Port_dir(u8 Copy_u8_port,u8 Copy_u8_dir)
{
	/*  SET DIRECTION TO GIVEN NUMBER  */
	switch(Copy_u8_port)
	{
		case PORTA : DDRA_REG=Copy_u8_dir;break;
		case PORTB : DDRB_REG=Copy_u8_dir;break;
		case PORTC : DDRC_REG=Copy_u8_dir;break;
		case PORTD : DDRD_REG=Copy_u8_dir;break;
	}
}

/********************************************************************************/

void DIO_Vid_Set_Port_Val(u8 Copy_u8_port,u8 Copy_u8_val)
{
	/*  SET VALUE TO GIVEN NUMBER  */
	switch(Copy_u8_port)
	{
		case PORTA : PORTA_REG=Copy_u8_val;break;
		case PORTB : PORTB_REG=Copy_u8_val;break;
		case PORTC : PORTC_REG=Copy_u8_val;break;
		case PORTD : PORTD_REG=Copy_u8_val;break;
	}
}