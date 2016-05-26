#include<GL/glut.h>
const int size = 300;
void display() {
  for (int i = 0; i < size; i = i + 10) {
    glBegin(GL_LINES);
    glVertex2f(i, 0);
    glVertex2f(i, size - 10);
    glVertex2f(0, i);
    glVertex2f(size - 10, i);
    glEnd();
  }
  glFlush();
}
int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Mesh");
  glClear(GL_COLOR_BUFFER_BIT);
  glOrtho(0, 500, 0, 500, -1, 1);
  glColor3f(1, 1, 1);
  glutDisplayFunc(display);
  glutMainLoop();
}