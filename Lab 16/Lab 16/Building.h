// Lab 15, ElevatorSimulation5, Building.h
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
using std::ostream;

#include <vector>
using std::vector;

class Elevator;
class Floor;

class Building
{
  private:
    int elsim5;
    vector<Floor*> floors;
    vector<Elevator*> elevators;

  public:
    Building();

    //inline functions
    int getFloorCount() const {return (floors.size());}// return #of floors in the vector of Floor*'s
    int getElevatorCount() const {return (elevators.size());} // return #of elevators in the vector of Elevator*'s
    const Floor& getFloor(int index) const {return *floors[index];}// return a reference to the "indexth" floor
    const Elevator& getElevator(int index) const {return *elevators[index];}// return a reference to the "indexth" elevator

    //function calls
    friend ostream& operator<<(ostream&, const Building&);  //oveloaded operator
    void getDifferentInts(int, int&, int&);  //get different ints fnction provided
    Building& step(int);  //step function
    ~Building();  //destructor
};

#endif // BUILDING_H
