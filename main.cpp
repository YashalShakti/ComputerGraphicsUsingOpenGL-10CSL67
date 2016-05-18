#include <iostream>
#include "main.h"
#include "CylinderAndParallelpiped/CylinderAndParallelpiped.h"
int main(int argc, char *argv[]) {
  int choice = 1;
  while (choice) {
    std::cout << "\nEnter the program you want to run:"
        << "\n0: Exit\n"
        << "\n1: Recursively subdivide a tetrahedron to from 3D Sierpinski gasket\n"
        << "\n2: Implement Liang-Barsky line clipping algorithm\n"
        << "\n3: Program to draw a color cube and spin it using OpenGL transformation matrice\n"
        << "\n4: Program to Rotate a house\n"
        << "\n5: Implement the Cohen-Sutherland line-clipping algorithm\n"
        << "\n6: Program to create a cylinder and a parallelepiped by extruding a circle and quadrilateral respectively. Allow the user to specify the circle and the quadrilateral.\n"
        << "\n7: Program, using OpenGL functions, to draw a simple shaded scene consisting of a tea pot on a table. Define suitably the position and properties of the light source along with the properties of the properties of the surfaces of the solid object used in the scene.\n"
        << "\n8: Program to draw a color cube and allow the user to move the camera suitably to experiment with perspective viewing. Use OpenGL functions.\n"
        << "\n9: Program to fill any given polygon using scan-line area filling algorithm. (Use appropriate data structures.)\n"
        << "\n10: Program to display a set of values { fij } as a rectangular mesh\n"
        << ">";
    std::cin >> choice;
    switch (choice) {
      case 1: {
        SierpinskiGasket *sierpinskiGasket = new SierpinskiGasket();
        sierpinskiGasket->main(argc, argv);
        break;
      }
      case 2: {
        LiangBarsky *liangBarsky = new LiangBarsky();
        liangBarsky->main(argc, argv);
        break;
      }
      case 3: {
        SpinACube *spinACube = new SpinACube();
        spinACube->main(argc, argv);
        break;
      }
      case 4: {
        RotatingAHouse *r = new RotatingAHouse();
        r->main(argc, argv);
        break;
      }
      case 5: {
        CohenSutherland *cohenSutherland = new CohenSutherland();
        cohenSutherland->main(argc, argv);
        break;
      }
      case 6: {
        CylinderAndParallelpiped *cylinderAndParallelpiped= new CylinderAndParallelpiped();
        cylinderAndParallelpiped->main(argc, argv);
        break;
      }
      case 7: {
        CohenSutherland *cohenSutherland = new CohenSutherland();
        cohenSutherland->main(argc, argv);
        break;
      }
      case 8: {
        CohenSutherland *cohenSutherland = new CohenSutherland();
        cohenSutherland->main(argc, argv);
        break;
      }
      case 9: {
        CohenSutherland *cohenSutherland = new CohenSutherland();
        cohenSutherland->main(argc, argv);
        break;
      }
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