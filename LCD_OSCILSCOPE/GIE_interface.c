
#include "BIT_MATH.h" 
#include "STD_TYPE.h"
#include "GIE_private.h" 

void GIE_Vid_Enable(){
	
	SET_BIT(SREG_REG,7) ; 
   
   //  volatile __asm("SEI") ; 
	 
}
void GIE_Vid_Disable(){
	
	CLR_BIT(SREG_REG,7) ; 
	//  volatile __asm("CLI") ; 
}