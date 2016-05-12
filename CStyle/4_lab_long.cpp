//
// Created by yashal on 9/5/16.
// Program to create a house like figure and rotate it about a given fixed point using OpenGL functions
//

#include "GL/glut.h"
#include "iostream"
#include <math.h>

GLfloat house[3][12] = {{100.0, 100.0, 250.0, 175, 100.0, 250.0, 250.0, 100.0, 150.0, 150.0, 200.0, 200.0},
                                  {100.0, 300.0, 300.0, 400, 300.0, 300.0, 100.0, 100.0, 100.0, 150.0, 150.0, 100.0},
                                  {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}};
GLfloat theta;

void multiply(GLfloat a[3][3], GLfloat b[3][12], GLfloat result[3][12]) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 12; j++) {
      for (int k = 0; k < 3; k++)
        result[i][j] = result[i][j] + a[i][k] * b[k][j];
    }
}

void drawHouse(GLfloat house[3][12]) {
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 12; i++) {
    glVertex2f(house[0][i], house[1][i]);
  }
  glEnd();
}

void rotate(GLfloat theta, GLfloat result[3][12]) {
  double m, n;
  GLfloat x = house[0][0];
  GLfloat y = house[1][0];
  m = x - (x * cos(theta) - y * sin(theta)); // of form x-xcos(theta)+ysin(theta)
  n = y - (x * sin(theta) + y * cos(theta)); // of form y-ycos(theta)-xsin(theta)

  GLfloat rot_mat[3][3] = {
      {cos(theta),  -sin(theta) , m},
      {sin(theta),  cos(theta)  , n},
      {0         ,  0           , 1}
  };

  multiply(rot_mat, house, result);
}

void display() {
  GLfloat result[3][12] = {{0}, {0}, {0}};
  drawHouse(house);//draw before rotating
  rotate(theta, result);//function to rotate
  drawHouse(result);//draw after rotating
  glFlush();
}

void initGl(int w, int h) {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, w, 0.0, h, -1, 1);
}

int main(int argc, char *argv[]) {
  std::cout << "Enter the rotation angle\n";
  std::cin >> theta;
  theta = theta * (3.14 / 180);
  glutInit(&argc, argv);
  glutInitWindowSize(720, 720);
  glutCreateWindow("house rotation");
  glutDisplayFunc(display);
  initGl(720, 720);
  glutMainLoop();
}