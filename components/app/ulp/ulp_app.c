#include "ulp_riscv.h"
#include "ulp_riscv_utils.h"
#include "ulp_riscv_uart_ulp_core.h"
#include "ulp_riscv_print.h"
#include "string.h"

volatile uint32_t var;
volatile char var_string[5];

static ulp_riscv_uart_t s_print_uart;
#define CONFIG_EXAMPLE_UART_TXD 4

int main (void)
{
    ulp_riscv_uart_cfg_t cfg = {
        .tx_pin = CONFIG_EXAMPLE_UART_TXD,
    };
    ulp_riscv_uart_init(&s_print_uart, &cfg);
    ulp_riscv_print_install((putc_fn_t)ulp_riscv_uart_putc, &s_print_uart);

    ulp_riscv_print_str("ULP: waked up!\r\n");
    ulp_riscv_print_str("ULP: var: 0x");
    ulp_riscv_print_hex(var);
    ulp_riscv_print_str("\r\n");

    if(var > 100) var = 0;
    else var++;

    if(var%2 == 0)
        strcpy(var_string, "even");
    else
        strcpy(var_string, "odd");

    if(var%20 == 0)
        ulp_riscv_wakeup_main_processor();
    return 0;
}
