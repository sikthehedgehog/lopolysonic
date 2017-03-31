#ifndef INPUT_H
#define INPUT_H

// Control
void init_input(void);
void refresh_presses(void);
void deinit_input(void);

// Events
void do_keydown(unsigned);
void do_keyup(unsigned);

// Checking input
int held_down(unsigned);
int was_pressed(unsigned);

#endif
