#ifndef MODEL_SONIC_H
#define MODEL_SONIC_H

// Sonic animations
enum {
   ANIMSONIC_IDLE,            // Idling
   ANIMSONIC_RUN,             // Running slow
   ANIMSONIC_RUN2,            // Running fast
   ANIMSONIC_ROLL,            // Rolling
   ANIMSONIC_SPRING,          // Launched off a spring
   ANIMSONIC_WAIT,            // Waiting
};

void generate_sonic_model(void);
void draw_sonic_model(unsigned, unsigned);

#endif
