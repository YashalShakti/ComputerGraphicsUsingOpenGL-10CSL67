//
// Created by yashal on 10/5/16.
//

#include "RotateACube.h"
static GLfloat vertices[] = {-0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f,
                             -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f};

static GLfloat colors[] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1,
                           1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};

static GLbyte faces[] = {0, 1, 2, 3, 2, 3, 7, 6, 4, 5, 6, 7, 4, 5, 1, 0, 5, 6, 2, 1, 0, 3, 7, 4};

int currentRotateAxis[3] = {0, 0, 1};

int RotateACube::main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(700, 700);
  glutCreateWindow("Click to spin the cube");
  glutDisplayFunc(display);
  glutIdleFunc(display);   // Sets global idle for animations etc.
  glutReshapeFunc(reshape); // Handles resizing of window; Not very necessary
  glutKeyboardFunc(keyboardListener);
  glInit();
  glutMainLoop();
}

void RotateACube::glInit() {
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

void RotateACube::reshape(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(0, 0, w, h); // Resize viewport to show new w and h.
  if (h >= w) //This is needed to main proper aspect ratio; otherwise the image would appear stretched
    glOrtho(-1.0, 1.0, (GLfloat) -h / w, (GLfloat) h / w, -1.0, 1.0); //width is smaller than height
  else
    glOrtho((GLfloat) -w / h, (GLfloat) w / h, -1.0, 1.0, -1.0, 1.0); //height is smaller
}

void RotateACube::keyboardListener(unsigned char key, int x, int y) {
  int sign = 1;
  switch (key) {
    case 'x':
      store(1, 0, 0);
      sign = 1;
      break;
    case 'X':
      store(1, 0, 0);
      sign = -1;
      break;
    case 'y':
      store(0, 1, 0);
      sign = 1;
      break;
    case 'Y':
      store(0, 1, 0);
      sign = -1;
      break;
    case 'z':
      store(0, 0, 1);
      sign = 1;
      break;
    case 'Z':
      store(0, 0, 1);
      sign = -1;
      break;
  }
  glRotated(sign*0.6, currentRotateAxis[0], currentRotateAxis[1], currentRotateAxis[2]);   // Rotate the selected axis
  glutPostRedisplay();
}

void RotateACube::store(int x, int y, int z) {
  currentRotateAxis[0] = x;
  currentRotateAxis[1] = y;
  currentRotateAxis[2] = z;
}

void RotateACube::display() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // glDrawElements(mode,count,type,pointer), specifies the indices in vertex and color pointer) 6 faces * 4 vertices total
  glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, faces);
  glFlush();
}