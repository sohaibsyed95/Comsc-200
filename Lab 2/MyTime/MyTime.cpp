// Lab 2a, MyTime
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::setfill;

class Time
{
  public:
    Time(); //constructor
    void setTime(int,int,int);
    void printUniversal();
    void printStandard();
  private:
    int hour;
    int minute;
    int second;
};

Time::Time()
{
  hour = minute = second = 0;
} // end Time constructor

void Time::setTime(int h, int m, int s)
{
  hour = (h >= 0 && h < 24) ? h : 0; //validate hour
  minute = (m >= 0 && m < 60) ? m : 0; //validate minute
  second = (s >= 0 && s < 60) ? s : 0;   //validate second
} //end function setTime

void Time::printUniversal()
{
  cout << setfill('0') << setw(2) << hour << ":"
    << setw(2) << minute <<":" <<setw(2) << second;
} //end function printUniversal

void Time::printStandard()
{
  cout << ( ( hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
    << setfill('0') <<setw(2) << minute << ":" <<setw(2)
    << second << (hour < 12 ? " AM" : " PM");
}

int main()
{
  cout << "Lab 2a, MyTime\n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: Code::Blocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Time t;

  //output Time object t's initial values
  cout<< "The initial universal time is ";
  t.printUniversal(); // 00:00:00
  cout<< "\nThe initial standard time is ";
  t.printStandard(); //12:00:00 AM

  //sets the time
  t.setTime( 13, 27, 6 );

  //output
  cout<<"\n\nUniversal time after setTime is ";
  t.printUniversal();
  cout<<"\nStandard time after setTime is ";
  t.printStandard();

  t.setTime(99,99,99); //attempt invalid time settings

  //prints out the times again
  cout<<"\n\nAfter attempting invalid settings: " << "\nUniversal time: ";
  t.printUniversal();
  cout << "\nStandard Time: ";
  t.printStandard();
  cout<<endl;
}
