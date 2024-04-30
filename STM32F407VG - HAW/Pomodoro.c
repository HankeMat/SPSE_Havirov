/**
 * @file Pomodoro.c
 * @author Hanke Matěj (hanke.matej@seznam.cz)
 * @brief Pomodore timer
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright Hanke Matěj (c) 2023
 * 
 */

//Defining constants
#define LCD_COLS    8                                         
#define LCD_ROWS    2 
#define KEYPAD_COLS   4                                           
#define KEYPAD_ROWS   4 
#define LCD_8x2 (((LCD_COLS) == 8) && ((LCD_ROWS) == 2))
#define KEYPAD_STEP 50

//Including libraries
#include <RTL.h>
#include "stm32_kit.h"
#include "stm32_kit/led.h"
#include "stm32_kit/lcd.h"
#include "stm32_kit/keypad.h"
#include <stdio.h>


//Keypad map (Sets what button means what character)
static uint8_t KeyPad_KeyMap[KEYPAD_ROWS][KEYPAD_COLS] = {      
													'1', '2', '3', 'A',
													'4', '5', '6', 'B',
													'7', '8', '9', 'C',
													'*', '0', '#', 'D'
};

//Declaration of tasks
OS_TID taskID1;
OS_TID taskID2;
OS_TID taskID3;
OS_TID taskID4;
OS_TID taskID5;

//Defining constants
#define CAS_FOCUS 25
#define CAS_SH_BRK 5
#define CAS_LNG_BRK 15

//Default setting for timers
int cas[] = {0, CAS_FOCUS - 1, 9}; 			//minutes, seconds, tenths of second
int casSB[] = {0, CAS_SH_BRK - 1, 9}; 	//minutes, seconds, tenths of second
int casLB[] = {0, CAS_LNG_BRK - 1, 9};	//minutes, seconds, tenths of second

//Default setting for variables
int bylFocus = 0;
int byl = 0;

//Including leds into one array
const enum pin ledky[] = {
    LED_IN_0,
    LED_IN_1,
    LED_IN_2,
    LED_IN_3
};

//Function for waiting untill user presses #
void zastaveni(){
	uint8_t znak;
	do{
		znak = KeyPad_getKey();
	}while(znak != '#');
}

//Dont wait untill user presses #, just check if he pressed it
void stop(){
		uint8_t znak = KeyPad_getKey();
		if(znak == '#'){
			os_evt_set(0x05, taskID5);
			os_tsk_pass();
		}		
}

__task void mereniCasu(void) {
	for (;;) {	
		//Wait for flag 0x01
		os_evt_wait_and (0x01, 0xffff);	
		
		//Check whether user wants to end
		stop();
		
		//If user button has been pressed
		if(io_read(USER_BUTTON)){
					//Skip task (not done yet)
		}
		
		//Every 100ms decrement one tenth of second in short break 
		delay_ms(100);
		cas[2] -= 1;
		
		//If tenths of second are at 0
		if (cas[2] < 0) {
			
			//Set tenths of second back to 9 and decrement seconds by one
			cas[1] -= 1;
			cas[2] = 9;
			
			//And so on
			if (cas[1] < 0) {
				cas[0] -= 1;
				cas[1] = 59;
				
				//If the whole focus time passed
				if(cas[0] < 0){
					
					//Increment "byl" variable by one (indicates how many time has focus time passed)
					byl++;
					
					//Turn on led based on how many times has focus time been
					io_set(ledky[byl - 1], 1);
					
					//Sets temporary variable to "1" so the printing task prints short break time 
					bylFocus = 1;
					
					//Reset short break time
					casSB[0] = 0;
					casSB[1] = 5;
					casSB[2] = 9;
					
					//Send flag to taskID3 (short break)
					os_evt_set(0x03, taskID3);
				}
			}
		}
		
		//Send flag 0x02 to print current time
		os_evt_set(0x02, taskID2);
	}
}

__task void zobrazeniCasu(void){
	//Firstly clear the string for printing
	char casChar[] = "        ";
	for (;;) {
		
		//Wait for flag 0x02
		os_evt_wait_and (0x02, 0xffff);
		
		//If flag came from short or long break
		if(bylFocus == 0){
			
			//Prepare LCD for print and print
			LCD_set(LCD_CUR_OFF);
			LCD_set(LCD_LINE2);
			LCD_print("FOCUS   ");
			LCD_set(LCD_LINE1);
			sprintf(casChar, "%02d:%02d:%01d", cas[0], cas[1], cas[2]);
			LCD_print(casChar);	
			
			//Send flag to taskID1 (focus timer)
			os_evt_set(0x01, taskID1);
			
		//If flag came from focus timer
		}else if(bylFocus == 1){
			
			//Prepare LCD for print and print
			LCD_set(LCD_CUR_OFF);
			LCD_set(LCD_LINE2);
			LCD_print("S.BREAK ");
			LCD_set(LCD_LINE1);
			sprintf(casChar, "%02d:%02d:%01d", casSB[0], casSB[1], casSB[2]);
			LCD_print(casChar);	
			
			//Send flag to taskID3 (short break)
			os_evt_set(0x03, taskID3);
			
		//If focus has happened four times
		}else if(bylFocus == 2){
			
			//Prepare LCD for print and print
			LCD_set(LCD_CUR_OFF);
			LCD_set(LCD_LINE2);
			LCD_print("L.BREAK ");
			LCD_set(LCD_LINE1);
			sprintf(casChar, "%02d:%02d:%01d", casLB[0], casLB[1], casLB[2]);
			LCD_print(casChar);	
			
			//Send flag to taskID3 (long break)
			os_evt_set(0x04, taskID4);
		}
		
	}
}

