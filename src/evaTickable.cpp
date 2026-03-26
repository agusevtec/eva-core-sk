#include "evaTickable.h"

using namespace eva;

Tickable *Tickable::first = nullptr;

Tickable::Tickable()
{
  this->next = first;
  first = this;
}

Tickable::~Tickable()
{
  for (Tickable **p = &first; *p != 0; p = &((*p)->next))
    if (*p == this)
    {
      *p = this->next;
      this->next = 0;
      return;
    }
}

void Tickable::tac()
{
  Tickable *current = first;
  while (current)
  {
    Tickable *next = current->next;
    current->tick();
    current = next;
  }
}
