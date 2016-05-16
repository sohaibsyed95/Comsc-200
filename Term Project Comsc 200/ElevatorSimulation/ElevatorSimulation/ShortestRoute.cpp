// Term project, ShortestRoute.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Visual Studios
// Compiler(s) used: Visual Studios

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include <set>
using std::set;

class Leg;
class Route;
class ShortestRoute;

class Leg
{
  private:
	const string startCity;
	const string endCity;
	const double distance;

  public:
	Leg(const string startingLocation, const string endingLocation, const double miles) : startCity(startingLocation), endCity(endingLocation), distance(miles){};
	friend class Route;
	friend class ShortestRoute;
	void operator=(const Leg&);
	friend ostream& operator<<(ostream&, const Leg&);
	friend ostream& operator<<(ostream&, const Route&);
};

class Route
{
  private:
	const int num;
	const Leg** const leg;
	const double tracker;

  public:
	Route(const Leg&);
	Route(const Route&, const Leg&);
	Route(const Route&);
	~Route(){ delete[] leg; }
	bool isGreaterThan(const Route&) const;
	bool operator<(const Route&) const;
	friend class ShortestRoute;
	void operator=(const Route&);
	friend ostream& operator<<(ostream& out, const Route& r);
};

Route::Route(const Leg& aLeg) : num(1), leg(new const Leg*[1]), tracker(aLeg.distance)
{
  leg[0] = &aLeg;
}

Route::Route(const Route& route, const Leg& bLeg) : num(route.num + 1), leg(new const Leg*[route.num + 1]), tracker(route.tracker + bLeg.distance)
{
  if (route.leg[num - 2]->endCity != bLeg.startCity)
  {
  	delete[] leg;
	throw "End route city and start leg city don't match";
  }

  for (int i = 0; i< num - 1; i++)
  {
	leg[i] = route.leg[i];
  }

  leg[route.num] = &bLeg;
}

Route::Route(const Route& cLeg) : num(cLeg.num), leg(new const Leg*[num]), tracker(cLeg.tracker)
{
  for (int i = 0; i<cLeg.num + 1; i++)
  {
	leg[i] = cLeg.leg[i];
  }
}

class ShortestRoute
{
  private:
	static const Leg legs[];
	static const int det;

  public:
	static const Route getAnyRoute(const string, const string);
	static const Route getShortestRoute(const string, const string);
};


const Route ShortestRoute::getAnyRoute(const string from, const string to)
{
  for (int i = 0; i < det; i++)
  {
 	if (legs[i].endCity.compare(to) == 0)
	{
		if (legs[i].startCity.compare(from) == 0)
		{
		  return Route(legs[i]);
		}
		else
		{
		  return Route(getAnyRoute(from, legs[i].startCity), legs[i]);
		}
		}
  }
  throw "No route possible from given legs";
}

Route const ShortestRoute::getShortestRoute(const string from, const string to)
{
  set<Route> routes;
 
  for (int i = 0; i < det; i++)
  {
	if (legs[i].endCity.compare(to) == 0)
	{
		if (legs[i].startCity.compare(from) == 0)
		{
		  routes.insert(Route(legs[i]));
		}
		else
		{
		  routes.insert(Route(getShortestRoute(from, legs[i].startCity), legs[i]));
		}
    }
  }

  set<Route>::iterator it = routes.begin();
  return *it;
}

const int ShortestRoute::det = 44;

const Leg ShortestRoute::legs[] =  //database
{
	Leg("San Francisco", "Milpitas", 46.2),
	Leg("Milpitas", "Dublin", 23.9),
	Leg("Milpitas", "Stockton", 70.7),
	Leg("Dublin", "Stockton", 49.9),
	Leg("Dublin", "Manteca", 42.8),
	Leg("Stockton", "Elko", 468),
	Leg("Stockton", "Reno", 179),
	Leg("Manteca", "Elko", 477),
	Leg("Manteca", "Reno", 189),
	Leg("Elko", "Salt Lake City", 230),
	Leg("Elko", "Logan", 264),
	Leg("Reno", "Logan", 553),
	Leg("Reno", "Salt Lake City", 518),
	Leg("Logan", "Casper", 403),
	Leg("Logan", "Cheyyene", 433),
	Leg("Salt Lake City", "Logan", 82.3),
	Leg("Salt Lake City", "Casper", 410),
	Leg("Salt Lake City", "Cheyyene", 440),
	Leg("Casper", "Lexington", 462),
	Leg("Casper", "Rochester", 824),
	Leg("Cheyyene", "Lexington", 282),
	Leg("Cheyyene", "Rochester", 838),
	Leg("Lexington", "Davenport", 520),
	Leg("Lexington", "Indianapolis", 802),
	Leg("Rochester", "Davenport", 251),
	Leg("Rochester", "Indianapolis", 531),
	Leg("Indianapolis", "Akron", 299),
	Leg("Indianapolis", "Richmond", 213),
	Leg("Davenport", "Akron", 521),
	Leg("Davenport", "Richmond", 523),
	Leg("Akron", "Pittsburgh", 111),
	Leg("Akron", "Indiana", 155),
	Leg("Richmond", "Pittsburgh", 394),
	Leg("Richmond", "Indiana", 430),
	Leg("Pittsburgh", "Lancaster", 238),
	Leg("Pittsburgh", "New York City", 371),
	Leg("Indiana", "Lancaster", 210),
	Leg("Indiana", "Buffalo", 237),
	Leg("Lancaster", "Buffalo", 320),
	Leg("Buffalo", "New York City", 373),
	Leg("San Francisco", "New York City", 21000),
};

int main()
{
  cout << "Term Project, ShortestRoute.cpp\n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Visual Studios\n";
  cout << "Compiler(s) used: Visual Studios\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
  try
  {
	cout << "Any route from SF->NYC (Besides just taking a simple 6 hour non-stop flight) : " << endl;
	cout << ShortestRoute::getAnyRoute("San Francisco", "New York City") << endl;
	cout << "The Shortest Route from SF->NYC: " << endl;
  	cout << ShortestRoute::getShortestRoute("San Francisco", "New York City");
  }
  catch (const char* a)
  {
	cout << "Error: " << a << endl;
  }
  cout << endl;
  cin.get();
}

bool Route::operator<(const Route& r) const
{
  if (this->isGreaterThan(r))
	return false;
  else
	return true;
}

ostream& operator<<(ostream& out, const Leg& l)
{
  out << l.startCity << " to " << l.endCity << " is " << l.distance << "miles" << endl;
  return out;
}

ostream& operator<<(ostream& out, const Route &r)
{
  out << r.leg[0]->startCity;
  for (int i = 1; i < r.num; i++)	
  {
    out << " to " << r.leg[i]->startCity;
  }
  out << " to " << r.leg[r.num - 1]->endCity << " is " << r.tracker << " miles. " << endl;
  return out;
}

bool Route::isGreaterThan(const Route& r) const
{
  if (this->tracker >= r.tracker)
  {
	return true;
  }
  else
  {
	return false;
  }
}
