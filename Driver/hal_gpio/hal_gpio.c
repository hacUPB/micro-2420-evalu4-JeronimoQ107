#include "hal_gpio.h"

void delay(void)		// Delay de 1 ms
{
    volatile uint32_t i = 0U;
    for (i = 0U; i < 400U; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

void HAL_GPIO_WritePin(GPIO_Type *base, uint32_t pin, uint8_t output)
{
    uint32_t u32flag = 1;

    if (output == 0U)
    {
        base->PCOR = GPIO_FIT_REG(u32flag << pin);
    }
    else
    {
        base->PSOR = GPIO_FIT_REG(u32flag << pin);
    }
}

void HAL_delay(uint32_t delay_value_ms) // Delay genérico en ms
{
	volatile uint32_t i = 0U;
	for (i = 0U; i < delay_value_ms; i++)
	{
		delay();
	}
}