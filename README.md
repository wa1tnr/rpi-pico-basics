# rpi-pico-basics

# Mon Feb  8 03:42:47 UTC 2021

# About

First exploration of RP2040 and Raspberry Pi Pico,
locally.  A primitive USB interpreter exists now.

# Interesting Files

This is a very rough interpreter that broadcasts
also on the UART, and only accepts keystrokes on
the USB.

The /dev/ttyACM0 is the primary interface (USB).

Using CP2104 USB-to-USART bridge, the secondary
interface (in Linux host PC) is /dev/ttyUSB0, but
that is arbitrary (you can bridge using other
methods and chips).

This is the interpreter file and its location:

rpi-pico-basics/07-interpreter.d/pico-examples/interpreter-a/interpreter-a.c


# Topics

# rp2040
# raspberry-pi-pico

# basics-of-rp2040

# rpi-pico-pio

# programmable-i-o

# forth assembly-language-programming
# basics
# c cpp

END.
