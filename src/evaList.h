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
    List(const List &) = delete;

    List &operator=(const List &) = delete;

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

    ItemClass &operator[](unsigned index)
    {
      int i = 0;
      for (auto *iter = this->head; iter != 0; iter = iter->next)
        if (index == i++)
          return iter->item;
    }

    unsigned inline count()
    {
      return this->length;
    }
  };
};

#endif
