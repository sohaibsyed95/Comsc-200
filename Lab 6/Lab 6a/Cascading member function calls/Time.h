// Lab 6a, Cascading Member Functions, Time.h
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef TIME_H
#define TIME_H

class Time
{
  public:
    Time( int = 0, int = 0, int = 0);

    Time &setTime(int, int, int);
    Time &setHour(int);
    Time &setMinute(int);
    Time &setSecond(int);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printUniversal() const;
    void printStandard() const;

  private:
    int hour;
    int minute;
    int second;
};

#endif
