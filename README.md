# Documentación del Proyecto
---
Nombre del estudiante:  Jerónimo Quintero Chavarría
ID: 000492388

## Código

En la documentación de este proyecto solo se quiere hacer enfásis en la configuración de los pines del microprocesador utilizados para operar el LCD.

Para todos los pines se utiliza el **GPIO_PORTB**.

    PTB0 - PIN_RS
    PTB1 - PIN_RW
    PTB2 - PIN_EN
    PTB8 - PIN_CS1
    PTB9 - PIN_CS1
    PTB(10,17) - PIN_DB(0,7)

Las funciones de la HAL, **HAL_GPIO_WritePin** y **HAL_delay**, vienen incluidas en el directorio hal_gpio de este mismo repositorio.

Las funciones del driver de bajo nivel, **lcd_send_command** y **lcd_send_data**, vienen incluidas en el directorio lowlvl_lcd.

Las funciones de la API, **lcd_init**, **lcd_clear**, **lcd_set_cursor** y **lcd_print**, vienen incluidas en el directorio lcd.