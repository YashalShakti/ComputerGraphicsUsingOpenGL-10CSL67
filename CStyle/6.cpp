//
// Created by yashal on 18/5/16.
//

#include <math.h>
#include <GL/glut.h>

#define SIZE 0.5f

void drawCircle() {
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 360; i++) {
    float theta = 2.0 * 3.1415926 * i / 360.0f; // Get angle
    float x = (SIZE / 2) * cosf(theta);
    float y = (SIZE / 2) * sinf(theta);
    glVertex2f(y, x);
  }
  glEnd();
}

void drawRectangle() {
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.0, 0.0);
  glVertex2f(SIZE, 0.0);
  glVertex2f(SIZE, SIZE);
  glVertex2d(0.0, SIZE);
  glEnd();
}

void display() {
  for (int i = 0; i < 30; i++) {
    glTranslated(0.01, 0.01, 0);
    drawRectangle();
  }

  glTranslated(0, -1.0, 0);
  for (int i = 0; i < 30; i++) {
    glTranslated(0.01, 0.01, 0);
    drawCircle();
  }
  glFlush();
}

void glInit() {

  glClear(GL_COLOR_BUFFER_BIT);

  glLoadIdentity();
  glTranslated(-0.4, 0, 0);

  glViewport(0, 0, 700, 700);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(700, 700);
  glutCreateWindow("Cylinder and Parallelpiped");
  glInit();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}