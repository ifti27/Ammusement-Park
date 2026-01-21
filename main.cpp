#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846
#define MAX_FIREWORKS 8

float ferrisAngle    = 0.0f;
float cloudOffset    = 0.0f;
bool  isNight        = false;
float peopleOffset   = 0.0f;

float skyR, skyG, skyB;
float groundR, groundG, groundB;
float sunMoonR, sunMoonG, sunMoonB;

float fw_x[MAX_FIREWORKS];
float fw_y[MAX_FIREWORKS];
float fw_size[MAX_FIREWORKS];
float fw_alpha[MAX_FIREWORKS];
int   fw_active[MAX_FIREWORKS];

void circle(float cx, float cy, float r, int segments = 50);
void updateColors();
void sky();
void sunOrMoon();
void clouds();
void ground();
void simpleTree(float tx, float ty, float scale = 1.0f);
void drawTrees();
void ticketBooth();
void foodStall();
void gameStall();
void ferrisWheel();
void pirateShip();
void stickPerson(float px, float py, float size = 1.0f);
void drawPeople();
void fireworks();
void timer(int value);
void keyboard(unsigned char key, int x, int y);
void init();
void display();

void circle(float cx, float cy, float r, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; ++i) {
        float theta = 2.0f * PI * i / segments;
        glVertex2f(cx + r * cosf(theta), cy + r * sinf(theta));
    }
    glEnd();
}

void updateColors() {
    if (isNight) {
        skyR = 0.04f; skyG = 0.03f; skyB = 0.20f;
        groundR = 0.10f; groundG = 0.18f; groundB = 0.06f;
        sunMoonR = 0.98f; sunMoonG = 0.94f; sunMoonB = 0.68f;
    } else {
        skyR = 0.50f; skyG = 0.80f; skyB = 0.97f;
        groundR = 0.36f; groundG = 0.76f; groundB = 0.04f;
        sunMoonR = 1.0f; sunMoonG = 0.84f; sunMoonB = 0.0f;
    }
}

void sky() {
    glColor3f(skyR, skyG, skyB);
    glBegin(GL_QUADS);
    glVertex2f(-50, 50);
    glVertex2f( 50, 50);
    glVertex2f( 50, -5);
    glVertex2f(-50, -5);
    glEnd();
}

void sunOrMoon() {
    glPushMatrix();
    glTranslatef(-18, 26, 0);
    glColor3f(sunMoonR, sunMoonG, sunMoonB);
    circle(0, 0, 4.0f);
    glPopMatrix();
}

void clouds() {
    cloudOffset -= 0.012f;
    if (cloudOffset < -80) cloudOffset = 80;

    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(-25 + cloudOffset, 22, 0);
    circle(0,0,4.5f); circle(5,1.8,5.5f); circle(-4,1,4.2f);
    glPopMatrix();

    glPushMatrix(); glTranslatef(20 + cloudOffset*0.7f, 28, 0);
    circle(0,0,4.0f); circle(4,1.5,5.0f); circle(8,0.6,3.8f);
    glPopMatrix();
}

void ground() {
    glColor3f(groundR, groundG, groundB);
    glBegin(GL_QUADS);
    glVertex2f(-50, -5);
    glVertex2f( 50, -5);
    glVertex2f( 50,-50);
    glVertex2f(-50,-50);
    glEnd();
}

void simpleTree(float tx, float ty, float scale) {
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(scale, scale, 1);

    glColor3f(0.50f, 0.25f, 0.06f);
    glBegin(GL_QUADS);
    glVertex2f(-0.9, 0);  glVertex2f(0.9, 0);
    glVertex2f(0.9, 6.5); glVertex2f(-0.9, 6.5);
    glEnd();

    glColor3f(0.08f, 0.50f, 0.08f);
    circle(0, 9.5, 4.2f);
    circle(-2.8, 7.5, 3.5f);
    circle(2.8, 7.5, 3.5f);
    circle(0, 6.0, 4.5f);

    glPopMatrix();
}

