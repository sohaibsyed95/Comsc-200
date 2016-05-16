#ifndef GEOMETRYHOMEWORK_H
#define GEOMETRYHOMEWORK_H

#include <iostream>
using std::ostream;

//#include "stdafx.h"
class Shape
{
  protected:
    double const dimension1;
    double const dimension2;
    double const dimension3;
  public:
    Shape(const char* const token[]);
    virtual void output(ostream&) const = 0;
    virtual ~Shape(){};
};


struct Square:public Shape
{
  Square(const char* const token[]);
  void output(ostream&) const;
};

struct Rectangle:public Shape
{
  Rectangle(const char* const token[]);
  void output(ostream&) const;
};

struct Circle:public Shape
{
  Circle(const char* const token[]);
  void output(ostream&) const;
};

struct Cube:public Square
{
  Cube(const char* const token[]);
  void output(ostream&) const;
};

struct Prism:public Rectangle
{
  Prism(const char* const token[]);
  void output(ostream&) const;
};

struct Cylinder:public Circle
{
  Cylinder(const char* const token[]);
  void output(ostream&) const;
};

ostream& reset(ostream&); //reset function
ostream& set(ostream&); //set function
ostream& operator<<(ostream& out, const Shape* s);


#endif // GEOMETRYHOMEWORK_H
