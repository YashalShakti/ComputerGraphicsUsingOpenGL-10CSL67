//
// Created by yashal on 26/5/16.
// Program to create a house like figure and rotate it about a given fixed point using OpenGL functions
//
#include<GL/glut.h>
float vertex[] = {

    0, 0, //left-bottom
    0, 10,//left-top
    10, 10,//right-top

    5, 15, //triangle-top

    0, 10,//left-top
    10, 10,//right-top
    10, 0,//right-bottom

    4, 0, //door-left-bottom
    4, 5, //door-left-top
    6, 5, //door-right-top
    6, 0 //door-right-bottom
};
GLubyte point[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void display() {
  glColor3f(0, 0, 0);
  glDrawElements(GL_LINE_LOOP, 11, GL_UNSIGNED_BYTE, point);
  glRotated(/*angle*/45, 0, 0, 1);
  glDrawElements(GL_LINE_LOOP, 11, GL_UNSIGNED_BYTE, point);
  glFlush();
}

void glInit() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_FLOAT, 0, vertex);
  // View from -20 to 20 since the left bottom is at 0 and after rotating left it will get clipped
  glOrtho(-20, 20, -20, 20, -1, 1);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutCreateWindow("House");
  glInit();
  glutDisplayFunc(display);
  glutMainLoop();
}

