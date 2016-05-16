// Lab 2b, GeometryHomework2
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

//structure definitions for square, rectangle, circle, cube, prism, cylinder
//square
struct Square
{
  double side;
};

//rectangle
struct Rectangle
{
  double length;
  double width;
};

//circle
struct Circle
{
  double radius;
};

//cube
struct Cube
{
  double side;
};

//prism
struct Prism
{
  double length;
  double width;
  double height;
};

//cylinder
struct Cylinder
{
  double radius;
  double height;
};

//function definitions
void outputSquare(Square* square);
void outputRectangle(Rectangle* rectangle);
void outputCircle(Circle* circle);
void outputCube(Cube* cube);
void outputPrism(Prism* prism);
void outputCylinder(Cylinder* cylinder);

//constant variable definitions
const int max_chars_per_line = 512;
const int max_tokens_per_line = 20;
const double pi = 3.14159;
const char* const delimiter = " ";

int main()
{
  cout << "Lab 2b, GeometryHomework2\n";
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

    double convertDub[max_tokens_per_line - 1];
    for(int j = 1; j < max_tokens_per_line; j++)
    {
      if(token[j] != 0)
        convertDub[j - 1] = atof(token[j]);
      else
        convertDub[j - 1] = 0;
    }

    for (int k = 0; k < n; k++)
    {
      //create square object
      if(strcmp(token[0], "SQUARE") == 0)
      {
        Square* square = new Square;
        square->side = convertDub[0];
        shapes[test] = square;
        shapeId[test] = 1;
        break;
      }
      //create rectangle object
      else if(strcmp(token[0], "RECTANGLE") == 0)
      {
        Rectangle* rectangle = new Rectangle;
        rectangle->length = convertDub[0];
        rectangle->width = convertDub[0];
        shapes[test] = rectangle;
        shapeId[test] = 2;
        break;
      }

      //create circle object
      else if(strcmp(token[0], "CIRCLE") == 0)
      {
        Circle* circle = new Circle;
        circle->radius = convertDub[0];
        shapes[test] = circle;
        shapeId[test] = 3;
        break;
      }

      //create cube object
      else if(strcmp(token[0], "CUBE") == 0)
      {
        Cube* cube = new Cube;
        cube->side = convertDub[0];
        shapes[test] = cube;
        shapeId[test] = 4;
        break;
      }

      //create prism object
      else if(strcmp(token[0], "PRISM") == 0)
      {
        Prism* prism = new Prism;
        prism->height = convertDub[0];
        prism->length = convertDub[1];
        prism->width = convertDub[2];
        shapes[test] = prism;
        shapeId[test] = 5;
        break;
      }

      //create cylinder object
      else if(strcmp(token[0], "CYLINDER") == 0)
      {
        Cylinder* cylinder = new Cylinder;
        cylinder->height = convertDub[0];
        cylinder->radius = convertDub[1];
        shapes[test] = cylinder;
        shapeId[test] = 6;
        break;
      }

      //output if it is an invalid object
      else
      {
        cout << token[0] << " invalid object " << endl;
        test--;
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
      outputSquare((Square*)shapes[i]);
    else if(shapeId[i] == 2)
      outputRectangle((Rectangle*)shapes[i]);
    else if(shapeId[i] == 3)
      outputCircle((Circle*)shapes[i]);
    else if(shapeId[i] == 4)
      outputCube((Cube*)shapes[i]);
    else if(shapeId[i] == 5)
      outputPrism((Prism*)shapes[i]);
    else if(shapeId[i] == 6)
      outputCylinder((Cylinder*)shapes[i]);
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

//output square dimensions and calculations
void outputSquare(Square* square)
{
  double side = square->side;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "SQUARE side=" << side << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "area=" << side * side << " " << "perimeter=" << side * 4 << endl;
}

//output rectangle dimensions and calculations
void outputRectangle(Rectangle* rectangle)
{
  double length = rectangle->length;
  double width = rectangle->width;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "RECTANGLE length=" << length << " " << "width=" << width << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "area=" << length * width << " " << "perimeter=" << (2 * length) + (2 * width) << endl;
}

//output circle dimensions and calculations
void outputCircle(Circle* circle)
{
  double radius = circle->radius;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "CIRCLE radius=" << radius << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "area=" << pi * radius * radius << " " << "circumference=" << 2 * pi * radius << endl;
}

//output cube dimensions and calculations
void outputCube(Cube* cube)
{
  double side = cube->side;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "CUBE side=" << side << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "surface area=" << 6 * (side * side) << " " << "volume=" << side * side * side << endl;
}

//output prism dimensions and calculations
void outputPrism(Prism* prism)
{
  double length = prism->length;
  double width = prism->width;
  double height = prism->height;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "PRISM length=" << length << " " << "width=" << width << " " << "height=" << height << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "surface area=" << (2 * length * width) + (2 * width * height) + (2 * length * height) << " " << "volume=" << length * width * height << endl;
}

//output square cylinder and calculations
void outputCylinder(Cylinder* cylinder)
{
  double radius = cylinder->radius;
  double height = cylinder->height;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6) << "CYLINDER radius=" << radius << " " << "height=" << height << " ";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << "surface area=" << (2 * pi * (radius * radius)) + (2 * pi * radius * height) << " " << "volume=" << pi * (radius * radius) * height << endl;
}
