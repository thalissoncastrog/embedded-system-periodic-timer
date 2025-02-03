#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

int state = 0;  // Controlls the state of the traffic light

//  Timer Callback
bool repeating_timer_callback(struct repeating_timer *t) {
    printf("3 segundos passaram\n");

    // Turn off all LEDs before turning on the next one
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_YELLOW, 0);
    gpio_put(LED_PIN_GREEN, 0);

    // Alternate between the LEDs based on the state
    if (state == 0) {
        gpio_put(LED_PIN_RED, 1);   // Vermelho
    } else if (state == 1) {
        gpio_put(LED_PIN_YELLOW, 1); // Amarelo
    } else if (state == 2) {
        gpio_put(LED_PIN_GREEN, 1); // Verde
    }

    // Advance the state
    state = (state + 1) % 3;

    return true;
}


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
