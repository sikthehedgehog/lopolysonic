#ifndef UTIL_H
#define UTIL_H

#include <math.h>
#define PI 3.1415926

//***************************************************************************
// deg2rad [inline]
// Converts an angle from degrees to radians
//---------------------------------------------------------------------------
// param angle: angle in degrees
// return: angle in radians
//***************************************************************************

static inline float deg2rad(float angle) {
   return angle / 180 * PI;
}

//***************************************************************************
// rad2deg [inline]
// Converts an angle from radians to degrees
//---------------------------------------------------------------------------
// param angle: angle in radians
// return: angle in degrees
//***************************************************************************

static inline float rad2deg(float angle) {
   return angle / PI * 180;
}

//***************************************************************************
// get_angle [inline]
// Calculates the angle of a vector
//---------------------------------------------------------------------------
// param x: X distance
// param y: Y distance
// return: angle in degrees
//***************************************************************************

static inline float get_angle(float x, float y) {
   return rad2deg(atan2(y, x));
}

//***************************************************************************
// within_dist [inline]
// Checks if a 2D vector is within a given distance.
//---------------------------------------------------------------------------
// param x: X distance
// param y: Y distance
// param limit: how far we want to check
// return: 1 if within limit, 0 if not
//***************************************************************************

static inline int within_dist(float x, float y, float limit) {
   return x * x + y * y <= limit * limit;
}

#endif
