#include <stdint.h>
#include <SDL2/SDL.h>

static uint64_t frame_len;       // Ticks per frame
static uint64_t next_frame;      // Timestamp of next frame

//***************************************************************************
// init_timer
// Sets up the timer.
//***************************************************************************

void init_timer(void)
{
   frame_len = SDL_GetPerformanceFrequency() / 60;
   next_frame = SDL_GetPerformanceCounter() + frame_len;
}

//***************************************************************************
// get_num_frames
// Waits until the next frame starts.
//---------------------------------------------------------------------------
// return: how many frames to process
//***************************************************************************

unsigned get_num_frames(void)
{
   uint64_t curr_frame;

   // Wait until at least one frame ellapsed
   // (if we want, it means we're going fast enough)
   for (;;) {
      curr_frame = SDL_GetPerformanceCounter();
      if (curr_frame >= next_frame) break;
      SDL_Delay(1);
   }

   // Check how many frames have ellapsed
   // (if more than 1, it means we're going too slow)
   unsigned num_frames = 0;
   while (curr_frame >= next_frame) {
      next_frame += frame_len;
      num_frames++;
   }

   // Impose a framerate cap
   // At this point we'd rather slow down the game
   if (num_frames > 6)
      num_frames = 6;

   // Return number of ellapsed frames
   return num_frames;
}

//***************************************************************************
// deinit_timer
// Shuts down the timer.
//***************************************************************************

void deinit_timer(void)
{
}
