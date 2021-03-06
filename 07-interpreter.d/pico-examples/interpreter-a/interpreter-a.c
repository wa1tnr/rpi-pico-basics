/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// wa1tnr
// Mon Feb  8 02:44:30 UTC 2021
// Sun Feb  7 18:46:13 UTC 2021

#include <stdio.h>
#include "pico/stdlib.h"

/// \tag::hello_uart[]

#define UART_ID uart0
#define BAUD_RATE 115200

#define UART_TX_PIN 0
#define UART_RX_PIN 1

char ch;
void _USB_read_tnr(void) {
    ch = getchar(); printf("%c", ch);
    uart_putc(UART_ID, ch);
    // putchar() on /dev/ttyACM0 - USB
    putchar('X');
}

void tryme() {
    ch = 'Q';
    _USB_read_tnr();
}

void looper() {

    tryme();
}

int main() {
    sleep_ms(9500);
    uart_init(UART_ID, BAUD_RATE);

    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    stdio_init_all();

    uart_putc_raw(UART_ID, 'A');

    uart_putc(UART_ID, 'B');
    uart_putc(UART_ID, 'B');
    uart_putc(UART_ID, 'B');
    uart_putc(UART_ID, 'B');
    uart_putc(UART_ID, 'B');
    uart_putc(UART_ID, 'B');
    uart_putc(UART_ID, 'B');
    uart_putc(UART_ID, 'B');
    uart_putc(UART_ID, 'B');
    uart_putc(UART_ID, 'B');
    uart_putc(UART_ID, 'B');
    sleep_ms(19500);
    uart_puts(UART_ID, " Hello, UART!\n");
    uart_puts(UART_ID, " project codenamed picoForth v0.0.0-a\n");

    while(1) {
        looper(); // called once and ran once ask asked ;)
    }
}

/// \end::hello_uart[]
