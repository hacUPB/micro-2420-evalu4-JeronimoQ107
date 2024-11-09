#include <stdint.h>

#ifndef LCD_H_
#define LCD_H_


void lcd_init(void);
void lcd_clear(void);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_print(const char *str);

#endif /* LCD_H_ */