#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_sleep.h"

#include "app.h"

void app_main(void)
{
    app_init();
    vTaskDelay(pdMS_TO_TICKS(10000));
    ESP_LOGE("MAIN", "Sleep time");
    esp_deep_sleep_start();
}