void drawTrees() {
    simpleTree(-45, -10, 1.15f);
    simpleTree(-42, -22, 0.95f);
    simpleTree(-48, -32, 1.05f);
    simpleTree(-30, -8, 1.20f);
    simpleTree(-26, -18, 1.00f);
    simpleTree(44, -12, 1.10f);
    simpleTree(47, -25, 0.90f);
    simpleTree(41, -35, 1.00f);
    simpleTree(28, -10, 1.15f);
    simpleTree(32, -20, 0.95f);
    simpleTree(-8, -38, 1.05f);
    simpleTree(10, -40, 1.00f);
}

void ticketBooth() {
    glPushMatrix();
    glTranslatef(-36, -8, 0);
    glScalef(1.6f, 1.6f, 1);
    glColor3f(0.88f, 0.12f, 0.12f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-4, 8); glVertex2f(4, 8); glVertex2f(0, 13.5);
    glEnd();
    glColor3f(0.97f, 0.97f, 0.78f);
    glBegin(GL_QUADS);
    glVertex2f(-4, 0); glVertex2f(4, 0); glVertex2f(4, 8); glVertex2f(-4, 8);
    glEnd();
    glColor3f(0.15f, 0.78f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-2.4, 3.8); glVertex2f(2.4, 3.8);
    glVertex2f(2.4, 7);    glVertex2f(-2.4, 7);
    glEnd();
    glColor3f(1,0,0);
    glRasterPos2f(-3.2, 1.2);
    const char* txt = "TICKETS";
    while (*txt) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *txt++);
    glPopMatrix();
}

void foodStall() {
    glPushMatrix();
    glTranslatef(-18, -12, 0);
    glScalef(1.5f, 1.5f, 1);
    glColor3f(1.0f, 0.55f, 0.08f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-5, 9); glVertex2f(5, 9); glVertex2f(0, 14.5);
    glEnd();
    glColor3f(0.92f, 0.38f, 0.08f);
    glBegin(GL_QUADS);
    glVertex2f(-5, 0); glVertex2f(5, 0); glVertex2f(5, 9); glVertex2f(-5, 9);
    glEnd();
    glColor3f(1,1,0.2f);
    glRasterPos2f(-3.5, 10.8);
    const char* f = "FOOD";
    while (*f) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *f++);
    glPopMatrix();
}

void gameStall() {
    glPushMatrix();
    glTranslatef(16, -14, 0);
    glScalef(1.5f, 1.5f, 1);
    glColor3f(0.15f, 0.55f, 0.95f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-5, 9); glVertex2f(5, 9); glVertex2f(0, 14.5);
    glEnd();
    glColor3f(0.96f, 0.96f, 0.65f);
    glBegin(GL_QUADS);
    glVertex2f(-5, 0); glVertex2f(5, 0); glVertex2f(5, 9); glVertex2f(-5, 9);
    glEnd();
    glColor3f(1,0,0);
    glRasterPos2f(-4.0, 10.8);
    const char* g = "GAMES";
    while (*g) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *g++);
    glPopMatrix();
}

void ferrisWheel() {
    glPushMatrix();
    glTranslatef(30, 14, 0);
    glRotatef(ferrisAngle, 0,0,1);
    glColor3f(0.22f, 0.22f, 0.40f);
    glLineWidth(5.5f);
    glBegin(GL_LINES);
    for (int i = 0; i < 360; i += 30) {
        float a = i * PI / 180.0f;
        glVertex2f(0,0);
        glVertex2f(16 * cosf(a), 16 * sinf(a));
    }
    glEnd();
    for (int i = 0; i < 12; i++) {
        float a = (i * 30.0f + ferrisAngle) * PI / 180.0f;
        float x = 16 * cosf(a);
        float y = 16 * sinf(a);
        glColor3f(0.92f, 0.12f, 0.12f);
        glBegin(GL_QUADS);
        glVertex2f(x-1.5, y-2.5); glVertex2f(x+1.5, y-2.5);
        glVertex2f(x+1.5, y+1.0); glVertex2f(x-1.5, y+1.0);
        glEnd();
        if (isNight) {
            glColor4f(1,1,0.4,0.75);
            circle(x, y+1.4, 1.2f);
        }
    }
    glPopMatrix();
}

