/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>

typedef uint8_t ime_status_state;
struct zmk_widget_ime_status
{
    lv_obj_t *obj;
    lv_obj_t *ime_label;
    ime_status_state ime_state;
    sys_snode_t node;
};

#define IME_STATUS_ON 1
#define IME_STATUS_OFF 0

#define DOT_COLOR_WHITE lv_color_hex(0xFFFFFF), lv_color_hex(0xFFFFFF)
#define DOT_COLOR_BLACK lv_color_hex(0x000000), lv_color_hex(0x000000)
#define DOT_COLOR_RED0 lv_color_hex(0xE00000), lv_color_hex(0xE00000)
#define DOT_COLOR_RED1 lv_color_hex(0xA70503), lv_color_hex(0xA70503)
#define DOT_COLOR_YELLOW0 lv_color_hex(0xF6F76B), lv_color_hex(0xF6F76B)
#define DOT_COLOR_YELLOW1 lv_color_hex(0xF5E700), lv_color_hex(0xF5E700)
#define DOT_COLOR_YELLOW2 lv_color_hex(0xE5B400), lv_color_hex(0xE5B400)
#define DOT_COLOR_YELLOW3 lv_color_hex(0xBA7E00), lv_color_hex(0xBA7E00)

int zmk_widget_ime_status_init(struct zmk_widget_ime_status *widget, lv_obj_t *parent);
lv_obj_t *zmk_widget_ime_status_obj(struct zmk_widget_ime_status *widget);
extern void ime_status_update(ime_status_state state);