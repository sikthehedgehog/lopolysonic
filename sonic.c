#include <SDL2/SDL.h>
#include "camera.h"
#include "entity.h"
#include "input.h"
#include "model_sonic.h"
#include "physics.h"
#include "sonic.h"
#include "util.h"

#define MAX_SPEED       8.0         // Speed at which Sonic can run
#define ACCEL_SPEED     0.075       // How fast Sonic accelerates
#define WEIGHT          0.25        // How fast Sonic falls
#define WEIGHT2         0.15        // Extra weight when not holding Z/C

#define RUN_SPEED       0.1         // Speed at which Sonic is running slow
#define RUN2_SPEED      7.0         // Speed at which Sonic is running fast

//***************************************************************************
// update_sonic
// Handles the logic for a Sonic entity.
//---------------------------------------------------------------------------
// param entity: pointer to entity
//***************************************************************************

void update_sonic(Entity *entity)
{
   // Determine direction to go
   unsigned dir = 0;
   if (held_down(SDL_SCANCODE_UP)) dir |= 0x01;
   if (held_down(SDL_SCANCODE_DOWN)) dir |= 0x02;
   if (held_down(SDL_SCANCODE_LEFT)) dir |= 0x04;
   if (held_down(SDL_SCANCODE_RIGHT)) dir |= 0x08;
   if ((dir & 0x03) == 0x03) dir &= 0x0C;
   if ((dir & 0x0C) == 0x0C) dir &= 0x03;

   float aim = 0;
   switch (dir) {
      case 0x01: aim = 90; break;         // North
      case 0x02: aim = -90; break;        // South
      case 0x04: aim = 180; break;        // West
      case 0x08: aim = 0; break;          // East
      case 0x05: aim = 135; break;        // Northwest
      case 0x09: aim = 45; break;         // Northeast
      case 0x06: aim = -135; break;       // Southwest
      case 0x0A: aim = -45; break;        // Southeast
   }

   // Determine acceleration
   float ideal_speed_x;
   float ideal_speed_z;

   if (dir) {
      entity->angle = aim - camera.angle - 90;
      ideal_speed_x = cos(deg2rad(entity->angle)) * MAX_SPEED;
      ideal_speed_z = -sin(deg2rad(entity->angle)) * MAX_SPEED;
   } else {
      ideal_speed_x = 0;
      ideal_speed_z = 0;
   }

   do_accel(entity, ACCEL_SPEED, 0, 0);
   do_accel(entity, ACCEL_SPEED*2, ideal_speed_x, ideal_speed_z);

   // Do physics
   apply_physics(entity);

   // Apply weight
   entity->speed_y -= WEIGHT;
   if (!entity->on_floor && entity->speed_y > 0 &&
   !(held_down(SDL_SCANCODE_Z) || held_down(SDL_SCANCODE_C))) {
      entity->speed_y -= WEIGHT2;
   }

   // Jump?
   if (entity->on_floor &&
   (was_pressed(SDL_SCANCODE_Z) || was_pressed(SDL_SCANCODE_C))) {
      entity->on_floor = 0;
      entity->speed_y = 6;
   }

   // Determine animation
   unsigned anim = ANIMSONIC_IDLE;
   if (!within_dist(entity->speed_x, entity->speed_z, RUN_SPEED))
      anim = ANIMSONIC_RUN;
   if (!within_dist(entity->speed_x, entity->speed_z, RUN2_SPEED))
      anim = ANIMSONIC_RUN2;
   if (!entity->on_floor)
      anim = ANIMSONIC_ROLL;

   if (entity->anim != anim) {
      entity->anim = anim;
      entity->anim_time = 0;
   }

   // Make camera chase us
   camera.x = entity->x;
   camera.y = entity->y;
   camera.z = entity->z;
}

//***************************************************************************
// draw_sonic
// Draws a Sonic entity.
//---------------------------------------------------------------------------
// param entity: pointer to entity
//***************************************************************************

void draw_sonic(Entity *entity)
{
   draw_sonic_model(entity->anim, entity->anim_time);
   entity->shadow = 28;
}
