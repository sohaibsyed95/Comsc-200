// Lab 8b, ElevatorSimulation1, Rider.h
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

  private:
    const int riderID;
    static int num;
    const Floor* const destination;
};

#endif
