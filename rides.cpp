#include "globals.h"
#include "rides.h"

void drawFerrisWheel(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    setColor(0.9f, 0.6f, 0.1f);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f); glVertex2f(-0.5f, -1.0f);
    glVertex2f(0.0f, 0.0f); glVertex2f( 0.5f, -1.0f);
    glEnd();
    glLineWidth(1.0f);

    glPushMatrix();
    glRotatef(ferrisAngle, 0.0f, 0.0f, 1.0f);

    setColor(0.8f, 0.1f, 0.1f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<40; i++) {
        float a = 2.0f * PI * i / 40;
        glVertex2f(cos(a)*0.6f, sin(a)*0.6f);
    }
    glEnd();

    if(isNight) {
        glPointSize(4.0f);
        glBegin(GL_POINTS);
        for(int i=0; i<16; i++) {
            float a = 2.0f * PI * i / 16;
            glColor3f(1.0f, 1.0f, 0.5f);
            glVertex2f(cos(a)*0.6f, sin(a)*0.6f);
        }
        glEnd();
    }

    for(int i=0; i<8; i++) {
        float a = i * 45.0f * PI / 180.0f;
        setColor(1.0f, 0.8f, 0.2f);
        glBegin(GL_LINES);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(cos(a)*0.6f, sin(a)*0.6f);
        glEnd();

        glPushMatrix();
        glTranslatef(cos(a)*0.6f, sin(a)*0.6f, 0.0f);
        glRotatef(-ferrisAngle, 0.0f, 0.0f, 1.0f);

        setColor(0.2f, 0.6f, 0.9f);
        drawRect(0.0f, 0.0f, 0.12f, 0.15f);
        glPopMatrix();
    }

    glPopMatrix();
    glPopMatrix();
}

void drawMerryGoRound(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    setColor(0.6f, 0.2f, 0.2f);
    drawOval(0.0f, -0.1f, 0.6f, 0.15f);

    setColor(0.8f, 0.6f, 0.4f);
    drawOval(0.0f, -0.05f, 0.55f, 0.12f);

    setColor(0.8f, 0.7f, 0.2f);
    drawRect(0.0f, 0.4f, 0.08f, 0.5f);

    float hY = sin(carouselAngle * 0.1f) * 0.05f;

    glPushMatrix();
    glTranslatef(0.3f, 0.15f + hY, 0.0f);
    setColor(1.0f, 1.0f, 1.0f);
    drawRect(0.0f, 0.0f, 0.12f, 0.08f);
    setColor(0.5f, 0.5f, 0.5f);
    drawRect(0.0f, 0.1f, 0.01f, 0.3f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3f, 0.15f - hY, 0.0f);
    setColor(0.8f, 0.5f, 0.2f);
    drawRect(0.0f, 0.0f, 0.12f, 0.08f);
    setColor(0.5f, 0.5f, 0.5f);
    drawRect(0.0f, 0.1f, 0.01f, 0.3f);
    glPopMatrix();

    glTranslatef(0.0f, 0.45f, 0.0f);
    setColor(0.9f, 0.1f, 0.1f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.3f);
    for(int i=0; i<=30; i++) {
        float a = 2.0f * PI * i / 30;
        glVertex2f(cos(a)*0.6f, sin(a)*0.15f);
    }
    glEnd();

    if(isNight) {
        glPointSize(4.0f);
        glBegin(GL_POINTS);
        for(int i=0; i<10; i++) {
            float a = 2.0f * PI * i / 10;
            glColor3f(1.0f, 1.0f, 0.5f);
            glVertex2f(cos(a)*0.6f, sin(a)*0.15f);
        }
        glEnd();
    }

    glPopMatrix();
}
