// Lab 10b, ElevatorSimulation3, Floor.h
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef Floor_H
#define Floor_H

class Floor
{
  public:
    Floor(const int floorLocation): floorLocation(floorLocation){}
    int getLocation() const{return floorLocation;}
  private:
    const int floorLocation;
};

#endif
