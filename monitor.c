#include "entity.h"
#include "model_monitor.h"
#include "monitor.h"

//***************************************************************************
// draw_monitor
// Draws a monitor entity.
//---------------------------------------------------------------------------
// param entity: pointer to entity
//***************************************************************************

void draw_monitor(Entity *entity)
{
   draw_monitor_model(entity->type - ENTITY_MON_RING, entity->anim_time);
}
