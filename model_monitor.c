#include <GL/gl.h>
#include "model_monitor.h"
#include "texture.h"

#define SIZE_1 14
#define SIZE_2 28

static unsigned texture;
static unsigned model;

//***************************************************************************
// generate_monitor_model
// Generates the monitor model.
//***************************************************************************

void generate_monitor_model(void)
{
   texture = load_texture("textures/monitor.png");

   model = glGenLists(1);
   glNewList(model, GL_COMPILE);

   // Top
   glBegin(GL_QUADS);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(-SIZE_1, SIZE_2, SIZE_1);
   glVertex3f(SIZE_1, SIZE_2, SIZE_1);
   glVertex3f(SIZE_1, SIZE_2, -SIZE_1);
   glVertex3f(-SIZE_1, SIZE_2, -SIZE_1);

   // Bottom
   glColor3ub(0x60, 0x60, 0x60);
   glVertex3f(-SIZE_1, 0, -SIZE_1);
   glVertex3f(SIZE_1, 0, -SIZE_1);
   glVertex3f(SIZE_1, 0, SIZE_1);
   glVertex3f(-SIZE_1, 0, SIZE_1);

   // Left
   glColor3ub(0xA0, 0xA0, 0xA0);
   glVertex3f(SIZE_1, SIZE_2, SIZE_1);
   glVertex3f(-SIZE_1, SIZE_2, SIZE_1);
   glVertex3f(-SIZE_1, 0, SIZE_1);
   glVertex3f(SIZE_1, 0, SIZE_1);

   // Right
   glColor3ub(0xA0, 0xA0, 0xA0);
   glVertex3f(SIZE_1, SIZE_2, -SIZE_1);
   glVertex3f(SIZE_1, 0, -SIZE_1);
   glVertex3f(-SIZE_1, 0, -SIZE_1);
   glVertex3f(-SIZE_1, SIZE_2, -SIZE_1);

   // Back
   glColor3ub(0x80, 0x80, 0x80);
   glVertex3f(-SIZE_1, SIZE_2, -SIZE_1);
   glVertex3f(-SIZE_1, 0, -SIZE_1);
   glVertex3f(-SIZE_1, 0, SIZE_1);
   glVertex3f(-SIZE_1, SIZE_2, SIZE_1);
   glEnd();

   glEndList();
}

//***************************************************************************
// draw_monitor_model
// Draws a monitor.
//---------------------------------------------------------------------------
// param type: what item is in it
//***************************************************************************

void draw_monitor_model(unsigned type, unsigned anim_time)
{
   // Blink every so often
   if (anim_time % 8 < 2)
      type = 7;

   // Which image to show?
   float u = (type % 4) * 0.25;
   float v = (type / 4) * 0.5;

   // Draw body
   glDisable(GL_TEXTURE_2D);
   glCallList(model);

   // Draw screen
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture);

   glBegin(GL_QUADS);
   glColor3ub(0xFF, 0xFF, 0xFF);
   glTexCoord2d(u, v);
   glVertex3f(SIZE_1, SIZE_2, SIZE_1);
   glTexCoord2d(u, v + 0.5);
   glVertex3f(SIZE_1, 0, SIZE_1);
   glTexCoord2d(u + 0.25, v + 0.5);
   glVertex3f(SIZE_1, 0, -SIZE_1);
   glTexCoord2d(u + 0.25, v);
   glVertex3f(SIZE_1, SIZE_2, -SIZE_1);
   glEnd();
}