void pirateShip() {
    glPushMatrix();
    glTranslatef(-10, -6, 0);
    glScalef(0.6f, 0.6f, 1.0f);
    glRotatef(sinf(glutGet(GLUT_ELAPSED_TIME)*0.0008f)*42.0f, 0,0,1);
    glColor3f(0.68f, 0.38f, 0.14f);
    glBegin(GL_POLYGON);
    glVertex2f(-15,-6); glVertex2f(-12,9);
    glVertex2f( 12,9);  glVertex2f( 15,-6);
    glVertex2f(  0,-10);
    glEnd();
    glColor3f(0.92f,0.92f,0.92f);
    glBegin(GL_QUADS);
    glVertex2f(-1.4,9); glVertex2f(1.4,9);
    glVertex2f(1.4,20); glVertex2f(-1.4,20);
    glEnd();
    glColor3f(0.92f,0.18f,0.18f);
    glBegin(GL_TRIANGLES);
    glVertex2f(1.4,20); glVertex2f(10,16); glVertex2f(1.4,13);
    glEnd();
    glPopMatrix();
}

void stickPerson(float px, float py, float size) {
    glPushMatrix();
    glTranslatef(px, py, 0);
    glScalef(size, size, 1);

    glColor3f(0.96f, 0.84f, 0.68f);
    circle(0, 5.0, 1.2f);

    glColor3f(0.18f, 0.38f, 0.78f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(0, 3.8); glVertex2f(0, 0.8);
    glVertex2f(-2.0, 2.8); glVertex2f(2.0, 2.8);
    glVertex2f(-1.0, 0.8); glVertex2f(1.0, 0.8);
    glEnd();

    glPopMatrix();
}

void drawPeople() {
    stickPerson(-42.0f, -6.5f, 0.95f);
    stickPerson(-27.0f, -9.0f, 1.02f);
    stickPerson(-9.0f, -11.5f, 0.98f);
    stickPerson(-1.5f, -14.0f, 1.05f);
    stickPerson(8.0f, -13.5f, 0.97f);
    stickPerson(24.0f, -13.0f, 1.00f);
    stickPerson(36.0f, -10.0f, 1.08f);
    stickPerson(-40.0f, -2.0f, 0.92f);
}

void fireworks() {
    if (!isNight) return;

    if (rand() % 65 == 0) {
        for (int i = 0; i < MAX_FIREWORKS; i++) {
            if (!fw_active[i]) {
                fw_x[i] = -35 + (rand() % 70);
                fw_y[i] = 20 + (rand() % 15);
                fw_size[i] = 0.4f + (rand()%9)/11.0f;
                fw_alpha[i] = 1.0f;
                fw_active[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < MAX_FIREWORKS; i++) {
        if (fw_active[i]) {
            fw_alpha[i] -= 0.0085f;
            fw_size[i] += 0.075f;
            if (fw_alpha[i] <= 0) {
                fw_active[i] = 0;
                continue;
            }
            glColor4f(0.9f + rand()%100/400.0f,
                      0.5f + rand()%100/200.0f,
                      0.3f + rand()%100/150.0f,
                      fw_alpha[i]);
            circle(fw_x[i], fw_y[i], fw_size[i], 30);
        }
    }
}

void timer(int value) {
    ferrisAngle -= 0.38f;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'n' || key == 'N') {
        isNight = !isNight;
        glutPostRedisplay();
    }
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50, 50, -50, 50);

    for (int i = 0; i < MAX_FIREWORKS; i++) fw_active[i] = 0;
    srand((unsigned)time(NULL));
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    updateColors();

    sky();
    sunOrMoon();
    clouds();
    ground();

    drawTrees();

    ticketBooth();
    foodStall();
    gameStall();

    ferrisWheel();
    pirateShip();

    drawPeople();

    fireworks();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1600, 1000);
    glutCreateWindow("Amusement Park");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);

    printf("Press 'N' to toggle Day / Night\n");

    glutMainLoop();
    return 0;
}
