//
// Created by yashal on 10/5/16.
//

#ifndef CG2016_SIERPINSKIGASKET_H
#define CG2016_SIERPINSKIGASKET_H
#include "GL/glut.h"

typedef float Vertex[3];

class SierpinskiGasket {
 public:
  int main(int argc,char *argv[]);
 private:
  static void drawTetrahedron(int divisions);
  static void drawTriangle(Vertex a,Vertex b,Vertex c);
  static void display();
  static void initGl();
  static void divideTriangle(Vertex a,Vertex b,Vertex c,int divisions);
};

#endif //CG2016_SIERPINSKIGASKET_H
