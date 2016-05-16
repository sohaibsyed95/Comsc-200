#ifndef RIDER_CPP
#define RIDER_CPP

#include "Rider.h"

int Rider::num = 0;

bool Rider::operator==(const Rider& rider) const
{
  bool result = true;
  if (riderID != rider.riderID)
    result = false;
  return result;
}

bool Rider::operator<(const Rider& rider) const
{
  bool result = false;
  if (riderID != rider.riderID)
    result = true;
  return result;
}

#endif
