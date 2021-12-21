set(CORE_SRCS
  cores/esp32/esp32-hal-adc.c
  cores/esp32/esp32-hal-cpu.c
  cores/esp32/esp32-hal-dac.c
  cores/esp32/esp32-hal-gpio.c
  cores/esp32/esp32-hal-i2c.c
  cores/esp32/esp32-hal-ledc.c
  cores/esp32/esp32-hal-matrix.c
  cores/esp32/esp32-hal-misc.c
  cores/esp32/esp32-hal-psram.c
  cores/esp32/esp32-hal-sigmadelta.c
  cores/esp32/esp32-hal-spi.c
  cores/esp32/esp32-hal-tinyusb.c
  cores/esp32/esp32-hal-touch.c
  cores/esp32/esp32-hal-rmt.c
  cores/esp32/FunctionalInterrupt.cpp
  cores/esp32/IPv6Address.cpp
  cores/esp32/stdlib_noniso.c
  cores/esp32/USB.cpp
  cores/esp32/USBCDC.cpp
  cores/esp32/wiring_pulse.c
  cores/esp32/wiring_shift.c
  cores/esp32/WMath.cpp
  )

set(LIBRARY_SRCS
  libraries/FS/src/FS.cpp
  libraries/FS/src/vfs_api.cpp
  libraries/SPI/src/SPI.cpp
  libraries/SPIFFS/src/SPIFFS.cpp
  libraries/Wire/src/Wire.cpp
  )


set(includedirs
  variants/esp32/
  cores/esp32/
  libraries/FS/src
  libraries/SPI/src
  libraries/SPIFFS/src
  libraries/Wire/src
  )

set(srcs ${CORE_SRCS} ${LIBRARY_SRCS} ${BLE_SRCS})
set(requires spi_flash mbedtls esp_adc_cal wifi_provisioning)
set(priv_requires nvs_flash spiffs bootloader_support openssl tinyusb espcpputils fmt)

idf_component_register(INCLUDE_DIRS ${includedirs} PRIV_INCLUDE_DIRS ${priv_includes} SRCS ${srcs} REQUIRES ${requires} PRIV_REQUIRES ${priv_requires})

if(IDF_TARGET STREQUAL "esp32")
target_compile_options(${COMPONENT_TARGET} PUBLIC -DARDUINO=10812 -DARDUINO_ESP32_DEV -DARDUINO_ARCH_ESP32 -DARDUINO_BOARD="ESP32_DEV" -DARDUINO_VARIANT="esp32" -DESP32)
endif()
if(IDF_TARGET STREQUAL "esp32s2")
target_compile_options(${COMPONENT_TARGET} PUBLIC -DARDUINO=10812 -DARDUINO_ESP32S2_DEV -DARDUINO_ARCH_ESP32 -DARDUINO_BOARD="ESP32S2_DEV" -DARDUINO_VARIANT="esp32s2" -DESP32)
endif()
