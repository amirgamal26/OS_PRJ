
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_configuration.h"

u8 DIO_u8SetPinDirection (u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinDirection)
{
	u8 local_u8ErorrState=STD_TYPES_OK;
	if((copy_u8PortId<=DIO_u8_PORTD) &&(copy_u8PinId<=DIO_u8_PIN7)&&((copy_u8PinDirection==DIO_u8_OUTPUT) ||(copy_u8PinDirection==DIO_u8_INPUT)))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:
			switch(copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRA_REG,copy_u8PinId );
				break;
				case DIO_u8_INPUT:
				CLR_BIT(DIO_u8_DDRA_REG ,copy_u8PinId );
				break;
			}
			break;
	        case DIO_u8_PORTB:
			switch(copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRB_REG,copy_u8PinId );
				break;
				case DIO_u8_INPUT:
				CLR_BIT(DIO_u8_DDRB_REG,copy_u8PinId );
				break;
			}
			break;
			case DIO_u8_PORTC:
			switch(copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRC_REG ,copy_u8PinId );
				break;
				case DIO_u8_INPUT:
				CLR_BIT(DIO_u8_DDRC_REG ,copy_u8PinId );
				break;
			}
			break;
			case DIO_u8_PORTD:
			switch(copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT:
				SET_BIT(DIO_u8_DDRD_REG,copy_u8PinId );
				break;
				case DIO_u8_INPUT:
				CLR_BIT(DIO_u8_DDRD_REG ,copy_u8PinId );
				break;
			}
			break;
		}
	}
	else
		local_u8ErorrState=STD_TYPES_NOK; 
	return local_u8ErorrState;
}
u8 DIO_u8SetPinValue     (u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue)
{
	u8 local_u8ErorrState=STD_TYPES_OK;
	if((copy_u8PortId<=DIO_u8_PORTD) &&(copy_u8PinId<=DIO_u8_PIN7)&&((copy_u8PinValue==DIO_u8_HIGH_VALUE)||(copy_u8PinValue==DIO_u8_LOW_VALUE)))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:
			switch(copy_u8PinValue)
			{
				case DIO_u8_HIGH_VALUE:
				SET_BIT(DIO_u8_PORTA_REG,copy_u8PinId );
				break;
				case DIO_u8_LOW_VALUE:
				CLR_BIT(DIO_u8_PORTA_REG ,copy_u8PinId );
				break;
			}
			break;
			case DIO_u8_PORTB:
			switch(copy_u8PinValue)
			{
				case DIO_u8_HIGH_VALUE:
				SET_BIT(DIO_u8_PORTB_REG,copy_u8PinId );
				break;
				case DIO_u8_LOW_VALUE:
				CLR_BIT(DIO_u8_PORTB_REG ,copy_u8PinId );
				break;
			}
			break;
			case DIO_u8_PORTC:
			switch(copy_u8PinValue)
			{
				case DIO_u8_HIGH_VALUE:
				SET_BIT(DIO_u8_PORTC_REG,copy_u8PinId );
				break;
				case DIO_u8_LOW_VALUE:
				CLR_BIT(DIO_u8_PORTC_REG ,copy_u8PinId );
				break;
			}
			break;
			case DIO_u8_PORTD:
			switch(copy_u8PinValue)
			{
				case DIO_u8_HIGH_VALUE:
				SET_BIT(DIO_u8_PORTD_REG,copy_u8PinId );
				break;
				case DIO_u8_LOW_VALUE:
				CLR_BIT(DIO_u8_PORTD_REG ,copy_u8PinId );
				break;
			}
			break;
     	}
	}
	else
		local_u8ErorrState=STD_TYPES_NOK; 
	return local_u8ErorrState;
}
u8 DIO_u8GetPinValue     (u8 copy_u8PortId,u8 copy_u8PinId,u8 *copy_pu8ReturnPinValue)
{
	u8 local_u8ErorrState=STD_TYPES_OK;
	u8 local_u8PinValue;
	if((copy_u8PortId<=DIO_u8_PORTD)&&(copy_u8PinId<=DIO_u8_PIN7)&&(copy_pu8ReturnPinValue!=NULL))	
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:
			local_u8PinValue=GET_BIT(DIO_u8_PINA_REG,copy_u8PinId);
			if(local_u8PinValue==1)
			{
				*copy_pu8ReturnPinValue=DIO_u8_HIGH_VALUE;
			}
			else
				*copy_pu8ReturnPinValue=DIO_u8_LOW_VALUE;
			break;
	       case DIO_u8_PORTB:
			local_u8PinValue=GET_BIT(DIO_u8_PINB_REG,copy_u8PinId);
			if(local_u8PinValue==1)
			{
				*copy_pu8ReturnPinValue=DIO_u8_HIGH_VALUE;
			}
			else
				*copy_pu8ReturnPinValue=DIO_u8_LOW_VALUE;
			break;
			case DIO_u8_PORTC:
			local_u8PinValue=GET_BIT(DIO_u8_PINC_REG,copy_u8PinId);
			if(local_u8PinValue==1)
			{
				*copy_pu8ReturnPinValue=DIO_u8_HIGH_VALUE;
			}
			else
				*copy_pu8ReturnPinValue=DIO_u8_LOW_VALUE;
			break;
			case DIO_u8_PORTD:
			local_u8PinValue=GET_BIT(DIO_u8_PIND_REG,copy_u8PinId);
			if(local_u8PinValue==1)
			{
				*copy_pu8ReturnPinValue=DIO_u8_HIGH_VALUE;
			}
			else
				*copy_pu8ReturnPinValue=DIO_u8_LOW_VALUE;
			break;
	  }
	}
	else
		local_u8ErorrState=STD_TYPES_NOK; 
	return local_u8ErorrState;
		
}
u8 DIO_u8SetPortDirection(u8 copy_u8PortId,u8 copy_u8PortDirection)
{
	u8 local_u8ErorrState=STD_TYPES_OK;
	if((copy_u8PortDirection<=DIO_u8_PIN7)&&((copy_u8PortDirection==DIO_u8_INPUT)||(copy_u8PortDirection==DIO_u8_OUTPUT )))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:
			switch(copy_u8PortDirection)
			{
				case DIO_u8_INPUT:
				DIO_u8_DDRA_REG=DIO_u8_PORT_INPUT;
				break;
				case DIO_u8_OUTPUT:
				DIO_u8_DDRA_REG=DIO_u8_PORT_OUTPUT;
				break;
			}
			break;
				case DIO_u8_PORTB:
			switch(copy_u8PortDirection)
			{
				case DIO_u8_INPUT:
				DIO_u8_DDRB_REG=DIO_u8_PORT_INPUT;
				break;
				case DIO_u8_OUTPUT:
				DIO_u8_DDRB_REG=DIO_u8_PORT_OUTPUT;
				break;
			}
			break;
				case DIO_u8_PORTC:
			switch(copy_u8PortDirection)
			{
				case DIO_u8_INPUT:
				DIO_u8_DDRC_REG=DIO_u8_PORT_INPUT;
				break;
				case DIO_u8_OUTPUT:
				DIO_u8_DDRC_REG=DIO_u8_PORT_OUTPUT;
				break;
			}
			break;
				case DIO_u8_PORTD:
			switch(copy_u8PortDirection)
			{
				case DIO_u8_INPUT:
				DIO_u8_DDRD_REG=DIO_u8_PORT_INPUT;
				break;
				case DIO_u8_OUTPUT:
				DIO_u8_DDRD_REG=DIO_u8_PORT_OUTPUT;
				break;
			}
			break;
		}
	}
	else{
		local_u8ErorrState=STD_TYPES_NOK;
	}
	return local_u8ErorrState;
	
}
u8 DIO_u8SetPortValue    (u8 copy_u8PortId,u8 copy_u8PortValue)
{
	u8 local_u8ErorrState=STD_TYPES_OK;
	if((copy_u8PortId<=DIO_u8_PORTD)&&(copy_u8PortValue<=DIO_u8_PORT_MAX))
	{
		switch(copy_u8PortId)
		{
		case DIO_u8_PORTA:
		DIO_u8_PORTA_REG=copy_u8PortValue;
		break;
		case DIO_u8_PORTB:
		DIO_u8_PORTB_REG=copy_u8PortValue;
		break;
		case DIO_u8_PORTC:
		DIO_u8_PORTC_REG=copy_u8PortValue;
		break;
		case DIO_u8_PORTD:
		DIO_u8_PORTD_REG=copy_u8PortValue;
		break;
		}
	}
	else
	{
		local_u8ErorrState=STD_TYPES_NOK;
	}
	return local_u8ErorrState;	
}
u8 DIO_u8GetPortValue    (u8 copy_u8PortId,u8 *copy_pu8ReturnPortValue)
{
	u8 local_u8ErorrState=STD_TYPES_OK;
	if((copy_u8PortId<=DIO_u8_PORTD)&&(copy_pu8ReturnPortValue!=NULL))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:
			*copy_pu8ReturnPortValue=DIO_u8_PINA_REG;
			break;
			case DIO_u8_PORTB:
			*copy_pu8ReturnPortValue=DIO_u8_PINB_REG;
			break;
			case DIO_u8_PORTC:
			*copy_pu8ReturnPortValue=DIO_u8_PINC_REG;
			break;
			case DIO_u8_PORTD:
			*copy_pu8ReturnPortValue=DIO_u8_PIND_REG;
			break;
		}
	}
	else
		local_u8ErorrState=STD_TYPES_NOK;
	return local_u8ErorrState;
}


