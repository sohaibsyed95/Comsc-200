// Lab 5b, Writing Friend Functions
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

//class definition
class Leg
{
  //private data members
  private:
    const char* const startCity;
    const char* const endCity;
    const double distance;

  //public date members
  public:
    Leg(const char* const startingLocation, const char* const endLocation, const double miles)
      : startCity(startingLocation),
        endCity(endLocation),
        distance(miles){};
	friend void printLeg(ostream&, const Leg&);
};

void printLeg(ostream&, const Leg&);

int main()
{
  cout << "Lab 5b, Writing Friend Functions\n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: Code::Blocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Create Legs
  Leg a("El Cerrito", "Pleasant Hill", 24.7);
  Leg b("Pleasant Hill", "San Jose", 52.2);
  Leg c("San Jose", "San Francisco", 48.4);
  Leg d("San Francisco", "Los Angeles", 381);
  Leg e("Los Angeles", "Las Vegas", 269);

  //Print Legs
  printLeg(cout, a);
  printLeg(cout, b);
  printLeg(cout, c);
  printLeg(cout, d);
  printLeg(cout, e);
}

void printLeg(ostream& out, const Leg& tripTotal)
{
	out << tripTotal.startCity << " to " << tripTotal.endCity << " is " << tripTotal.distance << " miles." <<endl;
}
