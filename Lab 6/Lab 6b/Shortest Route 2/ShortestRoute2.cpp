// Lab 6b, Using Dynamic Memory Allocation
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

//creates the class
class Route;

class Leg
{
  private:
	const char* const startCity;
	const char* const endCity;
	const double distance;

  public:
	Leg(const char* const startingLocation, const char* const endingLocation, const double miles): startCity(startingLocation), endCity(endingLocation), distance(miles){};
	friend class Route;
    friend void printLeg(ostream&, const Leg&);
	friend void outputRoute(ostream&, const Route&);
};

class Route
{
  private:
	const int num;
	const Leg** leg;
	const double tracker;

  public:
    Route(const Leg& aLeg);
	Route(const Route&, const Leg&);
	Route(const Route&);
	~Route(){delete[] leg;}
	friend void outputRoute(ostream&, const Route&);
};

Route::Route(const Leg& aLeg): num(1), leg(new const Leg*[1]), tracker(aLeg.distance)
{
	leg[0] = &aLeg;
}

Route::Route(const Route& route, const Leg& aLeg): num(route.num+1), leg(new const Leg*[route.num+1]), tracker(route.tracker + aLeg.distance)
{
	for(int i = 0; i< num-1; i++)
    {
      leg[i] = route.leg[i];
    }

	leg[route.num] = &aLeg;
}

Route::Route(const Route& bLeg): num(bLeg.num), leg(new const Leg*[num]), tracker(bLeg.tracker)
{
	for(int i=0; i<= bLeg.num; i++)
    {
      leg[i] = bLeg.leg[i];
    }
}

//function definitions
void printLeg(ostream&, const Leg&);
void outputRoute(ostream&, const Route&);

int main()
{
  cout << "Lab 6b, Using Dynamic Memory Allocation\n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: Code::Blocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Create Legs
  const Leg a("El Cerrito", "Pleasant Hill", 25);
  const Leg b("Pleasant Hill", "San Jose", 52);
  const Leg c("San Jose", "San Francisco", 48);
  const Leg d("San Francisco", "Los Angeles", 381);
  const Leg e("Los Angeles", "Las Vegas", 269);

  //create 5 routes
  const Route ra(a);
  const Route rb(ra, b);
  const Route rc(rb, c);
  const Route rd(rc, d);
  const Route re(rd, e);

  //Print Legs
  printLeg(cout, a);
  printLeg(cout, b);
  printLeg(cout, c);
  printLeg(cout, d);
  printLeg(cout, e);

  cout << endl;
  outputRoute(cout, ra);
  outputRoute(cout, rb);
  outputRoute(cout, rc);
  outputRoute(cout, rd);
  outputRoute(cout, re);
  cout << endl;

  {
    cout << "Testing the route class copy constructor:" << endl;
    Route rCopy = ra;
    outputRoute(cout, rCopy);
    cout << endl;
  }
}

//prints the legs
void printLeg(ostream& output, const Leg& trip)
{
	output << trip.startCity << " to " <<trip.endCity << " is  " << trip.distance << " miles." << endl;
}

//print the full route
void outputRoute(ostream& output, const Route& trip)
{
  output << trip.leg[0]->startCity;

  for(int i = 1; i < trip.num; i++)
  {
    output << " to " << trip.leg[i]->startCity;
  }

  output << " to " << trip.leg[trip.num-1]->endCity;
  output << " is a total of " << trip.tracker << " miles " << endl;
}
