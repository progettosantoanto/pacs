#ifndef HH_GRID_HH
#define HH_GRID_HH
#include <iostream>
#include <utility>
#include <memory>
#include <fstream>
#include <sstream>
#include "Polygon.hpp"

using namespace Geometry;
using namespace std;

class Grid
  {
  public:
    //! Default constructor
    Grid(ifstream & file);
    //! Default Copy constructor
    Grid(const Grid&) = default;
    //! Default assignment operator
    Grid & operator = (Grid &) = default;
    //! Print
    void getArea();

  private:
    Vertices Vect;
    vector <shared_ptr <AbstractPolygon>> AbstractPol;
  };
  #endif