

# Class eva::List

**template &lt;class ItemClass&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**List**](classeva_1_1_list.md)



_Simple singly-linked list container._ [More...](#detailed-description)

* `#include <evaList.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**append**](#function-append) (ItemClass item) <br>_Appends an item to the list._  |
|  unsigned | [**count**](#function-count) () <br>_Gets number of items in list._  |
|  [**ListIterator**](structeva_1_1_list_iterator.md)&lt; ItemClass &gt; \* | [**first**](#function-first) () <br>_Gets first iterator._  |
|  ItemClass & | [**operator[]**](#function-operator) (unsigned index) <br>_Array-style access by index._  |
|   | [**~List**](#function-list) () <br>_Destructor - frees all nodes._  |




























## Detailed Description




**Template parameters:**


* `ItemClass` Type of items to store 




    
## Public Functions Documentation




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



### function count 

_Gets number of items in list._ 
```C++
inline unsigned eva::List::count () 
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



### function operator[] 

_Array-style access by index._ 
```C++
inline ItemClass & eva::List::operator[] (
    unsigned index
) 
```





**Parameters:**


* `index` Index (0-based) 



**Returns:**

Reference to item 





        

<hr>



### function ~List 

_Destructor - frees all nodes._ 
```C++
inline eva::List::~List () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaList.h`

