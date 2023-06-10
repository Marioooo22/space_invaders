
#include "bsp.h"


void led_init(){
	
	SYSCTL->RCGCGPIO  |= (1U << 5); /* enable Run mode for GPIOB */
    SYSCTL->GPIOHBCTL |= (1U << 5); /* enable AHB for GPIOB */
    GPIOF_AHB->DIR |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIOF_AHB->DEN |= (LED_RED | LED_BLUE | LED_GREEN);
	GPIOF_AHB->DATA_Bits[LED_RED | LED_BLUE | LED_GREEN] = 0U;
}


void GPIOB_Handler(void) {
    if ((GPIOB_AHB->RIS & GPIO_PB0) != 0U) { /* interrupt caused by PB0? */
		GPIOF_AHB->DATA_Bits[LED_BLUE] ^= LED_BLUE;
    }
	 
    GPIOB_AHB->ICR |= GPIO_PB0; /* clear interrupt sources */
}