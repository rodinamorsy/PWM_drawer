/*
 * EXIT_interface.c
 *
 * Created: 09/09/2023 16:21:35
 *  Author: AMIT
 */ 
#include "BIT_MATH.h" 
#include "STD_TYPE.h" 
#include "EXIT_interface.h"
#include "EXIT_private.h" 
#include "GIE_interface.h"  
#include "DIO_interface.h"
/* CALL BACK FUNCTION POINTER FOR CALLING IN ISR */
void (*INT_1_FUN)(void);
void (*INT_2_FUN)(void);
void (*INT_3_FUN)(void);

void EXT_Vid_Interrupt_Init() {
/*======================================== LOW LEVEL SENSING =======================================================*/	
	#if SENSE_CONTROL == LOW_LEVEL 
	     /* INT1  */
	     CLR_BIT(MCUCR_REG,ISC11) ; 
		 CLR_BIT(MCUCR_REG,ISC10) ;
		 /* INT0*/
		 CLR_BIT(MCUCR_REG,ISC01) ;
		 CLR_BIT(MCUCR_REG,ISC00) ;
/*======================================== ANY_LOGIC_CHANGE SENSING =======================================================*/		 
    #elif SENSE_CONTROL == ANY_LOGIC_CHANGE 
	     /* INT1  */
	     CLR_BIT(MCUCR_REG,ISC11) ;
	     SET_BIT(MCUCR_REG,ISC10) ;
	     /* INT0*/
	     CLR_BIT(MCUCR_REG,ISC01) ;
	     SET_BIT(MCUCR_REG,ISC00) ;
/*======================================== FALLING_EDGE SENSING =======================================================*/
	#elif SENSE_CONTROL == FALLING_EDGE
		  /* INT1  */
		  SET_BIT(MCUCR_REG,ISC11) ;
		  CLR_BIT(MCUCR_REG,ISC10) ;
		  /* INT0*/
		  SET_BIT(MCUCR_REG,ISC01) ;
		  CLR_BIT(MCUCR_REG,ISC00) ;
		  /* INT2*/
		  CLR_BIT(MCUCSR_REG,ISC2)  ;
/*======================================== RISING_EDGE SENSING =======================================================*/
	#elif SENSE_CONTROL==RISING_EDGE
	      /* INT1  */
	      SET_BIT(MCUCR_REG,ISC11) ;
	      SET_BIT(MCUCR_REG,ISC10) ;
	      /* INT0*/
	      SET_BIT(MCUCR_REG,ISC01) ;
	      SET_BIT(MCUCR_REG,ISC00) ;
	      /* INT2*/
	      SET_BIT(MCUCSR_REG,ISC2)  ;
/*======================================== INT2 ONLY WORK WITH RISING AND FALLING EDGE ===============================*/
	 #endif
}
/*================================================EXT INT ENABLE================================================*/
void EXT_Vid_Interrupt0(){
	/* enable global interrupt */
	GIE_Vid_Enable(); 
	/*enable INT0 */
	SET_BIT(GICR_REG,INT_0) ; 
}
void EXT_Vid_Interrupt1(){
	/* enable global interrupt */
	GIE_Vid_Enable();
	/*enable INT0 */
	SET_BIT(GICR_REG,INT_1) ;
}
void EXT_Vid_Interrupt2(){
	/* enable global interrupt */
	GIE_Vid_Enable();
	/*enable INT0 */
	SET_BIT(GICR_REG,INT_2) ;
}
/*================================================EXT INT DISABLE================================================*/
void EXT_Vid_Interrupt0_Disable(){
	/* enable global interrupt */
	GIE_Vid_Enable();
	/*Disable INT0 */
	CLR_BIT(GICR_REG,INT_0) ;
}
void EXT_Vid_Interrupt1_Disable(){
	/* enable global interrupt */
	GIE_Vid_Enable();
	/*Disable INT0 */
	CLR_BIT(GICR_REG,INT_1) ;
}
void EXT_Vid_Interrupt2_Disable(){
	/* enable global interrupt */
	GIE_Vid_Enable();
	/*Disable INT0 */
	CLR_BIT(GICR_REG,INT_2) ;
}
/*===================================================================================================================*/
/* ISR for INT0 */
void  __vector_1(void)__attribute__((signal));
void __vector_1(void){
	INT_1_FUN();
}

/* ISR for INT1 */
void  __vector_2(void)__attribute__((signal));
void __vector_2(void){
	INT_2_FUN();
}
/* ISR for INT2 */
void  __vector_3(void)__attribute__((signal));
void __vector_3(void){
	INT_3_FUN();
}
/*===================================================================================================================*/
/* Set Call back function */

void EXT_Vid_Set_Callback1(void(*Fun1)(void))
{
	INT_1_FUN=Fun1;
}
void EXT_Vid_Set_Callback2(void(*Fun2)(void))
{
	INT_2_FUN=Fun2;
}
void EXT_Vid_Set_Callback3(void(*Fun3)(void))
{
	INT_3_FUN=Fun3;
}