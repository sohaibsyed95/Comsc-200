// Lab 15, ElevatorSimulation5, Floor.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "Elevator.h"
#include "Rider.h"
#include "Floor.h"

#include <iostream>
using std::ostream;

bool Floor::isPreferredDirectionUp() const
{
  if(!(hasDownRiders()))
    return true;
  if(!(hasUpRiders()))
    return false;
  if(upRiders[0] < downRiders[0])
    return true;

  return false;
}

void Floor::addNewRider(const Rider& r)
{
  if(r.getDestination().getLocation() > this->getLocation())
  {
    upRiders.push_back(r);
  }

  else
  {
    downRiders.push_back(r);
  }
}

vector<Rider> Floor::removeUpRiders(int remRiders)
{
    vector<Rider> gettingoff;
    vector<Rider> notgettingoff;
    if(hasDownRiders())
    {
      for(int i = 0; i < upRiders.size(); i++)
      {
        if(gettingoff.size() != remRiders)
        {
          gettingoff.push_back(upRiders[i]);
        }
        else
        {
          notgettingoff.push_back(upRiders[i]);
        }
      }
      upRiders = notgettingoff;
    }
    return gettingoff;
}

vector<Rider> Floor::removeDownRiders(int remRiders)
{
    vector<Rider> gettingoff;
    vector<Rider> notgettingoff;
    if(hasDownRiders())
    {
      for(int i = 0; i < downRiders.size(); i++)
      {
        if(gettingoff.size() != remRiders)
        {
          gettingoff.push_back(downRiders[i]);
        }
        else
        {
          notgettingoff.push_back(downRiders[i]);
        }
      }
      downRiders = notgettingoff;
    }
    return gettingoff;
}

ostream &operator<<(ostream &out, const Floor &floor)
{
  out << "The floor is: " << floor.NAME << "\n";
  out << "There are " << floor.upRiders.size() << " riders waiting to go up.\n";
  out << "There are " << floor.downRiders.size() << " riders waiting to go down.\n";
  out << "The elevator is currently located at floor " << floor.getLocation() << "\n";
  return out;
}
