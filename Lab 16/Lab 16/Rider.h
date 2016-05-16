// Lab 15, ElevatorSimulation5, Rider.h
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef RIDER_H
#define RIDER_H

class Floor;

class Rider
{
  private:
    const int riderID;
    static int num;
    const Floor* const destination;

  public:
    Rider(const Floor& floor): destination(&floor), riderID(num){++num;}
    bool operator==(const Rider&) const;
    bool operator<(const Rider&) const;
    const Floor& getDestination() const{return *destination;}
    const Rider& operator=(const Rider&);

};

#endif // RIDER_H_INCLUDED
