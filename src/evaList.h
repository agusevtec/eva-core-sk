#pragma once

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
    /**
     * @brief Default constructor
     */
    List() = default;

    /**
     * @brief Copy constructor - performs deep copy
     * @param other List to copy from
     */
    List(const List &other)
    {
      for (auto *iter = other.head; iter != nullptr; iter = iter->next)
        this->append(iter->item);
    }

    /**
     * @brief Assignment operator - performs deep copy
     * @param other List to copy from
     * @return Reference to this list
     */
    List &operator=(const List &other)
    {
      if (this != &other) {
        this->clear();
        for (auto *iter = other.head; iter != nullptr; iter = iter->next)
          this->append(iter->item);
      }
      return *this;
    }

    /**
     * @brief Destructor - frees all nodes
     */
    ~List()
    {
      this->clear();
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
     * @brief Finds index of first occurrence of an item
     * @param item Item to find
     * @return Index of item, or -1 if not found
     */
    int indexOf(const ItemClass &item) const
    {
      int i = 0;
      for (auto *iter = this->head; iter != nullptr; iter = iter->next)
      {
        if (iter->item == item)
          return i;
        i++;
      }
      return -1;
    }

    /**
     * @brief Removes first occurrence of an item
     * @param item Item to remove
     * @return true if item was found and removed
     */
    bool remove(const ItemClass &item)
    {
      int idx = indexOf(item);
      if (idx >= 0)
        return removeAt(idx);
      return false;
    }

    /**
     * @brief Removes item at specified index
     * @param index Index of item to remove (0-based)
     * @return true if index is valid and item was removed
     */
    bool removeAt(unsigned short index)
    {
      if (index >= this->length) return false;
      
      ListIterator<ItemClass> **current = &this->head;
      unsigned short i = 0;
      
      while (*current) {
        if (i == index) {
          ListIterator<ItemClass> *toDelete = *current;
          *current = toDelete->next;
          
          // Update tail if removing last element
          if (toDelete == this->tail)
            this->tail = (*current ? *current : nullptr);
            
          delete toDelete;
          this->length--;
          return true;
        }
        current = &((*current)->next);
        i++;
      }
      return false;
    }

    /**
     * @brief Removes all items from the list
     */
    void clear()
    {
      ListIterator<ItemClass> *current = this->head;
      while (current)
      {
        ListIterator<ItemClass> *next = current->next;
        delete current;
        current = next;
      }
      this->head = nullptr;
      this->tail = nullptr;
      this->length = 0;
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
     * @return Pointer to item or nullptr if index out of bounds
     */
    ItemClass *operator[](unsigned short index)
    {
      unsigned short i = 0;
      for (auto *iter = this->head; iter != nullptr; iter = iter->next)
        if (index == i++)
          return &(iter->item);
      return nullptr;
    }

    /**
     * @brief Gets number of items in list
     * @return Item count
     */
    unsigned inline count() const
    {
      return this->length;
    }

    /**
     * @brief Checks if list is empty
     * @return true if list has no items
     */
    bool inline isEmpty() const
    {
      return this->length == 0;
    }
  };
}
