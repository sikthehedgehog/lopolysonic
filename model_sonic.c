#include <math.h>
#include <GL/gl.h>
#include "model_sonic.h"
#include "texture.h"
#include "util.h"

static unsigned model_face;
static unsigned model_head;
static unsigned model_torso;
static unsigned model_arm;
static unsigned model_hand;
static unsigned model_leg;
static unsigned model_shoe;
static unsigned model_dash;
static unsigned model_roll;
static unsigned texture;

static unsigned generate_sonic_face(void);
static unsigned generate_sonic_head(void);
static unsigned generate_sonic_torso(void);
static unsigned generate_sonic_arm(void);
static unsigned generate_sonic_hand(void);
static unsigned generate_sonic_leg(void);
static unsigned generate_sonic_shoe(void);
static unsigned generate_sonic_dash(void);
static unsigned generate_sonic_roll(void);

//***************************************************************************
// generate_sonic_model
// Generates the Sonic model.
//***************************************************************************

void generate_sonic_model(void)
{
   model_face = generate_sonic_face();
   model_head = generate_sonic_head();
   model_torso = generate_sonic_torso();
   model_arm = generate_sonic_arm();
   model_hand = generate_sonic_hand();
   model_leg = generate_sonic_leg();
   model_shoe = generate_sonic_shoe();
   model_dash = generate_sonic_dash();
   model_roll = generate_sonic_roll();

   texture = load_texture("textures/sonic.png");
}

//***************************************************************************
// generate_sonic_face [internal]
// Generates Sonic's face.
//---------------------------------------------------------------------------
// return: OpenGL list
//***************************************************************************

static unsigned generate_sonic_face(void)
{
   // Create new list
   unsigned list = glGenLists(1);
   glNewList(list, GL_COMPILE);

   // Don't color the texture
   glColor3ub(0xFF, 0xFF, 0xFF);

   // Eyes
   glBegin(GL_TRIANGLE_STRIP);
   glTexCoord2d(0, 1);
   glVertex3f(3, 4, -6);
   glTexCoord2d(0, 0);
   glVertex3f(3, 12, -6);
   glTexCoord2d(0.5, 1);
   glVertex3f(9, 4, 0);
   glTexCoord2d(0.5, 0);
   glVertex3f(8, 12, 0);
   glTexCoord2d(0, 1);
   glVertex3f(3, 4, 6);
   glTexCoord2d(0, 0);
   glVertex3f(3, 12, 6);
   glEnd();

   // Chin
   glBegin(GL_TRIANGLE_STRIP);
   glTexCoord2d(0.5, 1);
   glVertex3f(2, 0, -4);
   glTexCoord2d(0.5, 0);
   glVertex3f(3, 4, -6);
   glTexCoord2d(1, 1);
   glVertex3f(6, 0, 0);
   glTexCoord2d(1, 0);
   glVertex3f(9, 4, 0);
   glTexCoord2d(0.5, 1);
   glVertex3f(2, 0, 4);
   glTexCoord2d(0.5, 0);
   glVertex3f(3, 4, 6);
   glEnd();

   // Done
   glEndList();
   return list;
}

//***************************************************************************
// generate_sonic_head [internal]
// Generates Sonic's head (sans face).
//---------------------------------------------------------------------------
// return: OpenGL list
//***************************************************************************

