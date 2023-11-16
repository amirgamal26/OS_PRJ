
/***************************************************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A                                   */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/

#ifndef LCD_H_
#define LCD_H_

/***************************************************************************************/
/********************************** Function Definition ********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand_1(u8 u8CmdCpy);
void LCD_vidSendCommand_2(void);

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr_1(u8 u8DataCpy);
void LCD_vidWriteCharctr_2(void);

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString_1 (u8* pu8StringCpy,u8 *pu8StringCpy_2);
/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidGotoxy (u8 Y,u8 X);
/***************************************************************************************/
/* Description! Interface to write extra characters saved in the CGRAM                 */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteExtraChar (u8 Y,u8 X);
/***************************************************************************************/
/* Description! Interface to write a number on LCD as a string                         */
/* Input      ! Copy_u16Number = Number needs to be written on the LCD                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_VoidSendNumber(u16 copy_u32Number);

#endif /* LCD_H_ */
