#include "APP_Includes.h"

int main(void){
	
	u8 RecieveData;
	DIO_voidInit();
	LCD_init();
	UART_Init();
	UART_SendString("Enter R | Y | G | F(ALL LEDS) | S(To Stop) : \n\r");
	
	while(1){
		UART_u8Recieve1ByteData(&RecieveData);

		if(RecieveData == 'R'){
			DIO_u8SetPinValue(0, 0, 1);
			DIO_u8SetPinValue(0, 1, 0);
			DIO_u8SetPinValue(0, 2, 0);
			_delay_ms(50);
			LCD_ClearScreen();
			LCD_displayString("Red LED");
		}
		
		else if(RecieveData == 'Y'){
			DIO_u8SetPinValue(0, 1, 1);
			DIO_u8SetPinValue(0, 0, 0);
			DIO_u8SetPinValue(0, 2, 0);
			_delay_ms(50);
			LCD_ClearScreen();
			LCD_displayString("Yellow LED");
		}
		
		else if(RecieveData == 'G'){
			DIO_u8SetPinValue(0, 2, 1);
			DIO_u8SetPinValue(0, 0, 0);
			DIO_u8SetPinValue(0, 1, 0);
			_delay_ms(50);
			LCD_ClearScreen();
			LCD_displayString("Green LED");
		}
		
		else if(RecieveData == 'S'){
			DIO_u8SetPinValue(0, 0, 0);
			DIO_u8SetPinValue(0, 1, 0);
			DIO_u8SetPinValue(0, 2, 0);
			_delay_ms(50);
			LCD_ClearScreen();
			LCD_displayString("Stop");
		}
		
		else if(RecieveData == 'F'){
			DIO_u8SetPinValue(0, 0, 1);
			DIO_u8SetPinValue(0, 1, 1);
			DIO_u8SetPinValue(0, 2, 1);
			_delay_ms(50);
			LCD_ClearScreen();
			LCD_displayString("ALL LEDS");
		}
	}
	return 0;
}
