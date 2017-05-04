#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "camera.h"
#include "entity.h"
#include "input.h"
#include "model_monitor.h"
#include "model_ring.h"
#include "model_sonic.h"
#include "shadow.h"
#include "timer.h"
#include "video.h"

// Never got SDL_main to work...
// This is good enough for Windows and Linux anyway
#ifdef main
#undef main
#endif

int main(void)
{
   // Initialize system
   SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER);
   init_timer();
   init_video();
   init_input();

   // Generate models
   generate_sonic_model();
   generate_ring_model();
   generate_monitor_model();
   generate_shadow();

   init_entities();
   add_entity(ENTITY_SONIC, 0,0,0, 90);
   add_entity(ENTITY_RING, -24,32,-64, 0);
   add_entity(ENTITY_RING, 0,32,-64, 0);
   add_entity(ENTITY_RING, 24,32,-64, 0);
   add_entity(ENTITY_RING, -24,32,-88, 0);
   add_entity(ENTITY_RING, 0,32,-88, 0);
   add_entity(ENTITY_RING, 24,32,-88, 0);
   add_entity(ENTITY_MON_STARS, -64,0,0, -45);

   // Main loop
   int quit = 0;
   while (!quit) {
      // Process game logic
      unsigned num_frames = get_num_frames();
      while (num_frames > 0) {
         update_entities();
         camera_controls();

         refresh_presses();
         num_frames--;
      }

      // Draw screen (for now...)
      clear_screen(0x404080);
      set_3d_mode();
      do_camera_transform();
      draw_entities();

      // Update screen
      update_video();

      // Check for events
      SDL_Event event;
      while (SDL_PollEvent(&event)) switch (event.type) {
         case SDL_KEYDOWN:
            do_keydown(event.key.keysym.scancode);
            break;
         case SDL_KEYUP:
            do_keyup(event.key.keysym.scancode);
            break;
         case SDL_QUIT:
            quit = 1;
            break;
         default:
            break;
      }
   }

   // Quitting program
   deinit_input();
   deinit_video();
   deinit_timer();
   SDL_Quit();

   return 0;
}
