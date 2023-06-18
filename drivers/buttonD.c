
#include "buttonD.h"
#include "TM4C123GH6PM.h"


void buttonInit(){
	SYSCTL->RCGCGPIO  |= (1U << 1); /* enable Run mode for GPIOB */
	GPIOB->DEN    |= GPIO_PB0;
	GPIOB->DIR    &= ~GPIO_PB0; 
	/* interrupts */
    GPIOB->IS  &= ~GPIO_PB0; /* edge detect for GPIOB */
    GPIOB->IBE &= ~GPIO_PB0; /* only one edge generate the interrupt */
    GPIOB->IEV |= GPIO_PB0; /* a rising edge triggers the interrupt */
    GPIOB->IM  |= GPIO_PB0;  /* enable GPIOB interrupt for GPIOB */
	/* set priorities */
	NVIC_SetPriority(GPIOB_IRQn, 3);
	NVIC_EnableIRQ(GPIOB_IRQn);
}


 
