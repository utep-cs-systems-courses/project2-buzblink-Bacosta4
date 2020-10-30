#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

char toggle_red()		/* always red led! */
{
  red_on = 1;
  green_on = 0;
  led_changed = 1;
  led_update();
}

char toggle_green()	/* always green led!  */
{
  green_on = 1;
  red_on = 0;
  led_changed = 1;
  led_update();
}

void toggle_led()
{
  static char state = 0;
  
  switch(state) {
  case 0:
    toggle_red();
    state = 1;
    break;

  case 1:
    toggle_green();
    state = 0;
    break;
  }
}
