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

  private:
    virtual short tick() = 0;

  private:
    Tickable *next = 0;
  };
};
#endif
