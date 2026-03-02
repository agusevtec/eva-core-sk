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

    /**
     * @brief Gets or sets the head of the tickable chain
     * @param mount If provided, adds to chain; if null, returns chain head
     * @return Head of chain
     */
    static Tickable *chain(Tickable *mount = 0);

    /**
     * @brief Triggers tick on this and all linked tickables
     */
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
