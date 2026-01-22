#ifndef GLOBALS_H
#define GLOBALS_H

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265f

// Global State Variables
extern bool isNight;
extern bool isAnimating;

// Animation Variables
extern float ferrisAngle;
extern float carouselAngle;

// Helper Functions
float randomFloat(float min, float max);
void setColor(float r, float g, float b); // Auto-dims at night
void drawCircle(float r, int segments);
void drawRect(float w, float h);
void drawRing(float innerR, float outerR, int segments);

#endif
