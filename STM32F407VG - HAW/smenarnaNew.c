/* Defining amount of keypad rows and columns */
#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

/* Including necessary libraries */
#include "stm32_kit.h"
#include "stm32_kit/lcd.h"
#include "stm32_kit/keypad.h"
#include "stm32_kit/led.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* An array that represents keypad layout */
#ifndef KeyPad_KeyMap
		static uint8_t KeyPad_KeyMap[KEYPAD_ROWS][KEYPAD_COLS] = {
				'1','2','3','A',
				'4','5','6','B',
				'7','8','9','C',
				'*','0','#','D'
		};							
#endif


/* Board inicializatzion (starting setups...) */		
BOARD_SETUP void setup(void){
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 10000);
	LCD_setup();
	KeyPad_setup();
	LED_setup();
}

/* Function for waiting for input instead of skipping the read instruction if there is no input in that particular time */
char getkey(){
	char znak;
	
	do{
		znak = KeyPad_getKey();
	} while(!znak);
	
	return znak;
}

int main(void){
	/* Declarations and inicializations */
	char volba, znak;
	int i = 0;

	/* Never ending loop */
	while(1){
		/* Setting default values for repeating */
		i = 0;
		char from[16];
		char naVypisEu[16];
		char naVypisCz[16];
		float cz, eu;
	
		/* Peparations of display */
		LCD_set(LCD_CUR_OFF);
		LCD_set(LCD_LINE1);
		LCD_print("Smenarna        ");
		LCD_set(LCD_LINE2);
		LCD_print("1-cz>eu 2-eu>cz ");
		/* Entering the "volba" variable */
		volba = getkey();
		
		/* Switch condition based on "volba" variable */
		switch(volba){
			case '1':
				/* Default preparation of display */
				LCD_set(LCD_CLR);
				LCD_set(LCD_LINE1);
				LCD_print("Kolik: (Konec *)");
				LCD_set(LCD_LINE2);
				LCD_set(LCD_CUR_ON);
				LCD_set(LCD_CUR_BLINK);
			
				/* Loop for entering the amount till you push '*' */
				do{
					znak = getkey();
					if(znak != '*'){
						LCD_symbol(znak);
						from[i] = znak;
					}
					i++;
				}while(znak != '*');
				
				/* Converts char array to float for calculation */
				cz = (float)atof(from);
				/* Calculation czech crowns to euros */
				eu = cz/24;
				
				
				sprintf(naVypisCz, "%.2f Czk        ", cz);
				sprintf(naVypisEu, "%.2f Eur        ", eu);
				
				
				LCD_set(LCD_CLR);
				LCD_set(LCD_LINE1);
				LCD_print(naVypisCz);
				LCD_set(LCD_LINE2);
				LCD_print(naVypisEu);
				delay_ms(5000);
				break;
			case '2':
				/* Default preparation of display */
				LCD_set(LCD_CLR);
				LCD_set(LCD_LINE1);
				LCD_print("Kolik: (Konec *)");
				LCD_set(LCD_LINE2);
				LCD_set(LCD_CUR_ON);
				LCD_set(LCD_CUR_BLINK);
			
				/* Loop for entering the amount till you push '*' */
				do{
					znak = getkey();
					if(znak != '*'){
						LCD_symbol(znak);
						from[i] = znak;
					}
					i++;
				}while(znak != '*');
				
				/* Converts char array to float for calculation */
				eu = (float)atof(from); 
				/* Calculates euros to czech crowns */
				cz = eu*24;
				
				/* Converts float back to char for printing */
				sprintf(naVypisCz, "%.2f Czk        ", cz);
				sprintf(naVypisEu, "%.2f Eur        ", eu);
				
				/* Prints result */ 
				LCD_set(LCD_CLR);
				LCD_set(LCD_LINE1);
				LCD_print(naVypisEu);
				LCD_set(LCD_LINE2);
				LCD_print(naVypisCz);
				delay_ms(5000);
				break;
			default:
				LCD_set(LCD_CLR);
				LCD_set(LCD_LINE1);
				LCD_print(" Spatna hodnota ");
				delay_ms(3000);
				break;
		}
	}
}
