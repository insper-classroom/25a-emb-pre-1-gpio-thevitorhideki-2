#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;
const int LED_R_PIN = 5;
const int LED_P_PIN = 8;
const int LED_B_PIN = 11;
const int LED_Y_PIN = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_init(LED_R_PIN);
  gpio_init(LED_P_PIN);
  gpio_init(LED_B_PIN);
  gpio_init(LED_Y_PIN);

  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_set_dir(LED_R_PIN, GPIO_OUT);
  gpio_set_dir(LED_P_PIN, GPIO_OUT);
  gpio_set_dir(LED_B_PIN, GPIO_OUT);
  gpio_set_dir(LED_Y_PIN, GPIO_OUT);

  gpio_pull_up(BTN_PIN);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      gpio_put(LED_R_PIN, 1);
      sleep_ms(300);
      gpio_put(LED_R_PIN, 0);
      sleep_ms(300);

      gpio_put(LED_P_PIN, 1);
      sleep_ms(300);
      gpio_put(LED_P_PIN, 0);
      sleep_ms(300);

      gpio_put(LED_B_PIN, 1);
      sleep_ms(300);
      gpio_put(LED_B_PIN, 0);
      sleep_ms(300);

      gpio_put(LED_Y_PIN, 1);
      sleep_ms(300);
      gpio_put(LED_Y_PIN, 0);
      sleep_ms(300);
      while (!gpio_get(BTN_PIN)) {}
    }
  }
}
