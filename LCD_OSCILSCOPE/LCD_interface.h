/*
 * LCD_interface.h
 *
 * Created: 9/1/2023 5:27:58 PM
 *  Author: Khaled AbdLdayem
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define DATA_LENGTH 4

#define LCD_MODE   FOUR_BIT

#define FOUR_BIT   1
#define _EIGHT_BIT  0

/************************************************************************************************
* Function name  : LCD_Vid_Send_Data
* Purpose        : Send Data to LCD display
* Parameters     : u8 copy_u8_data
* Return value   : void
************************************************************************************************/
void LCD_Vid_Send_Data(u8 copy_u8_data);
/************************************************************************************************
* Function name  : LCD_Vid_Send_Command
* Purpose        : Send Command to LCD display
* Parameters     : u8 copy_u8_command
* Return value   : void
************************************************************************************************/
void LCD_Vid_Send_Command(u8 copy_u8_command);
/************************************************************************************************
* Function name  : LCD_Vid_Init
* Purpose        : Initialize The LCD Display
* Parameters     : void
* Return value   : void
************************************************************************************************/
void LCD_Vid_Init(void);
/************************************************************************************************
* Function name  : LCD_Vid_Send_string
* Purpose        : Send string to the display
* Parameters     : c8 copy_u8_string[]
* Return value   : void
************************************************************************************************/
void LCD_Vid_Send_string(c8 copy_u8_string[]);
/************************************************************************************************
* Function name  : LCD_Vid_Send_Number
* Purpose        : Send Integer number to the display
* Parameters     : c8 u32 copy_u32_number
* Return value   : void
************************************************************************************************/
void LCD_Vid_Send_Number(u32 copy_u32_number);
/************************************************************************************************
* Function name  : LCD_Vid_GOTOXY
* Purpose        : Move the cursor to the wanted location (x,y)
* Parameters     : c8 u8 copy_u8_x,u8 copy_u8_y
* Return value   : void
************************************************************************************************/
void LCD_Vid_GOTOXY(u8 copy_u8_x,u8 copy_u8_y);
/************************************************************************************************
* Function name  : LCD_Vid_draw_data()
* Purpose        : Draw Custom char or symbol on the LCD
* Parameters     : u8 copy_u8_pattern,u8 copy_u8_data,u8 copy_u8_x,u8 copy_u8_y
* Return value   : void
************************************************************************************************/
void LCD_Vid_draw_data(u8 copy_u8_pattern,u8 copy_u8_data[],u8 copy_u8_x,u8 copy_u8_y);
#endif /* LCD_INTERFACE_H_ */