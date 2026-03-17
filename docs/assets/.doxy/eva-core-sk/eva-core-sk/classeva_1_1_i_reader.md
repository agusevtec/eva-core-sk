

# Class eva::IReader



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**IReader**](classeva_1_1_i_reader.md)



_Interface for value readers._ [More...](#detailed-description)

* `#include <evaIReader.h>`





Inherited by the following classes: [eva::IReaderAdapter](classeva_1_1_i_reader_adapter.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual signed short | [**getValue**](#function-getvalue) () = 0<br> |




























## Detailed Description


The library uses templates internally for maximum performance and flexibility, and never uses interfaces internally. However, forcing users to write template code everywhere can be cumbersome. All readers can be converted to this interface using the companion [**IReaderAdapter**](classeva_1_1_i_reader_adapter.md) for further use in polymorphic contexts.


This two-tier approach gives us benefits:
* Use templates directly for maximum performance
* Use this interface for simpler integration and loose coupling






**See also:** [**IReaderAdapter**](classeva_1_1_i_reader_adapter.md) 



    
## Public Functions Documentation




### function getValue 

```C++
virtual signed short eva::IReader::getValue () = 0
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaIReader.h`

