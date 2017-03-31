#ifndef TEXTURE_H
#define TEXTURE_H

// What's in a texture
typedef struct {
   unsigned id;            // OpenGL id
   unsigned width;         // Width in pixels
   unsigned height;        // Height in pixels
} Texture;

unsigned make_xor_texture(void);
unsigned load_texture(const char *);

#endif
