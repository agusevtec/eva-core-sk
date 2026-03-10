

# File evaList.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaList.h**](eva_list_8h.md)

[Go to the documentation of this file](eva_list_8h.md)


```C++
#ifndef EVALIST_H_
#define EVALIST_H_

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
//    List(const List &) = delete;

//    List &operator=(const List &) = delete;

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

    void append(ItemClass item)
    {
      if (!this->head)
        this->head = this->tail = new ListIterator<ItemClass>(item);
      else
        this->tail = this->tail->next = new ListIterator<ItemClass>(item);
      this->length++;
    }

    ListIterator<ItemClass> *first()
    {
      return this->head;
    }

    ItemClass *operator[](unsigned short index)
    {
      unsigned short i = 0;
      for (auto *iter = this->head; iter != 0; iter = iter->next)
        if (index == i++)
          return &(iter->item);
      return nullptr;
    }

    unsigned inline count()
    {
      return this->length;
    }
  };
};

#endif
```


