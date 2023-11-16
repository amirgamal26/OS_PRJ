

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "LCD_interface.h"
//#include "LCD_Extra.h"
#include "LCD_config.h"
/***************************************************************************************/

/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PA2|---------------->|E         |
 |        PA1|---------------->|RW        |
 |        PA0|---------------->|RS        |
 -----------                   ----------
 */

/***************************************************************************************/
/********************************** Function Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

/***************************************************************************************/
/********************************** Constant Variables *********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
//void LCD_vidInit(void)
//{
//
//
//	/* Delay 30ms to ensure the initialization of the LCD driver */
//	_delay_ms(30);
//
//	/* Return Home  */
//	LCD_vidSendCommand_1(lcd_Home);
//	_delay_ms(15);
//
//	/* Function Set  */
//	LCD_vidSendCommand_1(lcd_FunctionSet8bit);
//	_delay_ms(1);
//
//	/* Display ON OFF Control */
//	LCD_vidSendCommand_1(lcd_DisplayOn);
//	_delay_ms(1);
//
//	/* Clear Display */
//	LCD_vidSendCommand_1(lcd_Clear);
//	_delay_ms(15);
//
//	/* Entry Mode Set  */
//	LCD_vidSendCommand_1(lcd_EntryMode);
//	_delay_ms(2);
//
//}


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand_1(u8 u8CmdCpy)
{

	/* Set RS to LOW */
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8_LOW_VALUE);

	/* Set R/W to LOW */
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8_LOW_VALUE);

	/* Set E to HIGH  */
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_HIGH_VALUE);

	/* Load Command on Data bus */
	DIO_u8SetPortValue(LCD_DATA_PORT, u8CmdCpy);

	/* Set E to LOW */
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_LOW_VALUE);

	////* wait for e to settle */
	///_delay_ms(1);
   ///
	////* set e to high */
	///dio_voidsetpinvalue(lcd_control_port, lcd_e_pin, dio_u8_high_value);
   ///
	////* delay for 1ms to let the lcd execute command */
	//_delay_ms(1);
   
}
void LCD_vidSendCommand_2(void)
{
	/* Set E to HIGH */
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_HIGH_VALUE);
}
/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr_1(u8 u8DataCpy)
{
	/* Set RS to High */
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8_HIGH_VALUE);

	/* Set R/W to LOW */
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8_LOW_VALUE);

	/* Set E to HIGH  */
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_HIGH_VALUE);

	/* Load Command on Data bus */
	DIO_u8SetPortValue(LCD_DATA_PORT, u8DataCpy);

	/* Set E to LOW */
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_LOW_VALUE);

//	/* Wait for E to settle */
//	_delay_ms(1);
//
//	/* Set E to HIGH */
//	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_HIGH_VALUE);
//
//	/* Delay to let the LCD Display the character */
//	_delay_ms(1);

}
void LCD_vidWriteCharctr_2(void)
{
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_HIGH_VALUE);
}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString_1 (u8* pu8StringCpy,u8 *pu8StringCpy_2)
{

	//	/* Local loop index */
	//	u8 u8Index = 0;
//	*pu8StringCpy_2=pu8StringCpy;
	static u8 iteration=0;
	//	while (pu8StringCpy[u8Index] != '\0')
	for (; pu8StringCpy[iteration]!= '\0' ; )
	{

		/* Write Character on LCD */
		LCD_vidWriteCharctr_1(pu8StringCpy[iteration]);
		iteration++;
//		pu8StringCpy_2++;
		break;
		//		/* Increment local loop index */
		//		u8Index++;

//		/* Delay to let the LCD show the character */
//		_delay_ms(2);
	}
	if(pu8StringCpy[iteration]=='\0')
	{
		iteration=0;
		*pu8StringCpy_2=1;
	}

}

/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidGotoxy (u8 Y,u8 X)
{
	if (X>=0 && X<16)
	{
		u8 local_u8Address;

	/* first of all calculate the required address */
	switch(Y)
	{
	case 0:
		local_u8Address=X;     // ADDRESS OF THE FIRST LINE COMMAND(0x80)
		break;
	case 1:
		local_u8Address=X+0x40;
		break; //address 0x40 (command 0xC0) sets the address to the beginning of the second line
	case 2:
		local_u8Address=X+0x10;
		break;
	case 3:
		local_u8Address=X+0x50;
		break;
	}
	/* to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_vidSendCommand_1(local_u8Address | 0x80); 
	
	}
}

/***************************************************************************************/
/* Description! Interface to write extra characters saved in the CGRAM                 */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
//void LCD_vidWriteExtraChar (u8 Y,u8 X)
//{
//	u8 iteration1,iteration2;
//
//	/*DDRAM-->CGRAM*/
//	LCD_vidSendCommand(64);
//	for(iteration1=0 ; iteration1<64 ; iteration1++)
//	{
//		LCD_vidWriteCharctr(ExtraChar[iteration1]);
//	}
//	/*CGRAM-->DDRAM*/
//	LCD_vidSendCommand(128);
//	LCD_vidGotoxy(Y,X);
//	/*First eight character which saved at CGRAM*/
//	for (iteration2=0; iteration2<=7 ; iteration2++)
//	{
//		/* Write bytes of DDRAM */
//		LCD_vidWriteCharctr(iteration2);
//
//		_delay_ms(5);
//	}
//}
void LCD_VoidSendNumber(u16 copy_u32Number)
{
	u16 local_u32Rev=0;
	u16 local_u32Temp=0;
	while(copy_u32Number!=0)
	{
		local_u32Rev=((local_u32Rev*10)+(copy_u32Number%10));
		copy_u32Number=copy_u32Number/10;
	}
	while(local_u32Rev!=0)
	{
		local_u32Temp=local_u32Rev%10;
		LCD_vidWriteCharctr_1(local_u32Temp+48);
		vTaskDelay(1);
		LCD_vidWriteCharctr_2();
		local_u32Rev/=10;

	}

}

