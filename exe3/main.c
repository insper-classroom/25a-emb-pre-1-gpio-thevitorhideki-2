#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_R_PIN = 28;
const int LED_R_PIN = 4;
const int BTN_G_PIN = 26;
const int LED_G_PIN = 6;

int main() {
  bool red_led = false, green_led = false;

  stdio_init_all();

  gpio_init(BTN_R_PIN);
  gpio_init(LED_R_PIN);
  gpio_init(BTN_G_PIN);
  gpio_init(LED_G_PIN);

  gpio_set_dir(BTN_R_PIN, GPIO_IN);
  gpio_set_dir(LED_R_PIN, GPIO_OUT);
  gpio_set_dir(BTN_G_PIN, GPIO_IN);
  gpio_set_dir(LED_G_PIN, GPIO_OUT);

  gpio_pull_up(BTN_R_PIN);
  gpio_pull_up(BTN_G_PIN);

  while (true) {
    if (!gpio_get(BTN_R_PIN)) {
      red_led = !red_led;
      printf("Red button pressed\n");
      gpio_put(LED_R_PIN, red_led);
      while (!gpio_get(BTN_R_PIN)) {};
    }

    if (!gpio_get(BTN_G_PIN)) {
      green_led = !green_led;
      printf("Green button pressed\n");
      gpio_put(LED_G_PIN, green_led);
      while (!gpio_get(BTN_G_PIN)) {};
    }
  }
}
