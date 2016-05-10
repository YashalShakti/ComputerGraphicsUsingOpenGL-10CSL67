//
// Created by yashal on 10/5/16.
//

#ifndef CG2016_SIERPINSKIGASKET_H
#define CG2016_SIERPINSKIGASKET_H

#include "GL/glut.h"
typedef float point[3];

class SierpinskiGasket {
 public:
  int main(int argc,char *argv[]);
 private:
  static void drawTetrahedron(int divisions);
  static void drawTriangle(point a,point b,point c);
  static void display();
  static void initGl();
  static void divideTriangle(point a,point b,point c,int divisions);

};


#endif //CG2016_SIERPINSKIGASKET_H
