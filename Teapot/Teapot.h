//
// Created by yashal on 18/5/16.
//

#ifndef CG2016_TEAPOT_H
#define CG2016_TEAPOT_H


class Teapot {
 public:
  int main(int argc, char *argv[]);
 private:
  static void display();
  static void drawObject(double tx, double ty, double tz, double sx, double sy, double sz);
  static void glInit();
};


#endif //CG2016_TEAPOT_H
