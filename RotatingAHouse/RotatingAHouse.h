//
// Created by yashal on 9/5/16.
//

#ifndef CG2016_ROTATINGAHOUSE_H
#define CG2016_ROTATINGAHOUSE_H

#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include <iostream>

class RotatingAHouse {
 public:
  int main(int argc, char *argv[]);
 private:
  void initGl();
  static void display();
  static void rotate(GLfloat theta, GLfloat result[3][9]);
  static void multiply(GLfloat a[3][3], GLfloat b[3][9], GLfloat result[3][9]);
  static void drawHouse(GLfloat house[3][9]);
};


#endif //CG2016_ROTATINGAHOUSE_H
