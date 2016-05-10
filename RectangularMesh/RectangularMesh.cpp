//
// Created by Yashal on 8/5/16.
// Program to display a set of values { fij } as a rectangular mesh
//

#include "RectangularMesh.h"

void RectangularMesh::init() {

  // Specify clear values for the color buffers and clear the buffer.
  // Sets the background in simple terms
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // Specify diameter of rasterized points
  glPointSize(5.0);

  // The matrix to be used. Can be GL_MODELVIEW, GL_PROJECTION, and GL_TEXTURE
  glMatrixMode(GL_PROJECTION);

  // Replaces current matrix with identity matrix
  glLoadIdentity();

  // Set the clipping region of the screen/window to be viewed.
  // Our window size is 500 x 500 so this function will view it from left=0,right=500 and bottom=0,top=500
  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void RectangularMesh::display() {

  /*
   * Declare few variables
   * MAX_X and MAX_Y are the max numbers of segments
   * dX and dY are the sizes of each segment
   * x0 and y0 are the origin points
   * i,j,x[],y[] are used to store the various endpoints of the segments
   */

  const GLint MAX_X = 15;
  const GLint MAX_Y = 10;
  const GLint dX = 15;
  const GLint dY = 10;
  const GLfloat x0 = 50, y0 = 50;
  GLint i, j;
  GLfloat x[MAX_X];
  GLfloat y[MAX_Y];

  // Store the various endpoints of the segments
  for (i = 0; i < MAX_X; i++) {
    x[i] = x0 + i * dX;
  }

  for (i = 0; i < MAX_Y; i++) {
    y[i] = y0 + i * dY;
  }

  // Color out segments blue
  glColor3f(0.0, 0.0, 1.0);

  for (i = 0; i < MAX_X - 1; i++) {
    for (j = 0; j < MAX_Y - 1; j++) {

      /*
       * Using GL_LINE_LOOP we specify four points
       * 2  3
       * 1  4
       * to draw a loop
       */
      //Begin
      glBegin(GL_LINE_LOOP);
      glVertex2f(x[i], y[j]);
      glVertex2f(x[i], y[j + 1]);
      glVertex2f(x[i + 1], y[j + 1]);
      glVertex2f(x[i + 1], y[j]);
      // End
      glEnd();
    }
    // Flush the complete mesh to the screen
    glFlush();
  }
}

int RectangularMesh::main(int argc, char *argv[]) {

  // Glut is used for making window.First initGl the window
  glutInit(&argc, argv);

  /* This is not necessary since the default values are GLUT_SINGLE and GLUT_RGB
   *
   * glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   *
   */

  // Specify the window size and position
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);

  // Create the window
  glutCreateWindow("Rectangular mesh");

  // Initialize our window ( Background, buffer, matrix etc)
  init();

  // Specify the callback function that will render our window
  glutDisplayFunc(display);

  // This starts the OpenGL flow using callbacks
  glutMainLoop();

  return 1;
}
