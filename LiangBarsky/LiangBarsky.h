//
// Created by yashal on 10/5/16.
//

#ifndef CG2016_LIANGBARSKY_H
#define CG2016_LIANGBARSKY_H
#include <iostream>
#include "GL/glut.h"
#include "../ClippingAlgorithm/ClippingAlgorithm.h"

class LiangBarsky: public ClippingAlgorithm {
 public:
  int main(int argc, char *argv[]);
 private:
  static void display();
  static void initGl();
  static void clipAndDraw();
  static int clipTest(float p, float q, float *t0, float *t1);
  static void drawSquare(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1);
  static void drawLine(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1);
  static void drawResult();
};

#endif //CG2016_LIANGBARSKY_H
