#include "evaTickable.h"

using namespace eva;

Tickable::Tickable()
{
  chain(this);
}

Tickable *Tickable::chain(Tickable *mount)
{
  static Tickable *first = 0;
  if (!mount)
    return first;
  if (!first)
    first = mount;
  static Tickable *last = 0;
  if (last)
    last->next = mount;
  last = mount;
  return first;
}

void Tickable::tac()
{
  tick();
  if (this->next)
    this->next->tac();
}

inline unsigned long eva::Tickable::millis()
{
#ifndef UNIT_TESTING
  return millis();
#else
  return self->millisMock;
#endif
}
#ifdef UNIT_TESTING
void setMillis(unsigned long millisMock)
{
  self->millisMock = millisMock;
}
#endif