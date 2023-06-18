#ifndef __adc_H__
#define __adc_H__


#define GPIO_PB4  (1U << 4)
#define ADC_SS3    (1U << 3)       /* sample sequencer 3 */ 
/* adc configuration */ 
#define ADC_CLK          (1U << 16)  /* adc0 enabled */
#define ADC_SAMPLE_SPEED  0x0       /* 125k samples/second */
#define ADC_SEQS_PRI      0x123; /* Seq3 max priority and other seqs to whatever*/
#define ADC_EV_TRIG       (0xf<<12)  /* SEQ3 trigger initiated by settting ssn bit in ADCPSSI */
#define ADC_CHANNEL       0xA       /* select ain1 */
#define ADC_SCTL_CONFIG   0x6	      /* noTemp-interrups-endSeq-noSampleDif */
#define ADC_IM_ENABLED    (1U << 3)       /* SS3 interrupt mask */ 


void adc_init(void);
unsigned long ADC0_inseq3(void);


#endif /* __adc_H__ */