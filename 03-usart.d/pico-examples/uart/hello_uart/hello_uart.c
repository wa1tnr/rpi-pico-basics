/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// wa1tnr
// Sun Feb  7 18:46:13 UTC 2021

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

/// \tag::hello_uart[]

#define UART_ID uart0
#define BAUD_RATE 115200

// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART_TX_PIN 0
#define UART_RX_PIN 1

void looper() {
    // see if the loop is called as expected before trying for any input.
    uart_putc(UART_ID, 'h'); // use new test chars
    uart_putc(UART_ID, 'i');
    uart_putc(UART_ID, 'j');
    uart_putc(UART_ID, ' ');
    // larger delay - empty loop volatile int won't be optimized out
    // suspiciously fast now - these should take a finite time to complete - not sure that's true
    // lets just look it up - what they recommend for a delay in a loop
    // of course just used it yesterday in blink.c
    // sleep_ms(250);
    for (volatile int i=2299338871;i>0;i--) { } // keepsake code - nonfunctioning ;)
    sleep_ms(250); // works a treat as they say - nice calm repeated group of 3 chars
}

int main() {
    // Set up our UART with the required speed.
    uart_init(UART_ID, BAUD_RATE);

    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    // Use some the various UART functions to send out data
    // In a default system, printf will also output via the default UART

    // Send out a character without any conversions
    uart_putc_raw(UART_ID, 'A');

    // Send out a character but do CR/LF conversions
    uart_putc(UART_ID, 'B');

    // Send out a string, with CR/LF conversions
    uart_puts(UART_ID, " Hello, UART!\n");

    // locally authored payload - a loop:
    while(1) {
        looper(); // called once and ran once ask asked ;)
    }
}

/// \end::hello_uart[]