static unsigned generate_sonic_head(void)
{
   // Create new list
   unsigned list = glGenLists(1);
   glNewList(list, GL_COMPILE);

   // Nose
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0x00);
   glVertex3f(9, 4, 0);
   glVertex3f(10, 3, 0);
   glColor3ub(0x40, 0x40, 0x40);
   glVertex3f(10.5, 5, 1.5);
   glVertex3f(10.5, 5, -1.5);
   glColor3ub(0x00, 0x00, 0x00);
   glVertex3f(10, 3, 0);
   glEnd();
   glBegin(GL_TRIANGLES);
   glColor3ub(0x00, 0x00, 0x00);
   glVertex3f(10, 3, 0);
   glColor3ub(0x40, 0x40, 0x40);
   glVertex3f(10.5, 5, -1.5);
   glVertex3f(10.5, 5, 1.5);
   glEnd();

   // Top of face
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(3, 16, 0);
   glVertex3f(3, 12, 6);
   glVertex3f(8, 12, 0);
   glVertex3f(3, 12, -6);
   glEnd();

   // Bottom of face
   glBegin(GL_TRIANGLES);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(2, 0, 4);
   glVertex3f(2, 0, -4);
   glVertex3f(6, 0, 0);
   glEnd();

   // Around his face
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-1, 0, 4);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(2, 0, 4);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-5, 4, 6);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(3, 4, 6);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 12, 6);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(3, 12, 6);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(-5, 16, 0);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(3, 16, 0);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 12, -6);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(3, 12, -6);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-5, 4, -6);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(3, 4, -6);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-1, 0, -4);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(2, 0, -4);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-1, 0, 4);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(2, 0, 4);
   glEnd();

   // Right ear
   glBegin(GL_TRIANGLES);
   glColor3ub(0xFF, 0xC0, 0xA0);
   glVertex3f(2, 12, 6);
   glVertex3f(2, 15, 1.5);
   glColor3ub(0xC0, 0x80, 0x60);
   glVertex3f(2, 18, 5);
   glEnd();
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(2, 18, 5);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(2, 15, 1.5);
   glVertex3f(-2, 14, 3);
   glVertex3f(2, 12, 6);
   glEnd();

   // Left ear
   glBegin(GL_TRIANGLES);
   glColor3ub(0xFF, 0xC0, 0xA0);
   glVertex3f(2, 15, -1.5);
   glVertex3f(2, 12, -6);
   glColor3ub(0xC0, 0x80, 0x60);
   glVertex3f(2, 18, -5);
   glEnd();
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(2, 18, -5);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(2, 12, -6);
   glVertex3f(-2, 14, -3);
   glVertex3f(2, 15, -1.5);
   glEnd();

   // Top middle quill
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-12, 13, 0);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(-5, 16, 0);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 12, -6);
   glColor3ub(0x00, 0x00, 0x80);
   glVertex3f(-6, 9, 0);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 12, 6);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(-5, 16, 0);
   glEnd();

   // Top right quill
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-12, 3, 8);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 12, 6);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-6, 9, 0);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 4, 6);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 12, 6);
   glEnd();

   // Top left quill
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-12, 3, -8);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 12, -6);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 4, -6);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-6, 9, 0);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 12, -6);
   glEnd();

   // Bottom middle quill
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xA0);
   glVertex3f(-12, -1, 0);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-5, 4, 6);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(-6, 9, 0);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-5, 4, -6);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-1, 0, 0);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-5, 4, 6);
   glEnd();

   // Bottom right quill
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-9, -4, 7);
   glColor3ub(0x00, 0x00, 0xA0);
   glVertex3f(-1, 0, 0);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-1, 0, 4);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 4, 6);
   glColor3ub(0x00, 0x00, 0x80);
   glVertex3f(-1, 0, 0);
   glEnd();

   // Bottom left quill
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-9, -4, -7);
   glColor3ub(0x00, 0x00, 0xA0);
   glVertex3f(-1, 0, 0);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(-5, 4, -6);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-1, 0, -4);
   glColor3ub(0x00, 0x00, 0x80);
   glVertex3f(-1, 0, 0);
   glEnd();

   // Done
   glEndList();
   return list;
}

//***************************************************************************
// generate_sonic_torso [internal]
// Generates Sonic's torso.
//---------------------------------------------------------------------------
// return: OpenGL list
//***************************************************************************

