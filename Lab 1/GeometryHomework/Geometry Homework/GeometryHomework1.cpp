// Lab 1b, GeometryHomework1
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <fstream>
using std::ifstream;

#include <iomanip>
using std::setprecision;

#include <cstring>

#include <cstdlib>

const int max_chars_per_line = 512;
const int max_tokens_per_line = 20;
const char* const delimiter = " ";

int main()
{
  cout << "Lab 1b, GeometryHomework1\n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: Code::Blocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  double pi = 3.14159;
  ifstream fin;
  fin.open("geo.txt");
  if(!fin)
    return 1;

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

    if(strcmp(token[0], "SQUARE") == 0)
    {
      double sideo = convertDub[0];
      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6) << "SQUARE side=" << sideo << " ";
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2) << "area=" << sideo * sideo << " " << "perimeter=" << sideo * 4 << endl;
    }

    else if(strcmp(token[0], "RECTANGLE") == 0)
    {
      double length = convertDub[0];
      double width = convertDub[1];
      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6) << "RECTANGLE length=" << length << " " << "width=" << width << " ";
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2) << "area=" << length * width << " " << "perimeter=" << (2 * length) + (2 * width) << endl;
    }

    else if(strcmp(token[0], "CIRCLE") == 0)
    {
      double radius = convertDub[0];
      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6) << "CIRCLE radius=" << radius << " ";
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2) << "area=" << pi * radius * radius << " " << "circumference=" << 2 * pi * radius << endl;
    }

    else if(strcmp(token[0], "CUBE") == 0)
    {
      double sidet = convertDub[0];
      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6) << "CUBE side=" << sidet << " ";
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2) << "surface area=" << 6 * (sidet * sidet) << " " << "volume=" << sidet * sidet * sidet << endl;
    }

    else if(strcmp(token[0], "PRISM") == 0)
    {
      double length = convertDub[0];
      double width = convertDub[1];
      double height = convertDub[2];
      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6) << "PRISM length=" << length << " " << "width=" << width << " " << "height=" << height << " ";
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2) << "surface area=" << (2 * length * width) + (2 * width * height) + (2 * length * height) << " " << "volume=" << length * width * height << endl;
    }

    else if(strcmp(token[0], "CYLINDER") == 0)
    {
      double radius = convertDub[0];
      double height = convertDub[1];
      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6) << "CYLINDER radius=" << radius << " " << "height=" << height << " ";
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2) << "surface area=" << (2 * pi * (radius * radius)) + (2 * pi * radius * height) << " " << "volume=" << pi * (radius * radius) * height << endl;
    }

    else
      cout << token[0] << " invalid object " << endl;
  }
}
