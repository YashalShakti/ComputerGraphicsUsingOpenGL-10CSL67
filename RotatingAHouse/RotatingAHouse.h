//
// Created by yashal on NUM_VERTICES/5/16.
//

#ifndef CG2016_ROTATINGAHOUSE_H
#define CG2016_ROTATINGAHOUSE_H

#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include <iostream>
const int NUM_VERTICES = 12;

class RotatingAHouse {
 public:
  int main(int argc, char *argv[]);
 private:
  static void initGl(int w, int h);
  static void display();
  static void rotate(GLfloat theta, GLfloat result[3][NUM_VERTICES]);
  static void multiply(GLfloat a[3][3], GLfloat b[3][NUM_VERTICES], GLfloat result[3][NUM_VERTICES]);
  static void drawHouse(GLfloat house[3][NUM_VERTICES]);
  static void reshape(int w,int h);
};


#endif //CG2016_ROTATINGAHOUSE_H
