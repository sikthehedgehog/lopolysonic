#include <stdlib.h>
#include <GL/gl.h>
#include "entity.h"
#include "monitor.h"
#include "ring.h"
#include "shadow.h"
#include "sonic.h"

// Entity list
// If the need arises this may be changed to a dynamically allocated list...
// just interested on getting it working for now. Gonna try isolating this
// as much as possible by relying on entity IDs (which are integers) instead.
#define MAX_ENTITIES 0x400
static Entity entities[MAX_ENTITIES];

// Helper functions
static void update_an_entity(Entity *);
static void draw_an_entity(Entity *);

//***************************************************************************
// init_entities
// Initializes the entity manager.
//***************************************************************************

void init_entities(void)
{
   // Free up all slots
   for (unsigned i = 0; i < MAX_ENTITIES; i++)
      entities[i].type = ENTITY_NONE;
}

//***************************************************************************
// add_entity
// Spawns a new entity.
//---------------------------------------------------------------------------
// param type: kind of entity
// param x: initial X coordinate
// param y: initial Y coordinate
// param z: initial Z coordinate
// param angle: initial angle
// return: entity ID
//***************************************************************************

unsigned add_entity(EntityType type, float x, float y, float z, float angle)
{
   // Find a free slot
   unsigned id;
   for (id = 0; id < MAX_ENTITIES; id++)
      if (entities[id].type == ENTITY_NONE) break;
   if (id == MAX_ENTITIES)
      abort();

   // Initialize entity
   Entity *entity = get_entity_ptr(id);
   entity->type = type;
   entity->update_func = NULL;
   entity->draw_func = NULL;

   entity->x = x;
   entity->y = y;
   entity->z = z;
   entity->speed_x = 0;
   entity->speed_y = 0;
   entity->speed_z = 0;

   entity->angle = angle;
   entity->tilt = 0;

   entity->anim = 0;
   entity->anim_time = 0;
   entity->shadow = 0;

   entity->on_floor = 0;

   // Hackish way to set up object behavior
   switch (type) {
      case ENTITY_SONIC:
         entity->update_func = update_sonic;
         entity->draw_func = draw_sonic;
         break;
      case ENTITY_RING:
         entity->draw_func = draw_ring;
         break;
      case ENTITY_MON_RING:
      case ENTITY_MON_STARS:
      case ENTITY_MON_SHOES:
         entity->draw_func = draw_monitor;
         break;
      default:
         break;
   }

   // Done
   return id;
}

//***************************************************************************
// get_entity_ptr
// Gets a pointer to an entity by its ID.
//---------------------------------------------------------------------------
// param id: entity ID
// return: pointer to entity
//***************************************************************************

Entity *get_entity_ptr(unsigned id)
{
   return &entities[id];
}

//***************************************************************************
// update_entities
// Updates the logic for all entities.
//***************************************************************************

void update_entities(void)
{
   for (unsigned id = 0; id < MAX_ENTITIES; id++)
      update_an_entity(get_entity_ptr(id));
}

static void update_an_entity(Entity *entity)
{
   // Don't bother with these
   if (entity->type == ENTITY_NONE)
      return;

   // Let the animation flow
   entity->anim_time++;

   // Let the entity run its logic
   if (entity->update_func != NULL)
      entity->update_func(entity);
}

//***************************************************************************
// draw_entities
// Draws all entities.
//***************************************************************************

void draw_entities(void)
{
   for (unsigned id = 0; id < MAX_ENTITIES; id++)
      draw_an_entity(get_entity_ptr(id));
}

static void draw_an_entity(Entity *entity)
{
   // Don't bother with these
   if (entity->type == ENTITY_NONE)
      return;

   // Draw entity
   if (entity->draw_func != NULL) {
      glPushMatrix();
      glTranslatef(entity->x, entity->y, entity->z);
      glRotatef(entity->angle, 0, 1, 0);
      glRotatef(entity->tilt, 0, 0, 1);
      entity->draw_func(entity);
      glPopMatrix();
   }

   // If it has a shadow, draw it
   if (entity->shadow > 0) {
      draw_shadow(entity->x, entity->y, entity->z, entity->shadow);
   }
}
