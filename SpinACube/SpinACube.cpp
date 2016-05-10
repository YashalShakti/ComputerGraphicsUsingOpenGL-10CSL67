//
// Created by yashal on 10/5/16.
//

#include "SpinACube.h"
/*static GLfloat vertices[]={-0.5,-0.5,-0.5,    -0.5,0.5,-0.5,    0.5,0.5,-0.5,   0.5,-0.5,-0.5,
                         -0.5,-0.5,0.5,     -0.5,0.5,0.5,     0.5,0.5,0.5,     0.5,-0.5,-0.5};

 static GLint colors[] = {0,0,0,   0,0,1,    0,1,0,    0,1,1,
                          1,0,0,  1,0,1,    1,1,0,     1,1,1};

static GLbyte faces[] = {0,1,2,3,   2,3,7,6,   4,5,6,7,  4,5,1,0,   5,6,2,1,   0,3,7,4};
 */



static GLfloat vertices[] = {-0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f,
                             -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f};

static GLfloat colors[] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1,
                           1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};

static GLbyte faces[] = {0, 1, 2, 3, 2, 3, 7, 6, 4, 5, 6, 7, 4, 5, 1, 0, 5, 6, 2, 1, 0, 3, 7, 4};

int currentAxis[3] = {0, 0, 1};

int SpinACube::main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(700, 700);
  glutCreateWindow("Click to spin the cube");
  glutDisplayFunc(display);
  // Sets global idle for animations etc.
  glutIdleFunc(display);
  // Handles mouse click callback
  glutMouseFunc(mouseClickListener);
  glInit();
  glutMainLoop();
}

void SpinACube::glInit() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // glEnableClientState — enable or disable client-side capability
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  // Sets the pointers. Takes size,type,stride and pointer.
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glColorPointer(3, GL_FLOAT, 0, colors);
  // Enable hidden surface removal.
  glEnable(GL_DEPTH_TEST);
}
void SpinACube::mouseClickListener(int btn, int state, int x, int y) {
  // Bind one axis to one button
  currentAxis[0] = 0;
  currentAxis[1] = 0;
  currentAxis[2] = 0;
  if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    currentAxis[0] = 1;
  }
  if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
    currentAxis[1] = 1;
  }
  if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
    currentAxis[2] = 1;
  }
}

void SpinACube::display() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Rotate the selected axis
  glRotated(0.06, currentAxis[0], currentAxis[1], currentAxis[2]);
  // glDrawElements(mode,count,type,pointer), specifies the indices in vertex and color pointer) 6 faces * 4 vertices total
  glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, faces);
  glFlush();
}