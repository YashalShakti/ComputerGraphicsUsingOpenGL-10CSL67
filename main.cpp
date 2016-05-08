#include <iostream>
#include "main.h"
int main(int argc, char *argv[]) {
  int choice = 1;
  while (choice) {
    std::cout << "\nEnter the program you want to run:"
        << "\n0: Exit\n"
        << "\n10: Program to display a set of values { fij } as a rectangular mesh\n"
        << ">";
    std::cin >> choice;
    switch (choice) {
      case 10: {
        RectangularMesh *r = new RectangularMesh();
        r->main(argc, argv);
        break;
      }
      case 0:
        // Exit
        return 1;
      default:
        std::cout << "Wrong choice";
        break;
    }
  }
  return 0;

}