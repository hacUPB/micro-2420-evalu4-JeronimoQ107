#include "lcd.h"
#include "hal_gpio.h"
#include "lowlvl_lcd.h"

extern const uint8_t DB_PINS[8];

uint8_t num_pages = 8;  // Número de páginas (cada página es de 8 filas de altura)
uint8_t num_columns = 64;  // Número de columnas por cada mitad de la pantalla (CS1 o CS2)

void lcd_init(void)
{
    lcd_send_command(0x3F);  // Comando para encender el display y modo 1/64 duty

}

void lcd_clear(void)
{
    // Limpiar la mitad izquierda (CS1)
    HAL_GPIO_WritePin(GPIO_BASE, CS1_PIN, 1);  // Activar CS1
    HAL_GPIO_WritePin(GPIO_BASE, CS2_PIN, 1);  // Desactivar CS2

    for (uint8_t page = 0; page < num_pages; page++) {
        lcd_send_command(0xB8 | page);  // Comando para establecer la página actual (X address)
        lcd_send_command(0x40);         // Comando para establecer la columna en 0 (Y address)

        for (uint8_t col = 0; col < num_columns; col++) {
            lcd_send_data(0x00);  // Escribir 0 en cada posición de la columna para limpiar
        }
    }

    // Desactivar ambos chip selects al final
    HAL_GPIO_WritePin(GPIO_BASE, CS1_PIN, 0);
    HAL_GPIO_WritePin(GPIO_BASE, CS2_PIN, 0);
}

void lcd_print(const char *str)
{
    // Recorremos la cadena de texto carácter por carácter
    while (*str) {
        lcd_send_data((uint8_t)*str);  // Envía el carácter actual al LCD
        str++;  // Avanza al siguiente carácter en la cadena
    }
}


void lcd_set_cursor(uint8_t row, uint8_t col) {
    // Determine which half of the LCD to control
    if (col < 64) {
        // Activate CS1 for columns 0-63
        HAL_GPIO_WritePin(GPIO_BASE, CS1_PIN, 0);
        HAL_GPIO_WritePin(GPIO_BASE, CS2_PIN, 1);
    } else {
        // Activate CS2 for columns 64-127
        col -= 64; // Adjust the column address for the second half
        HAL_GPIO_WritePin(GPIO_BASE, CS1_PIN, 1);
        HAL_GPIO_WritePin(GPIO_BASE, CS2_PIN, 0);
    }

    // Send the command to set the X address (row)
    uint8_t x_address_command = 0xB8 | (row & 0x07); // Page address set command
    lcd_send_command(x_address_command);

    // Send the command to set the Y address (column)
    uint8_t y_address_command = 0x40 | (col & 0x3F); // Column address set command
    lcd_send_command(y_address_command);
}