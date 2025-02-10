#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_1_PIN = 26;
const int BTN_2_PIN = 7;

int main() {
  stdio_init_all();

  gpio_init(BTN_1_PIN);
  gpio_init(BTN_2_PIN);
  
  gpio_set_dir(BTN_1_PIN, GPIO_IN);
  gpio_set_dir(BTN_2_PIN, GPIO_IN);

  gpio_pull_up(BTN_1_PIN);
  gpio_pull_up(BTN_2_PIN);

  while (true) {
    if (!gpio_get(BTN_1_PIN)) {
      printf("Botao 1\n");
      while (!gpio_get(BTN_1_PIN)) {};
    }

    if (!gpio_get(BTN_2_PIN)) {
      printf("Botao 2\n");
      while (!gpio_get(BTN_2_PIN)) {}
    }
  }
}
