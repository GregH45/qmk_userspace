// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "qp.h"
#include "qp_surface.h"
#include "bongo.h"

static uint8_t bongo_frame = 0;
static uint32_t last_bongo_tap = 0;

// All values (including hue) are scaled to 0-255
#define HSV_SPLITKB 145, 235, 155
#define HSV_CAPS_OFF 17, 104, 77
#define HSV_CAPS_ON 17, 191, 245
#define HSV_SCROLL_OFF 202, 104, 77
#define HSV_SCROLL_ON 202, 191, 245
#define HSV_NUM_OFF 142, 104, 77
#define HSV_NUM_ON 142, 191, 245

#define HSV_LAYER_0 0, 0, 160
#define HSV_LAYER_3 0, 82, 255
#define HSV_LAYER_1 23, 89, 255
#define HSV_LAYER_2 43, 71, 255
#define HSV_LAYER_4 77, 64, 255
#define HSV_LAYER_6 131, 99, 255
#define HSV_LAYER_7 154, 94, 255
#define HSV_LAYER_5 176, 77, 255
// #define HSV_LAYER_8 213, 56, 255
#define HSV_LAYER_UNDEF 0, 255, 255

extern painter_device_t lcd;
extern painter_device_t lcd_surface;

void render_bongo(void) {
    if (timer_elapsed32(last_bongo_tap) > 200) {
        bongo_frame = 0; // idle after inactivity
    }

    switch (bongo_frame) {
        case 1:
            qp_drawimage(lcd_surface, 20, 40, qp_load_image_mem(bongo_left));
            break;
        case 2:
            qp_drawimage(lcd_surface, 20, 40, qp_load_image_mem(bongo_right));
            break;
        default:
            qp_drawimage(lcd_surface, 20, 40, qp_load_image_mem(bongo_idle));
            break;
    }
}
void draw_grid(void);
void update_grid(void);
void init_grid(void);
void add_cell_cluster(void);
uint8_t get_random_color_index(void);
void update_display(void);
void backlight_wakeup(void);
void backlight_suspend(void);
