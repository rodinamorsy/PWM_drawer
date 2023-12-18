/*
 * DIO_private.h
 *
 * Created: 8/26/2023 4:20:04 PM
 *  Author: Khaled AbdLdayem
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* PORT A ADDRESSES */
#define  PORTA_REG   *((volatile u8*)0x3B)
#define  DDRA_REG    *((volatile u8*)0x3A)
#define  PINA_REG    *((volatile u8*)0x39)
/* PORT B ADDRESSES */
#define  PORTB_REG   *((volatile u8*)0x38)
#define  DDRB_REG    *((volatile u8*)0x37)
#define  PINB_REG    *((volatile u8*)0x36)
/* PORT C ADDRESSES */
#define  PORTC_REG   *((volatile u8*)0x35)
#define  DDRC_REG    *((volatile u8*)0x34)
#define  PINC_REG    *((volatile u8*)0x33)
/* PORT D ADDRESSES */
#define  PORTD_REG   *((volatile u8*)0x32)
#define  DDRD_REG    *((volatile u8*)0x31)
#define  PIND_REG    *((volatile u8*)0x30)





#endif /* DIO_PRIVATE_H_ */