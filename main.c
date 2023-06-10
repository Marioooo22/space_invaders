/* 

hi 

*/

#include "drivers/display.h"
#include "common/bsp.h"


int main(){
	buttonInit();
	led_init();
	
	
	__enable_irq();
	while(1){
	}
}
