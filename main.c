/* 

hi 

*/

#include "drivers/display.h"
#include "common/bsp.h"

static unsigned long potValue;
int main(){
	bsp_init();
	/*potValue = ADC0_inseq3();*/
	
	__enable_irq();
	while(1){
	}
}