static unsigned generate_sonic_torso(void)
{
   // Create new list
   unsigned list = glGenLists(1);
   glNewList(list, GL_COMPILE);

   // Belly
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0xFF, 0xC0, 0xA0);
   glVertex3f(4, 0, 0);
   glVertex3f(2, 3, -3);
   glVertex3f(2, 4, 0);
   glVertex3f(2, 3, 3);
   glColor3ub(0xC0, 0x80, 0x60);
   glVertex3f(2, -3, 3);
   glVertex3f(2, -4, 0);
   glVertex3f(2, -3, -3);
   glColor3ub(0xFF, 0xC0, 0xA0);
   glVertex3f(2, 3, -3);
   glEnd();

   // Body
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(2, 3, -3);
   glVertex3f(-2, 4, -4);
   glVertex3f(2, 4, 0);
   glVertex3f(-2, 5, 0);
   glVertex3f(2, 3, 3);
   glVertex3f(-2, 4, 4);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(2, -3, 3);
   glVertex3f(-2, -4, 4);
   glColor3ub(0x00, 0x00, 0x80);
   glVertex3f(2, -4, 0);
   glVertex3f(-2, -5, 0);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(2, -3, -3);
   glVertex3f(-2, -4, -4);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(2, 3, -3);
   glVertex3f(-2, 4, -4);
   glEnd();

   // Back
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-5, 0, 0);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(-2, 4, 4);
   glVertex3f(-2, 5, 0);
   glVertex3f(-2, 4, -4);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-2, -4, -4);
   glColor3ub(0x00, 0x00, 0x80);
   glVertex3f(-2, -5, 0);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-2, -4, 4);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(-2, 4, 4);
   glEnd();

   // Done
   glEndList();
   return list;
}

//***************************************************************************
// generate_sonic_arm [internal]
// Generates Sonic's arms.
//---------------------------------------------------------------------------
// return: OpenGL list
//***************************************************************************

static unsigned generate_sonic_arm(void)
{
   // Create new list
   unsigned list = glGenLists(1);
   glNewList(list, GL_COMPILE);

   // Main part
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0xC0, 0x80, 0x60);
   glVertex3f(1, -1, 3);
   glVertex3f(1.5, -1.5, -3);
   glColor3ub(0xFF, 0xC0, 0xA0);
   glVertex3f(1, 1, 3);
   glVertex3f(1.5, 1.5, -3);
   glColor3ub(0xFF, 0xC0, 0xA0);
   glVertex3f(-1, 1, 3);
   glVertex3f(-1.5, 1.5, -3);
   glColor3ub(0xC0, 0x80, 0x60);
   glVertex3f(-1, -1, 3);
   glVertex3f(-1.5, -1.5, -3);
   glColor3ub(0xC0, 0x80, 0x60);
   glVertex3f(1, -1, 3);
   glVertex3f(1.5, -1.5, -3);
   glEnd();

   // Endpoints
   glBegin(GL_QUADS);
   glColor3ub(0xC0, 0x80, 0x60);
   glVertex3f(1.5, -1.5, -3);
   glColor3ub(0xC0, 0x80, 0x60);
   glVertex3f(-1.5, -1.5, -3);
   glColor3ub(0xFF, 0xC0, 0xA0);
   glVertex3f(-1.5, 1.5, -3);
   glColor3ub(0xFF, 0xC0, 0xA0);
   glVertex3f(1.5, 1.5, -3);

   glColor3ub(0xC0, 0x80, 0x60);
   glVertex3f(1, -1, 3);
   glColor3ub(0xFF, 0xC0, 0xA0);
   glVertex3f(1, 1, 3);
   glColor3ub(0xFF, 0xC0, 0xA0);
   glVertex3f(-1, 1, 3);
   glColor3ub(0xC0, 0x80, 0x60);
   glVertex3f(-1, -1, 3);
   glEnd();

   // Done
   glEndList();
   return list;
}

//***************************************************************************
// generate_sonic_hand [internal]
// Generates Sonic's hands.
//---------------------------------------------------------------------------
// return: OpenGL list
//***************************************************************************

