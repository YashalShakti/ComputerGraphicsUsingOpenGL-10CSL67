//
// Created by yashal on 10/5/16.
// Program to draw a color cube and spin it using OpenGL transformation matrices
//

#ifndef CG2016_ROTATEACUBE_H
#define CG2016_ROTATEACUBE_H
#include "GL/glut.h"

class RotateACube {
 public:
  int main(int argc, char *argv[]);
 private:
  static void glInit();
  static void display();
  static void store(int x, int y, int z);
  static void reshape(int w, int h);
  static void keyboardListener(unsigned char key, int x, int y);
};

#endif //CG2016_ROTATEACUBE_H
