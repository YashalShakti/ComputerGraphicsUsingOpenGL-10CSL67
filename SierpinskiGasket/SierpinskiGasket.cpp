//
// Created by yashal on 10/5/16.
// Program to recursively subdivide a tetrahedron to from 3D Sierpinski gasket. The
// number of recursive steps is to be specified by the user
//

#include "SierpinskiGasket.h"
typedef SierpinskiGasket SG;

typedef float Vertex[3];
// Vertices of a tetrahedron in 3D viewed with one vertex pointing directly towards viewer.
Vertex vertices[] = {{0.0, 0.0, 1.0f}, {0.0, 0.8f, 0.0f}, {-0.8f, -0.4f, 0.0f}, {0.8f, -0.4f, 0.0f}};

int SG::main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(720, 720);
  glutCreateWindow("Sierpinski Gasket");
  glutDisplayFunc(display);
  glutReshapeFunc(glInit);
  glInit(720,720);
  glutMainLoop();
}

void SG::glInit(int w, int h) {

  glClearColor(1, 1, 1, 1); // Set buffer color to White and clear using buffer.
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnable(GL_DEPTH_TEST);   // Enable hidden surface removal

  glMatrixMode(GL_PROJECTION);   // Load identity matrix into Projection matrix
  glLoadIdentity();

  glViewport(0, 0, w, h); // Resize viewport to show new w and h.
  if (h>=w) //This is needed to main proper aspect ratio; otherwise the image would appear stretched
    glOrtho(-1.0, 1.0, (GLfloat) -h / w, (GLfloat) h / w, -1.0, 1.0); //width is smaller than height
  else
    glOrtho((GLfloat) -w / h, (GLfloat) w / h, -1.0, 1.0, -1.0, 1.0); //height is smaller
}

void SG::display() {
  int divisions = 1; // Take input if need be.
  drawTetrahedron(divisions);
  glFlush();
}

void SG::drawTetrahedron(int divisions) {
  // Take each triangular face of Tetrahedron at a time and divide/draw it with different color.
  glColor3f(1, 0, 0);
  divideTriangle(vertices[0], vertices[1], vertices[2], divisions);
  glColor3f(0, 0, 1);
  divideTriangle(vertices[0], vertices[1], vertices[3], divisions);
  glColor3f(0, 0, 0);
  divideTriangle(vertices[0], vertices[2], vertices[3], divisions);
  glColor3f(0, 1, 0);
  divideTriangle(vertices[1], vertices[2], vertices[3], divisions);
}

void SG::divideTriangle(Vertex a, Vertex b, Vertex c, int divisions) {
  Vertex v1, v2, v3;
  if (divisions > 0) { // If we still need to divide
    for (int j = 0; j < 3; j++) {
      v1[j] = (a[j] + b[j]) / 2;
      v2[j] = (c[j] + a[j]) / 2;
      v3[j] = (b[j] + c[j]) / 2;
    }
    // Divide triangle from a/b/c to two other midpoints they are connected to. (a is connected to in v1 and v2)
    divideTriangle(a, v1, v2, divisions - 1);
    divideTriangle(b, v3, v1, divisions - 1);
    divideTriangle(c, v2, v3, divisions - 1);
  } else {
    drawTriangle(a, b, c);
  }
}

void SG::drawTriangle(Vertex a, Vertex b, Vertex c) {
  glBegin(GL_POLYGON);
  glVertex3fv(a);
  glVertex3fv(b);
  glVertex3fv(c);
  glEnd();
}
