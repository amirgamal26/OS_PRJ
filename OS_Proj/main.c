

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD _interface.h"
#include"FreeRTOS.h"
#include "task.h"
/*enum for state*/
typedef enum {
	LCD_STATE_INIT_COMM1,
	LCD_STATE_REST_COMM1,
	LCD_STATE_INIT_COMM2,
	LCD_STATE_REST_COMM2,
	LCD_STATE_INIT_COMM3,
	LCD_STATE_REST_COMM3,
	LCD_STATE_INIT_COMM4,
	LCD_STATE_REST_COMM4,
	LCD_STATE_INIT_COMM5,
	LCD_STATE_REST_COMM5

} LCD_State;

typedef enum {
	LCD_WRITE_STRING1,
	LCD_REST_STRING1

} LCD_STRING;

typedef enum {
	ADC_CLEAR,
	ADC_DISPLAY
} ADC_STATE;
	
	ADC_STATE ADC_S=ADC_CLEAR;

typedef enum {
	LCD_WRITE_char1,
	LCD_REST_char1
} LCD_char;
static u8 ptr_string=0;
/*variable to read tick time to use in adc*/
portTickType read=100;
/*flag for lcd init indicator*/
u8 flag=0;
/*variable to read temp*/
u16 read_temp=0;
xTaskHandle xHandle = NULL;
xTaskHandle xdelete = NULL;
void LCD_Init(void *pv);
void ENTER_PASS(void *pv);

void ADC_TASK(void *pv);

//void ADC_TASK(void *pv);
int main(void)
{
	DIO_Init();
	ADC_voidInit();
	xTaskCreate(LCD_Init,NULL,150,NULL,3,&xHandle);
	xTaskCreate(ADC_TASK,NULL,200,NULL,1,NULL);
	xTaskCreate(ENTER_PASS,NULL,350,NULL,2,&xdelete);
	
	vTaskStartScheduler();
	while(1)
	{
	}
	return 0;
}

