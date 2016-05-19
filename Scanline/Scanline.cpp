//
// Created by yashal on 19/5/16.
//

#include "Scanline.h"
#include<GL/glut.h>

float x1 = 200, x2 = 300, x3 = 400, x4 = 300, y1 = 200, y2 = 300, y3 = 200, y4 = 100;
int le[500], re[500];

void Scanline::edgeDetect(float x1, float y1, float x2, float y2) {
  float slopeX, swapTemp;

  if (y2 < y1) {
    swapTemp = y1;
    y1 = y2;
    y2 = swapTemp;

    swapTemp = x1;
    x1 = x2;
    x2 = swapTemp;
  }

  if (y2 != y1)
    slopeX = (x2 - x1) / (y2 - y1);
  else
    slopeX = x2 - x1;

  for (int i = (int) y1; i <= y2; i++,x1 += slopeX) {
    if (x1 < le[i])
      le[i] = (int) x1;

    if (x1 > re[i])
      re[i] = (int) x1;
  }
}

void Scanline::drawPixel(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void Scanline::scanFill() {
  for (int i = 0; i < 500; i++) {
    le[i] = 500;
    re[i] = 0;
  }

  edgeDetect(x1, y1, x2, y2);
  edgeDetect(x2, y2, x3, y3);
  edgeDetect(x3, y3, x4, y4);
  edgeDetect(x4, y4, x1, y1);

  for (int j = 0; j < 500; j++) {
    if (le[j] <= re[j])
      for (int k = le[j]; k < re[j]; k++)
        drawPixel(k, j);
  }
}

void Scanline::display() {

  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glVertex2f(x3, y3);
  glVertex2f(x4, y4);
  glEnd();

  glColor3f(1.0, 0.0, 0.0);
  scanFill();

  glFlush();
}

void Scanline::initGl() {

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(0.0, 720.0, 0.0, 720.0, -1, 1);
}

int Scanline::main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(720, 720);
  glutCreateWindow("Scanline");
  glutDisplayFunc(display);
  initGl();
  glutMainLoop();
}