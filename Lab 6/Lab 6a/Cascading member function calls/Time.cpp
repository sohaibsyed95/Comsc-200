// Lab 6a, Cascading Member Functions, Time.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>
using std::setprecision;

#include "Time.h"

Time::Time(int hr, int mins, int sec)
{
  setTime(hr, mins, sec);
}

Time &Time::setTime(int h, int m, int s)
{
  setHour(h);
  setMinute(m);
  setSecond(s);
  return *this;
}

Time &Time::setHour(int h)
{
  hour = (h >= 0 && h < 24) ? h : 0;
  return *this;
}

Time &Time::setMinute(int m)
{
  minute = (m >= 0 && m < 60) ? m : 0;
  return *this;
}

Time &Time::setSecond(int s)
{
  second = (s >= 0 && s < 60) ? s : 0;
  return *this;
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
  cout << setprecision(2) << hour << ":" << minute << ":" << second;
}

void Time::printStandard() const
{
  cout.setf(ios::fixed|ios::showpoint);
  cout << ( (hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << setprecision(2) << minute << ":" << second << (hour < 12 ? " AM" : " PM");
}
