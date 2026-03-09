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
    virtual ~Tickable();

    /**
     * @brief Gets or sets the head of the tickable chain
     * @return Head of chain
     */
    static Tickable *chain();

    /**
     * @brief Triggers tick on this and all linked tickables
     */
    void tac();

  private:
    virtual void tick() = 0;

  private:
    Tickable *next = 0;
    static Tickable *last;
    static Tickable *first;
  };
};
#endif