static unsigned generate_sonic_hand(void)
{
   // Create new list
   unsigned list = glGenLists(1);
   glNewList(list, GL_COMPILE);

   // Inside
   glBegin(GL_QUADS);
   glColor3ub(0xA0, 0xA0, 0xA0);
   glVertex3f(3, -3, -3+3);
   glVertex3f(-3, -3, -3+3);
   glVertex3f(-3, 3, -3+3);
   glVertex3f(3, 3, -3+3);
   glEnd();

   // Inner part
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0xC0, 0xC0, 0xC0);
   glVertex3f(2, -2, 0+3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(3, -3, -3+3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(2, 2, 0+3);
   glColor3ub(0xFF, 0xFF, 0xFF);
   glVertex3f(3, 3, -3+3);
   glColor3ub(0xC0, 0xC0, 0xC0);
   glVertex3f(-2, 2, 0+3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(-3, 3, -3+3);
   glColor3ub(0xA0, 0xA0, 0xA0);
   glVertex3f(-2, -2, 0+3);
   glColor3ub(0xC0, 0xC0, 0xC0);
   glVertex3f(-3, -3, -3+3);
   glColor3ub(0xC0, 0xC0, 0xC0);
   glVertex3f(2, -2, 0+3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(3, -3, -3+3);
   glEnd();

   // Outer part
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(3, -3, 3+3);
   glVertex3f(2, -2, 0+3);
   glColor3ub(0xFF, 0xFF, 0xFF);
   glVertex3f(3, 3, 3+3);
   glVertex3f(2, 2, 0+3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(-3, 3, 3+3);
   glVertex3f(-2, 2, 0+3);
   glColor3ub(0xC0, 0xC0, 0xC0);
   glVertex3f(-3, -3, 3+3);
   glVertex3f(-2, -2, 0+3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(3, -3, 3+3);
   glVertex3f(2, -2, 0+3);
   glEnd();

   // "Fingers"
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(0, 0, 6+3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(3, -3, 3+3);
   glColor3ub(0xFF, 0xFF, 0xFF);
   glVertex3f(3, 3, 3+3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(-3, 3, 3+3);
   glColor3ub(0xC0, 0xC0, 0xC0);
   glVertex3f(-3, -3, 3+3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(3, -3, 3+3);
   glEnd();

   // Done
   glEndList();
   return list;
}

//***************************************************************************
// generate_sonic_leg [internal]
// Generates Sonic's legs.
//---------------------------------------------------------------------------
// return: OpenGL list
//***************************************************************************

static unsigned generate_sonic_leg(void)
{
   // Create new list
   unsigned list = glGenLists(1);
   glNewList(list, GL_COMPILE);

   // Main part
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(1.5, 3, -1.5);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(1.5, -3, -1.5);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-1.5, 3, -1.5);
   glColor3ub(0x00, 0x00, 0xA0);
   glVertex3f(-1.5, -3, -1.5);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-1.5, 3, 1.5);
   glColor3ub(0x00, 0x00, 0xA0);
   glVertex3f(-1.5, -3, 1.5);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(1.5, 3, 1.5);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(1.5, -3, 1.5);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(1.5, 3, -1.5);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(1.5, -3, -1.5);
   glEnd();

   // Endpoints
   glBegin(GL_QUADS);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(1.5, 3, -1.5);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-1.5, 3, -1.5);
   glColor3ub(0x00, 0x00, 0xC0);
   glVertex3f(-1.5, 3, 1.5);
   glColor3ub(0x00, 0x00, 0xFF);
   glVertex3f(1.5, 3, 1.5);

   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(1.5, -3, -1.5);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(1.5, -3, 1.5);
   glColor3ub(0x00, 0x00, 0xA0);
   glVertex3f(-1.5, -3, 1.5);
   glColor3ub(0x00, 0x00, 0xA0);
   glVertex3f(-1.5, -3, -1.5);
   glEnd();

   // Done
   glEndList();
   return list;
}

//***************************************************************************
// generate_sonic_shoe [internal]
// Generates Sonic's shoes.
//---------------------------------------------------------------------------
// return: OpenGL list
//***************************************************************************

static unsigned generate_sonic_shoe(void)
{
   // Create new list
   unsigned list = glGenLists(1);
   glNewList(list, GL_COMPILE);

   // Socks
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0xFF, 0xFF, 0xFF);
   glVertex3f(3, 0, 3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(2, -3, 2);
   glColor3ub(0xFF, 0xFF, 0xFF);
   glVertex3f(3, 0, -3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(2, -3, -2);
   glColor3ub(0xC0, 0xC0, 0xC0);
   glVertex3f(-3, 0, -3);
   glColor3ub(0xA0, 0xA0, 0xA0);
   glVertex3f(-2, -3, -2);
   glColor3ub(0xC0, 0xC0, 0xC0);
   glVertex3f(-3, 0, 3);
   glColor3ub(0xA0, 0xA0, 0xA0);
   glVertex3f(-2, -3, 2);
   glColor3ub(0xFF, 0xFF, 0xFF);
   glVertex3f(3, 0, 3);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(2, -3, 2);
   glEnd();
   glBegin(GL_QUADS);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(3, 0, 3);
   glVertex3f(3, 0, -3);
   glVertex3f(-3, 0, -3);
   glVertex3f(-3, 0, 3);
   glEnd();

   // Back
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0xFF, 0x00, 0x00);
   glVertex3f(2, -3, -2);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(1, -7, -4);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(-2, -3, -2);
   glColor3ub(0xA0, 0x00, 0x00);
   glVertex3f(-5, -7, -3);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(-2, -3, 2);
   glColor3ub(0xA0, 0x00, 0x00);
   glVertex3f(-5, -7, 3);
   glColor3ub(0xFF, 0x00, 0x00);
   glVertex3f(2, -3, 2);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(1, -7, 4);
   glEnd();

   // Stripes
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0xC0, 0xC0, 0xC0);
   glVertex3f(1, -7, 4);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(5, -7, 4);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(2, -3, 2);
   glColor3ub(0xFF, 0xFF, 0xFF);
   glVertex3f(5, -3, 2);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(2, -3, -2);
   glColor3ub(0xFF, 0xFF, 0xFF);
   glVertex3f(5, -3, -2);
   glColor3ub(0xC0, 0xC0, 0xC0);
   glVertex3f(1, -7, -4);
   glColor3ub(0xE0, 0xE0, 0xE0);
   glVertex3f(5, -7, -4);
   glEnd();

   // Front
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0xE0, 0x00, 0x00);
   glVertex3f(12, -7, 0);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(5, -7, -4);
   glColor3ub(0xFF, 0x00, 0x00);
   glVertex3f(5, -3, -2);
   glVertex3f(5, -3, 2);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(5, -7, 4);
   glEnd();

   // Bottom
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0x40, 0x40, 0x40);
   glVertex3f(12, -7, 0);
   glVertex3f(5, -7, 4);
   glVertex3f(5, -7, -4);
   glVertex3f(2, -7, 4);
   glVertex3f(2, -7, -4);
   glVertex3f(-5, -7, 3);
   glVertex3f(-5, -7, -3);
   glEnd();

   // Done
   glEndList();
   return list;
}

//***************************************************************************
// generate_sonic_dash [internal]
// Generates Sonic's feet dashing.
//---------------------------------------------------------------------------
// return: OpenGL list
//***************************************************************************

static unsigned generate_sonic_dash(void)
{
   // Create new list
   unsigned list = glGenLists(1);
   glNewList(list, GL_COMPILE);

   // Back
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(-8, -4, 0);
   glColor3ub(0xFF, 0x00, 0x00);
   glVertex3f(-4, 5, 3);
   glVertex3f(-4, 5, -3);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(-2, 2, -3);
   glVertex3f(-2, 2, 3);
   glColor3ub(0xFF, 0x00, 0x00);
   glVertex3f(-4, 5, 3);
   glEnd();

   // Middle
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0xFF, 0x00, 0x00);
   glVertex3f(4, 8, -3);
   glVertex3f(-4, 5, -3);
   glVertex3f(4, 8, 3);
   glVertex3f(-4, 5, 3);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(2, 2, 3);
   glVertex3f(-2, 2, 3);
   glVertex3f(2, 2, -3);
   glVertex3f(-2, 2, -3);
   glColor3ub(0xFF, 0x00, 0x00);
   glVertex3f(4, 8, -3);
   glVertex3f(-4, 5, -3);
   glEnd();

   // Front
   glBegin(GL_TRIANGLE_STRIP);
   glColor3ub(0xFF, 0x00, 0x00);
   glVertex3f(10, 4, -3);
   glVertex3f(4, 8, -3);
   glVertex3f(10, 4, 3);
   glVertex3f(4, 8, 3);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(6, 0, 3);
   glVertex3f(2, 2, 3);
   glVertex3f(6, 0, -3);
   glVertex3f(2, 2, -3);
   glColor3ub(0xFF, 0x00, 0x00);
   glVertex3f(10, 4, -3);
   glVertex3f(4, 8, -3);
   glEnd();
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(11, -1, 0);
   glColor3ub(0xFF, 0x00, 0x00);
   glVertex3f(10, 4, -3);
   glVertex3f(10, 4, 3);
   glColor3ub(0xC0, 0x00, 0x00);
   glVertex3f(6, 0, 3);
   glVertex3f(6, 0, -3);
   glColor3ub(0xFF, 0x00, 0x00);
   glVertex3f(10, 4, -3);
   glEnd();

   // Done
   glEndList();
   return list;
}

//***************************************************************************
// generate_sonic_roll [internal]
// Generates Sonic when rolling.
//---------------------------------------------------------------------------
// return: OpenGL list
//***************************************************************************

static unsigned generate_sonic_roll(void)
{
   // Create new list
   unsigned list = glGenLists(1);
   glNewList(list, GL_COMPILE);

   // Most of the ball
   for (int angle = -60; angle < 60; angle += 30) {
      glBegin(GL_TRIANGLE_STRIP);
      for (int angle2 = 0; angle2 <= 360; angle2 += 30) {
         float x1 = 15 * cos(deg2rad(angle2)) * cos(deg2rad(angle));
         float x2 = 15 * cos(deg2rad(angle2)) * cos(deg2rad(angle+30));
         float y1 = 15 * sin(deg2rad(angle2)) * cos(deg2rad(angle));
         float y2 = 15 * sin(deg2rad(angle2)) * cos(deg2rad(angle+30));
         float z1 = -15 * sin(deg2rad(angle));
         float z2 = -15 * sin(deg2rad(angle+30));

         glColor3f(0, 0, 0.875 + y1 / 64);
         glVertex3f(x1, y1, z1);
         glColor3f(0, 0, 0.875 + y2 / 64);
         glVertex3f(x2, y2, z2);
      }
      glEnd();
   }

   // Endpoints
   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(0, 0, 15);
   for (int angle = 0; angle <= 360; angle += 30) {
      float x = 15 * cos(deg2rad(angle)) * cos(deg2rad(60));
      float y = 15 * sin(deg2rad(angle)) * cos(deg2rad(60));
      float z = 15 * sin(deg2rad(60));

      glColor3f(0, 0, 0.875 + y / 64);
      glVertex3f(x, y, z);
   }
   glEnd();

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0x00, 0x00, 0xE0);
   glVertex3f(0, 0, -15);
   for (int angle = 360; angle >= 0; angle -= 30) {
      float x = 15 * cos(deg2rad(angle)) * cos(deg2rad(60));
      float y = 15 * sin(deg2rad(angle)) * cos(deg2rad(60));
      float z = -15 * sin(deg2rad(60));

      glColor3f(0, 0, 0.875 + y / 64);
      glVertex3f(x, y, z);
   }
   glEnd();

   // Done
   glEndList();
   return list;
}

