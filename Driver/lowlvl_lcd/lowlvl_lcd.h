#include <stdint.h>

#ifndef LOWLVL_LCD_H_
#define LOWLVL_LCD_H_

#define GPIO_BASE GPIOB

#define RS_PIN 0U
#define RW_PIN 1U
#define EN_PIN 2U

#define CS1_PIN 8U
#define CS2_PIN 9U

void lcd_send_command(uint8_t command);
void lcd_send_data(uint8_t data);


#endif /* LOWLVL_LCD_H_ */