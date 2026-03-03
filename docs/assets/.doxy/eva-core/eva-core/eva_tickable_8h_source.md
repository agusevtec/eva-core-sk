

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

    static Tickable *chain(Tickable *mount = 0);

    void tac();

    inline unsigned long millis();

  private:
    virtual short tick() = 0;

  private:
    Tickable *next = 0;
#ifdef UNIT_TESTING
  public:
    unsigned long millisMock;
    void setMillis(unsigned long);
#endif
  };
};
#endif
```


