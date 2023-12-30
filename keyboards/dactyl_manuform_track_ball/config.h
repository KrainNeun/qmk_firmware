// Copyright 2023 KrainNeun (@KrainNeun)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* 分割キーボード */
#define MASTER_RIGHT
#define SOFT_SERIAL_PIN D2
#define LAYER_STATE_8BIT
#define DYNAMIC_KEYMAP_LAYER_COUNT 7

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

/* ポインティングデバイス */
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define ADNS5050_SCLK_PIN         B2
#define ADNS5050_SDIO_PIN         B6
#define ADNS5050_CS_PIN           B5

/* RGB */
#define WS2812_DI_PIN D3
#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_LED_COUNT 52
#   define RGB_MATRIX_SPLIT { 27, 25 }
#   define SPLIT_TRANSPORT_MIRROR
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
#   define RGB_DISABLE_WHEN_USB_SUSPENDED
#   define RGB_MATRIX_KEYPRESSES
#   define RGB_MATRIX_DEFAULT_VAL 128
#   define ENABLE_RGB_MATRIX_ALPHAS_MODS
#   define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#   define ENABLE_RGB_MATRIX_BREATHING
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_UP_DOWN
#   define RGB_MATRIX_DEFAULT_SPD 32

#   undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#   undef ENABLE_RGB_MATRIX_BAND_SAT
#   undef ENABLE_RGB_MATRIX_BAND_VAL
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#   undef ENABLE_RGB_MATRIX_CYCLE_ALL
#   undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#   undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#   undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#   undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#   undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#   undef ENABLE_RGB_MATRIX_DUAL_BEACON
#   undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#   undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#   undef ENABLE_RGB_MATRIX_RAINDROPS
#   undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#   undef ENABLE_RGB_MATRIX_HUE_BREATHING
#   undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#   undef ENABLE_RGB_MATRIX_HUE_WAVE
#   undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#   undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#   undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   undef ENABLE_RGB_MATRIX_SPLASH
#   undef ENABLE_RGB_MATRIX_MULTISPLASH
#   undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#   undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif