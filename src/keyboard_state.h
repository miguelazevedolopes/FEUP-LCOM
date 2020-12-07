
#include <stdint.h>
#include <stdio.h>


typedef enum  {
    up_pressing,
    up_pressed,
    down_pressing,
    down_pressed,
    escape,
    right_pressing, 
    right_pressed,
    first_byte,

    up_right_pressed,
    down_right_pressed,

    up_right_pressing,
    down_right_pressing, 
    
    up_pressed_right_pressing,
    down_pressed_right_pressing, 
    
    up_pressing_right_pressed,
    down_pressing_right_pressed,

    null,
}keyboard_state;


void(print_state)(keyboard_state * state);

void (update_state)(keyboard_state * state , uint8_t scancode);
