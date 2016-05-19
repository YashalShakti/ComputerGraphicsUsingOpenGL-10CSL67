//
// Created by yashal on 10/5/16.
// Program to draw a color cube and spin it using OpenGL transformation matrices
//

#ifndef CG2016_SPINACUBE_H
#define CG2016_SPINACUBE_H
#include "GL/glut.h"

class SpinACube {
 public:
  int main(int argc, char *argv[]);
 private:
  static void glInit();
  static void mouseClickListener(int btn, int state, int x, int);
  static void display();
  static void reshape(int w, int h);
};

#endif //CG2016_SPINACUBE_H
