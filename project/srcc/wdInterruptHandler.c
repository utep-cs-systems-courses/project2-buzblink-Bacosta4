#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if ((++blink_count == 4) && switch3_state_down) {
    dim();
    blink_count = 0;
  }
  if((++blink_count == 60) && switch2_state_down) {
    buzzer();
    blink_count = 0;

  }
}