__task void mereniSB(void){
	for(;;) {
		//Wait for flag 0x03
		os_evt_wait_and (0x03, 0xffff);	
		
		//Check whether user wants to end
		stop();
		
		//If user button was pushed
		if(io_read(USER_BUTTON)){
			//Skip task  (Not done yet)
		}
		
		//If focus has been four times
		if(byl == 4){
			
			//Sets temporary variable to "2" so task the printing task prints long break time
			bylFocus = 2;
			
			//Reset long break
			casLB[0] = 0;
			casLB[1] = CAS_LNG_BRK - 1;
			casLB[2] = 9;
			
			//Send flag to taskID4 (long break)
			os_evt_set(0x04, taskID4);
		}
		
		//Every 100ms decrement one tenth of second in short break 
		delay_ms(100);
		casSB[2] -= 1;
		
		//If tenths of second are at 0
		if (casSB[2] < 0) {
			
			//Set tenths of second back to 9 and decrement seconds by one
			casSB[1] -= 1;
			casSB[2] = 9;
			
			//And so on
			if (casSB[1] < 0) {
				casSB[0] -= 1;
				casSB[1] = 59;
				
				//If the whole short break passed
				if(casSB[0] < 0){
					
					//Reset temporary variables
					bylFocus = 0;
					
					//Reset focus time
					cas[0] = 0;
					cas[1] = 9;
					cas[2] = 9;
					
					//Send flag to taskID1 (focus timer)
					os_evt_set(0x01, taskID1);					
				}
			}
		}
		
		//Send flag to taskID2 to print current time to LCD
		os_evt_set(0x02, taskID2);
	}
}

__task void mereniLB(void){
	for(;;) {
		//Wait for flag 0x04
		os_evt_wait_and (0x04, 0xffff);	
		
		//Check whether user wants to end
		stop();
		
		//Every 100ms decrement one tenth of second in long break
		delay_ms(100);
		casLB[2] -= 1;
		
		//If tenths of second are at 0
		if (casLB[2] < 0) {
	
			//Set tenths of second back to 9 and decrement second by one
			casLB[1] -= 1;
			casLB[2] = 9;
			
			//And so on
			if (casLB[1] < 0) {
				casLB[0] -= 1;
				casLB[1] = 59;
				
				//If the whole long break passed
				if(casLB[0] < 0){
					
					//Turn off all leds
					for(int i=0;i<4;i++){
						io_set(ledky[i], 0);
					}
					
					//Reset temporary variables
					byl=0;
					bylFocus = 0;
					
					//Reset focus time
					cas[0] = 0;
					cas[1] = CAS_FOCUS - 1;
					cas[2] = 9;
					
					//Send flag to taskID1 (focus timer)
					os_evt_set(0x01, taskID1);	
				}
			}
		}
		
		//Send flag to taskID2 to print current time to LCD
		os_evt_set(0x02, taskID2);
	}
}

__task void cekani(void){
	for(;;){
		//Wait for flag 0x05
		os_evt_wait_and (0x05, 0xffff);
		
		//Reset temporary variables
		bylFocus = 0;	
		byl=0;
		
		//Delete all tasks except this one
		os_tsk_delete(taskID1);
		os_tsk_delete(taskID2);
		os_tsk_delete(taskID3);
		os_tsk_delete(taskID4);
		
		//Set LCD for end text
		LCD_set(LCD_CLR);
		LCD_set(LCD_LINE1);
		LCD_set(LCD_CUR_OFF);
		
		//End text
		LCD_print("Ukoncen!");
		delay_ms(100);
		
		//Wait untill next # is pressed
		zastaveni();		//Ceka na #
		delay_ms(100);
		
		//Create tasks again
		taskID1 = os_tsk_create(mereniCasu, 0);
		taskID2 = os_tsk_create(zobrazeniCasu, 0);
		taskID3 = os_tsk_create(mereniSB, 0);
		taskID4 = os_tsk_create(mereniLB, 0);
		
		//Set the LCD
		LCD_set(LCD_CLR);
		LCD_set(LCD_CUR_OFF);
		
		//Reset focus time to default
		cas[0] = 0;
		cas[1] = CAS_FOCUS - 1;
		cas[2] = 9;
		
		//Reset short break time to default
		casSB[0] = 0;
		casSB[1] = CAS_SH_BRK - 1;
		casSB[2] = 9;				
		
		//Reset long break time to default
		casLB[0] = 0;
		casLB[1] = CAS_LNG_BRK - 1;
		casLB[2] = 9;
		
		//Turn off all leds
		for(int i=0;i<4;i++){
			io_set(ledky[i], 0);
		}
		
		//Send flag back to taskID1
		os_evt_set(0x01, taskID1);
		os_tsk_pass();
	}
}

__task void board_init(void) {
	//Setups
  LED_setup();
  LCD_setup();
	KeyPad_setup();
	LCD_set(LCD_CUR_OFF);
	
	//Instatiate all tasks
  taskID1 = os_tsk_create(mereniCasu, 0);
  taskID2 = os_tsk_create(zobrazeniCasu, 0);
	taskID3 = os_tsk_create(mereniSB, 0);
	taskID4 = os_tsk_create(mereniLB, 0);
	taskID5 = os_tsk_create(cekani, 0);
	
	//Send flag to taskID1 (focus timer)
	os_evt_set(0x01, taskID1);
	
	// Delete the init(self) task
  os_tsk_delete_self (); 
}

//Function that happenes before everything
int main(void) {
	
		//Just call board initialization task
    os_sys_init(board_init);
}
