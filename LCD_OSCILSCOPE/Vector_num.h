#ifndef _VECTOR_NUM_H
#define _VECTOR_NUM_H

#define ISR(__vector_num)    void  __vector_num(void)__attribute__((signal));\
                             void __vector_num(void)

#define INT_0     __vector_1
#define INT_1     __vector_2
#define INT_2     __vector_3
#define ADC_      __vector_16
#define TIM0_OVF  __vector_11
#define TIM0_CTC  __vector_10
#define TIM1_CAPT __vector_6

#endif /* _VECTOR_NUM_H */