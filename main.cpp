#include <GL/glut.h>
#include <iostream>
#include "globals.h"
#include "background.h"
#include "rides.h"
#include "stall.h"
#include "human.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawBackground();
    drawScenery();

    drawFerrisWheel(-0.7f, 0.2f, 0.65f);
    drawMerryGoRound(0.75f, -0.2f, 0.65f);

    drawTicketCounter(-0.35f, -0.2f);
    drawIceCreamStall(0.35f, -0.2f);

    drawLamp(-0.2f, -0.4f);
    drawLamp( 0.2f, -0.4f);

    drawHumans();

    glutSwapBuffers();
}

void update(int value) {
    if (isAnimating) {
        ferrisAngle += 1.0f;
        if(ferrisAngle > 360) ferrisAngle -= 360;

        carouselAngle += 2.0f;

        cloudOffset += 0.001f;
        if(cloudOffset > 2.0f) cloudOffset = -2.0f;

        humanOffset += 0.05f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'n' || key == 'N') isNight = !isNight;
    if (key == ' ') isAnimating = !isAnimating;
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Amusement Park");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    std::cout << "Controls:\n[D] Day\n[N] Night\n[Space] Start/Stop" << std::endl;

    glutMainLoop();
    return 0;
}
