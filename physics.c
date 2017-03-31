#include "entity.h"
#include "physics.h"
#include "util.h"

//***************************************************************************
// apply_physics
// Computes the physics stuff for an entity.
//---------------------------------------------------------------------------
// param entity: pointer to entity
//***************************************************************************

void apply_physics(Entity *entity)
{
   // Keep old coordinates around
   // Used for collision response
   float old_x = entity->x;
   float old_y = entity->y;
   float old_z = entity->z;

   // Apply momentum
   entity->x += entity->speed_x;
   entity->y += entity->speed_y;
   entity->z += entity->speed_z;

   // Don't let it go through the floor
   float floor = find_floor(entity->x, entity->y, entity->z);
   if (entity->y <= floor) {
      entity->y = floor;
      entity->on_floor = 1;
   } else {
      entity->on_floor = 0;
   }

   // Update speed according to collision response
   entity->speed_x = entity->x - old_x;
   entity->speed_y = entity->y - old_y;
   entity->speed_z = entity->z - old_z;
}

//***************************************************************************
// find_floor
// Finds the height of the nearest floor at this position.
//---------------------------------------------------------------------------
// param x: X coordinate
// param y: Y coordinate
// param z: Z coordinate
// return: height of nearest floor
//***************************************************************************

float find_floor(float x, float y, float z)
{
   // Hardcoded for now
   (void)(x);
   (void)(y);
   (void)(z);
   return 0;
}

void do_accel(Entity *entity, float accel, float target_x, float target_z)
{
   float dist_x = target_x - entity->speed_x;
   float dist_z = target_z - entity->speed_z;

   if (within_dist(dist_x, dist_z, accel)) {
      entity->speed_x = target_x;
      entity->speed_z = target_z;
   } else {
      float angle = get_angle(dist_x, dist_z);
      entity->speed_x += cos(deg2rad(angle)) * accel;
      entity->speed_z += sin(deg2rad(angle)) * accel;
   }
}
