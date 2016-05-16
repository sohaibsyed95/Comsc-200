// Lab 15, ElevatorSimulation5, Elevator.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "Elevator.h"

#include "Floor.h"

#include <iostream>
using std::ostream;

#include <cstdlib>

#include <vector>
using std::vector;

int Elevator::elevatorID = 0;
const int Elevator::IDLE = 0;
const int Elevator::UP = 1;
const int Elevator::DOWN = -1;

//create constructors
Elevator::Elevator(const int space, const int spd, const Floor& start):ID(elevatorID), capacity(space), speed(spd),toFloor(0)
{
  location = start.getLocation();
  direction = IDLE;
  doorOpen = true;
}

bool Elevator::isNearDestination() const
{
  double distance = (toFloor->getLocation() - location);

  if(distance < 0)
  {
    distance *= -1;
  }
  return (distance <= speed);
}

void Elevator::moveToDestinationFloor()
{
  if(hasADestination())
  {
    location = toFloor->getLocation();
  }
}

ostream& operator<<(ostream& out, const Elevator& e)
{
  out << "Elevator is located at "<< e.getLocation() << " inches from the ground.";

  if(e.isIdle())
  {
    out << "\nthe Elevator is idle, ";
  }
  else if(e.isDirectionUp())
  {
    out << "\nthe Elevator is going up, ";
  }
  else if(e.isDirectionDown())
  {
    out << "\nthe Elevator is going down, ";
  }

  if(e.isDoorOpen())
  {
    out << "the Door is open.\n";
  }
  else
  {
    out << "door is closed.\n";
  }
  return out;
}

vector<Rider> Elevator::removeRidersForDestinationFloor()
{
  vector<Rider> riderLeaving;
  vector<Rider> riderStaying;

  for(int i = 0; i < riders.size(); i++)
  {
    if(toFloor == &(riders[i].getDestination()))
      riderLeaving.push_back(riders[i]);
    else
      riderStaying.push_back(riders[i]);
  }

  riders = riderStaying;
  return riderLeaving;
}

void Elevator::addRiders(const vector<Rider>& adrders)
{
  vector<Rider>::const_iterator i;
  for(i = adrders.begin(); i != adrders.end(); i++)
  {
    if(riders.size() < capacity)
      riders.push_back(*i);
  }
}

void Elevator::setDestinationBasedOnRiders()
{
  if(!hasRiders())
    return;
  int distance = 1;

  for(int i = 0; i < riders.size(); i++)
  {
    //calculate distance
    distance = getLocation() - riders[i].getDestination().getLocation();

    //convert to absolute value
    distance = abs(distance);
    if(getLocation() - riders[i].getDestination().getLocation() < 0 ||
       getLocation() - riders[i].getDestination().getLocation() > distance)
         distance = getLocation() - riders[i].getDestination().getLocation();

    setDestination(&riders[i].getDestination());
  }
}
