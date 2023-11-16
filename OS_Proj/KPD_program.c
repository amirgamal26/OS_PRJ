
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#define F_CPU  8000000UL
#include<util/delay.h>

#include"DIO_interface.h"

#include "KPD _config.h"
#include "KPD _interface.h"
#include "KPD _private.h"

const u8 KPD_Au8Keys[4][4]=KPD_KEYS;
const u8 KPD_Au8RowsPins[4]={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
const u8 KPD_Au8colsPins[4]={KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};


u8 KPD_u8GetKeyState(u8 *copy_pu8ReturnKey)
{
	u8 local_u8ErrorState=STD_TYPES_OK;
	if(copy_pu8ReturnKey!= NULL)
	{	
		*copy_pu8ReturnKey=KPD_u8_KEY_NOT_PRESSED;
		u8 local_columnid,local_u8PinValue;
		u8 local_rowid;
		/*activation each row */
		for(local_columnid=0;local_columnid<4;local_columnid++)
		{
			DIO_u8SetPinValue(KPD_u8_PORT,KPD_Au8colsPins[local_columnid],DIO_u8_LOW_VALUE);
			/*check which input pin has zero */
			for(local_rowid=0;local_rowid<4;local_rowid++)
			{
				DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8RowsPins[local_rowid],&local_u8PinValue);
				if(local_u8PinValue==DIO_u8_LOW_VALUE)/*switch is pressed*/
				{
					/*debouncing*/
					//					_delay_ms(20);
					//					DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8RowsPins[local_rowid],&local_u8PinValue);
					/*check the bin is still equal low*/
					*copy_pu8ReturnKey=KPD_Au8Keys[local_rowid][local_columnid];
					while(local_u8PinValue==DIO_u8_LOW_VALUE)
					{
						DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8RowsPins[local_rowid],&local_u8PinValue);
					}
						return local_u8ErrorState;

				}
				//deactivate

			}
			DIO_u8SetPinValue(KPD_u8_PORT,KPD_Au8colsPins[local_columnid],DIO_u8_HIGH_VALUE);

		}
	}		
	else
		local_u8ErrorState=STD_TYPES_NOK;
	return local_u8ErrorState;
}
