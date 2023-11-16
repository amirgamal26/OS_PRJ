



#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_u8_ADC_CHANNEL_0            0
#define ADC_u8_ADC_CHANNEL_1            1
#define ADC_u8_ADC_CHANNEL_2            2
#define ADC_u8_ADC_CHANNEL_3            3
#define ADC_u8_ADC_CHANNEL_4            4
#define ADC_u8_ADC_CHANNEL_5            5
#define ADC_u8_ADC_CHANNEL_6            6
#define ADC_u8_ADC_CHANNEL_7            7

void ADC_voidInit           (void); // ADC Initialization And Enable
void  ADC_u16GetDigitalValue (u8 Copy_u8ChannelNb,u16 *ptr); // Read From The ADC Channel


#endif /* ADC_INITIALIZATION_H_ */



