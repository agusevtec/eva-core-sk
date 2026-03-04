// evaTickable.cpp (обновленный)
#include "evaTickable.h"

using namespace eva;

Tickable *Tickable::first = nullptr;
Tickable *Tickable::last = nullptr;

Tickable::Tickable() : next(nullptr)
{
  if (first == nullptr)
  {
    first = this;
    last = this;
  }
  else
  {
    last->next = this;
    last = this;
  }
}

Tickable::~Tickable()
{
  Tickable *prev = nullptr;
  Tickable *current = first;

  while (current != this && current != nullptr)
  {
    prev = current;
    current = current->next;
  }

  if (current == this)
  {
    if (prev == nullptr)
      first = this->next;
    else
      prev->next = this->next;

    if (this == last)
      last = prev;
  }
  this->next = nullptr;
}

Tickable *Tickable::chain()
{
  return first;
}

void Tickable::tac()
{
  tick();
  if (next)
    next->tac();
}
