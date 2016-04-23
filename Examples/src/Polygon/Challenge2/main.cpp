#include "Polygon.hpp"
#include "Grid.hpp"
//! Main program
int main()
{
  std::ifstream file("mesh.dat");
  Grid P(file);
  P.getArea();
}
  

