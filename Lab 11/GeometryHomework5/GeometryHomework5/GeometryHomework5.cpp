// Lab 11, GeometryHomework5
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

#include <cstring>

#include <cstdlib>

//class definitions for square, rectangle, circle, cube, prism, cylinder

//square
class Square
{
  protected:
    const double side;
  public:
    Square(const char* const token[4])
      : side(token[1] == 0?0:atof(token[1]))
    {
    }
    void output(ostream&) const;
};

//rectangle
class Rectangle
{
  protected:
    const double length;
    const double width;
  public:
    Rectangle(const char* const token[4])
      : length(token[1] == 0?0:atof(token[1])),
        width(token[2] == 0?0:atof(token[2]))
        {
        }
    void output(ostream&) const;
};

//circle
class Circle
{
  protected:
    const double radius;
  public:
    Circle(const char* const token[4])
      : radius(token[1] == 0?0:atof(token[1]))
      {
      }
    void output(ostream&) const;
};

//3d cube, with reference to 2d square
class Cube: public Square
{
  public:
    Cube(const char* const token[]):Square(token){}
    void output(ostream&) const;
};

//3d prism, with reference to 2d rectangle
class Prism: public Rectangle
{
    const double height;
  public:
    Prism(const char* const token[])
      : Rectangle(token), height(token[3] == 0?0:atof(token[3])){}
    void output(ostream&) const;
};

//3d cylinder, with reference to 2d circle
class Cylinder: public Circle
{
  const double height;
  public:
    Cylinder(const char* const token[])
      : Circle(token), height(token[2] == 0?0:atof(token[2])){}
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
  cout << "Lab 11, GeometryHomework5\n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: Code::Blocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //file input
  ifstream fin;
  fin.open("geo.txt");
  if(!fin)
    return 1;

  const void* shapes[100];
  int shapeId[100];
  int test = 0;

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
        const Square* const square = new Square(token);
        shapes[test] = square;
        shapeId[test] = 1;
        break;
      }

      //create rectangle object
      else if(strcmp(token[0], "RECTANGLE") == 0)
      {
        const Rectangle* const rectangle = new Rectangle(token);
        shapes[test] = rectangle;
        shapeId[test] = 2;
        break;
      }

      //create circle object
      else if(strcmp(token[0], "CIRCLE") == 0)
      {
        const Circle* const circle = new Circle(token);
        shapes[test] = circle;
        shapeId[test] = 3;
        break;
      }

      //create cube object
      else if(strcmp(token[0], "CUBE") == 0)
      {
        const Cube* const cube = new Cube(token);
        shapes[test] = cube;
        shapeId[test] = 4;
        break;
      }

      //create prism object
      else if(strcmp(token[0], "PRISM") == 0)
      {
        const Prism* const prism = new Prism(token);
        shapes[test] = prism;
        shapeId[test] = 5;
        break;
      }

      //create cylinder object
      else if(strcmp(token[0], "CYLINDER") == 0)
      {
        const Cylinder* const cylinder = new Cylinder(token);
        shapes[test] = cylinder;
        shapeId[test] = 6;
        break;
      }

      //output if it is an invalid object
      else
      {
        cout << token[0] << " invalid object " << endl;
        break;
      }
    }
    test++;
  }
  //close file, no longer needed at this point
  fin.close();

  for(int i = 0; i < test; i++)
  {
    if(shapeId[i] == 1)
      ((Square*)shapes[i])->output(cout);
    else if(shapeId[i] == 2)
      ((Rectangle*)shapes[i])->output(cout);
    else if(shapeId[i] == 3)
      ((Circle*)shapes[i])->output(cout);
    else if(shapeId[i] == 4)
      ((Cube*)shapes[i])->output(cout);
    else if(shapeId[i] == 5)
      ((Prism*)shapes[i])->output(cout);
    else if(shapeId[i] == 6)
      ((Cylinder*)shapes[i])->output(cout);
  }

  for(int m = 0; m < test; m++)
  {
    if(shapeId[m] == 1)
      delete((Square*)shapes[m]);
    else if(shapeId[m] == 2)
      delete((Rectangle*)shapes[m]);
    else if(shapeId[m] == 3)
      delete((Circle*)shapes[m]);
    else if(shapeId[m] == 4)
      delete((Cube*)shapes[m]);
    else if(shapeId[m] == 5)
      delete((Prism*)shapes[m]);
    else if(shapeId[m] == 6)
      delete((Cylinder*)shapes[m]);
  }

  cout << "Shapes deleted..." << endl;
}

//constructor functions
//output square dimensions and calculations
void Square::output(ostream& out) const
{
  double s = side;
  cout << reset;
  out << "SQUARE side=" << s << " ";
  cout << set;
  out << "area=" << s * s << " " << "perimeter=" << s * 4 << endl;
}

//output rectangle dimensions and calculations
void Rectangle::output(ostream& out) const
{
  double area = length * width;
  double perimeter = (2 * length) + (2 * width);
  out << reset;
  out << "RECTANGLE length=" << length << " " << "width=" << width << " ";
  cout << set;
  out << "area=" << area << " " << "perimeter=" << perimeter << endl;
}

//output circle dimensions and calculations
void Circle::output(ostream& out) const
{
  double area = pi * pi * radius;
  double circumference = 2 * pi * radius;
  out << reset;
  out << "CIRCLE radius=" << radius << " ";
  cout << set;
  out << "area=" << area << " " << "circumference=" << circumference << endl;
}

//output cube dimensions and calculations
void Cube::output(ostream& out) const
{
  double surface = 6 * (side + side);
  double volume = side * side * side;
  out << reset;
  out << "CUBE side=" << side << " ";
  cout << set;
  out << "surface area=" << surface << " " << "volume=" << volume << endl;
}

//output prism dimensions and calculations
void Prism::output(ostream& out) const
{
  double surfaceArea = (2 * length * width) + (2 * width * height) + (2 * length * height);
  double volume = length * width * height;
  out << reset;
  out << "PRISM length=" << length << " " << "width=" << width << " " << "height=" << height << " ";
  cout << set;
  out << "surface area=" << surfaceArea << " " << "volume=" << volume << endl;
}

//output square cylinder and calculations
void Cylinder::output(ostream& out) const
{
  double surfaceArea = (2 * pi * (radius * radius)) + (2 * pi * radius * height);
  double volume = pi * (radius * radius) * height;
  out << reset;
  out << "CYLINDER radius=" << radius << " " << "height=" << height << " ";
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