void LCD_Init(void *pv)
{
	LCD_State STATE=LCD_STATE_INIT_COMM1;
	LCD_STRING STRING=LCD_WRITE_STRING1;
	while(1)
	{
		if(flag==0)
		{
			switch(STATE)
			{
			case LCD_STATE_INIT_COMM1:
				LCD_vidSendCommand_1(0x02);
				STATE=LCD_STATE_REST_COMM1;
				break;
			case LCD_STATE_REST_COMM1:
				LCD_vidSendCommand_2();
				STATE=LCD_STATE_INIT_COMM2;
				break;
			case LCD_STATE_INIT_COMM2:
				LCD_vidSendCommand_1(0x38);
				STATE=LCD_STATE_REST_COMM2;
				break;
			case LCD_STATE_REST_COMM2:
				LCD_vidSendCommand_2();
				STATE=LCD_STATE_INIT_COMM3;
				break;
			case LCD_STATE_INIT_COMM3:
				LCD_vidSendCommand_1(0x0C);
				STATE=LCD_STATE_REST_COMM3;
				break;
			case LCD_STATE_REST_COMM3:
				LCD_vidSendCommand_2();
				STATE=LCD_STATE_INIT_COMM4;
				break;
			case LCD_STATE_INIT_COMM4:
				LCD_vidSendCommand_1(0x01);
				STATE=LCD_STATE_REST_COMM4;
				break;
			case LCD_STATE_REST_COMM4:
				LCD_vidSendCommand_2();
				STATE=LCD_STATE_INIT_COMM5;
				break;
			case LCD_STATE_INIT_COMM5:
				LCD_vidSendCommand_1(0x06);
				STATE=LCD_STATE_REST_COMM5;
				break;
			case LCD_STATE_REST_COMM5:
				LCD_vidSendCommand_2();

				flag=1;
				break;
			}

		}
		/*if lcd intilized*/
		else if(flag==1)
		{


			/*if string still not equal null*/

			/*switch to which state*/
			switch(STRING)
			{
			/*case:still writing char*/
			case LCD_WRITE_STRING1:
				/*pass flag*/
				LCD_vidWriteString_1("password= ",&ptr_string);
				 if(ptr_string==1)
				{

					if( xHandle != NULL )
					{

						ptr_string=2;
						vTaskDelete( xHandle );
					
					}

				}

				STRING=LCD_REST_STRING1;
				break;
				/*case:display char on lcd*/
			case LCD_REST_STRING1:
				LCD_vidWriteCharctr_2();
				STRING=LCD_WRITE_STRING1;


				break;
			}


		}


		vTaskDelay(30);
	}

}
void ENTER_PASS(void *pv)
{
	LCD_char char_state=LCD_WRITE_char1;
	//	vTaskDelay(200);
	//	ptr_string=0;
	/*make state intilised*/
	LCD_STRING STRING=LCD_WRITE_STRING1;
	//	static u8 key;
	/*static password*/
	 static u8 pass[4]={'1','2','3','4'};
	/*read from keypad*/
	static u8 local_u8Read;
	/*freq used for first delay*/
	portTickType Freq = 100;
	/*array for compare with the password*/
	static u8 arr[4]={0};
	/*iterations*/
	static u8 i=0;
	static u8 j=0;
	while(1)
	{

		
		if(ptr_string==2)
		{
			//			DIO_u8SetPinValue(0,0,1);
			/*take 4 numbers to compare with password*/
			if(i<4)
			{
				/*get pressed key*/
				do 
				{
					KPD_u8GetKeyState(&local_u8Read);
				} while (local_u8Read==0xff);
				
				/*check if the valid number*/
				if(local_u8Read!=0xff)
				{
					
					switch(char_state)
					{
						
						case LCD_WRITE_char1:
					
						LCD_vidWriteCharctr_1(local_u8Read);
						char_state=	LCD_REST_char1;
						vTaskDelay(1);
						case LCD_REST_char1:
						LCD_vidWriteCharctr_2();
						char_state=	LCD_WRITE_char1;
					}
					/*assign to the buffer*/
					arr[i]=local_u8Read;
					/*next element in the buffer*/
					i++;
					
				}
				/*if not valid dont do any thing*/
				else
				{
				
				}
				if(i==4)
				{
					LCD_vidSendCommand_1(0x01);
					vTaskDelay(1);
					LCD_vidSendCommand_2();
				}
			}
			/*if i become more than pass size buffer */
			else
			{
				/*check for pass equal to pressed keys*/
				if(j<4)
				{

					if(arr[j]!=pass[j])
					{

						switch(STRING)
						{
						case LCD_WRITE_STRING1:
							/*pass flag*/
							
							LCD_vidWriteString_1("wrong pass",&ptr_string);
							if(ptr_string==1)
							{
								LCD_vidSendCommand_1(0x01);
								vTaskDelay(1);
								LCD_vidSendCommand_2();
								i=0;
							}
							STRING=LCD_REST_STRING1;
							vTaskDelay(1);
						case LCD_REST_STRING1:
							LCD_vidWriteCharctr_2();
							STRING=LCD_WRITE_STRING1;


							break;
						}
						

					}
					else
					{
						j++;
					}
				}
				else
				{
					
			
					
						switch(STRING)
						{
						case LCD_WRITE_STRING1:
							/*pass flag*/
							
							LCD_vidWriteString_1("CORRECT",&ptr_string);
							if(ptr_string==1)
							{
								/*delete this task*/
								
								if( xdelete != NULL )
								{
									flag=2;
									vTaskDelete( xdelete );
									
								}
							}
							STRING=LCD_REST_STRING1;
							break;
						case LCD_REST_STRING1:
							LCD_vidWriteCharctr_2();
							STRING=LCD_WRITE_STRING1;


							break;
						}
					
				}
			}
			

		}


		//		vTaskDelayUntil(&read,Freq);
		vTaskDelay(70);
	}
}
	

void ADC_TASK(void *pv)
{
	//	portTickType Freq = 50;
	while(1)
	{
		if(flag==2)
		{
			ptr_string=0;
			switch(ADC_S)
			{
				case ADC_CLEAR:
				LCD_vidSendCommand_1(0x01);
				vTaskDelay(1);
				LCD_vidSendCommand_2();
				ADC_S=ADC_DISPLAY;
				break;
				case ADC_DISPLAY:
				LCD_vidWriteString_1("TEMP= ",&ptr_string);
				if(ptr_string==1)
				{
					
					flag=3;
					
				}
				
				vTaskDelay(1);
				LCD_vidWriteCharctr_2();
				ADC_S=ADC_DISPLAY;
				break;
			}
		}
		if(flag==3)
		{
			ADC_u16GetDigitalValue(0,&read_temp);
			read_temp=((read_temp*5000UL)/1024);
			
			
			LCD_VoidSendNumber(read_temp);
			vTaskDelay(1);
			ADC_S=ADC_CLEAR;
			flag=2;
		}
		vTaskDelay(80);
	}

}




