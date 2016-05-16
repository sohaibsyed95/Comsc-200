// Lab 15, ElevatorSimulation5, Building.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <cstdlib>

#include <vector>
using std::vector;

#include "Building.h"
#include "Elevator.h"
#include "Floor.h"
#include "Rider.h"

Building::Building(): elsim5(0)
{
  //Floor declarations
  Floor* f1 = new Floor(-500, "Crypt");
  floors.push_back(f1);

  Floor* f2 = new Floor(0, "First Floor");
  floors.push_back(f2);

  Floor* f3 = new Floor(500, "Second Floor");
  floors.push_back(f3);

  Floor* f4 = new Floor(1000, "Third Floor");
  floors.push_back(f4);

  Floor* f5 = new Floor(1500, "Fourth Floor");
  floors.push_back(f5);

  //Elevator declarations
  Elevator* e1 = new Elevator(10, 25, *floors[1]);
  elevators.push_back(e1);

  Elevator* e2 = new Elevator(5, 50, *floors[4]);
  elevators.push_back(e2);
}

Building& Building::step(int a)
{
  // POSSIBLE RIDER ACTION [1]
  for(int i = 0; i < a; i++)
  {
    int f1 = getFloorCount();// add rider(s) in this time step (The number of riders to be added is sent to this function in the parameter list, and is greater or equal to 0.) [1]
    int f2;
    int f3;
    getDifferentInts(f1, f2, f3);// create a rider with randomly selected from- and to-floors (where from- and to- are not the same!) [1]
    floors[f2]->addNewRider(Rider(*floors[f3]));// tell the from-floor to add this rider [1]
  }
  // ELEVATOR ACTIONS [3]
  for(int i = 0; i < getElevatorCount(); i++)// tell each elevator to perform an action [3]
  {
    if(getElevator(i).isDoorOpen() == false)  // if elevator door is closed (move up or down) [3]
    // tell each elevator to perform an action [3]
    {
      if(getElevator(i).isNearDestination()== false)// if not near enough to destination to reach it in this time step, continue moving [3]
      {
        if(getElevator(i).isDirectionUp() == true)
        {
          elevators[i]->moveUp();  // if elevator direction is up, move up [3]
        }
        else
        {
          elevators[i]->moveDown();  // otherwise, move down [3]
        }
      }

      else  // otherwise it's near enough to destination to reach it in this time step... [4]
      {
        elevators[i]->moveToDestinationFloor();  // tell elevator to move to its destination floor [4]
        elevators[i]->openDoor();  // tell elevator to open its door [4]
        elevators[i]->removeRidersForDestinationFloor();  // tell elevator to remove riders for its destination floor -- ignore returned vector of removed riders [4]
        Floor* nonconst;

        if(getElevator(i).getRiderCount() == 0)  // if elevator is empty, choose a direction based on longest-waiting rider (the one with the smallest ID) on the floor: [5]
        {
          if(nonconst->isPreferredDirectionUp() == true) // if the floor's chosen direction is up [5]
          {
            elevators[i]->setDirectionUp();  // tell elevator to set its direction to up [5]
          }
          else  // otherwise [5]
          {
            elevators[i]->setDirectionDown();  // tell elevator to set its direction to down [5]
          }
        }

        if(getElevator(i).getAvailableSpace() > 0 && elevators[i]->isDoorOpen() == true)  // if there is space in the elevator after letting off riders, board new ones [6]
        {
          const_cast<const Floor*&>(nonconst) = &getElevator(i).getDestination();  // get a constant mutating pointer to the elevator's destination floor (using const_cast) [6] HINT: lecture topic 9
          if(getElevator(i).isDirectionUp() == true)
          {
            elevators[i]->addRiders(nonconst->removeUpRiders(elevators[i]->getAvailableSpace()));  // if elevator direction is up, board up-riders (if any)... [6]
          }
          else
          {
            elevators[i]->addRiders(nonconst->removeDownRiders(elevators[i]->getAvailableSpace()));  // otherwise, board down-riders (if any) [6]
          }
        }
        elevators[i]->setDestinationBasedOnRiders();  // reassess elevator destination based on its riders [8]
      }
    }

    else  // otherwise (then it already let off riders, or is in its initial state) [7]
    {
      if(getElevator(i).hasRiders()== true)  // if elevator has any riders (then they just boarded in the previous time step) [7]
      {
        elevators[i]->closeDoor();  // tell elevator to close its door [7]
      }
      else  // otherwise [9]
      {
        elevators[i]->setIdle();// tell elevator to go idle [9]
      }
    }

  }

  // FLOOR ACTIONS [2]
  for(int i = 0; i < getFloorCount(); i++)
  {
    if(getFloor(i).hasRidersWaiting() == false)  // check each floor (for waiting riders) [2]
      continue;  // if there are no riders waiting on this floor, continue with next floor [2]

    for(int j = 0; j < getElevatorCount(); j++)
    {
      int loc = elevators[j]->getLocation() - floors[i]->getLocation();
      // get elevator's relative location (negative if elevator is below floor) [2]
      if(getElevator(j).isIdle() == true) // if this elevator's idle... [2]
      {
        // look at each elevator to see if it needs to be sent here [2]
        if(loc >= 0)
        {
          elevators[j]->setDirectionDown();  // if elevator is above the floor, set elevator direction to down [2]
          elevators[j]->setDestination(floors[i]);// set elevator's destination to this floor [2]
          elevators[j]->closeDoor();// tell elevator to close its door [2]
        }
        else
        {
          elevators[j]->setDirectionUp();// otherwise if it's below, set elevator direction to up [2]
          elevators[j]->setDestination(floors[i]);// set elevator's destination to this floor [2]
          elevators[j]->closeDoor();  // tell elevator to close its door [2]
        }
      }

      // else if there are riders on this floor waiting to go up, and the elevator is going up... [10]
      else if(getFloor(i).hasUpRiders() == true && getElevator(j).isDirectionUp() == true)
      {
        double elvDistanceToThisFloor = getElevator(j).getDestination().getLocation() - getFloor(i).getLocation();  // get distance from elevator's destination floor to this floor (positive if elevator destination is above this floor) [10]
        if (elvDistanceToThisFloor > 0 && loc < 0)
        {
          elevators[j]->setDestination(&(getFloor(i)));
        }
      }

      else if(getFloor(i).hasUpRiders() == true && getElevator(j).isDirectionUp() == true)
      {
        double elvDistanceToThisFloor = getElevator(j).getDestination().getLocation() - getFloor(i).getLocation();  // get distance from elevator's destination floor to this floor (positive if elevator destination is above this floor) [10]
        if (elvDistanceToThisFloor < 0 && loc > 0)
        {
          elevators[j]->setDestination(&(getFloor(i)));
        }
      }
    }
  }

  elsim5++;
  return *this;
}

Building::~Building()
{
  //deallocate floors
  for(int i = 0; i < getFloorCount(); i++)
  {
    delete floors[i];
  }

  //deallocate elevators
  for(int i = 0; i < getElevatorCount(); i++)
  {
    delete elevators[i];
  }
}

//get different ints function provided for us
void Building::getDifferentInts(int max, int& a, int& b)
{
  do
  {
    a = rand() % max; // range is 0 to (max-1)
    b = rand() % max; // range is 0 to (max-1)
  } while (a == b); // try again if they are the same
}

ostream& operator<<(ostream& out, const Building& a)
{
  out << a.elsim5 << " seconds have passed" << endl;
  for(int i = 0; i < a.elevators.size(); i++)
  {
    out << "Elevator #" << i << ": " << *a.elevators[i] << endl;
  }
  for(int i = 0; i < a.floors.size(); i++)
  {
    out << *a.floors[i] << endl;
  }
  return out;
}
