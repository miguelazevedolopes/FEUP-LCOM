#include "keyboard_state.h"
#include "i8042.h"

void(update_state)(keyboard_state *state, uint8_t scancode) {

    switch (scancode)
    {
      case ESC_KEY:
          *state = escape;
          break;

      case UP_KEY:          
          if(*state == up_pressed || *state == up_pressing || *state == down_pressed || 
          *state == right_pressed || *state == up_right_pressed || *state == down_right_pressed || *state == null) {
              *state = up_pressing;
          } 
          else if(*state == right_pressing || *state == up_pressed_right_pressing) {
              *state = up_right_pressing;
          }

          break;

      case DOWN_KEY:
          if(*state == up_pressed || *state == down_pressing || *state == down_pressed || 
          *state == right_pressed || *state == up_right_pressed || *state == down_right_pressed) {
              *state = down_pressing;
          }
          else if(*state == right_pressing || *state == down_pressed_right_pressing) {
              *state = down_right_pressing; 
          }

          break;

      case RIGHT_KEY:
          if (*state == up_pressing || *state == up_pressing_right_pressed) {
              *state = up_right_pressing;
          }
          else if (*state == down_pressing || *state == down_pressing_right_pressed) {
              *state = down_right_pressing;
          }
          else if (*state == right_pressing || *state == right_pressed || *state == up_pressed ||
           *state == down_pressed || *state == up_right_pressed || *state == down_right_pressed) {
              *state = right_pressing;
          }

          break;
      case UP_KEY_BREAK:
          if (*state == up_pressing) {
              *state = up_pressed;
          }
          else if (*state == up_right_pressing) {
              *state = up_pressed_right_pressing;
          }
          else if (*state == up_pressing_right_pressed) {
              *state = up_right_pressed;
          }
          break;

      case DOWN_KEY_BREAK:
          if (*state == down_pressing) {
              *state = down_pressed;
          }
          else if (*state == down_right_pressing) {
              *state = down_pressed_right_pressing;
          }
          else if (*state == down_pressing_right_pressed) {
              *state = down_right_pressed;
          }
          break;
      case RIGHT_KEY_BREAK:
          if (*state == right_pressing) {
             *state = right_pressed;
          }
          else if(*state == up_right_pressing) {
              *state = up_pressing_right_pressed;
          }
          else if(*state == down_right_pressing) {
              *state = down_pressing_right_pressed;
          }
          
          else if(*state == up_pressed_right_pressing) {
              *state = up_right_pressed;
          }
          else if(*state == down_pressed_right_pressing) {
              *state = down_right_pressed;
          }
      default:
        break;
    }
}

void(print_state)(keyboard_state * state) {
    if (*state == up_pressing || *state == up_pressed)
    {
      printf("\ngoing up\n");
    }
    else if(*state == down_pressing || *state == down_pressed) {
      printf("\ngoing down\n");
    }
    else if(*state == right_pressing || *state == right_pressed) {
      printf("\nright\n");
    }
    else if(*state == up_right_pressing) {
      printf("\nentrar declive positivo\n");
    }
    else if (*state == down_right_pressing) {
      printf("\nentrar declive negativo\n");
    }
    else if( *state == up_right_pressed ) {
      printf("\nsair declive positivo\n");
    }
    else if( *state == down_right_pressed ) {
      printf("\nsair declive negativo\n");
    }
    else if(*state == up_pressed_right_pressing || *state == down_pressed_right_pressing) {
      printf("\nlarga o RIGHT\n");
    }
    else if(*state == up_pressing_right_pressed ) {
      printf("\nlarga o UP\n");
    }
    
    else if(*state == down_pressing_right_pressed ) {
      printf("\nlarga o DOWN\n");
    }
}
