

# File evaList.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaList.h**](eva_list_8h.md)

[Go to the documentation of this file](eva_list_8h.md)


```C++
#pragma once

namespace eva
{
  template <class ItemClass>
  struct ListIterator
  {
    ItemClass item;
    ListIterator<ItemClass> *next;
    ListIterator(ItemClass &item) : item(item), next(0) {}
  };

  template <class ItemClass>
  class List
  {
    ListIterator<ItemClass> *head = 0;
    ListIterator<ItemClass> *tail = 0;
    unsigned length = {0};

  public:
    List() = default;

    List(const List &other)
    {
      for (auto *iter = other.head; iter != nullptr; iter = iter->next)
        this->append(iter->item);
    }

    List &operator=(const List &other)
    {
      if (this != &other) {
        this->clear();
        for (auto *iter = other.head; iter != nullptr; iter = iter->next)
          this->append(iter->item);
      }
      return *this;
    }

    ~List()
    {
      this->clear();
    }

    void append(ItemClass item)
    {
      if (!this->head)
        this->head = this->tail = new ListIterator<ItemClass>(item);
      else
        this->tail = this->tail->next = new ListIterator<ItemClass>(item);
      this->length++;
    }

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

    bool remove(const ItemClass &item)
    {
      int idx = indexOf(item);
      if (idx >= 0)
        return removeAt(idx);
      return false;
    }

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

    ListIterator<ItemClass> *first()
    {
      return this->head;
    }

    ItemClass *operator[](unsigned short index)
    {
      unsigned short i = 0;
      for (auto *iter = this->head; iter != nullptr; iter = iter->next)
        if (index == i++)
          return &(iter->item);
      return nullptr;
    }

    unsigned inline count() const
    {
      return this->length;
    }

    bool inline isEmpty() const
    {
      return this->length == 0;
    }
  };
}
```


