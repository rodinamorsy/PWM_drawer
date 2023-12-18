/*
 * EXIT_interface.h
 *
 * Created: 09/09/2023 16:22:14
 *  Author: AMIT
 */ 


#ifndef EXIT_INTERFACE_H_
#define EXIT_INTERFACE_H_

/* SENSE control  */

#define  SENSE_CONTROL    RISING_EDGE

#define  RISING_EDGE      0
#define  FALLING_EDGE     1
#define  ANY_LOGIC_CHANGE 2 
#define  LOW_LEVEL        3 
/*****************************************************************************
* Function Name: EXT_Vid_Interrupt_Init()
* Purpose      : INITIALIZATION OF EXTERNAL INTERRUPT
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXT_Vid_Interrupt_Init() ;
/*****************************************************************************
* Function Name: EXT_Vid_Interrupt0() ;
* Purpose      : Enable the interrupt for INT0
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXT_Vid_Interrupt0() ;
/*****************************************************************************
* Function Name: EXT_Vid_Interrupt1() ;
* Purpose      : Enable the interrupt for INT1
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXT_Vid_Interrupt2() ;
/*****************************************************************************
* Function Name: EXT_Vid_Interrupt2() ;
* Purpose      : Enable the interrupt for INT2
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXT_Vid_Interrupt1();
/*****************************************************************************
* Function Name: EXT_Vid_Interrupt0_Disable()
* Purpose      : Disable Enable the interrupt for INT2
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXT_Vid_Interrupt0_Disable();
/*****************************************************************************
* Function Name: EXT_Vid_Interrupt1_Disable()
* Purpose      : Disable the interrupt for INT2
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXT_Vid_Interrupt1_Disable();
/*****************************************************************************
* Function Name: EXT_Vid_Interrupt2_Disable()
* Purpose      : Disable the interrupt for INT2
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXT_Vid_Interrupt2_Disable();

/* SET THE CALL BACK FUNCTION */
void EXT_Vid_Set_Callback1(void(*Fun1)(void));
void EXT_Vid_Set_Callback2(void(*Fun2)(void));
void EXT_Vid_Set_Callback3(void(*Fun3)(void));


#endif /* EXIT_INTERFACE_H_ */