//
// Created by yashal on 9/5/16.
//

#include "RotatingAHouse.h"

GLfloat house[3][9] = {{100.0, 100.0, 175.0, 250.0, 250.0, 150.0, 150.0, 200.0, 200.0},
                       {100.0, 300.0, 400.0, 300.0, 100.0, 100.0, 150.0, 150.0, 100.0},
                       {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}};
GLfloat theta;
void RotatingAHouse::multiply(GLfloat a[3][3], GLfloat b[3][9], GLfloat result[3][9]) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 9; j++) {
      for (int k = 0; k < 3; k++)
        result[i][j] = result[i][j] + a[i][k] * b[k][j];
    }
}

void RotatingAHouse::drawHouse(GLfloat c[3][9]) {

  int i;

  //box
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_LINE_LOOP);
  for (i = 0; i <= 4; i++) {
    if (i != 2) {
      glVertex2f(c[0][i], c[1][i]);
    }
  }
  glEnd();

  //door
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINE_LOOP);
  for (i = 5; i <= 8; i++) {
    glVertex2f(c[0][i], c[1][i]);
  }
  glEnd();

  //triangle
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_LINE_LOOP);
  for (i = 1; i <= 3; i++) {
    glVertex2f(c[0][i], c[1][i]);
  }
  glEnd();

}
void RotatingAHouse::rotate(GLfloat theta, GLfloat result[3][9]) {

  GLfloat m, n;
  GLfloat h = 100.0;
  GLfloat k = 100.0;
  m = (GLfloat) (-h * (cos(theta) - 1) + k * (sin(theta)));// of form x-xcos(theta)+ysin(theta)
  n = (GLfloat) (-k * (cos(theta) - 1) - h * (sin(theta)));// of form y-ycos(theta)-xsin(theta)

  GLfloat rot_mat[3][3] = {
      {(GLfloat) cos(theta), (GLfloat) -sin(theta), m},
      {(GLfloat) sin(theta), (GLfloat) cos(theta), n},
      {0, 0, 1}
  };
  /*  GLfloat rot_mat[3][3] = {
      {cos(theta),  -sin(theta) , m},
      {sin(theta),  cos(theta)  , n},
      {0         ,  0           , 1}
  };*/

  multiply(rot_mat, house, result);
}

void RotatingAHouse::display() {
  GLfloat result[3][9] = {{0}, {0}, {0}};
  drawHouse(house);//draw before rotation
  rotate(theta, result);//function to rotate
  drawHouse(result);
  glFlush();
}

void RotatingAHouse::init() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int RotatingAHouse::main(int argc, char *argv[]) {
  std::cout << "Enter the rotation angle\n";
  std::cin >> theta;
  theta = theta * (3.14 / 180);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("house rotation");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}