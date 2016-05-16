#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"

int main()
{
    Date t(8, 13, 15);
	cout << "We have created the object Date 2, It should print out 8/13/15\n";
	cout << "The date is " << t << endl;

	//increment date by 10
	cout << "We are going to add 15 days to the date\n";
	t+=15;

	cout << "The date is now " << t << endl;
	//pre and post increment
	cout << "We will now test with pre and post increment\n";
	cout << "The date hows now changed to " << ++t << "Using pre increment. \n";
	cout << "The date should print 24 but it will print " << t++ << " because we are using post increment.";

}
