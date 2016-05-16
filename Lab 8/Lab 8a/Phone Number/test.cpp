#include "PhoneNumber.h"

#include <iostream>
using std::cout;
using std::endl;

#include <sstream>
using std::istringstream;

int main()
{
  istringstream sin;

  sin.str ("510");

  int val;
  sin >> val;
  cout << val << endl;

  cout << "Sin printed out and its: ";
  cout << sin.str() << '\n';
  cout << endl;
}
