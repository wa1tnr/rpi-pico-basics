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

// since this is a quick port from the uart version,
// it won't be immediately corrected to remove
// the uart stuff (which may still work for outbound).

#define UART_ID uart0
#define BAUD_RATE 115200

// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART_TX_PIN 0
#define UART_RX_PIN 1

char ch;
// uint8_t countah = 0 ;

void _USB_read_tnr(void) {
    // getchar() is compiled in but no help.
    ch = getchar(); printf("%c", ch);
    // countah++;
    // char buffah[24];
    // itoa(countah, buffah);

    // char *intStr = itoa(countah);
    // char *intStr = string(countah);

    uart_putc(UART_ID, ' ');
    // uart_puts(UART_ID, "countahxx fam");
    // printf(countah);
    // uart_puts(UART_ID, inStr);

    // uart_puts(UART_ID, buffah);

    uart_putc(UART_ID, ' ');
    // uart_puts(countah);
    uart_putc(UART_ID, 'p');
    // while (! uart_is_readable) { }

    char* deer;
    uart_putc(UART_ID, ' ');
    if (! uart_is_readable) {
    uart_putc(UART_ID, 'u');
    uart_putc(UART_ID, 'n');
    }
    if (uart_is_readable) {
    uart_putc(UART_ID, 'r');
    uart_putc(UART_ID, 'd');
    uart_putc(UART_ID, 'b');
    uart_putc(UART_ID, 'l');
    uart_putc(UART_ID, ' ');
    }
    // uart_getc is blocking and don't know why.
    // deer = uart_getc(UART_ID);
    sleep_ms(90);
    uart_putc(UART_ID, 'b');
    ch = *deer;

    uart_putc(UART_ID, ' ');
    uart_putc(UART_ID,  ch);
    uart_putc(UART_ID, ' ');

    uart_putc(UART_ID, ' ');
    uart_putc(UART_ID, 'x');
    uart_putc(UART_ID, 'x');
    uart_putc(UART_ID, 'x');
    uart_putc(UART_ID, ' ');

    // if (uart_is_readable) {
        // uart_read_blocking(UART_ID, (uint8_t *)ch, 1);
        // ch = uart_getc(UART_ID);
    // }
    // never reaches here, 2nd interation:
    uart_putc(UART_ID, ' ');
    uart_putc(UART_ID, 'y');
    uart_putc(UART_ID, 'y');
    uart_putc(UART_ID, 'y');
    uart_putc(UART_ID, ' ');
}

void ticker() { // some feedback
    uart_putc(UART_ID, '.'); // a dot heartbeat
    sleep_ms(90);
}

void tryme() {

    // uint8_t ch = 'Q';
    ch = 'Q';

    uart_puts(UART_ID, "\n\r  the tryme loop function\n\r\n\r");

    // while (! uart_is_readable(UART_ID)) {  ticker(); } // maybe blink LED smarter here
    // while (! uart_is_readable(UART_ID)) { sleep_ms(8); }

    uart_putc(UART_ID, 'J'); // not blocked anymore

/*
J READ << cursor
*/
    // if (uart_is_readable(UART_ID)) { // says this only once
            uart_putc(UART_ID, ' '); uart_putc(UART_ID, 'R'); uart_putc(UART_ID, 'E');
            uart_putc(UART_ID, 'A'); uart_putc(UART_ID, 'D'); uart_putc(UART_ID, ' '); 
        // ch = uart_getc(UART_ID); // had type originally
        // sleep_ms(90);
        // uart_read_blocking(UART_ID, ch, 1); // had type originally
        _USB_read_tnr();
        // want to see about these output chars - might be handy to keep them active.
            uart_putc(UART_ID, 'Y');
            uart_putc(UART_ID, ch); // should not be the 'Q' loaded earlier
            uart_putc(UART_ID, 'Z');

            uart_putc(UART_ID, 'W');
    // }
}

void looper() {
    // see if the loop is called as expected before trying for any input.
    uart_putc(UART_ID, 'h'); // use new test chars
    uart_putc(UART_ID, 'i');
    uart_putc(UART_ID, 'j');
    uart_putc(UART_ID, ' ');

    tryme();
    // larger delay - empty loop volatile int won't be optimized out
    // suspiciously fast now - these should take a finite time to complete - not sure that's true
    // lets just look it up - what they recommend for a delay in a loop
    // of course just used it yesterday in blink.c
    // sleep_ms(250);
    // for (volatile int i=2299338871;i>0;i--) { } // keepsake code - nonfunctioning ;)
    // sleep_ms(4); // works a treat as they say - nice calm repeated group of 3 chars
}

int main() {
    sleep_ms(2500);
    // Set up our UART with the required speed.
    uart_init(UART_ID, BAUD_RATE);

    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    // Use some the various UART functions to send out data
    // In a default system, printf will also output via the default UART

    stdio_init_all();


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
