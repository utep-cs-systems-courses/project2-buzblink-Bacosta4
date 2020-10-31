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

void led25()
{
    char changed = 0;
    static char state = 0;
    
    switch(state) {
      
      case 0:
	red_on = 0;
	green_on = 0;
	state = 1;
	changed = 1;
	break;

      case 1:
	red_on = 0;
	green_on = 0;
	state = 2;
	break;

      case 2:
	red_on = 0;
	green_on = 0;
	state = 3;
	break;

      case 3:
        red_on = 1;
        green_on = 1;
        state = 0;
	changed = 1;
      }
    led_changed = changed;
    led_update();
}

void led50()
{
  char changed = 0;
  static char state = 0;
  
  switch(state) {
    case 0:
      red_on = 1;
      green_on = 1;
      state = 1;
      changed = 1;
      break;

    case 1:
      red_on = 0;
      green_on = 0;
      state = 0;
      changed = 1;
      break;
    }
  led_changed = changed;
  led_update();
}

void led75()
{
  char changed = 0;
  static char state = 0;
  
  switch(state) {
    
  case 0:
    red_on = 0;
    green_on = 0;
    state = 1;
    changed = 1;
    break;
    
  case 1:
    red_on = 1;
    green_on = 1;
    state = 2;
    changed = 1;
    break;
    
  case 2:
    red_on = 1;
    green_on = 1;
    state = 3;
    break;

  case 3:
    red_on = 1;
    green_on = 1;
    state = 0;
  }
  led_changed = changed;
  led_update();
}

void dim()
{
  static char state = 0;
  switch(state) {
  case 0:
    led50();
    led50();
    state = 1;
    break;

  case 1:
    led75();
    led75();
    state = 2;
    break;

  case 2:
    led25();
    led25();
    state = 0;
    break;
  }
  led_changed = 1;
  led_update();
}
