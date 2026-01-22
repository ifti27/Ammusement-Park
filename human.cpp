#include "globals.h"
#include "human.h"

void drawMan(float x, float y) {
    float headSize = 0.055f;
    float bodyW = headSize * 1.8f;
    float bodyH = headSize * 2.6f;

    setColor(0.2f, 0.2f, 0.8f);
    drawRect(x, y - bodyH/2, bodyW, bodyH);

    setColor(0.9f, 0.7f, 0.6f);
    drawCircle(x, y + headSize * 0.6f, headSize, 20);

    setColor(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    float legLen = bodyH * 0.8f;
    float walk = sin(humanOffset * 10.0f) * 0.05f;
    glVertex2f(x - bodyW/4, y - bodyH); glVertex2f(x - bodyW/4 + walk, y - bodyH - legLen);
    glVertex2f(x + bodyW/4, y - bodyH); glVertex2f(x + bodyW/4 - walk, y - bodyH - legLen);
    glEnd();
    glLineWidth(1.0f);
}

void drawWoman(float x, float y) {
    float headSize = 0.052f;
    float bodyW = headSize * 1.7f;
    float bodyH = headSize * 2.5f;

    setColor(0.8f, 0.3f, 0.8f);
    drawTriangle(x, y + headSize, x - bodyW, y - bodyH, x + bodyW, y - bodyH);

    setColor(0.9f, 0.7f, 0.6f);
    drawCircle(x, y + headSize * 0.8f, headSize, 20);

    setColor(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    float walk = sin(humanOffset * 8.0f) * 0.03f;
    glVertex2f(x - 0.02f, y - bodyH); glVertex2f(x - 0.02f + walk, y - bodyH - 0.1f);
    glVertex2f(x + 0.02f, y - bodyH); glVertex2f(x + 0.02f - walk, y - bodyH - 0.1f);
    glEnd();
    glLineWidth(1.0f);
}

void drawChild(float x, float y) {
    float headSize = 0.042f;
    float bodyW = headSize * 1.6f;
    float bodyH = headSize * 2.0f;

    setColor(0.2f, 0.8f, 0.2f);
    drawRect(x, y - bodyH/2, bodyW, bodyH);

    setColor(0.9f, 0.7f, 0.6f);
    drawCircle(x, y + headSize * 0.6f, headSize, 20);

    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(x + 0.03f, y);
    glVertex2f(x + 0.05f, y + 0.2f);
    glEnd();
    setColor(1.0f, 0.0f, 0.0f);
    drawCircle(x + 0.05f, y + 0.25f, 0.05f, 20);
}

void drawHumans() {
    float mX = -1.0f + fmod(humanOffset * 0.3f, 2.0f);
    if(mX > 1.0f) mX -= 2.0f;
    drawMan(mX, -0.6f);

    float wX = 1.0f - fmod(humanOffset * 0.2f, 2.0f);
    if(wX < -1.0f) wX += 2.0f;
    drawWoman(wX, -0.7f);

    drawChild(wX + 0.1f, -0.75f);
}
