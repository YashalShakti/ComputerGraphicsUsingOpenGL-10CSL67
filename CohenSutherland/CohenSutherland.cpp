//
// Created by yashal on 10/5/16.
//

#include "CohenSutherland.h"
typedef CohenSutherland CSL;

typedef int OutCode;
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

OutCode CSL::ComputeOutCode(double x, double y) {
  OutCode code;

  code = INSIDE;          // initialised as being inside of clip window

  if (x < xMin)           // to the left of clip window
    code |= LEFT;
  else if (x > xMax)      // to the right of clip window
    code |= RIGHT;

  if (y < yMin)           // below the clip window
    code |= BOTTOM;
  else if (y > yMax)      // above the clip window
    code |= TOP;

  return code;
}

void CSL::clipAndDraw() {
  // compute outcodes for P0, P1, and whatever Vertex lies outside the clip rectangle
  OutCode outcode0 = ComputeOutCode(x0, y0);
  OutCode outcode1 = ComputeOutCode(x1, y1);
  bool accept = false;

  while (true) {
    if (!(outcode0 | outcode1)) { // Bitwise OR is 0. Trivially accept and get out of loop
      accept = true;
      break;
    } else if (outcode0 & outcode1) { // Bitwise AND is not 0. Trivially reject and get out of loop
      break;
    } else {

      // failed both tests, so calculate the line segment to clip
      // from an outside Vertex to an intersection with clip edge
      double x, y;

      // At least one endpoint is outside the clip rectangle; pick it.
      OutCode outcodeOut = outcode0 ? outcode0 : outcode1;

      // Now find the intersection Vertex;
      // use formulas y = y0 + slope * (x - x0), x = x0 + (1 / slope) * (y - y0)
      double slope = (y1 - y0) / (x1 - x0);
      if (outcodeOut & TOP) {           // Vertex is above the clip rectangle
        x = x0 + (yMax - y0) / slope;
        y = yMax;
      } else if (outcodeOut & BOTTOM) { // Vertex is below the clip rectangle
        x = x0 + (yMin - y0) / slope;
        y = yMin;
      } else if (outcodeOut & RIGHT) {  // Vertex is to the right of clip rectangle
        y = y0 + (xMax - x0) * slope;
        x = xMax;
      } else if (outcodeOut & LEFT) {   // Vertex is to the left of clip rectangle
        y = y0 + (xMin - x0) * slope;
        x = xMin;
      }

      // Now we move outside Vertex to intersection Vertex to clip
      // and get ready for next pass.
      if (outcodeOut == outcode0) {
        x0 = x;
        y0 = y;
        outcode0 = ComputeOutCode(x0, y0);
      } else {
        x1 = x;
        y1 = y;
        outcode1 = ComputeOutCode(x1, y1);
      }
    }
  }
  if (accept) {
    drawResult();
  }
}

// The following code is same for both clipping algorithms
int CSL::main(int argc, char **argv) {
  getValues();
  glutInit(&argc, argv);
  glutInitWindowSize(720, 720);
  glutCreateWindow("Cohen Sutherland");
  glInit();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void CSL::glInit() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glOrtho(0, 720, 0, 720, 1, -1);
}

void CSL::display() {

  glColor3i(1, 0, 0);
  drawLine(x0, y0, x1, y1);

  glColor3i(0, 0, 1);
  drawSquare(xMin, yMin, xMax, yMax);

  clipAndDraw();
  glFlush();
}

void CSL::drawLine(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1) {
  glBegin(GL_LINE_LOOP);
  {
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
  }
  glEnd();
}

void CSL::drawSquare(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1) {
  glBegin(GL_LINE_LOOP);
  {
    glVertex2f(x0, y0);
    glVertex2f(x1, y0);
    glVertex2f(x1, y1);
    glVertex2f(x0, y1);
  }
  glEnd();
}

void CSL::drawResult() {
  drawSquare(xvMin, yvMin, xvMax, yvMax);
  double sx, sy, vx0, vy0, vx1, vy1;
  sx = (xvMax - xvMin) / (xMax - xMin);
  sy = (yvMax - yvMin) / (yMax - yMin);
  vx0 = xvMin + (x0 - xMin) * sx;
  vy0 = yvMin + (y0 - yMin) * sy;
  vx1 = xvMin + (x1 - xMin) * sx;
  vy1 = yvMin + (y1 - yMin) * sy;
  glColor3f(1.0, 0.0, 0.0);
  drawLine(vx0, vy0, vx1, vy1);
}

