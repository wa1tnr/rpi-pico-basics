add_executable(usb2
        usb2.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(usb2 pico_stdlib)

# enable usb output, disable uart output - input as well?
pico_enable_stdio_usb(usb2 1)
pico_enable_stdio_uart(usb2 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(usb2)

# add url via pico_set_program_url
example_auto_set_url(usb2)
