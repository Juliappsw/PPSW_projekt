#include "led.h"
#include "keyboard.h"

void Delay(unsigned int uiTimeInMS){

	unsigned int uiLoopCounter;
	unsigned int uiNumberOfCycles=uiTimeInMS*12000;
	
	for(uiLoopCounter=0; uiLoopCounter< uiNumberOfCycles; uiLoopCounter++)
	{
		
	}
} 

int main(){

	enum LedState{STOP, LED_RIGHT, LED_LEFT}; 
	enum LedState eLedState = STOP;

	LedInit();
	KeyboardInit();
	
	while(1) 
	{
		switch(eLedState){
			
			case STOP:
				if(eKeyboardRead()==BUTTON_0){
					eLedState= LED_LEFT;
				}
				else if(eKeyboardRead()==BUTTON_2){
					eLedState = LED_RIGHT;
				}
				else{
					eLedState = STOP; 
				}
				break;
					
			case LED_LEFT :
				LedStepLeft();
				if(eKeyboardRead()==BUTTON_1){
					eLedState = STOP;
				}
				else{
					eLedState = LED_LEFT;
				}
				break;
			
			case LED_RIGHT :
				LedStepRight();
				if(eKeyboardRead()==BUTTON_1){
					eLedState=STOP;
					}	
				else{
					eLedState = LED_RIGHT;
				}					
				break;

				default:
				break;
		}
		Delay(100);

	}
}

// zaliczenie git 

