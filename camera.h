#ifndef CAMERA_H
#define CAMERA_H

typedef struct {
   float x,y,z;         // Target position
   float distx;         // Horizontal distance from target
   float disty;         // Vertical distance from target
   float angle;         // Horizontal angle
   float tilt;          // Vertical angle
} Camera;
extern Camera camera;

void do_camera_transform(void);
void camera_controls(void);

#endif
