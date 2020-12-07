
static uint8_t timerBitmask;
static uint8_t keyboardBitmask;
static uint8_t mouseBitmask;


void gameStart(){
    //falta parte gráfica

    //NOT DONE
    timer_subscribe_int(&timerBitmask);
    //NOT DONE
    keyboard_subscribe_int(&keyboardBitmask);
    //NOT DONE
    mouse_subscribe_int(&mouseBitmask);

    //falta rtc e porta serie


    menuStart(/*some sort of variable that holds game settings*/);
    game(/*the same variable passed as an argument in menu start*/);


}