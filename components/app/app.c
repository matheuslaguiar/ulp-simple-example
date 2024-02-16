#include "app.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_sleep.h"
#include "ulp_riscv.h"

#include "ulp_app.h"

#define GPIO_INPUT_WAKEUP_NUM   GPIO_NUM_1
#define TAG_APP "APP"

extern const uint8_t ulp_bin_start[] asm("_binary_ulp_app_bin_start");
extern const uint8_t ulp_bin_end[]   asm("_binary_ulp_app_bin_end");

/**
 * @brief Init ULP RISC-V program
 */
static void init_ulp_program(void) {
    esp_err_t err = ulp_riscv_load_binary(ulp_bin_start, (ulp_bin_end - ulp_bin_start));
    ESP_ERROR_CHECK(err);

    /* The first argument is the period index, which is not used by the ULP-RISC-V timer
     * The second argument is the period in microseconds, which gives a wakeup time period of: 1s
     */
    err = ulp_set_wakeup_period(0, 1000000);
    ESP_ERROR_CHECK(err);

    /* Start the program */
    err = ulp_riscv_run();
    ESP_ERROR_CHECK(err);
}

/**
 * @brief Set the wakeup source
 */
static void set_wakeup_source(void) {
    /* Enable EXT0 wakeup on pin GPIO_INPUT_WAKEUP_NUM */
    esp_sleep_enable_ext0_wakeup(GPIO_INPUT_WAKEUP_NUM, 0);
    /* Enable ULP wakeup source */
    esp_sleep_enable_ulp_wakeup();
}

static void task_read(void *pvParameters)
{
    char* parity = (char*)&ulp_var_string;
    while (1)
    {
        ESP_LOGW(TAG_APP, "ULP variable value: %lu", ulp_var);
        ESP_LOGW(TAG_APP, "Parity: %s", parity);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }   
}

void app_init(void)
{
    if(esp_reset_reason() != ESP_RST_DEEPSLEEP) {
        init_ulp_program();
    }
    set_wakeup_source();
    xTaskCreate(task_read, "task_read", 4096, NULL, 1, NULL);
}

