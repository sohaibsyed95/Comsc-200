// Lab 14, ElevatorSimulation4, Floor.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Rider.h"

#ifndef FLOOR_H
#define FLOOR_H

class Floor
{
  private:
  const string NAME; // name of floor, for example: Mezzanine
  const int location; // inches above ground levels
  vector<Rider> upRiders; // affected by addNewRider, removeUpRiders,...
  vector<Rider> downRiders; // ...and removeDownRiders functions

  public:
  Floor(const int location, const char* const NAME = "unnamed"):location(location), NAME(NAME){} // name and location (inches above ground) of floor

  // inline functions
  int getLocation() const {return location;};
  bool hasRidersWaiting() const{return !upRiders.size()?0:(!downRiders.size()?0:0);}
  bool hasUpRiders() const {return (upRiders.size() != 0);}
  bool hasDownRiders() const {return (downRiders.size() != 0);}
  int getUpRiderCount() const{return (upRiders.size());}
  int getDownRiderCount() const{return (downRiders.size());}
  string getName() const{return NAME;}

  // non-inline functions
  bool isPreferredDirectionUp() const; // based on Rider with smallest ID
  void addNewRider(const Rider&); // add to up- or down-vector
  vector<Rider> removeUpRiders(int); // int is max #of riders...
  vector<Rider> removeDownRiders(int); //...to move onto elevator

  friend ostream& operator<<(ostream&, const Floor&); // say name, location, #'s of up/down riders waiting
};
#endif // FLOOR_H
