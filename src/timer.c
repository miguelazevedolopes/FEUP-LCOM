#include <lcom/lcf.h>
#include <lcom/timer.h>

#include <stdint.h>
#include "utils.c"
#include "i8254.h"

int id;
unsigned int timer_interrupt_counter = 0;

int (timer_set_frequency)(uint8_t timer, uint32_t freq) {
  //duvidas - linha 19
  //minimun working frequency is 19Hz and maximum is TIMER_FREQ
  if(freq<19||freq>TIMER_FREQ){
    printf("timer_set_frequency:Frequency must be a value between 19 and 1193182Hz");
  }
  uint8_t conf;
  uint16_t val;
  val=TIMER_FREQ/freq; //determines the frequency of the interrupts
  uint8_t val_msb,val_lsb;
  timer_get_conf(timer,&conf);
  conf=conf&0x0F;//making sure the 4 MS bits stay the same (mas pq??)
  util_get_MSB(val,&val_msb);
  util_get_LSB(val,&val_lsb);

  switch (timer){
    case 0:
      conf=(conf|TIMER_SEL0|TIMER_LSB_MSB);
      if (sys_outb(TIMER_CTRL,conf)!=OK) {
        printf("timer_set_frequency:Error writing control word");
        return 1;}
      if (sys_outb(TIMER_0,val_lsb)!=OK) {
        printf("timer_set_frequency:Error writing counter initial value");
        return 1;}
      if (sys_outb(TIMER_0,val_msb)!=OK) {
        printf("timer_set_frequency:Error writing counter initial value");
        return 1;}
      break;
    case 1:
      conf=(conf|TIMER_SEL1|TIMER_LSB_MSB);
      if (sys_outb(TIMER_CTRL,conf)!=OK) {
        printf("timer_set_frequency:Error writing control word");
        return 1;}
      if (sys_outb(TIMER_1,val_lsb)!=OK) {
        printf("timer_set_frequency:Error writing counter initial value");
        return 1;}
      if (sys_outb(TIMER_1,val_msb)!=OK) {
        printf("timer_set_frequency:Error writing counter initial value");
        return 1;}
      break;
    case 2:
      conf=(conf|TIMER_SEL2|TIMER_LSB_MSB);
      if (sys_outb(TIMER_CTRL,conf)!=OK) {
        printf("timer_set_frequency:Error writing control word");
        return 1;}
      if (sys_outb(TIMER_2,val_lsb)!=OK) {
        printf("timer_set_frequency:Error writing counter initial value");
        return 1;}
      if (sys_outb(TIMER_2,val_msb)!=OK) {
        printf("timer_set_frequency:Error writing counter initial value");
        return 1;}
      break;
    
  }
  return 0;
}



int (timer_subscribe_int)(uint8_t *bit_no) {
  *bit_no = BIT(id);
  //subscribes notifications from timer0 based on id passed as 3rd argument
  //from now on the IRQ line 0 will be masked
  if(sys_irqsetpolicy(TIMER0_IRQ,IRQ_REENABLE,&id) != OK){
    printf("sys_irqsetpolicy::Error setting policy\n");
    return 1;
  }

  return 0;
}

int (timer_unsubscribe_int)() {
    if (sys_irqdisable(&id) == 0){
        if (sys_irqrmpolicy(&id) == 0) {
          return 0;
        }
        printf("timer_unsubscribe_int didn't disable the policy\n");
        return 1;
    }
    else {
      printf("timer_unsubscribe_int didn't disable interruptions\n");
      return 1;
    }
    

    
  return 1;
}

void (timer_int_handler)() {
  timer_interrupt_counter++;
}

int (timer_get_conf)(uint8_t timer, uint8_t *st) {  
  //(ler a configuração do timer "timer")
  // 1º prear o read back command para aceder ao status do timer
    uint8_t cmd = 0;
    cmd = TIMER_RB_CMD | TIMER_RB_COUNT_ |TIMER_RB_SEL(timer);   //timer readback command
//count barra fica 0 1110..
    if (sys_outb(TIMER_CTRL, cmd) != OK) {
      printf("Error in sys_outb()\n");
    } //envia para para o registo/port timer ctrl o cmd(read back command) que diz que quero ler o status do timer "timer"(0,1,2)
    //buscar ao timer "timer" a informacao a util sys_inb
    if (util_sys_inb(TIMER_0 + timer, st) != OK)
    {
      printf("Error in sys_inb()\n");
      return 1;
    }
    
    return 0;

}

int (timer_display_conf)(uint8_t timer, uint8_t st,enum timer_status_field field) {
    union timer_status_field_val stat;
    uint8_t init_mode;
    uint8_t temp;
    switch (field)
    {
      case tsf_all:
        stat.byte = st;
        break;

      case tsf_initial:
        init_mode = st;
          switch (init_mode)
          {
          case 0:
            stat.in_mode = INVAL_val;
            break;
          case 1:
            stat.in_mode = LSB_only;
            break;
          case 2:
            stat.in_mode = MSB_only;
            break;
          case 3:
            stat.in_mode = MSB_after_LSB;
            break;
          default:
            return 1;
          }
        break;

      
      case tsf_mode:
        temp =st;
        stat.count_mode = temp;
        break;

      case tsf_base:
        stat.bcd = (bool) st;
        break;

        default:
          return 1;
    }

    timer_print_config(timer, field, stat);
    return 0;
}


