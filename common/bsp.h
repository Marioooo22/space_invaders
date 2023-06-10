#ifndef __BSP_H__
#define __BSP_H__

#include "TM4C123GH6PM.h"
#include "../drivers/buttonD.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

void led_init(void);


#endif /* __BSP_H__ */
