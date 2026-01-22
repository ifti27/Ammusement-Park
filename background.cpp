#include "globals.h"
#include "background.h"

void drawCloud(float x, float y, float scale) {
    if(isNight) return;
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 0.1f * scale, 20);
    drawCircle(x + 0.12f*scale, y + 0.05f*scale, 0.12f * scale, 20);
    drawCircle(x - 0.12f*scale, y + 0.05f*scale, 0.12f * scale, 20);
}

void drawTree(float x, float y, float size, bool isBush) {
    float trunkTopY = y + (isBush ? 0.10f : 0.22f) * size;

    setColor(0.55f, 0.35f, 0.20f);
    glBegin(GL_POLYGON);
        glVertex2f(x - 0.03f*size, trunkTopY);
        glVertex2f(x + 0.03f*size, trunkTopY);
        glVertex2f(x + 0.03f*size, y - 0.20f*size);
        glVertex2f(x - 0.03f*size, y - 0.20f*size);
    glEnd();

    if (isBush) {
        setColor(0.2f, 0.8f, 0.2f);
        drawCircle(x, trunkTopY + 0.02f*size, 0.12f*size, 30);
        setColor(0.15f, 0.7f, 0.15f);
        drawCircle(x - 0.07f*size, trunkTopY + 0.05f*size, 0.09f*size, 30);
        drawCircle(x + 0.07f*size, trunkTopY + 0.05f*size, 0.09f*size, 30);
    } else {
        setColor(0.1f, 0.7f, 0.1f);
        drawCircle(x, trunkTopY + 0.03f*size, 0.15f*size, 35);
        drawCircle(x - 0.09f*size, trunkTopY + 0.10f*size, 0.11f*size, 30);
        drawCircle(x + 0.09f*size, trunkTopY + 0.10f*size, 0.11f*size, 30);
        drawCircle(x, trunkTopY + 0.16f*size, 0.13f*size, 30);
    }
}

void drawBackground() {
    glBegin(GL_QUADS);
    if (isNight) {
        glColor3f(0.05f, 0.05f, 0.2f);
        glVertex2f(-1.0, 1.0); glVertex2f(1.0, 1.0);
        glColor3f(0.1f, 0.1f, 0.35f);
        glVertex2f(1.0, 0.0); glVertex2f(-1.0, 0.0);
    } else {
        glColor3f(0.4f, 0.7f, 1.0f);
        glVertex2f(-1.0, 1.0); glVertex2f(1.0, 1.0);
        glColor3f(0.6f, 0.9f, 1.0f);
        glVertex2f(1.0, 0.0); glVertex2f(-1.0, 0.0);
    }
    glEnd();

    glPushMatrix();
    glTranslatef(0.6f, 0.8f, 0.0f);
    if (isNight) {
        glColor3f(0.95f, 0.95f, 0.8f);
        drawCircle(0.0f, 0.0f, 0.08f, 30);
    } else {
        glColor3f(1.0f, 0.9f, 0.2f);
        drawCircle(0.0f, 0.0f, 0.1f, 40);
        drawCloud(-1.2f + cloudOffset, 0.0f, 1.0f);
        drawCloud(-0.8f + cloudOffset, -0.2f, 0.8f);
    }
    glPopMatrix();

    glBegin(GL_QUADS);
    setColor(0.2f, 0.7f, 0.2f);
    glVertex2f(-1.0, 0.2f); glVertex2f(1.0, 0.2f);
    setColor(0.1f, 0.6f, 0.1f);
    glVertex2f(1.0, -1.0); glVertex2f(-1.0, -1.0);
    glEnd();

    float roadW = 0.3f;
    float endY = -0.3f;

    glBegin(GL_QUAD_STRIP);
    setColor(0.8f, 0.7f, 0.5f);
    for(float y = endY; y >= -1.0f; y-=0.1f) {
        float perspective = (y + 1.0f) * 0.1f;
        glVertex2f(-roadW/2 - perspective, y);
        glVertex2f( roadW/2 + perspective, y);
    }
    glEnd();

    glPushMatrix();
    glTranslatef(0.0f, endY, 0.0f);
    setColor(0.8f, 0.7f, 0.5f);
    drawOval(0.0f, 0.0f, 0.25f, 0.1f);
    glPopMatrix();
}

void drawScenery() {
    drawTree(-0.95f, -0.2f, 1.0f, false);
    drawTree(-0.80f, -0.25f, 0.8f, true);
    drawTree( 0.95f, -0.30f, 0.9f, true);
}
