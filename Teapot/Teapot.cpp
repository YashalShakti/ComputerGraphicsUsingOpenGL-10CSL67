//
// Created by yashal on 18/5/16.
//

#include "Teapot.h"
#include<GL/glut.h>

typedef Teapot TP;

void TP::drawCube(double tx, double ty, double tz, double sx, double sy, double sz) {
  glRotated(50, 0, 1, 0);
  glRotated(10, -1, 0, 0);
  glRotated(10, 0, 0, -1);

  glTranslated(tx, ty, tz);
  glScaled(sx, sy, sz);

  glutSolidCube(1);
  glLoadIdentity();
}

void TP::display() {
  drawCube(0, 0, 0.5, 1, 1, 0.04); // Behind wall
  drawCube(0, -0.5, 0, 1, 0.04, 1); // Left wall
  drawCube(-0.5, 0, 0, 0.04, 1, 1); // Bottom wall

  drawCube(0, -0.3, 0, 0.02, 0.2, 0.02);  // Four table legs
  drawCube(0, -0.3, -0.4, 0.02, 0.2, 0.02);
  drawCube(0.4, -0.3, 0, 0.02, 0.2, 0.02);
  drawCube(0.4, -0.3, -0.4, 0.02, 0.2, 0.02);

  drawCube(0.2, -0.18, -0.2, 0.6, 0.02, 0.6);  // Table top

  // Draw the teapot
  glRotated(50, 0, 1, 0);
  glRotated(10, -1, 0, 0);
  glRotated(10, 0, 0, -1);
  glTranslated(0.3, -0.1, -0.3);
  glutSolidTeapot(0.09);

  glFlush();
  glLoadIdentity();
}

void TP::glInit() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  float lightPosition[] = {27, 80, 2, 3};
  glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

  float ambient[] = {1, 1, 1, 1};
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);

  glEnable(GL_DEPTH_TEST);
  glViewport(0, 0, 700, 700);
}

int TP::main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(700, 700);
  glutCreateWindow("scene");
  glInit();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}