// Lab 4a, Applying Const, Time.h
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef TIME_H
#define TIME_H

class Time
{
  public:
    Time(int = 0, int = 0, int = 0);

    // set functions
	void setTime(int, int, int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);

    // get functions (normally declared const)
	int getHour() const;
	int getMinute() const;
	int getSecond() const;

    // print functions (normally declared const)
	void printUniversal() const;
	void printStandard() const;

	//creates variables
  private:
	int hour;  //0-23
	int minute;  //0-59
	int second;  //0-59
};

#endif
