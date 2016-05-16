// Lab 16, ElevatorSimulation6, ElevatorSimulation6.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>
#include <ctime>
#include <cmath>

#include "Building.h"

int getArrivalsForThisSecond(double);

int main()
{
  // execute this ONCE in your program -- as the first statements in main
  srand(time(0)); rand(); // requires cstdlib and ctime
  Building bldg;

  for (int i = 0;; i++)
  {
	  cout << bldg.step(getArrivalsForThisSecond(0.3)) << endl;

	  if (!(i % 10)) 
	  {
		  cout << "Press ENTER to continue, X-ENTER to quit...\n";
		  if (cin.get() > 31) break;
	  }
  }
  cout << "DONE: All riders should be gone, and all elevators idle\n";
}

int getArrivalsForThisSecond(double averageRiderArrivalRate)
{
	int arrivals = 0;
	double probOfnArrivals = exp(-averageRiderArrivalRate); // for n=0 -- requires cmath
	for (double randomValue = (rand() % 1000) / 1000.0; // requires cstdlib AND srand in main
		(randomValue -= probOfnArrivals) > 0.0;
		probOfnArrivals *= averageRiderArrivalRate / ++arrivals);
	return arrivals;
}