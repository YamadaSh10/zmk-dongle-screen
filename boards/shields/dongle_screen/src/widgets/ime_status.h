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

int zmk_widget_ime_status_init(struct zmk_widget_wpm_status *widget, lv_obj_t *parent);
lv_obj_t *zmk_widget_ime_status_obj(struct zmk_widget_wpm_status *widget);
extern void ime_status_update(ime_status_state state);