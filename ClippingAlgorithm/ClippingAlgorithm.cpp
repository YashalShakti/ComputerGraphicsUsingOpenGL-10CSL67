//
// Created by yashal on 11/5/16.
//

#include "ClippingAlgorithm.h"
typedef ClippingAlgorithm CA;
void CA::getValues() {
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

GLfloat CA::x0 = 0, CA::y0 = 0, CA::x1 = 120, CA::y1 = 150,
    CA::xMin = 20, CA::yMin = 20, CA::xMax = 100, CA::yMax = 100,
    CA::xvMin = 200, CA::yvMin = 200, CA::xvMax = 680, CA::yvMax = 680;