//
// Created by yashal on 10/5/16.
//

#ifndef CG2016_COHENSUTHERLAND_H
#define CG2016_COHENSUTHERLAND_H
#include "GL/glut.h"
#include "../ClippingAlgorithm/ClippingAlgorithm.h"
#include <iostream>
typedef int OutCode;
class CohenSutherland: public ClippingAlgorithm {
 public:
  int main(int argc, char *argv[]);
 private:
  static void display();
  static OutCode ComputeOutCode(double x, double y);
  static void glInit();
  static void clipAndDraw();
  static void drawSquare(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1);
  static void drawLine(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1);
  static void drawResult();
};
#endif //CG2016_COHENSUTHERLAND_H
