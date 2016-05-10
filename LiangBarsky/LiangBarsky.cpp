//
// Created by yashal on 10/5/16.
//
#include "LiangBarsky.h"
typedef LiangBarsky LB;

int LB::main(int argc, char **argv) {
  // Get/store vertices of the original line, windowport and viewport using any method of choice.
  getValues();
  glutInit(&argc, argv);
  glutInitWindowSize(720, 720);
  glutCreateWindow("Liang Barsky line clipping");
  initGl();
  glutDisplayFunc(display);
  glutMainLoop();
}

void LB::initGl() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 700, 0, 700);
}

void LB::display() {
  // Draw the original line
  glColor3i(1, 0, 0);
  glBegin(GL_LINE_LOOP);
  {
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
  }
  glEnd();

  // Draw the windowport
  glColor3i(0, 0, 1);
  glBegin(GL_LINE_LOOP);
  {
    glVertex2f(xMin, yMin);
    glVertex2f(xMax, yMin);
    glVertex2f(xMax, yMax);
    glVertex2f(xMin, yMax);
  }
  glEnd();

  clipAndDraw();
  glFlush();
}

int LB::clipTest(float p, float q, float *t0, float *t1) {
  float t = q / p;
  // For understanding lets assume x0 < x1 and y0 < y1
  // Aim is to increase t0 value decrease t1 value to clip the line
  // If p is negative we check for lower/minimum clipping boundary and vice-versa.
  if (p < 0.0) {
    if (t > *t0) *t0 = t; // If current t is > t0 we update t0 value.
    if (t > *t1) return (0);
  } else if (p > 0.0) {
    if (t < *t1) *t1 = t; // If current t is < t1 we update t1 value.
    if (t < *t0) return 0;
  } else if (t == 0) {
    if (q < 0.0) {
      return 0;
    }
  }
  return 1;
}

void LB::clipAndDraw() {
  float dx = x1 - x0, dy = y1 - y0, t0 = 0.0, t1 = 1.0;

  if (clipTest(-dx, x0 - xMin, &t0, &t1)
      && clipTest(dx, xMax - x0, &t0, &t1)
      && clipTest(-dy, y0 - yMin, &t0, &t1)
      && clipTest(dy, yMax - y0, &t0, &t1)) {

    if (t1 < 1.0) {
      x1 = x0 + t1 * dx;
      y1 = y0 + t1 * dy;
    }
    if (t0 > 0.0) {
      x0 = x0 + t0 * dx;
      y0 = y0 + t0 * dy;
    }

    // Get scaled values ie the ratio of windowport to viewport
    float sx, sy, vx0, vy0, vx1, vy1;
    sx = (xvMax - xvMin) / (xMax - xMin);
    sy = (yvMax - yvMin) / (yMax - yMin);
    // scale the values
    vx0 = xvMin + (x0 - xMin) * sx;
    vy0 = yvMin + (y0 - yMin) * sy;
    vx1 = xvMin + (x1 - xMin) * sx;
    vy1 = yvMin + (y1 - yMin) * sy;

    // Draw the clipped line
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(vx0, vy0);
    glVertex2f(vx1, vy1);
    glEnd();

    // Draw the viewport
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xvMin, yvMin);
    glVertex2f(xvMax, yvMin);
    glVertex2f(xvMax, yvMax);
    glVertex2f(xvMin, yvMax);
    glEnd();
  }
}