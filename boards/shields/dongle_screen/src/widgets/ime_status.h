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

#define DOT_COLOR_WHITE 0xFFFFFF
#define DOT_COLOR_BLACK 0x000000
#define DOT_COLOR_RED0 0xE00000
#define DOT_COLOR_RED1 0xA70503
#define DOT_COLOR_YELLOW0 0xF6F76B
#define DOT_COLOR_YELLOW1 0xF5E700
#define DOT_COLOR_YELLOW2 0xE5B400
#define DOT_COLOR_YELLOW3 0xBA7E00
#define DOT_COLOR_BACK DOT_COLOR_BLACK

#define ILLUST_WIDTH 78
#define ILLUST_HEIGHT 90

int zmk_widget_ime_status_init(struct zmk_widget_ime_status *widget, lv_obj_t *parent);
lv_obj_t *zmk_widget_ime_status_obj(struct zmk_widget_ime_status *widget);
extern void ime_status_update(ime_status_state state);
extern const unsigned char blue_ham_ham_mini_left_map[];
extern const unsigned char blue_ham_ham_mini_right_map[];