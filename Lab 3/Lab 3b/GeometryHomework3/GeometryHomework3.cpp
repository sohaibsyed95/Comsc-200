// Lab 3b, GeometryHomework3
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::ios;

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
  private:
    double side;
  public:
    Square(char* token[4]);
    void output() const;
};

//rectangle
class Rectangle
{
  private:
    double length;
    double width;
  public:
    Rectangle(char* token[4]);
    void output() const;
};

//circle
class Circle
{
  private:
    double radius;
  public:
    Circle(char* token[4]);
    void output() const;
};

//cube
class Cube
{
  private:
    double side;
  public:
    Cube(char* token[4]);
    void output() const;
};

//prism
class Prism
{
  private:
    double length;
    double width;
    double height;
  public:
    Prism(char* token[4]);
    void output() const;
};

//cylinder
class Cylinder
{
  private:
    double radius;
    double height;
  public:
    Cylinder(char* token[4]);
    void output() const;
};

//constant variable definitions
const int max_chars_per_line = 512;
const int max_tokens_per_line = 20;
const double pi = 3.14159;
const char* const delimiter = " ";

int main()
{
  cout << "Lab 3b, GeometryHomework3\n";
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

  void* shapes[100];
  int shapeId[100];
  int test = 0;

  //read each line of the txt file
  while(!fin.eof())
  {
    char buf[max_chars_per_line];
    fin.getline(buf, max_chars_per_line);

    int n = 0;
    char* token[max_tokens_per_line] = {};

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
        Square* square = new Square(token);
        shapes[test] = square;
        shapeId[test] = 1;
        break;
      }

      //create rectangle object
      else if(strcmp(token[0], "RECTANGLE") == 0)
      {
        Rectangle* rectangle = new Rectangle(token);
        shapes[test] = rectangle;
        shapeId[test] = 2;
        break;
      }

      //create circle object
      else if(strcmp(token[0], "CIRCLE") == 0)
      {
        Circle* circle = new Circle(token);
        shapes[test] = circle;
        shapeId[test] = 3;
        break;
      }

      //create cube object
      else if(strcmp(token[0], "CUBE") == 0)
      {
        Cube* cube = new Cube(token);
        shapes[test] = cube;
        shapeId[test] = 4;
        break;
      }

      //create prism object
      else if(strcmp(token[0], "PRISM") == 0)
      {
        Prism* prism = new Prism(token);
        shapes[test] = prism;
        shapeId[test] = 5;
        break;
      }

      //create cylinder object
      else if(strcmp(token[0], "CYLINDER") == 0)
      {
        Cylinder* cylinder = new Cylinder(token);
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
      ((Square*)shapes[i])->output();
    else if(shapeId[i] == 2)
      ((Rectangle*)shapes[i])->output();
    else if(shapeId[i] == 3)
      ((Circle*)shapes[i])->output();
    else if(shapeId[i] == 4)
      ((Cube*)shapes[i])->output();
    else if(shapeId[i] == 5)
      ((Prism*)shapes[i])->output();
    else if(shapeId[i] == 6)
      ((Cylinder*)shapes[i])->output();
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
Square::Square(char* token[4])
{
  if(side!=0)
    this->side = atof(token[1]);
  else
    side = 0;
}

Rectangle::Rectangle(char* token[4])
{
  if (length !=0)
    this->length = atof(token[1]);
  else
    length = 0;

  if (width != 0)
    this->width = atof(token[2]);
  else
    width = 0;
}

Circle::Circle(char* token[4])
{
  if (radius != 0)
    this->radius = atof(token[1]);
  else
    radius = 0;
}

Cube::Cube(char* token[4])
{
  if (side != 0)
    this->side = atof(token[1]);
  else
    side = 0;
}

Prism::Prism(char* token[4])
{
  if (length != 0)
    this->length = atof(token[1]);
  else
    length = 0;

  if (width != 0)
    this->width = atof(token[2]);
  else
    width = 0;

  if (height != 0)
    this->height = atof(token[3]);
  else
    height = 0;
}

Cylinder::Cylinder(char* token[4])
{
  if (radius != 0)
    this->radius = atof(token[1]);
  else
    radius = 0;
  if (height != 0)
    this->height = atof(token[2]);
  else
    height = 0;
}

//output square dimensions and calculations
void Square::output() const
{
  double s = side;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "SQUARE side=" << s << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "area=" << s * s << " " << "perimeter=" << s * 4 << endl;
}

//output rectangle dimensions and calculations
void Rectangle::output() const
{
  double area = length * width;
  double perimeter = (2 * length) + (2 * width);
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "RECTANGLE length=" << length << " " << "width=" << width << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "area=" << area << " " << "perimeter=" << perimeter << endl;
}

//output circle dimensions and calculations
void Circle::output() const
{
  double area = pi * pi * radius;
  double circumference = 2 * pi * radius;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "CIRCLE radius=" << radius << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "area=" << area << " " << "circumference=" << circumference << endl;
}

//output cube dimensions and calculations
void Cube::output() const
{
  double surface = 6 * (side + side);
  double volume = side * side * side;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "CUBE side=" << side << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "surface area=" << surface << " " << "volume=" << volume << endl;
}

//output prism dimensions and calculations
void Prism::output() const
{
  double surfaceArea = (2 * length * width) + (2 * width * height) + (2 * length * height);
  double volume = length * width * height;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "PRISM length=" << length << " " << "width=" << width << " " << "height=" << height << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "surface area=" << surfaceArea << " " << "volume=" << volume << endl;
}

//output square cylinder and calculations
void Cylinder::output() const
{
  double surfaceArea = (2 * pi * (radius * radius)) + (2 * pi * radius * height);
  double volume = pi * (radius * radius) * height;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "CYLINDER radius=" << radius << " " << "height=" << height << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "surface area=" << surfaceArea << " " << "volume=" << volume << endl;
}
