add_executable(hello_uart
        hello_uart.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(hello_uart pico_stdlib)

# enable usb output, disable uart output - input as well?
pico_enable_stdio_usb(hello_uart 0)
pico_enable_stdio_uart(hello_uart 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(hello_uart)

# add url via pico_set_program_url
example_auto_set_url(hello_uart)
