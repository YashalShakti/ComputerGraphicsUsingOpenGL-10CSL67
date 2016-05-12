//
// Created by yashal on 10/5/16.
//
#include "GL/glut.h"

GLfloat   x0 = 0, y0 = 0, x1 = 120, y1 = 150, // small line
          xMin = 20, yMin = 20, xMax = 100, yMax = 100, // windowport or small square
          xvMin = 200, yvMin = 200, xvMax = 680, yvMax = 680; // viewport or big square

float t0 = 0.0, t1 = 1.0;

// Same for Q2 and Q5
void drawLine(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1) {
  glBegin(GL_LINE_LOOP);
  {
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
  }
  glEnd();
}

// Same for Q2 and Q5
void drawSquare(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1) {
  glBegin(GL_LINE_LOOP);
  {
    glVertex2f(x0, y0);
    glVertex2f(x1, y0);
    glVertex2f(x1, y1);
    glVertex2f(x0, y1);
  }
  glEnd();
}

// Same for Q2 and Q5
void drawResult() {
  drawSquare(xvMin, yvMin, xvMax, yvMax); // draw the viewport

  double sx, sy, vx0, vy0, vx1, vy1;

  sx = (xvMax - xvMin) / (xMax - xMin); // Get ratio of viewport/windowport
  sy = (yvMax - yvMin) / (yMax - yMin);

  vx0 = xvMin + (x0 - xMin) * sx; // Get values of the scaled line
  vy0 = yvMin + (y0 - yMin) * sy; // the line is scaled with reference to xmin and xvmin
  vx1 = xvMin + (x1 - xMin) * sx;
  vy1 = yvMin + (y1 - yMin) * sy;

  glColor3f(1.0, 0.0, 0.0);
  drawLine(vx0, vy0, vx1, vy1); // draw the scaled line of viewport
}

int clipTest(float p, float q) {
  float t = q / p;
  // Aim is to increase t0 value and decrease t1 value to clip the line
  // If p is negative; check for lower/minimum clipping boundary and vice-versa.
  if (p < 0.0) {
    if (t > t0) t0 = t; // If current t is > t0; update t0 value.
    if (t > t1) return (0);
  } else if (p > 0.0) {
    if (t < t1) t1 = t; // If current t is < t1; update t1 value.
    if (t < t0) return 0;
  } else if (t == 0) {
    if (q < 0.0) {
      return 0;
    }
  }
  return 1;
}

void clipAndDraw() {
  float dx = x1 - x0, dy = y1 - y0;

  if (clipTest(-dx, x0 - xMin)
      && clipTest(dx, xMax - x0)
      && clipTest(-dy, y0 - yMin)
      && clipTest(dy, yMax - y0)) {

    // Simultaneously update x1,y1 and x0,y0
    // It is important to update x1,y1 first since otherwise value of x0,y0 will change
    if (t1 < 1.0) {
      x1 = x0 + t1 * dx;
      y1 = y0 + t1 * dy;
    }

    if (t0 > 0.0) {
      x0 = x0 + t0 * dx;
      y0 = y0 + t0 * dy;
    }

    drawResult();
  }
}

// Same for Q2 and Q5
void display() {

  glColor3i(1, 0, 0);
  drawLine(x0, y0, x1, y1);

  glColor3i(0, 0, 1);
  drawSquare(xMin, yMin, xMax, yMax);

  clipAndDraw();
  glFlush();
}

// Same for Q2 and Q5
void glInit() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  /*glMatrixMode(GL_PROJECTION);
  glLoadIdentity();*/

  glOrtho(0, 720, 0, 720, -1, 1);
}

// Same for Q2 and Q5
int main(int argc, char **argv) {
  // Get/store vertices of the original line, windowport and viewport using any method of choice.
  //getValues();  Not really needed unless someone asks
  glutInit(&argc, argv);
  glutInitWindowSize(720, 720);
  glutCreateWindow("Liang Barsky line clipping");
  glInit();
  glutDisplayFunc(display);
  glutMainLoop();
}

/*
 * Not really needed unless someone asks
 *
 * void getValues() {
  using namespace std;
  cout << "Do you want to input values? y/n:";
  char choice;
  cin >> choice;
  if (choice == 'n') {
    cout << "Using default values";
    return;
  }
  cout << "Enter x0,y0 and x1,y1\n";
  cin >> x0;
  cin >> y0;
  cin >> x1;
  cin >> y1;

  cout << "Enter xMin,yMin and xMax,yMax\n";
  cin >> xMin;
  cin >> yMin;
  cin >> xMax;
  cin >> yMax;

  cout << "Enter xvMin,yvMin and xvMax,yvMax\n";
  cin >> xvMin;
  cin >> yvMin;
  cin >> xvMax;
  cin >> yvMax;
}
*/