//***************************************************************************
// draw_sonic_model
// Draws Sonic. Adjust his position using the modelview matrix.
//---------------------------------------------------------------------------
// param anim: animation to play
// param anim_time: animation counter
//***************************************************************************

void draw_sonic_model(unsigned anim, unsigned anim_time)
{
   // For posing Sonic
   float offset = 17;                        // Overall offset from floor

   float head_angle = 0;                     // Which way is the head facing
   float head_tilt = 0;                      // How much is the head tilted
   float body_tilt = 0;                      // How much is the torso tilted
   float body_angle = 0;                     // Horizontal rotation

   float arm_height[2] = { 0, 0 };           // How low are the arms
   float arm_swing[2] = { 0, 0 };            // How forward/back are the arms
   float arm_angle[2] = { 0, 0 };            // How angled are the arms
   float arm_angle2[2] = { 0, 0 };

   float leg_height[2] = { 0, 0 };           // How high are the legs
   float leg_angle[2] = { 0, 0 };            // How angled are the legs
   float leg_angle2[2] = { 10, 10 };         // Feet angle outwards

   int dashing = 0;                          // Show dashing feet instead?
   float dash_angle = 0;                     // Spinning of dashing feet

   int rolling = 0;                          // Show Sonic as a ball?
   float roll_angle = 0;                     // Spinning when rolled

   // Quick hack to implement waiting animation
   // Stay idle too long and Sonic will wait instead
   if (anim == ANIMSONIC_IDLE && anim_time >= 8*60) {
      anim = ANIMSONIC_WAIT;
      anim_time -= 8*60;
   }

   // Do animation
   switch (anim) {
      // Idle
      default:
      case ANIMSONIC_IDLE: {
         float motion = sin(deg2rad(anim_time * 3 % 360));

         body_tilt = motion;
         arm_height[0] = arm_height[1] = 45;
         arm_swing[0] = arm_swing[1] = motion * 5;
         arm_angle[0] = arm_angle[1] = 45;
         arm_angle2[0] = arm_angle2[1] = motion * 5;
      } break;

      // Running slow
      case ANIMSONIC_RUN: {
         float motion = sin(deg2rad(anim_time * 10 % 360));
         offset += fabs(motion) * 2;
         body_tilt = -5;

         arm_height[0] = arm_height[1] = 30;
         arm_swing[0] = motion * 60;
         arm_swing[1] = motion * -60;
         arm_angle[0] = 30 + motion * 30;
         arm_angle[1] = 30 + motion * -30;

         leg_height[0] = motion * -75;
         leg_height[1] = motion * 75;
         leg_angle[0] = 45 + motion * 45;
         leg_angle[1] = 45 + motion * -45;
      } break;

      // Running fast
      case ANIMSONIC_RUN2: {
         float motion1 = sin(deg2rad(anim_time * 12 % 360));
         float motion1b = fabs(motion1);

         offset -= 2;
         offset += motion1b * 2;
         head_tilt = 20 - motion1b * 2;
         body_tilt = -30 - motion1b;

         arm_height[0] = arm_height[1] = 45 - motion1b * 10;
         arm_swing[0] = arm_swing[1] = -30 - motion1b * 10;
         arm_angle[0] = arm_angle[1] = 120 + motion1b * 10;

         dashing = 1;
         dash_angle = anim_time * 24 % 360;
      } break;

      // Rolling
      case ANIMSONIC_ROLL: {
         offset = 15;
         rolling = 1;
         roll_angle = anim_time * 24 % 360;
      } break;

      // Lauching off
      case ANIMSONIC_SPRING: {
         float motion = sin(deg2rad(anim_time * 6 % 360));
         body_angle = (anim_time * 12) % 360;

         head_tilt = 30 + motion;
         body_tilt = 15 + motion;
         arm_height[0] = arm_height[1] = 30 + motion * 2.5;
         arm_swing[0] = arm_swing[1] = -30 + motion;
         leg_height[0] = leg_height[1] = -15 + motion * -2.5;
         leg_angle[0] = leg_angle[1] = 45;
      } break;

      // Waiting
      case ANIMSONIC_WAIT: {
         float motion = sin(deg2rad(anim_time * 3 % 360));
         float motion2 = fabs(sin(deg2rad(anim_time * 9 % 360)));
         float motion3 = anim_time / 12.0;
         if (motion3 > 1) motion3 = 1;
         float motion3b = 1 - motion3;

         body_tilt = motion;
         arm_height[0] = arm_height[1] = 45;
         arm_angle[0] = arm_angle[1] = motion3b * 45;
         arm_angle2[0] = arm_angle2[1] = motion3 * 90;

         leg_angle[1] = motion2 * -30;
         leg_angle2[0] = leg_angle2[1] = 10 + motion3 * 20;
      } break;
   }

   // Apply overall offset
   glPushMatrix();
   glTranslatef(0, offset, 0);
   glRotatef(body_angle, 0, 1, 0);

   // Rolling?
   if (rolling) {
      glRotatef(roll_angle, 0, 0, -1);
      glCallList(model_roll);
      glPopMatrix();
      return;
   }

   // Tilt the whole body from waist up
   glPushMatrix();
   glTranslatef(0, -2, 0);
   glRotatef(body_tilt, 0, 0, 1);
   glTranslatef(0, 2, 0);

   // Head
   glPushMatrix();
   glTranslatef(-1, 5, 0);
   glRotatef(head_angle, 0, 1, 0);
   glRotatef(head_tilt, 0, 0, 1);

   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture);
   glCallList(model_face);
   glDisable(GL_TEXTURE_2D);
   glCallList(model_head);
   glPopMatrix();

   // Torso
   glCallList(model_torso);

   // Right arm
   glPushMatrix();
   glTranslatef(0, 4, 4);
   glRotatef(arm_height[0], 1, 0, 0);
   glRotatef(arm_swing[0], 0, 1, 0);

   glPushMatrix();
   glTranslatef(-1, 0, 3);
   glRotatef(-45, 0, 0, 1);
   glCallList(model_arm);
   glPopMatrix();

   // Right hand
   glTranslatef(0, 0, 6);
   glRotatef(arm_angle2[0], 1, 0, 0);
   glRotatef(arm_angle[0], 0, 1, 0);

   glCallList(model_hand);
   glPopMatrix();

   // Left arm
   glPushMatrix();
   glTranslatef(0, 4, -4);
   glRotatef(arm_height[1], -1, 0, 0);
   glRotatef(arm_swing[1], 0, -1, 0);

   glPushMatrix();
   glTranslatef(-1, 0, -3);
   glRotatef(-45, 0, 0, 1);
   glRotatef(180, 0, 1, 0);
   glCallList(model_arm);
   glPopMatrix();

   // Left hand
   glTranslatef(0, 0, -6);
   glRotatef(arm_angle2[1], -1, 0, 0);
   glRotatef(arm_angle[1], 0, -1, 0);

   glPushMatrix();
   glRotatef(90, 0, 0, -1);
   glRotatef(180, 0, 1, 0);
   glCallList(model_hand);
   glPopMatrix();
   glPopMatrix();

   // Legs not affected by body tilt
   glPopMatrix();

   // Normal legs?
   if (!dashing) {
      // Right leg
      glPushMatrix();
      glTranslatef(0, -5, 3);
      glRotatef(leg_height[0], 0, 0, 1);
      glTranslatef(0, -2, 0);

      glPushMatrix();
      glRotatef(10, -1, 0, 0);
      glCallList(model_leg);
      glPopMatrix();

      // Right shoe
      glTranslatef(0, -3, 1);
      glRotatef(leg_angle2[0], 0, -1, 0);
      glRotatef(leg_angle[0], 0, 0, -1);

      glCallList(model_shoe);
      glPopMatrix();

      // Left leg
      glPushMatrix();
      glTranslatef(0, -5, -3);
      glRotatef(leg_height[1], 0, 0, 1);
      glTranslatef(0, -2, 0);

      glPushMatrix();
      glRotatef(10, 1, 0, 0);
      glCallList(model_leg);
      glPopMatrix();

      // Left shoe
      glTranslatef(0, -3, -1);
      glRotatef(leg_angle2[1], 0, 1, 0);
      glRotatef(leg_angle[1], 0, 0, -1);

      glCallList(model_shoe);
      glPopMatrix();
   }

   // Dashing legs?
   else {
      // Right leg
      glPushMatrix();
      glTranslatef(0, -7, 8);
      glScalef(1.5, 1, 1);
      glRotatef(dash_angle, 0, 0, -1);
      glCallList(model_dash);
      glPopMatrix();

      // Left leg
      glPushMatrix();
      glTranslatef(0, -7, -8);
      glScalef(1.5, 1, 1);
      glRotatef(dash_angle + 180, 0, 0, -1);
      glCallList(model_dash);
      glPopMatrix();
   }

   // Done
   glPopMatrix();
}
