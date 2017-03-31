#include <GL/gl.h>
#include "physics.h"
#include "shadow.h"
#include "texture.h"

static unsigned texture;

//***************************************************************************
// generate_shadow
// Loads the shadow assets.
//***************************************************************************

void generate_shadow(void)
{
   texture = load_texture("textures/shadow.png");
}

//***************************************************************************
// draw_shadow
// Draws a shadow. The position indicates where the object is, the shadow
// will be drawn in whatever floor is below it.
//---------------------------------------------------------------------------
// param x: X coordinate
// param y: Y coordinate
// param z: Z coordinate
// param size: shadow size
//***************************************************************************

void draw_shadow(float x, float y, float z, float size)
{
   // Turn size into a radius
   size *= 0.5;

   // Find floor height
   y = find_floor(x, y, z) + 0.25;

   // Draw the shadow
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture);
   glColor3ub(0xFF, 0xFF, 0xFF);
   glBegin(GL_QUADS);
   glTexCoord2d(1, 0);
   glVertex3f(x - size, y, z - size);
   glTexCoord2d(0, 0);
   glVertex3f(x - size, y, z + size);
   glTexCoord2d(0, 1);
   glVertex3f(x + size, y, z + size);
   glTexCoord2d(1, 1);
   glVertex3f(x + size, y, z - size);
   glEnd();
}
