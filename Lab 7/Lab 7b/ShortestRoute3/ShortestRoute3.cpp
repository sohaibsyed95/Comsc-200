// Lab 7b, Using the const Keyword and strings
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

//crates the class
class Route;

class Leg
{
  private:
	const string startCity;
	const string endCity;
	const double distance;

  public:
	Leg(const string startingLocation, const string endingLocation, const double miles): startCity(startingLocation), endCity(endingLocation), distance(miles){};
	friend class Route;
	void friend printLeg(ostream&, const Leg&);
	void friend outputRoute(ostream&, const Route&);
};

class Route
{
  private:
    const Leg** const leg;
    const int num;
	const double tracker;

  public:
    Route(const Leg&);
    Route(const Route&, const Leg&);
	Route(const Route&);
	~Route(){delete[] leg;}
	void friend outputRoute(ostream&, const Route&);
	bool isGreaterThan(const Route&) const;
};

Route::Route(const Leg& aLeg):  leg(new const Leg*[1]), num(1), tracker(aLeg.distance)
{
	leg[0] = &aLeg;
}

Route::Route(const Route& route, const Leg& bLeg): leg(new const Leg*[route.num+1]), num(route.num+1),  tracker(route.tracker+bLeg.distance)
{
    if(route.leg[num-2]->endCity != bLeg.startCity)
    {
      delete[] leg;
      throw "End route city and start leg city don't match";
    }

    for(int i = 0; i< num-1; i++)
    {
      leg[i] = route.leg[i];
    }

    leg[route.num] = &bLeg;
}

Route::Route(const Route& cLeg): leg(new const Leg*[num]), num(cLeg.num), tracker(cLeg.tracker)
{
  for(int i=0; i<cLeg.num+1; i++)
  {
    leg[i] = cLeg.leg[i];
  }
}

//function definitions
void printLeg(ostream&, const Leg&);
void outputRoute(ostream&, const Route&);

int main()
{
  cout << "Lab 7b, Using the const Keyword and strings\n";
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

  //creats 5 routes
  const Route ra(a);
  const Route rb(ra, b);
  const Route rc(rb, c);
  const Route rd(rc, d);
  const Route re(rd, e);

  try
  {
    Route(Route(Leg("a", "b", 0)), Leg("c", "d", 0));
  }
  catch (const char* ex)
  {
    cout << "ERROR DETECTED: " << ex << endl;
  }

  //Print Legs
  printLeg(cout, a);
  printLeg(cout, b);
  printLeg(cout, c);
  printLeg(cout, d);
  printLeg(cout, e);

  cout << endl;
  outputRoute(cout, re);
  cout << endl;

 //ra and rb comparison
  if(rb.isGreaterThan(ra))
  {
    cout << "Route rb is greater than ra." << endl;
  }
  else
  {
    cout << "Route ra is greater than rb." << endl;
  }

 //rb and rc comparison
  if(rb.isGreaterThan(rc))
  {
    cout << "Route rb is greater than rc" << endl;
  }
  else
  {
    cout << "Route rc is greater than rb" << endl;
  }

 //rb and rd comparison
  if(rb.isGreaterThan(rd))
  {
    cout << "Route rb is greater than rd" << endl;
  }
  else
  {
    cout << "Route rd is greater than rb" << endl;
  }

  cout << endl;

  //Testing routE class copy constructor
  {
    cout << "Testing the route class copy constructor:" <<endl;
    Route rCopy = ra;
    outputRoute(cout, rCopy);
    cout << endl;
  }

  cout <<"Test what was originally copied" << endl;
  outputRoute(cout, ra);
  cout << endl;
}

//prints the legs
void printLeg(ostream& output, const Leg& trip)
{
  output << trip.startCity << " to " <<trip.endCity << " is  " << trip.distance << " miles." << endl;
}

//print the full route
void outputRoute(ostream& output, const Route& trip)
{
  output<< trip.leg[0]->startCity;

  for(int i = 1; i<trip.num; i++)
  {
    output << " to " << trip.leg[i]->startCity;
  }

  output << " to " << trip.leg[trip.num-1]->endCity;

  output << " is a total of " << trip.tracker << " miles " << endl;
}

bool Route::isGreaterThan(const Route& cmp) const
{
  if(this->tracker > cmp.tracker)
    return true;
  else
    return false;
}
