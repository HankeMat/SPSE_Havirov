//Defining keypad
#define KEYPAD_STEP 250
#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

//Including libraries
#include <RTL.h>
#include "stm32_kit.h"
#include "stm32_kit/led.h"
#include "stm32_kit/lcd.h"
#include "stm32_kit/KeyPad.h"
#include <stdio.h>

//Keypad configuration
static uint8_t KeyPad_KeyMap[KEYPAD_ROWS][KEYPAD_COLS] = {
	'1','2','3','A',
	'4','5','6','B',
	'7','8','9','C',
	'*','0','#','D'
};

//Declaration of tasks
OS_TID taskID1;
OS_TID taskID2;

//Declaration of each part of time (for future extension)
const int minutes = 0;
const int seconds = 20;
const int tenthsOfSecond = 9;

//Declaration of time array
int time[] = {minutes, seconds, tenthsOfSecond};	//minutes, seconds, tenths of second

//Function that waits for button to be pushed
uint8_t getkey(){
	uint8_t symbol;
	do{
		symbol = KeyPad_getKey();
	}while(!symbol);
	return symbol;
}

//Task for prinitng current time
__task void timePrint(){
	//Character array declaration
	char timeToPrint[] = "                ";
	for(;;){
		//Waiting for 0x02 flag
		os_evt_wait_and(0x02, 0xffff);
		//Preparing the LCD
		LCD_set(LCD_CUR_OFF);
		LCD_set(LCD_LINE1);
		//Converting time elements from int to string
		sprintf(timeToPrint, "%02d:%02d:%01d", time[0], time[1], time[2]);
		//Printing the time
		LCD_print(timeToPrint);
		//Sending 0x01 flag to taskID1
		os_evt_set(0x01, taskID1);
	}
}

//Task for measureing the time
__task void timeMeasure(){
	//Declaration
	char restart, interTime;
	char printInter[] = "                ";
	for(;;){
		//Waiting for 0x01 flag
		os_evt_wait_and(0x01, 0xffff);
		//Gathering push impuls
		interTime = KeyPad_getKey();
		//If push impuls was '*'
		if(interTime == '*'){
			//Switch to LINE2
			LCD_set(LCD_LINE2);
			//Converts time elements from int to string
			sprintf(printInter, "%02d:%02d:%01d", time[0], time[1], time[2]);
			//Prinitng current time as an intermediate time
			LCD_print(printInter);
			//Switching back to LINE1
			LCD_set(LCD_LINE1);
		}
		
		//Waiting for 100ms = thenth of second
		delay_ms(100);
		//Decrementing time element "tenths of second"
		--time[2];
		
		//Condition that happens when the tenths of second goes below 0
		if(time[2] < 0){
			//Decrement time element "seconds"
			--time[1];
			//Sets the tenths of second back to default value
			time[2] = tenthsOfSecond;
			//Condition that happens when the seconds goes below 0
			if(time[1] < 0){
				//Decrement time element minutes
				--time[0];
				//Sets the seconds back to default value
				time[1] = seconds;
				//Condition what happens when there is no time left
				if(time[0] < 0){
					//Printf ending message
					LCD_set(LCD_LINE1);
					LCD_print("==End of time===");
					LCD_set(LCD_LINE2);
					LCD_print("==# - restart===");
					//Wait for keyboard impuls for restaring
					do{
						restart = getkey();
					}while(restart != '#');
					//Clear the LCD
					LCD_set(LCD_CLR);
					//Reset time back to default
					time[0] = minutes;
					time[1] = seconds;
					time[2] = tenthsOfSecond;
				}
			}
		}
		//Send flag 0x02 back to taskID2
		os_evt_set(0x02, taskID2);
	}
}

__task void board_init(void) {
	//Setups
	KeyPad_setup();
	LCD_setup();
	LED_setup();
	
	//Creating the tasks
	taskID1 = os_tsk_create(timeMeasure,0);
	taskID2 = os_tsk_create(timePrint,0);
	
	//Sending first flag
	os_evt_set(0x01, taskID1);
	
	// Delete the init(self) task
  os_tsk_delete_self (); 
}

//Function that happenes before everything
int main(void) {
		//Just call board initialization task
    os_sys_init(board_init);
}
