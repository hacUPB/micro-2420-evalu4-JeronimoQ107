#include "lowlvl_lcd.h"
#include "hal_gpio.h"

const uint8_t DB_PINS[8] = {10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U};

void lcd_send_command(uint8_t command)
{
    // Configurar RS en bajo para modo instrucción
    HAL_GPIO_WritePin(GPIO_BASE, RS_PIN, 1);
    // Configurar R/W en bajo para modo escritura
    HAL_GPIO_WritePin(GPIO_BASE, RW_PIN, 0);
    HAL_delay(1);
    // Generar pulso de habilitación
    HAL_GPIO_WritePin(GPIO_BASE, EN_PIN, 1);
    // Configurar los pines DB0-DB7
        for (int i = 0; i < 8; i++) {
            HAL_GPIO_WritePin(GPIO_BASE, DB_PINS[i], (command & (1 << i)) ? 1 : 0);
        }
    HAL_delay(1);  // Breve pausa para asegurar que el controlador lo capte
    HAL_GPIO_WritePin(GPIO_BASE, EN_PIN, 0);
    HAL_delay(1);

}

void lcd_send_data(uint8_t data)
{
    // Configurar RS en alto para modo de datos (indica que se envía un dato y no un comando)
    HAL_GPIO_WritePin(GPIO_BASE, RS_PIN, 1);
    // Configurar R/W en bajo para modo escritura
    HAL_GPIO_WritePin(GPIO_BASE, RW_PIN, 0);
    HAL_delay(1);

    HAL_GPIO_WritePin(GPIO_BASE, EN_PIN, 1);
    // Configurar los pines DB0-DB7
        for (int i = 0; i < 8; i++) {
            HAL_GPIO_WritePin(GPIO_BASE, DB_PINS[i], (data & (1 << i)) ? 1 : 0);
        }
    HAL_delay(5);  // Breve pausa para asegurar que el controlador lo capte
    HAL_GPIO_WritePin(GPIO_BASE, EN_PIN, 0);
    HAL_delay(1);

}