/* adc activation using sequencer 3 only*/

#include "adcPot.h"
#include "TM4C123GH6PM.h"



void adc_init(){
	/* enable adc and set the speed */
	SYSCTL->RCGC0 |= ADC_CLK;
	SYSCTL->RCGC0 |= ADC_SAMPLE_SPEED;
	/* setting pb4 */
	GPIOB->DEN 	 &= ~GPIO_PB4;
	GPIOB->AFSEL |= GPIO_PB4;
	GPIOB->AMSEL |= GPIO_PB4;
	ADC0->SSPRI    = ADC_SEQS_PRI;
	/* sample sequencer configuration*/
	ADC0->EMUX    &= ~ADC_EV_TRIG;
	ADC0->SSMUX3  |= ADC_CHANNEL;
	ADC0->SSCTL3  |= ADC_SCTL_CONFIG;
	ADC0->ACTSS   |= ADC_SS3;
	ADC0->IM      |= ADC_IM_ENABLED;
	 
	NVIC_SetPriority(ADC0SS3_IRQn, 4);
	NVIC_EnableIRQ(ADC0SS3_IRQn);
	
}


unsigned long ADC0_inseq3(void){  
	unsigned long result;
	ADC0->PSSI = ADC_SS3;            // 1) initiate SS3
	/*while((){};   // 2) wait for conversion done*/
	result = ADC0->SSFIFO3&0xFFF;   // 3) read result
	/*ADC0->ISC = ADC_SS3;             // 4) acknowledge completion*/
	return result;
}
