#include "entity.h"
#include "model_ring.h"
#include "ring.h"

//***************************************************************************
// draw_ring
// Draws a ring entity.
//---------------------------------------------------------------------------
// param entity: pointer to entity
//***************************************************************************

void draw_ring(Entity *entity)
{
   draw_ring_model(entity->anim_time);
   entity->shadow = 16;
}
