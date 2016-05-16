#include <cstdlib>

#include <iostream>
using std::endl;
using std::ios;
using std::ostream;
using std::cout;

#include <iomanip>
using std::setprecision;
using std::setw;
using std::fixed;

#include "GeometryHomework.h"
//#include "stdafx.h"

const double pi = 3.14159;

Shape::Shape(const char* const token[])
:dimension1(token[1]==0?0:atof(token[1])), dimension2(token[2]==0?0:atof(token[2])), dimension3(token[3]==0?0:atof(token[3])){}

//output square dimensions and calculations
Square::Square(const char* const token[]): Shape(token) {}
void Square::output(ostream& out) const
{
  double area = dimension1 * dimension1;
  double perimeter = dimension1 * 4;
  cout << reset;
  out << "SQUARE side=" << dimension1 << " ";
  cout << set;
  out << "area=" << area << " " << "perimeter=" << perimeter << endl;
}

//output rectangle dimensions and calculations
Rectangle::Rectangle(const char* const token[]): Shape(token) {}
void Rectangle::output(ostream& out) const
{
  double area = dimension1 * dimension2;
  double perimeter = (2 * dimension1) + (2 * dimension2);
  out << reset;
  out << "RECTANGLE length=" << dimension1 << " " << "width=" << dimension2 << " ";
  cout << set;
  out << "area=" << area << " " << "perimeter=" << perimeter << endl;
}

//output circle dimensions and calculations
Circle::Circle(const char* const token[]): Shape(token) {}
void Circle::output(ostream& out) const
{
  double area = pi * dimension1 * dimension1;
  double circumference = 2 * pi * dimension1;
  out << reset;
  out << "CIRCLE radius=" << dimension1 << " ";
  cout << set;
  out << "area=" << area << " " << "circumference=" << circumference << endl;
}

//output cube dimensions and calculations
Cube::Cube(const char* const token[]): Square(token) {}
void Cube::output(ostream& out) const
{
  double surface = 6 * (dimension1 + dimension1);
  double volume = dimension1 * dimension1 * dimension1;
  out << reset;
  out << "CUBE side=" << dimension1 << " ";
  cout << set;
  out << "surface area=" << surface << " " << "volume=" << volume << endl;
}

//output prism dimensions and calculations
Prism::Prism(const char* const token[]): Rectangle(token) {}
void Prism::output(ostream& out) const
{
  double surfaceArea = (2 * dimension1 * dimension2) + (2 * dimension2 * dimension3) + (2 * dimension1 * dimension3);
  double volume = dimension1 * dimension2 * dimension3;
  out << reset;
  out << "PRISM length=" << dimension1 << " " << "width=" << dimension2 << " " << "height=" << dimension3 << " ";
  cout << set;
  out << "surface area=" << surfaceArea << " " << "volume=" << volume << endl;
}

//output square cylinder and calculations
Cylinder::Cylinder(const char* const token[]): Circle(token) {}
void Cylinder::output(ostream& out) const
{
  double surfaceArea = (2 * pi * (dimension1 * dimension1)) + (2 * pi * dimension1 * dimension2);
  double volume = pi * (dimension1 * dimension1) * dimension2;
  out << reset;
  out << "CYLINDER radius=" << dimension1 << " " << "height=" << dimension2 << " ";
  cout << set;
  out << "surface area=" << surfaceArea << " " << "volume=" << volume << endl;
}

ostream& reset(ostream& out)
{
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  return out;
}

ostream& set(ostream& out)
{
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  return out;
}

ostream& operator<<(ostream& out, const Shape* s)
{
  s->output(out);
  return out;
}
