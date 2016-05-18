//
// Created by yashal on 18/5/16.
//

#include "CylinderAndParallelpiped.h"
#include <math.h>
#include <GL/glut.h>

typedef CylinderAndParallelpiped CAP;
#define SIZE 0.5f

void CAP::drawCircle() {
  glBegin(GL_LINE_LOOP); //circle
  for (int i = 0; i < 360; i++) {
    float theta = 2.0 * 3.1415926 * i / 360.0f;
    float x = SIZE/2 * cosf(theta);
    float y = SIZE/2 * sinf(theta);
    glVertex2f(x + 0.4, y - 0.7);
  }
  glEnd();
}

void CAP::drawRectangle() {
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.0, 0.0);
  glVertex2f(SIZE, 0.0);
  glVertex2f(SIZE, SIZE);
  glVertex2d(0.0, SIZE);
  glEnd();
}

void CAP::display() {
  for (int i = 0; i < 30; i++) {
    glTranslated(0.01, 0.01, 0);
    drawRectangle();
    drawCircle();
  }
  glFlush();
}

void CAP::glInit() {
  glClear(GL_COLOR_BUFFER_BIT);
  glViewport(0, 0, 700, 700);
  glLoadIdentity();
  glTranslated(-0.4, 0, 0);
}

int CAP::main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(700, 700);
  glutCreateWindow("Cylinder and parallelpiped");
  glInit();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}