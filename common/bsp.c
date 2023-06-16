
#include "bsp.h"





void bsp_init(void){
	PLL_Init();
	SysTick_Init();
	
	SYSCTL->RCGCGPIO  |= ((1U << 5) |(1U << 2)); /* enable Run mode for GPIOF and C */
    SYSCTL->GPIOHBCTL |= ((1U << 5) |(1U << 2)); /* enable AHB for GPIOB and c*/
    GPIOF_AHB->DIR |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIOF_AHB->DEN |= (LED_RED | LED_BLUE | LED_GREEN);
	GPIOF_AHB->DATA_Bits[LED_RED | LED_BLUE | LED_GREEN] = 0U;
	
    GPIOC_AHB->DIR |= TEST_PINC4;
    GPIOC_AHB->DEN |= TEST_PINC4;
	

	buttonInit();
	/*adc_init();*/
}

void SysTick_Handler(void){
	GPIOC_AHB->DATA_Bits[TEST_PINC4] ^= TEST_PINC4;
}


void GPIOB_Handler(void) {
    if ((GPIOB_AHB->RIS & GPIO_PB0) != 0U) { /* interrupt caused by PB0? */
		GPIOF_AHB->DATA_Bits[LED_BLUE] ^= LED_BLUE;
    }
	 
    GPIOB_AHB->ICR |= GPIO_PB0; /* clear interrupt sources */
}
/*
void ADC0SS3_Handler(void) {
    if ((ADC0->RIS & ADC_SS3) != 0U) {  interrupt caused by SS3? 
		GPIOF_AHB->DATA_Bits[LED_RED] ^= LED_RED;
    }
	
    ADC0->ISC |= ADC_SS3;  clear interrupt sources 
} 
*/
