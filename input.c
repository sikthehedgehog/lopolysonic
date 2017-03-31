#include <SDL2/SDL.h>
#include "input.h"

// Number of key scancodes
#define NUM_KEYS 0x200

static int key_held[NUM_KEYS];      // Keys which are held down
static int key_press[NUM_KEYS];     // Keys which just got pressed

//***************************************************************************
// init_input
// Sets up the input devices.
//***************************************************************************

void init_input(void)
{
   // Reset keys
   for (unsigned i = 0; i < NUM_KEYS; i++) {
      key_held[i] = 0;
      key_press[i] = 0;
   }
}

//***************************************************************************
// refresh_presses
// Takes care of one-frame key presses. Call it after every logic frame.
//***************************************************************************

void refresh_presses(void)
{
   for (unsigned i = 0; i < NUM_KEYS; i++)
      key_press[i] = 0;
}

//***************************************************************************
// deinit_input
// Shuts down the input devices.
//***************************************************************************

void deinit_input(void)
{
}

//***************************************************************************
// do_keydown
// Handles a key getting pressed.
//---------------------------------------------------------------------------
// param scancode: key scancode
//***************************************************************************

void do_keydown(unsigned scancode)
{
   key_press[scancode] = !key_held[scancode];
   key_held[scancode] = 1;
}

//***************************************************************************
// do_keyup
// Handles a key getting released.
//---------------------------------------------------------------------------
// param scancode: key scancode
//***************************************************************************

void do_keyup(unsigned scancode)
{
   key_held[scancode] = 0;
}

//***************************************************************************
// held_down
// Checks if a key is being held down.
//---------------------------------------------------------------------------
// param scancode: key scancode
// return: 1 if pressed, 0 if not
//***************************************************************************

int held_down(unsigned scancode)
{
   return key_held[scancode];
}

//***************************************************************************
// was_pressed
// Checks if a key was just pressed.
//---------------------------------------------------------------------------
// param scancode: key scancode
// return: 1 if pressed, 0 if not
//***************************************************************************

int was_pressed(unsigned scancode)
{
   return key_press[scancode];
}
