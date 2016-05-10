//
// Created by yashal on 11/5/16.
//

#ifndef CG2016_CLIPPINGALGORITHM_H
#define CG2016_CLIPPINGALGORITHM_H
#include <GL/gl.h>
#include "iostream"
class ClippingAlgorithm {
 protected:
  static void getValues();
  static GLfloat x0, y0, x1, y1;
  static GLfloat xMin, yMin, xMax, yMax;
  static GLfloat xvMin, yvMin, xvMax, yvMax;
};


#endif //CG2016_CLIPPINGALGORITHM_H
