// Lab 0c, Console Programming Basics
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::string;
using std::getline;

#include <iomanip>
using std::setprecision;

#include <cstdlib>


int main()
{
  //Sohaib Syed, Console Programming Basics
  cout << "Lab 0c, Console Programming Basics\n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: Code::Blocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //define variables
  int age;
  string fullname;
  double fahrenheitt;
  double celsiust;
  string city;
  string buf;

  //collects user name
  cout << "Please enter your age: \n";
  cin >> buf;
  age = atoi(buf.c_str());
  cin.ignore(1000, 10);

  //collects user age
  cout << "Please enter your full name: \n";
  getline (cin, fullname);

  //fahrenheit
  cout << "Enter the temperature outside right now (in degrees F) \n";
  cin >> buf;
  fahrenheitt = atof(buf.c_str());
  cin.ignore(1000, 10);

  //collects user location
  cout << "What city are you in right now?\n";
  getline (cin, city);

  //resulting output based on user input
  cout << fullname << " is " << age << " years old right now, and will be " <<  age + 1 << " a year from now.\n";

  //resulting output line 2
  cout << "It's " << fahrenheitt << " Degrees F in " << city;

  //conversion from degrees fahrenheit to degrees celsius
  celsiust = (5.0 / 9.0) * (fahrenheitt - 32);
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(1);

  //resulting output line 3
  cout << " -- that's " << celsiust << " degrees C\n";
}
