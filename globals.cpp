#include "globals.h"

bool isNight = false;
bool isAnimating = true;
float animSpeed = 0.5f;

float ferrisAngle = 0.0f;
float carouselAngle = 0.0f;
float cloudOffset = 0.0f;
float birdOffset = 0.0f;
float humanOffset = 0.0f;

float randomFloat(float min, float max) {
    return min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
}

void setColor(float r, float g, float b) {
    if (isNight) {
        glColor3f(r * 0.4f, g * 0.4f, b * 0.55f);
    } else {
        glColor3f(r, g, b);
    }
}

void drawCircle(float cx, float cy, float r, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * PI * i / segments;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();
}

void drawOval(float cx, float cy, float w, float h) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 40; i++) {
        float angle = 2.0f * PI * i / 40;
        glVertex2f(cx + w * cos(angle), cy + h * sin(angle));
    }
    glEnd();
}

void drawRect(float x, float y, float w, float h) {
    glBegin(GL_QUADS);
    glVertex2f(x - w/2, y);
    glVertex2f(x + w/2, y);
    glVertex2f(x + w/2, y - h);
    glVertex2f(x - w/2, y - h);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}
