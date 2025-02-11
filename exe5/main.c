#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;

int main() {
    bool blue_state = false, green_state = false;
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);
    int cnt_1 = 0;
    int cnt_2 = 0;

    while (true) {
        if (!gpio_get(BTN_PIN) && !green_state) {
            sleep_ms(500);
            green_state = true;
            printf("Botao 1: %d\n", cnt_1++);
        }  else if (gpio_get(BTN_PIN) && green_state) {
            sleep_ms(500);
            green_state = false;
        }

        if (!gpio_get(BTN_PIN_2) && !blue_state) {
            sleep_ms(500);
            blue_state = true;
            printf("Botao 2: %d\n", cnt_2++);
        } else if (gpio_get(BTN_PIN) && blue_state) {
            sleep_ms(500);
            blue_state = false;
        }
    }
}
