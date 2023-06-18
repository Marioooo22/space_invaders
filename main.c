/* 

hi 

*/

#include "drivers/display.h"
#include "common/bsp.h"

unsigned long potValue;
int main(){
	bsp_init();
	
	__enable_irq();
	while(1){
		potValue = ADC0_inseq3();
		SysTick_Wait10ms(8);
	}
}
