#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "camera.h"
#include "input.h"

// The camera needs to go somewhere
Camera camera = {
   0,0,0, 80,64, -90,20
};

//***************************************************************************
// do_camera_transform
// Adds in all the matrix transforms needed to move the camera.
//***************************************************************************

void do_camera_transform(void)
{
   glRotatef(camera.tilt, 1, 0, 0);
   glTranslatef(0, 0, -camera.distx);
   glRotatef(camera.angle + 90, 0, 1, 0);
   glTranslatef(-camera.x, -camera.y - camera.disty, -camera.z);

   // For debugging only
   // Draw the floor
   glDisable(GL_TEXTURE_2D);
   glBegin(GL_LINES);
   glColor3ub(0x80, 0x80, 0xA0);
   for (int i = -64; i <= 64; i += 8) {
      glVertex3f(-i, 0, -64);
      glVertex3f(-i, 0, +64);
      glVertex3f(-64, 0, -i);
      glVertex3f(+64, 0, -i);
   }
   glEnd();
}

//***************************************************************************
// camera_controls
// Takes care of the camera controls (see numpad).
//***************************************************************************

void camera_controls(void)
{
   // Turn left/right
   if (held_down(SDL_SCANCODE_KP_4) ||
   held_down(SDL_SCANCODE_KP_7) ||
   held_down(SDL_SCANCODE_KP_1)) {
      camera.angle += 3;
   }

   if (held_down(SDL_SCANCODE_KP_6) ||
   held_down(SDL_SCANCODE_KP_9) ||
   held_down(SDL_SCANCODE_KP_3)) {
      camera.angle -= 3;
   }

   // Turn up/down
   if (held_down(SDL_SCANCODE_KP_8) ||
   held_down(SDL_SCANCODE_KP_7) ||
   held_down(SDL_SCANCODE_KP_9)) {
      camera.distx--;
   }

   if (held_down(SDL_SCANCODE_KP_2) ||
   held_down(SDL_SCANCODE_KP_1) ||
   held_down(SDL_SCANCODE_KP_3)) {
      camera.distx++;
   }

   // Move up/down
   if (held_down(SDL_SCANCODE_KP_PLUS)) {
      camera.disty--;
      camera.distx += 0.25;
      camera.tilt -= 0.5;
   }
   if (held_down(SDL_SCANCODE_KP_MINUS)) {
      camera.disty++;
      camera.distx -= 0.25;
      camera.tilt += 0.5;
   }

   // Look up/down
   if (held_down(SDL_SCANCODE_KP_MULTIPLY))
      camera.tilt += 2;
   if (held_down(SDL_SCANCODE_KP_DIVIDE))
      camera.tilt -= 2;

   // Reset camera
   if (was_pressed(SDL_SCANCODE_KP_5)) {
      camera.distx = 80;
      camera.disty = 64;
      camera.angle = -90;
      camera.tilt = 20;
   }
}
