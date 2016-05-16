// Lab 12, GeometryHomework6
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

#include <fstream>
using std::ifstream;

#include <iomanip>
using std::setprecision;

#include <vector>
using std::vector;

#include <cstring>

#include <cstdlib>

//class definitions for square, rectangle, circle, cube, prism, cylinder

class Shape
{
  protected:
    double const dimension1;
    double const dimension2;
    double const dimension3;
  public:
    Shape(const char* const[]);
    virtual void output(ostream&) const = 0;
    virtual ~Shape(){};
};

Shape::Shape(const char* const token[])
:dimension1(token[1]==0?0:atof(token[1])), dimension2(token[2]==0?0:atof(token[2])), dimension3(token[3]==0?0:atof(token[3])){}

struct Square:public Shape
{
  Square(const char* const token[]): Shape(token){}
  void output(ostream&) const;
};

struct Rectangle:public Shape
{
  Rectangle(const char* const token[]): Shape(token){}
  void output(ostream&) const;
};

struct Circle:public Shape
{
  Circle(const char* const token[]): Shape(token){}
  void output(ostream&) const;
};

struct Cube:public Square
{
  Cube(const char* const token[]): Square(token){}
  void output(ostream&) const;
};

struct Prism:public Rectangle
{
  Prism(const char* const token[]): Rectangle(token){}
  void output(ostream&) const;
};

struct Cylinder:public Circle
{
  Cylinder(const char* const token[]): Circle(token){}
  void output(ostream&) const;
};

ostream& reset(ostream&); //reset function
ostream& set(ostream&); //set function

//constant variable definitions
const int max_chars_per_line = 512;
const int max_tokens_per_line = 20;
const double pi = 3.14159;
const char* const delimiter = " ";

int main()
{
  cout << "Lab 12, GeometryHomework6\n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: Code::Blocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  vector <Shape*> emptyShapes;
  //file input
  ifstream fin;
  fin.open("geo.txt");
  if(!fin)
    return 1;

  //read each line of the txt file
  while(!fin.eof())
  {
    char buf[max_chars_per_line];
    fin.getline(buf, max_chars_per_line);

    int n = 0;
    const char* token[max_tokens_per_line] = {};

    token[0] = strtok(buf, delimiter);
    if(token[0])
    {
      for (n = 1; n < max_tokens_per_line; n++)
      {
        token[n] = strtok(0, delimiter);
        if(!token[n])
          break;
      }
    }

    for (int k = 0; k < n; k++)
    {
      //create square object
      if(strcmp(token[0], "SQUARE") == 0)
      {
        emptyShapes.push_back(new Square(token));
      }

      //create rectangle object
      else if(strcmp(token[0], "RECTANGLE") == 0)
      {
        emptyShapes.push_back(new Rectangle(token));
      }

      //create circle object
      else if(strcmp(token[0], "CIRCLE") == 0)
      {
        emptyShapes.push_back(new Circle(token));
      }

      //create cube object
      else if(strcmp(token[0], "CUBE") == 0)
      {
        emptyShapes.push_back(new Cube(token));
      }

      //create prism object
      else if(strcmp(token[0], "PRISM") == 0)
      {
        emptyShapes.push_back(new Prism(token));
      }

      //create cylinder object
      else if(strcmp(token[0], "CYLINDER") == 0)
      {
        emptyShapes.push_back(new Cylinder(token));
      }

      //output if it is an invalid object
      else
      {
        cout << token[0] << " invalid object " << endl;
        break;
      }
    }
  }

  //close file, no longer needed at this point
  fin.close();

  for(vector <Shape*>::const_iterator m = emptyShapes.begin(); m != emptyShapes.end();m++)
  {
    (*m)->output(cout);
  }

  for(vector <Shape*>::const_iterator n = emptyShapes.begin(); n != emptyShapes.end();n++)
  {
    delete *n;
  }

  cout << "Shapes deleted..." << endl;
}

//constructor functions
//output square dimensions and calculations
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
void Circle::output(ostream& out) const
{
  double area = pi * pi * dimension1;
  double circumference = 2 * pi * dimension1;
  out << reset;
  out << "CIRCLE radius=" << dimension1 << " ";
  cout << set;
  out << "area=" << area << " " << "circumference=" << circumference << endl;
}

//output cube dimensions and calculations
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
