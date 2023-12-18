/*******************************************
 * DIO_interface.h
 * Created: 8/26/2023 4:17:37 PM
 * Author: Khalid AbdLdayem
 ******************************************/ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/**********************************  MACROS  ********************************************/
/* PORT DIR MACROS */
#define  PORT_OUTPUT     0xff
#define  PORT_INPUT      0x00
/* PORT VAL MACROS */
#define  PORT_HIGH       0xff
#define  PORT_LOW        0x00
/* PIN DIR MACROS */
#define  OUTPUT          1
#define  INPUT           0
/* PIN VAL MACROS */
#define  HIGH            1
#define  LOW             0
/*  PORT   MACROS */
#define  PORTA           0
#define  PORTB           1
#define  PORTC           2
#define  PORTD           3
/*  PINS   MACROS */
#define  PIN0            0
#define  PIN1            1
#define  PIN2            2
#define  PIN3            3
#define  PIN4            4
#define  PIN5            5
#define  PIN6            6
#define  PIN7            7

/**************************************  PROTOTYPES  ********************************************/

/************************************************************************************************
* Function name  : DIO_Vid_Set_Pin_dir
* Purpose        : Set pin direction ( OUTPUT , INPUT )
* Parameters     : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_dir
* Return value   : void
************************************************************************************************/
void DIO_Vid_Set_Pin_dir(u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_dir);
/************************************************************************************************
* Function name  : DIO_Vid_Set_Pin_Val
* Purpose        : Set pin Value ( HIGH , LOW )
* Parameters     : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_dir
* Return value   : void
************************************************************************************************/
void DIO_Vid_Set_Pin_Val(u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_val);
/************************************************************************************************
* Function name  : DIO_Vid_Toggle_Pin_Val
* Purpose        : Toggle pin Value ( HIGH , LOW )
* Parameters     : u8 Copy_u8_port,u8 Copy_u8_pin
* Return value   : void
************************************************************************************************/
void DIO_Vid_Toggle_Pin_Val(u8 Copy_u8_port,u8 Copy_u8_pin);
/************************************************************************************************
* Function name  : DIO_u8_Get_Pin_Val
* Purpose        : Get pin value ( HIGH , LOW )
* Parameters     : u8 Copy_u8_port,u8 Copy_u8_pin
* Return value   : u8
************************************************************************************************/
u8   DIO_u8_Get_Pin_Val (u8 Copy_u8_port,u8 Copy_u8_pin);
/************************************************************************************************
* Function name  : DIO_Vid_Set_Port_dir
* Purpose        : Set port direction ( OUTPUT , INPUT )
* Parameters     : u8 Copy_u8_port,u8 Copy_u8_dir
* Return value   : void
************************************************************************************************/
void DIO_Vid_Set_Port_dir(u8 Copy_u8_port,u8 Copy_u8_dir);
/************************************************************************************************
* Function name  : DIO_Vid_Set_Port_Val
* Purpose        : Set Port Value ( HIGH , LOW )
* Parameters     : u8 Copy_u8_port,u8 Copy_u8_val
* Return value   : void
************************************************************************************************/
void DIO_Vid_Set_Port_Val(u8 Copy_u8_port,u8 Copy_u8_val);
/************************************************************************************************
* Function name  : DIO_Vid_Set_Port_Val
* Purpose        : Set Port Value ( HIGH , LOW )
* Parameters     : u8 Copy_u8_port,u8 Copy_u8_val
* Return value   : void
************************************************************************************************/


#endif /* DIO_INTERFACE_H_ */