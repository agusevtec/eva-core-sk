

# Class eva::List

**template &lt;class ItemClass&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**List**](classeva_1_1_list.md)



_Simple singly-linked list container._ [More...](#detailed-description)

* `#include <evaList.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**List**](#function-list-12) () = default<br>_Default constructor._  |
|   | [**List**](#function-list-22) (const List & other) <br>_Copy constructor - performs deep copy._  |
|  void | [**append**](#function-append) (ItemClass item) <br>_Appends an item to the list._  |
|  void | [**clear**](#function-clear) () <br>_Removes all items from the list._  |
|  unsigned | [**count**](#function-count) () const<br>_Gets number of items in list._  |
|  [**ListIterator**](structeva_1_1_list_iterator.md)&lt; ItemClass &gt; \* | [**first**](#function-first) () <br>_Gets first iterator._  |
|  int | [**indexOf**](#function-indexof) (const ItemClass & item) const<br>_Finds index of first occurrence of an item._  |
|  bool | [**isEmpty**](#function-isempty) () const<br>_Checks if list is empty._  |
|  [**List**](classeva_1_1_list.md#function-list-12) & | [**operator=**](#function-operator) (const [**List**](classeva_1_1_list.md#function-list-12) & other) <br>_Assignment operator - performs deep copy._  |
|  ItemClass \* | [**operator[]**](#function-operator_1) (unsigned short index) <br>_Array-style access by index._  |
|  bool | [**remove**](#function-remove) (const ItemClass & item) <br>_Removes first occurrence of an item._  |
|  bool | [**removeAt**](#function-removeat) (unsigned short index) <br>_Removes item at specified index._  |
|   | [**~List**](#function-list) () <br>_Destructor - frees all nodes._  |




























## Detailed Description




**Template parameters:**


* `ItemClass` Type of items to store 




    
## Public Functions Documentation




### function List [1/2]

_Default constructor._ 
```C++
eva::List::List () = default
```




<hr>



### function List [2/2]

_Copy constructor - performs deep copy._ 
```C++
inline eva::List::List (
    const List & other
) 
```





**Parameters:**


* `other` [**List**](classeva_1_1_list.md) to copy from 




        

<hr>



### function append 

_Appends an item to the list._ 
```C++
inline void eva::List::append (
    ItemClass item
) 
```





**Parameters:**


* `item` Item to append 




        

<hr>



### function clear 

_Removes all items from the list._ 
```C++
inline void eva::List::clear () 
```




<hr>



### function count 

_Gets number of items in list._ 
```C++
inline unsigned eva::List::count () const
```





**Returns:**

Item count 





        

<hr>



### function first 

_Gets first iterator._ 
```C++
inline ListIterator < ItemClass > * eva::List::first () 
```





**Returns:**

Pointer to first iterator 





        

<hr>



### function indexOf 

_Finds index of first occurrence of an item._ 
```C++
inline int eva::List::indexOf (
    const ItemClass & item
) const
```





**Parameters:**


* `item` Item to find 



**Returns:**

Index of item, or -1 if not found 





        

<hr>



### function isEmpty 

_Checks if list is empty._ 
```C++
inline bool eva::List::isEmpty () const
```





**Returns:**

true if list has no items 





        

<hr>



### function operator= 

_Assignment operator - performs deep copy._ 
```C++
inline List & eva::List::operator= (
    const List & other
) 
```





**Parameters:**


* `other` [**List**](classeva_1_1_list.md) to copy from 



**Returns:**

Reference to this list 





        

<hr>



### function operator[] 

_Array-style access by index._ 
```C++
inline ItemClass * eva::List::operator[] (
    unsigned short index
) 
```





**Parameters:**


* `index` Index (0-based) 



**Returns:**

Pointer to item or nullptr if index out of bounds 





        

<hr>



### function remove 

_Removes first occurrence of an item._ 
```C++
inline bool eva::List::remove (
    const ItemClass & item
) 
```





**Parameters:**


* `item` Item to remove 



**Returns:**

true if item was found and removed 





        

<hr>



### function removeAt 

_Removes item at specified index._ 
```C++
inline bool eva::List::removeAt (
    unsigned short index
) 
```





**Parameters:**


* `index` Index of item to remove (0-based) 



**Returns:**

true if index is valid and item was removed 





        

<hr>



### function ~List 

_Destructor - frees all nodes._ 
```C++
inline eva::List::~List () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaList.h`

