#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT_NO)     VAR=VAR|(1<<BIT_NO)
#define CLR_BIT(VAR,BIT_NO)     VAR=VAR&(~(1<<BIT_NO))
#define TOGGLE_BIT(VAR,BIT_NO)  VAR=VAR^(1<<BIT_NO)
#define GET_BIT(VAR,BIT_NO)     (1&(VAR>>BIT_NO))
#define ASSIGN_H_NIB(Reg_Value)     Reg=(Reg & 0x0F)|(Value<<4)    
#define ASSIGN_L_NIB(Reg_Value)     Reg =(Reg & 0xF0) | (Value) 
#define GET_H_NIB(Reg)              (Reg&(0xF0))>>4
#define GET_L_NIB(Reg)           	(Reg&(0x0F))

typedef enum{
	DIO_enumOK,
	DIO_enumNOK
}DIO_enumErrorStatus;
typedef enum{
	ADC_enumOK,
	ADC_enumNOK
}ADC_enumErrorStatus;
#define STD_TYPES_u8_ERROR_OK 1
#define STD_TYPES_u8_ERROR_NOK 0
#endif
