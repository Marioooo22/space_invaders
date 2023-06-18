#ifndef __BSP_H__
#define __BSP_H__

#include "TM4C123GH6PM.h"
#include "../drivers/buttonD.h"
#include "PLL.h"
#include "SysTick.h"
#include "../drivers/adcPot.h"


#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)
#define TEST_PINC4 (1U << 4)


/* system clock*/
#define SYS_CLOCK_HZ 80000000U


void led_init(void);
void bsp_init(void);


#endif /* __BSP_H__ */
