#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#include "lcd.h"
#include "hal_gpio.h"
#include "lowlvl_lcd.h"

int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    // Inicializar el LCD
    lcd_init();

    // Limpiar la pantalla
    lcd_clear();

    // Colocar el cursor en la primera fila y la primera columna
    lcd_set_cursor(20,20);

    // Imprimir el texto "hola mundo" en la pantalla
    lcd_print("HOLA MUNDO");

    // Bucle infinito (mantener el programa corriendo)
    while (1) {
    	// Aquí podrías añadir código adicional si es necesario
    }

    return 0;  // No se llegará a esta línea en un bucle infinito, pero se incluye por convención
}