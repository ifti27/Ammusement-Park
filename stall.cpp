#include "globals.h"

#include "stall.h"

void drawTicketCounter(float x, float y) {

    float width = 0.18f;

    float height = 0.25f;

    setColor(0.75f, 0.50f, 0.30f);

    drawRect(x, y - height/2, width, height);

    setColor(0.60f, 0.40f, 0.20f);

    float pillarWidth = 0.02f;

    float pillarHeight = height / 2;

    float pillarY = y - (pillarHeight / 2);

    drawRect(x - width/2 + pillarWidth, pillarY, pillarWidth, pillarHeight);

    drawRect(x + width/2 - pillarWidth, pillarY, pillarWidth, pillarHeight);

    setColor(0.95f, 0.25f, 0.25f);

    drawTriangle(x - width/2 - 0.02f, y-0.07, x + width/2 + 0.02f, y-0.07, x, y + 0.1f);

    setColor(0.95f, 0.95f, 0.95f);

    drawRect(x, y - 0.1f, 0.12f, 0.08f);

    setColor(0.2f, 0.2f, 0.2f);

    drawRect(x, y + 0.02f, 0.12f, 0.03f);

    if(isNight) {

        glColor3f(1.0f, 1.0f, 0.8f);

        drawCircle(x, y - 0.1f, 0.02f, 10);

    }

}

void drawIceCreamStall(float x, float y) {

    float width = 0.22f;

    float Size = 0.05f;


    setColor(1.0f, 0.8f, 0.40f);

    drawRect(x, y - 0.15f, width, 0.15f);

    setColor(0.36f, 0.25f, 0.20f);

    drawRect(x - 0.1f, y, 0.01f, 0.3f);

    drawRect(x + 0.1f, y, 0.01f, 0.3f);

    setColor(0.36f, 0.25f, 0.20f);

    drawRect(x, y + 0.05f, width + 0.04f, 0.05f);

    setColor(1.0f, 0.6f, 0.78f);

    drawCircle(x, y + Size * 0.9f, Size, 20);


    setColor(0.9f, 0.7f, 0.4f);

    drawTriangle(x-0.05f, y + 0.08f, x+0.05 , y + 0.20f, x + 0.05f, y + 0.05f);

    if(isNight) {

        glColor3f(1.0f, 1.0f, 1.0f);

        drawCircle(x, y -0.01f, 0.02f, 10);

    }

}

void drawLamp(float x, float y) {

    setColor(0.2f, 0.2f, 0.2f);

    drawRect(x, y + 0.25f, 0.02f, 0.5f);

    setColor(0.1f, 0.1f, 0.1f);

    drawRect(x, y + 0.3f, 0.08f, 0.08f);

    if(isNight) {

        glColor4f(1.0f, 1.0f, 0.0f, 0.3f);

        drawCircle(x, y + 0.28f, 0.08f, 10);

    } else {

        glColor3f(0.8f, 0.8f, 0.8f);

        drawCircle(x, y + 0.28f, 0.02f, 10);

    }

}

