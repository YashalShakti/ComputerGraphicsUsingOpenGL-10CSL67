//
// Created by Yashal on 8/5/16.
// Program to display a set of values { fij } as a rectangular mesh
//

#include "RectangularMesh.h"

void RectangularMesh::initGl() {

  // Specify clear values for the color buffers and clear the buffer.
  // Sets the background in simple terms
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // The matrix to be used. Can be GL_MODELVIEW, GL_PROJECTION, and GL_TEXTURE
  glMatrixMode(GL_PROJECTION);

  // Replaces current matrix with identity matrix
  glLoadIdentity();

  // Set the clipping region of the screen/window to be viewed.
  // The window size is 500 x 500 so this function will view it from left=0,right=500 and bottom=0,top=500
  glOrtho(0.0, 720.0, 0.0, 720.0, -1, 1);
}

void RectangularMesh::display() {
  // Color the segments blue
  glColor3f(0.0, 0.0, 1.0);

  for (float i = 0.0; i < 700; i = i + 10) {
    glBegin(GL_LINE_STRIP);
    for (float j = 0.0; j < 700; j = j + 15)
      glVertex2f(i, j);
    glEnd();
  }
  for (float i = 0.0; i < 700; i = i + 15) {
    glBegin(GL_LINE_STRIP);
    for (float j = 0.0; j < 700; j = j + 10)
      glVertex2f(j, i);
    glEnd();
  }

  // Flush the complete mesh to the screen
  glFlush();
}

int RectangularMesh::main(int argc, char *argv[]) {

  // Glut is used for making window. First init the window
  glutInit(&argc, argv);

  /* This is not necessary since the default values are GLUT_SINGLE and GLUT_RGB
   *
   * glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   *
   */

  // Specify the window size and position
  glutInitWindowSize(500, 500);

  // Create the window
  glutCreateWindow("Rectangular mesh");

  // Initialize the window ( Background, buffer, matrix etc)
  initGl();

  // Specify the callback function that will render the window
  glutDisplayFunc(display);

  // This starts the OpenGL flow using callbacks
  glutMainLoop();

  return 1;
}
