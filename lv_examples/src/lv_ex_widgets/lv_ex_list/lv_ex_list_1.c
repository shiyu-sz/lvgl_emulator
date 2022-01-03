#include "../../../lv_examples.h"
#include <stdio.h>
#if LV_USE_LIST

static void event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        printf("Clicked: %s\n", lv_list_get_btn_text(obj));
    }
}

static lv_style_t btn_style;

void style_init(void){
    lv_style_init(&btn_style);
    lv_style_set_bg_color(&btn_style,LV_STATE_DEFAULT, LV_COLOR_MAKE(21,21,21));
    lv_style_set_bg_color(&btn_style,LV_STATE_PRESSED, LV_COLOR_MAKE(58,97,238));
    lv_style_set_border_width(&btn_style,LV_STATE_DEFAULT, 0);
    lv_style_set_radius(&btn_style, LV_STATE_DEFAULT, 0);
}

void lv_ex_list_1(void)
{
    /*Create a list*/
    lv_obj_t * list1 = lv_list_create(lv_scr_act(), NULL);
    lv_obj_set_size(list1, 160, 128);
    lv_obj_align(list1, NULL, LV_ALIGN_IN_TOP_LEFT, 0,0);

    style_init();
    /*Add buttons to the list*/
    lv_obj_t * list_btn;
//LV_LIST_PART_BG
    lv_obj_add_style(list1,LV_OBJ_PART_MAIN,&btn_style);

//    list_btn = lv_list_add_btn(list1, LV_SYMBOL_FILE, "New");
    lv_obj_t *list_btn1;

    lv_obj_add_style(list_btn1,LV_OBJ_PART_MAIN,&btn_style);
    list_btn1= lv_list_add_btn(list1, LV_SYMBOL_FILE, "New");
    lv_obj_set_event_cb(list_btn1, event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_DIRECTORY, "Open");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_CLOSE, "Delete");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_EDIT, "Edit");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_SAVE, "Save");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_BELL, "Notify");
    lv_obj_set_event_cb(list_btn, event_handler);

    list_btn = lv_list_add_btn(list1, LV_SYMBOL_BATTERY_FULL, "Battery");
    lv_obj_set_event_cb(list_btn, event_handler);
}

#endif
