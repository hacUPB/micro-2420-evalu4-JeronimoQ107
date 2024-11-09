#include <stdint.h>
#include "fsl_gpio.h"

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

void delay(void);
void HAL_GPIO_WritePin(GPIO_Type *base, uint32_t pin, uint8_t output);
void HAL_delay(uint32_t delay_value_ms);

#endif /* HAL_GPIO_H_ */
