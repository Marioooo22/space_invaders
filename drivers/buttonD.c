
#include "buttonD.h"
#include "TM4C123GH6PM.h"
#include <stdbool.h>

#define GPIO_PB0 (1U << 0)

void buttonInit(){
	SYSCTL->RCGCGPIO  |= (1U << 1); /* enable Run mode for GPIOB */
	SYSCTL->GPIOHBCTL |= (1U << 1); /* enable AHB for GPIOB */
	GPIOB_AHB->DEN    |= GPIO_PB0;
	GPIOB_AHB->DIR    &= ~GPIO_PB0; 
	/* interrupts */
	
}


 
