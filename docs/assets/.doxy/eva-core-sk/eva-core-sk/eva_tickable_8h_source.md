

# File evaTickable.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaTickable.h**](eva_tickable_8h.md)

[Go to the documentation of this file](eva_tickable_8h.md)


```C++
#ifndef EVATICKABLE_H
#define EVATICKABLE_H

namespace eva
{
  class Tickable
  {
  public:
    Tickable();
    Tickable(const Tickable&) = delete;
    Tickable& operator=(const Tickable&) = delete;
    Tickable(Tickable&&) = delete;
    Tickable& operator=(Tickable&&) = delete;
    virtual ~Tickable();

    static void tac();

  private:
    virtual void tick() = 0;

  private:
    Tickable *next = 0;
    static Tickable *last;
    static Tickable *first;
  };
};
#endif
```


