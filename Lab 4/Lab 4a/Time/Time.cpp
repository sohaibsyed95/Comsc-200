// Lab 4a, Applying Const, Time.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "Time.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ios;

#include <iomanip>
using std::setprecision;

Time::Time(int hour, int minute, int second)
{
  setTime(hour, minute, second);
}

void Time::setTime(int hour, int minute, int second)
{
  setHour(hour);
  setMinute(minute);
  setSecond(second);
}

void Time::setHour(int h)
{
  hour = (h >= 0 && h < 24) ? h:0;
}

void Time::setMinute(int m)
{
  minute = (m >= 0 && m < 60) ? m:0;
}

void Time::setSecond(int s)
{
  second = (s >= 0 && s < 60) ? s:0;
}

int Time::getHour() const
{
  return hour;
}

int Time::getMinute() const
{
  return minute;
}

int Time::getSecond() const
{
  return second;
}

void Time::printUniversal() const
{
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2) << hour << " : "  << minute << " : "  << second;
}

void Time::printStandard() const
{
  cout.setf(ios::fixed|ios::showpoint);
  cout << ((hour == 0|| hour == 12)? 12 : hour % 12 ) << " : " << setprecision(2) << minute << " : " << second << (hour < 12 ? "AM" : " PM");
}
