

# Class eva::IReaderAdapter

**template &lt;class T&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**IReaderAdapter**](classeva_1_1_i_reader_adapter.md)



_Adapter that converts any class with getValue() into an_ [_**IReader**_](classeva_1_1_i_reader.md) _._[More...](#detailed-description)

* `#include <evaIReader.h>`



Inherits the following classes: [eva::IReader](classeva_1_1_i_reader.md),  T






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual signed short | [**getValue**](#function-getvalue) () override<br> |
| virtual bool | [**isValid**](#function-isvalid) () override<br> |


## Public Functions inherited from eva::IReader

See [eva::IReader](classeva_1_1_i_reader.md)

| Type | Name |
| ---: | :--- |
| virtual signed short | [**getValue**](classeva_1_1_i_reader.md#function-getvalue) () = 0<br> |
| virtual bool | [**isValid**](classeva_1_1_i_reader.md#function-isvalid) () = 0<br> |






















































## Detailed Description


This adapter serves as a bridge between the template-based library core and the interface-based library boundary. It allows:
* Using template-based readers polymorphically
* Passing library readers to functions expecting IReader\*
* Users to work with interfaces instead of templates when preferred






**Template parameters:**


* `T` Class that implements getValue() (typically a reader decorator or a user-defined reader)



**Note:**

This adapter incurs a virtual call overhead, so use it at API boundaries, not in performance-critical internal loops where templates are preferred. 





    
## Public Functions Documentation




### function getValue 

```C++
inline virtual signed short eva::IReaderAdapter::getValue () override
```



Implements [*eva::IReader::getValue*](classeva_1_1_i_reader.md#function-getvalue)


<hr>



### function isValid 

```C++
inline virtual bool eva::IReaderAdapter::isValid () override
```



Implements [*eva::IReader::isValid*](classeva_1_1_i_reader.md#function-isvalid)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaIReader.h`

