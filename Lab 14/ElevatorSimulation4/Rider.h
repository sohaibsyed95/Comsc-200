// Lab 10b, ElevatorSimulation3, Floor.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef Rider_H
#define Rider_H

class Floor;

class Rider
{
  public:
    Rider(const Floor& floor): destination(&floor), riderID(num){++num;}
    bool operator==(const Rider&) const;
    bool operator<(const Rider&) const;
    const Floor& getDestination() const{return *destination;}
    const Rider& operator=(const Rider&);

  private:
    const int riderID;
    static int num;
    const Floor* const destination;

};

#endif // RIDER_H_INCLUDED
