#ifndef EVATICKABLE_H
#define EVATICKABLE_H

namespace eva
{
  /**
   * @brief Base class for objects that need periodic updates
   */
  class Tickable
  {
  public:
    Tickable();
    Tickable(const Tickable &) = delete;
    Tickable &operator=(const Tickable &) = delete;
    Tickable(Tickable &&) = delete;
    Tickable &operator=(Tickable &&) = delete;
    virtual ~Tickable();

    /**
     * @brief Triggers tick on this and all linked tickables
     */
    static void tac();

  private:
    virtual void tick() = 0;

  private:
    Tickable *next = 0;
//static Tickable *last;
    static Tickable *first;
  };
};
#endif
