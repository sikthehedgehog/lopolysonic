#ifndef PHYSICS_H
#define PHYSICS_H

#include "entity.h"

void apply_physics(Entity *);
float find_floor(float, float, float);
void do_accel(Entity *, float, float, float);

#endif
