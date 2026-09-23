

# Class eva::ValueReader



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**ValueReader**](classeva_1_1_value_reader.md)



_Simple stateful reader acting as a bridge between raw control values and evaf filters._ [More...](#detailed-description)

* `#include <evaStdReaders.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  signed short | [**getValue**](#function-getvalue) () const<br> |
|  bool | [**isValid**](#function-isvalid) () const<br> |
|  void | [**setValue**](#function-setvalue) (signed short value) <br> |




























## Detailed Description


getValue()/isValid() are public because evaf filters call them. setValue() is public so that decorators can push the target value straight into the filter. 


    
## Public Functions Documentation




### function getValue 

```C++
inline signed short eva::ValueReader::getValue () const
```




<hr>



### function isValid 

```C++
inline bool eva::ValueReader::isValid () const
```




<hr>



### function setValue 

```C++
inline void eva::ValueReader::setValue (
    signed short value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaStdReaders.h`

