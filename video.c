#include <stdint.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "video.h"

static SDL_Window *window;          // Output window
static SDL_GLContext *opengl;       // OpenGL context

static const uint8_t mesh_pattern[] = {
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
   0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,
};

//***************************************************************************
// init_video
// Sets up the video hardware.
//***************************************************************************

void init_video(void)
{
   // Create window
   window = SDL_CreateWindow("Lopoly Sonic",
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      640, 448, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);

   // Set up OpenGL
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
   SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
   SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
   SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
   SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
   SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
   SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

   opengl = SDL_GL_CreateContext(window);
   SDL_GL_MakeCurrent(window, opengl);

   // Set up some common states
   glEnable(GL_CULL_FACE);
   glEnable(GL_ALPHA_TEST);
   glAlphaFunc(GL_GEQUAL, 0.5);
}

//***************************************************************************
// update_window
// Updates the screen contents.
//***************************************************************************

void update_video(void)
{
   SDL_GL_SwapWindow(window);
}

//***************************************************************************
// deinit_video
// Shuts down the video hardware.
//***************************************************************************

void deinit_video(void)
{
   // Get rid of the window
   SDL_GL_DeleteContext(opengl);
   SDL_DestroyWindow(window);
}

//***************************************************************************
// clear_screen
// Clears the screen.
//---------------------------------------------------------------------------
// param color: color to clear with
//***************************************************************************

void clear_screen(unsigned color)
{
   uint8_t r = color >> 16;
   uint8_t g = color >> 8;
   uint8_t b = color;

   glClearColor(r / 255.0, g / 255.0, b / 255.0, 1);
   glClearDepth(1);

   glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
   glDepthMask(GL_TRUE);

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//***************************************************************************
// set_3d_mode
// Sets up OpenGL to start drawing 3D shapes.
//***************************************************************************

void set_3d_mode(void)
{
   // Turn on depth buffer
   glEnable(GL_DEPTH_TEST);
   glDepthMask(GL_TRUE);
   glDepthFunc(GL_LEQUAL);

   // Set up camera
   glViewport(0, 0, 640, 448);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-16, 16, -12, 12, 16, 1024);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
