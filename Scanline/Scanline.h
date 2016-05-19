//
// Created by yashal on 19/5/16.
//

#ifndef CG2016_SCANLINE_H
#define CG2016_SCANLINE_H


class Scanline {
 public:
  int main(int argc, char *argv[]);
 private:
  static void initGl();
  static void edgeDetect(float x1, float y1, float x2, float y2);
  static void scanFill();
  static void display();
  static void drawPixel(int x, int y);
};


#endif //CG2016_SCANLINE_H