void DIO_Init(void)
{
	/*SET INTIAL DIRECTION AS INPUT*/
	DIO_u8_DDRA_REG=Conc(DIO_u8_PA7_INTIAL_DIRECTION,DIO_u8_PA6_INTIAL_DIRECTION,DIO_u8_PA5_INTIAL_DIRECTION,DIO_u8_PA4_INTIAL_DIRECTION,
						 DIO_u8_PA3_INTIAL_DIRECTION,DIO_u8_PA2_INTIAL_DIRECTION,DIO_u8_PA1_INTIAL_DIRECTION,DIO_u8_PA0_INTIAL_DIRECTION);
	DIO_u8_DDRB_REG=Conc(DIO_u8_PB7_INTIAL_DIRECTION,DIO_u8_PB6_INTIAL_DIRECTION,DIO_u8_PB5_INTIAL_DIRECTION,DIO_u8_PB4_INTIAL_DIRECTION,
						 DIO_u8_PB3_INTIAL_DIRECTION,DIO_u8_PB2_INTIAL_DIRECTION,DIO_u8_PB1_INTIAL_DIRECTION,DIO_u8_PB0_INTIAL_DIRECTION);
	DIO_u8_DDRC_REG=Conc(DIO_u8_PC7_INTIAL_DIRECTION,DIO_u8_PC6_INTIAL_DIRECTION,DIO_u8_PC5_INTIAL_DIRECTION,DIO_u8_PC4_INTIAL_DIRECTION,
						 DIO_u8_PC3_INTIAL_DIRECTION,DIO_u8_PC2_INTIAL_DIRECTION,DIO_u8_PC1_INTIAL_DIRECTION,DIO_u8_PC0_INTIAL_DIRECTION);
	DIO_u8_DDRD_REG=Conc(DIO_u8_PD7_INTIAL_DIRECTION,DIO_u8_PD6_INTIAL_DIRECTION,DIO_u8_PD5_INTIAL_DIRECTION,DIO_u8_PD4_INTIAL_DIRECTION,
						 DIO_u8_PD3_INTIAL_DIRECTION,DIO_u8_PD2_INTIAL_DIRECTION,DIO_u8_PD1_INTIAL_DIRECTION,DIO_u8_PD0_INTIAL_DIRECTION);
	
	/*SET INTIAL VALUE AS INPUT FLOAT*/
	
	DIO_u8_PORTA_REG=Conc(DIO_u8_PA7_INTIAL_VALUE,DIO_u8_PA6_INTIAL_VALUE,DIO_u8_PA5_INTIAL_VALUE,DIO_u8_PA4_INTIAL_VALUE,
						  DIO_u8_PA3_INTIAL_VALUE,DIO_u8_PA2_INTIAL_VALUE,DIO_u8_PA1_INTIAL_VALUE,DIO_u8_PA0_INTIAL_VALUE);
	DIO_u8_PORTB_REG=Conc(DIO_u8_PB7_INTIAL_VALUE,DIO_u8_PB6_INTIAL_VALUE,DIO_u8_PB5_INTIAL_VALUE,DIO_u8_PB4_INTIAL_VALUE,
						  DIO_u8_PB3_INTIAL_VALUE,DIO_u8_PB2_INTIAL_VALUE,DIO_u8_PB1_INTIAL_VALUE,DIO_u8_PB0_INTIAL_VALUE);
	DIO_u8_PORTC_REG=Conc(DIO_u8_PC7_INTIAL_VALUE,DIO_u8_PC6_INTIAL_VALUE,DIO_u8_PC5_INTIAL_VALUE,DIO_u8_PC4_INTIAL_VALUE,
						  DIO_u8_PC3_INTIAL_VALUE,DIO_u8_PC2_INTIAL_VALUE,DIO_u8_PC1_INTIAL_VALUE,DIO_u8_PC0_INTIAL_VALUE);
	DIO_u8_PORTD_REG=Conc(DIO_u8_PD7_INTIAL_VALUE,DIO_u8_PD6_INTIAL_VALUE,DIO_u8_PD5_INTIAL_VALUE,DIO_u8_PD4_INTIAL_VALUE,
						  DIO_u8_PD3_INTIAL_VALUE,DIO_u8_PD2_INTIAL_VALUE,DIO_u8_PD1_INTIAL_VALUE,DIO_u8_PD0_INTIAL_VALUE);	
}









