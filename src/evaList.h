#ifndef EVALIST_H_
#define EVALIST_H_

namespace eva
{
  /**
   * @brief Iterator node for List
   */
  template <class ItemClass>
  struct ListIterator
  {
    ItemClass item;
    ListIterator<ItemClass> *next;
    ListIterator(ItemClass &item) : item(item), next(0) {}
  };

  /**
   * @brief Simple singly-linked list container
   * @tparam ItemClass Type of items to store
   */
  template <class ItemClass>
  class List
  {
    ListIterator<ItemClass> *head = 0;
    ListIterator<ItemClass> *tail = 0;
    unsigned length = {0};

  public:
//    List(const List &) = delete;

//    List &operator=(const List &) = delete;

    /**
     * @brief Destructor - frees all nodes
     */
    ~List()
    {
      ListIterator<ItemClass> *current = this->head;
      while (current)
      {
        ListIterator<ItemClass> *next = current->next;
        delete current;
        current = next;
      }
    }

    /**
     * @brief Appends an item to the list
     * @param item Item to append
     */
    void append(ItemClass item)
    {
      if (!this->head)
        this->head = this->tail = new ListIterator<ItemClass>(item);
      else
        this->tail = this->tail->next = new ListIterator<ItemClass>(item);
      this->length++;
    }

    /**
     * @brief Gets first iterator
     * @return Pointer to first iterator
     */
    ListIterator<ItemClass> *first()
    {
      return this->head;
    }

    /**
     * @brief Array-style access by index
     * @param index Index (0-based)
     * @return Reference to item
     */
    ItemClass &operator[](unsigned index)
    {
      int i = 0;
      for (auto *iter = this->head; iter != 0; iter = iter->next)
        if (index == i++)
          return iter->item;
    }

    /**
     * @brief Gets number of items in list
     * @return Item count
     */
    unsigned inline count()
    {
      return this->length;
    }
  };
};

#endif
