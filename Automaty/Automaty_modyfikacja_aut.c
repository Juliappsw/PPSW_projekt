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

	enum LedState{STOP, LED_RIGHT, LED_LEFT,WIPER};
	enum LedState eLedState = STOP;

	enum Direction { LEFT, RIGHT };
	enum Direction eWiperDirection = RIGHT;
	
	unsigned char ucWiperPos = 0;
	unsigned char ucWiperCycles = 0; 
	const unsigned char UC_MAX_WIPER_CYCLES = 2;
	
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
			else if(eKeyboardRead()==BUTTON_3){ 
				eLedState = WIPER;
				ucWiperCycles = 0; 
				ucWiperPos = 0; 
				eWiperDirection = RIGHT; 			
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

			case WIPER: 
				if(eWiperDirection == RIGHT){
					LedStepRight();
					if(ucWiperPos < 3){
						ucWiperPos++;
					}
					if(ucWiperPos == 3){ 
						eWiperDirection = LEFT;
					}
				}
				else { 
					LedStepLeft();
					if(ucWiperPos > 0){
						ucWiperPos--;
					}
					if(ucWiperPos == 0){ 
						eWiperDirection = RIGHT;
						ucWiperCycles++; 
					}

					if(ucWiperCycles = UC_MAX_WIPER_CYCLES){
						eLedState = LED_RIGHT; 
					}
				else if(eKeyboardRead() == BUTTON_1){ 
					eLedState = STOP;
					ucWiperPos = 0;
					eWiperDirection = RIGHT;
					ucWiperCycles = 0; 
				}
				break;
			
				default:
				break;
		}
		Delay(100);

	}
}
