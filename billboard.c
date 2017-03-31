#include <GL/gl.h>
#include "billboard.h"
#include "camera.h"

//***************************************************************************
// draw_billboard
// Draws a billboard (a sprite in 3D space always facing the camera).
//---------------------------------------------------------------------------
// param texture: texture ID
// param width: width in units
// param height: height in units
// param u1, v1: top-left coordinate of texture
// param u2, v2: bottom-right coordinate of texture
//***************************************************************************

void draw_billboard(unsigned texture, float width, float height,
                    float u1, float v1, float u2, float v2)
{
   // We need to undo the camera rotation
   // This makes the billboard always face the camera
   glPushMatrix();
   glRotatef(camera.angle + 90, 0, -1, 0);
   glRotatef(camera.tilt, -1, 0, 0);

   // Billboard boundaries
   float x1 = width * -0.5;
   float y1 = height * 0.5;
   float x2 = width * 0.5;
   float y2 = height * -0.5;

   // Draw the billboard
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture);

   glBegin(GL_QUADS);
   glColor3ub(0xFF, 0xFF, 0xFF);
   glTexCoord2d(u1, v1);
   glVertex3f(x1, y1, 0);
   glTexCoord2d(u1, v2);
   glVertex3f(x1, y2, 0);
   glTexCoord2d(u2, v2);
   glVertex3f(x2, y2, 0);
   glTexCoord2d(u2, v1);
   glVertex3f(x2, y1, 0);
   glEnd();

   // Undo the transform
   glPopMatrix();
}
