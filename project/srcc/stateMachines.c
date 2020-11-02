#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"


static char sb = 1;
static char state = 0;

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

char toggle_both() {
  green_on = 1;
  red_on = 1;
  led_changed = 1;
  led_update();
}

void toggle_led()
{  
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
    switch(state) {
      
      case 0:
	red_on = 0;
	state = 1;
	break;

      case 1:
	red_on = 0;
	state = 2;
	break;

      case 2:
	red_on = 0;
	state = 3;
	break;

      case 3:
        red_on = 1;
        state = 0;
    } 
}

void led50()
{ 
  switch(state) {
    case 0:
      red_on = 1;
      state = 1;
      break;

    case 1:
      red_on = 0;
      state = 0;
      break;
    }
}

void led75()
{ 
  switch(state) {
    
  case 0:
    red_on = 1;
    state = 1;
    break;
    
  case 1:
    red_on = 1;
    state = 2;
    break;
    
  case 2:
    red_on = 1;
    state = 3;
    break;

  case 3:
    red_on = 0;
    state = 0;
  }
}

void dim()
{
  static char state = 0;
  switch (state){
  case 0:
    toggle_red();
    state = 1;
    break;
    
  case 1:
    led25();
    state = 2;
    break;

  case 2:
    led50();
    state = 3;

  case 3:
    led75();
    state = 0;
    break;
 }
}

void buzzer() {
  static int x = 500;
  if(sb) {
    toggle_red();
    x += 225;
  }
  else { 
    toggle_green();
    x -= 450;
  }
  short cycles = 2000000 / x;
  buzzer_set_period(cycles);
}

void siren() {

  switch(state) {

  case 0:
    sb = 1;
    state++;
    break;
    
  case 1:
    sb = 0;
    state = 0;
    break;
    
  default:
    break;
  }
}
