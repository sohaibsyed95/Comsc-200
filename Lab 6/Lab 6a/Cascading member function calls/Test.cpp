#include "Time.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
  Time cascade;
  cout << "Time object set to 12, 17, 19 without cascading"<<endl;
  cascade.setTime(12, 17, 19);
  cascade.printStandard();
  cout<<endl;
  cascade.printUniversal();

  //copy of the original object
  cout<<"\nTime object set to 8, 54, 17 with cascading"<<endl;
  cascade.setHour(8).setMinute(54).setSecond(17);

  cout <<"Hour is: " <<cascade.getHour()<<endl;
  cout<<"Min is: " <<cascade.getMinute()<<endl;
  cout<<"Seconds is: "<<cascade.getSecond()<<endl;

  cout<<"Print the copy of the function on before"<<endl;
  const Time copy = cascade;
  copy.printStandard();
  cout << endl;
  copy.printUniversal();

  cout<<"\nPrint copy after declaration"<<endl;
  Time copyCopy;
  copyCopy = cascade;
  copyCopy.printStandard();
  cout<<endl;
  copyCopy.printUniversal();

  cout<<endl;
}
