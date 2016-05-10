//
// Created by yashal on 10/5/16.
//

#include "SierpinskiGasket.h"

typedef float point[3];
point vertices[] = {{1.0f, 0.0f, -0.5f}, {-1.0f, 0.0f, -0.5f}, {0.0f, 1.0f, 0.5f}, {0.0f, -1.0f, 0.5f}};
//{{1,1,1}, {1,−1.0f,−1.0f}, {−1,1,−1}, {−1,−1,1}};
//{{0.0, 0.0, -1.0f}, {0.0, 1.0f, -0.3333f}, {-1.0f, -0.5f, -0.3333f}, {1.0f, -0.5f, -0.5f}};
//point v[]={{0.0,0.0,-1.0},{0.0,0.9428,-0.3333},{-0.8164,-0.4714,-0.3333},{0.8164,-0.4714,-0.5}};

int SierpinskiGasket::main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Sierpinski Gasket");
  initGl();
  glutDisplayFunc(display);
  glutMainLoop();
}

void SierpinskiGasket::initGl() {

  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnable(GL_DEPTH_TEST);
  glLoadIdentity();

  glViewport(0, 0, 500, 500);
}

void SierpinskiGasket::display() {
  int divisions = 5;
  drawTetrahedron(divisions);
  glFlush();
}

void SierpinskiGasket::drawTetrahedron(int divisions) {
  glColor3f(1, 0, 0);
  divideTriangle(vertices[0], vertices[1], vertices[2], divisions);
  glColor3f(0, 0, 1);
  divideTriangle(vertices[0], vertices[1], vertices[3], divisions);
  glColor3f(0, 0, 0);
  divideTriangle(vertices[0], vertices[2], vertices[3], divisions);
  glColor3f(0, 1, 0);
  divideTriangle(vertices[1], vertices[2], vertices[3], divisions);
}

void SierpinskiGasket::divideTriangle(point a, point b, point c, int divisions) {
  point v1, v2, v3;
  if (divisions > 0) {
    for (int j = 0; j < 3; j++) {
      v1[j] = (a[j] + b[j]) / 2;
      v2[j] = (a[j] + c[j]) / 2;
      v3[j] = (b[j] + c[j]) / 2;
    }
    divideTriangle(a, v1, v2, divisions - 1);
    divideTriangle(b, v3, v1, divisions - 1);
    divideTriangle(c, v2, v3, divisions - 1);
  } else {
    drawTriangle(a, b, c);
  }
}

void SierpinskiGasket::drawTriangle(point a, point b, point c) {
  glBegin(GL_POLYGON);
  glVertex3fv(a);
  glVertex3fv(b);
  glVertex3fv(c);
  glEnd();
}
