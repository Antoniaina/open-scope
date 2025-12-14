#include "adc.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_log.h"

static adc_oneshot_unit_handle_t adc_handle;
static adc_oneshot_chan_cfg_t chan_cfg;

void adc_init(void) {
  adc_oneshot_unit_init_cfg_t init_cfg = {
      .unit_id = ADC_UNIT_1,
  };

  adc_oneshot_new_unit(&init_cfg, &adc_handle);

  chan_cfg.bitwidth = ADC_BITWIDTH_12;
  chan_cfg.atten = ADC_ATTEN_DB_12;

  adc_oneshot_config_channel(adc_handle, ADC_CHANNEL_6, &chan_cfg);
}

uint16_t adc_read(void) {
  int raw;
  adc_oneshot_read(adc_handle, ADC_CHANNEL_6, &raw);
  return (uint16_t)raw;
}
