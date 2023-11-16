
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

//MACROS FOR PORTS
#define DIO_u8_PORTA   0
#define DIO_u8_PORTB   1
#define DIO_u8_PORTC   2
#define DIO_u8_PORTD   3

//MACROS FOR PINS
#define DIO_u8_PIN0    0
#define DIO_u8_PIN1    1
#define DIO_u8_PIN2    2
#define DIO_u8_PIN3    3
#define DIO_u8_PIN4    4
#define DIO_u8_PIN5    5
#define DIO_u8_PIN6    6
#define DIO_u8_PIN7    7

//MACROS FOR PIN DIRECTION
#define DIO_u8_OUTPUT     1
#define DIO_u8_INPUT      0

//MACROS FOR PIN VALUE
#define DIO_u8_HIGH_VALUE   1
#define DIO_u8_LOW_VALUE   0

//MACROS FOR PORT DIRECTION
#define DIO_u8_PORT_OUTPUT  0xff
#define DIO_u8_PORT_INPUT   0x00

//MACROS FOR PORT MAX VALUE
#define DIO_u8_PORT_MAX     127

void DIO_Init(void);

u8 DIO_u8SetPinDirection (u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinDirection);
u8 DIO_u8SetPinValue     (u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue);
u8 DIO_u8GetPinValue     (u8 copy_u8PortId,u8 copy_u8PinId,u8 *copy_pu8ReturnPinValue);
u8 DIO_u8SetPortDirection(u8 copy_u8PortId,u8 copy_u8PortDirection);
u8 DIO_u8SetPortValue    (u8 copy_u8PortId,u8 copy_u8PortValue); 
u8 DIO_u8GetPortValue    (u8 copy_u8PortId,u8 *copy_pu8ReturnPortValue);



#endif