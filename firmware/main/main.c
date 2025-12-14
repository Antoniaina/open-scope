#include "adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

void app_main(void) {
  adc_init();

  while (1) {
    uint16_t v = adc_read();
    printf("%u\n", v);
    vTaskDelay(pdMS_TO_TICKS(1));
  }
}
