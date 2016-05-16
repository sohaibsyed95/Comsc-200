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

#include "GeometryHomework.h"

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
    //if(token[0])
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
