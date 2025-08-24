/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/event_manager.h>
#include <zmk/events/ime_state_changed.h>

#include "ime_status.h"
#include <fonts.h>

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

static void set_ime(struct zmk_widget_ime_status *widget, ime_status_state state)
{

    char ime_text[12];
    if(state==IME_STATUS_ON) snprintf(ime_text, sizeof(ime_text), "ON");
    else snprintf(ime_text, sizeof(ime_text), "OFF");
    lv_label_set_text(widget->ime_label, ime_text);
}

void ime_status_update(ime_status_state state)
{
    struct zmk_widget_ime_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node)
    {
        set_ime(widget, state);
    }
}

// output_status.c
int zmk_widget_ime_status_init(struct zmk_widget_ime_status *widget, lv_obj_t *parent)
{
    widget->obj = lv_obj_create(parent);
    lv_obj_set_size(widget->obj, 240, 77);

    widget->ime_label = lv_label_create(widget->obj);
    lv_obj_align(widget->ime_label, LV_ALIGN_TOP_LEFT, 0, 0);

    sys_slist_append(&widgets, &widget->node);

    widget->ime_state = IME_STATUS_OFF;
    return 0;
}

lv_obj_t *zmk_widget_ime_status_obj(struct zmk_widget_ime_status *widget)
{
    return widget->obj;
}
