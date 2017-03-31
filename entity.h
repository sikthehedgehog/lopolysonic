#ifndef ENTITY_H
#define ENTITY_H

// What an entity can be
typedef enum {
   ENTITY_NONE,            // Nothing
   ENTITY_SONIC,           // Sonic
   ENTITY_RING,            // Ring
   ENTITY_MON_RING,        // 10 rings monitor
   ENTITY_MON_STARS,       // Invincibility monitor
   ENTITY_MON_SHOES,       // Supersneakers monitor
} EntityType;

// Function format for callbacks
typedef struct Entity Entity;
typedef void (*EntityFunc)(Entity *);

// Entity state
struct Entity {
   EntityType type;              // Entity type
   EntityFunc update_func;       // Function to run entity logic
   EntityFunc draw_func;         // Function used for drawing

   float x;                      // Current X coordinate
   float y;                      // Current Y coordinate
   float z;                      // Current Z coordinate
   float speed_x;                // Momentum in the X axis
   float speed_y;                // Momentum in the Y axis
   float speed_z;                // Momentum in the Z axis

   float angle;                  // Horizontal angle
   float tilt;                   // Vertical angle

   unsigned anim;                // Current animation
   unsigned anim_time;           // Animation timer
   float shadow;                 // Shadow size

   unsigned on_floor: 1;         // Set when stepping on the floor
};

void init_entities(void);
unsigned add_entity(EntityType, float,float,float, float);
Entity *get_entity_ptr(unsigned);
void update_entities(void);
void draw_entities(void);

#endif
