// Lab 10b, ElevatorSimulation1, Rider.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "Rider.h"

int Rider::num = 0;

bool Rider::operator==(const Rider& r) const
{
  bool result = true;
  if (riderID != r.riderID)
    result = false;
  return result;
}

bool Rider::operator<(const Rider& r) const
{
  bool result = false;
  if (riderID < r.riderID)
    result = true;
  return result;
}

const Rider& Rider::operator=(const Rider &r)
{
  if (&r != this)
  {
    const_cast<int&>(riderID) = r.riderID;
    const_cast<const Floor*&>(destination) = r.destination;
  }
  return *this;
}
