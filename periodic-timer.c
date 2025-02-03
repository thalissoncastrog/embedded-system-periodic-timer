#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

int state = 0;  // Controlls the state of the traffic light


int main()
{
    stdio_init_all();

    // Initialize the GPIO pins for the LEDs
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, true);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, true);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, true);

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
