/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>

struct zmk_widget_wpm_status
{
    lv_obj_t *obj;
    lv_obj_t *wpm_label;
    lv_obj_t *font_test;
    sys_snode_t node;
};

#define BATTERY 0x00u
#define LAYER 0x01u
#define MOD 0x02u
#define OUTPUT 0x03u
#define BRIGHTNESS 0x04u

int zmk_widget_wpm_status_init(struct zmk_widget_wpm_status *widget, lv_obj_t *parent);
lv_obj_t *zmk_widget_wpm_status_obj(struct zmk_widget_wpm_status *widget);

void wpm_status_update_cb(unsigned char state);