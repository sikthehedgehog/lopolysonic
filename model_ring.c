#include <GL/gl.h>
#include "billboard.h"
#include "texture.h"

static unsigned texture;

//***************************************************************************
// generate_ring_model
// Loads the ring assets.
//***************************************************************************

void generate_ring_model(void)
{
   texture = load_texture("textures/ring.png");
}

//***************************************************************************
// draw_ring_model
// Draws a ring.
//---------------------------------------------------------------------------
// param anim: animation counter
//***************************************************************************

void draw_ring_model(unsigned anim)
{
   anim = (anim / 2) % 32;
   float u = (anim % 4) * 0.25;
   float v = (anim / 4) * 0.25;

   draw_billboard(texture, 16, 16,
      u, v, u + 0.25, v + 0.25);
}
