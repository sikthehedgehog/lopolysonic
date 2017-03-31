#include <png.h>
#include <GL/gl.h>
#include "stb_image.h"
#include "texture.h"

//***************************************************************************
// make_xor_texture
// Generates a 16x16 XOR texture. Used for testing.
//---------------------------------------------------------------------------
// return: texture ID
//***************************************************************************

unsigned make_xor_texture(void)
{
   uint8_t bitmap[1024];

   // Generate bitmap
   uint8_t *ptr = bitmap;
   for (unsigned y = 0; y < 16; y++)
   for (unsigned x = 0; x < 16; x++) {
      unsigned color = x ^ y;
      color = color | (color << 4);
      *ptr++ = color;
      *ptr++ = color;
      *ptr++ = color;
      *ptr++ = 0xFF;
   }

   // Generate the texture
   unsigned id;
   glGenTextures(1, &id);
   glBindTexture(GL_TEXTURE_2D, id);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 16, 0,
      GL_RGBA, GL_UNSIGNED_BYTE, bitmap);

   // Set up the texture
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

   // Done
   return id;
}

//***************************************************************************
// load_texture
// Generates a texture from an image file. If the texture can't be loaded
// then it'll return a XOR texture instead.
//---------------------------------------------------------------------------
// param filename: file name
// return: texture ID
//***************************************************************************

unsigned load_texture(const char *filename)
{
   // Load the image
   int width, height, num_channels;
   uint8_t *bitmap = stbi_load(filename, &width, &height, &num_channels, 4);
   if (bitmap == NULL) return make_xor_texture();

   // Generate the texture
   unsigned id;
   glGenTextures(1, &id);
   glBindTexture(GL_TEXTURE_2D, id);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
      GL_RGBA, GL_UNSIGNED_BYTE, bitmap);

   // Set up the texture
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

   // Done
   stbi_image_free(bitmap);
   return id;
}
