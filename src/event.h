typedef enum keyboard_event {
  W_pressed = 0,
  A_pressed = 1,
  D_pressed = 2,
  S_pressed = 3,
  enter_pressed = 4,
  up_pressed = 5,
  down_pressed = 6,
  left_pressed = 7,
  right_pressed = 8,

  W_released = 9,
  A_released = 10,
  D_released = 11,
  S_released = 12,
  enter_released = 13,
  up_released = 14,
  down_released = 15,
  left_released = 16,
  right_released = 17,

  any_pressed = 18,
  any_released = 19,

  ESC_pressed = 20

} event_keyboard;

