#include "evaTac.h"
#include "evaTickable.h"

void eva::tac()
{
  Tickable *first = Tickable::chain();
  if (first)
    first->tac();
}
