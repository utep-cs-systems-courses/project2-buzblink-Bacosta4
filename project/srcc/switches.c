#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

//char switch_state_down, switch_state_changed; /* effectively boolean */

char switch1_state,switch2_state,switch3_state,switch4_state;
switch_state = 0;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  switch1_state = (p2val & SW1) ? 0 : 1;  // which button is being pressed
  switch2_state = (p2val & SW2) ? 0 : 1;
  //switch3_state = (p2val & SW3) ? 0 : 1;
  // switch4_state = (p2val & SW4) ? 0 : 1;

  if (switch1_state) {   // which button was pressed
    dim();
    switch_state = 1;
  }

  // if (switch2_state) {
  //dim();
  //switch_state = 2;
  //  }
  
}
