
#include "buttonD.h"
#include "TM4C123GH6PM.h"


void buttonInit(){
	SYSCTL->RCGCGPIO  |= (1U << 1); /* enable Run mode for GPIOB */
	SYSCTL->GPIOHBCTL |= (1U << 1); /* enable AHB for GPIOB */
	GPIOB_AHB->DEN    |= GPIO_PB0;
	GPIOB_AHB->DIR    &= ~GPIO_PB0; 
	/* interrupts */
    GPIOB_AHB->IS  &= ~GPIO_PB0; /* edge detect for GPIOB */
    GPIOB_AHB->IBE &= ~GPIO_PB0; /* only one edge generate the interrupt */
    GPIOB_AHB->IEV |= GPIO_PB0; /* a rising edge triggers the interrupt */
    GPIOB_AHB->IM  |= GPIO_PB0;  /* enable GPIOB interrupt for GPIOB */
	/* set priorities */
	NVIC_SetPriority(GPIOB_IRQn, 3);
	NVIC_EnableIRQ(GPIOB_IRQn);
}


 
