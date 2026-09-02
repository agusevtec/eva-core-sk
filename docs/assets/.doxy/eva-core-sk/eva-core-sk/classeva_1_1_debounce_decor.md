

# Class eva::DebounceDecor

**template &lt;class TReader&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**DebounceDecor**](classeva_1_1_debounce_decor.md)



_Decorator that stabilizes readings by requiring value to be stable for a period._ [More...](#detailed-description)

* `#include <evaReaderDecors.h>`



Inherits the following classes: TReader


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DebounceDecor**](#function-debouncedecor) (Args... args) <br>_Constructs a_ [_**DebounceDecor**_](classeva_1_1_debounce_decor.md) _._ |
|  signed short | [**getValue**](#function-getvalue) () <br>_Gets debounced value._  |




























## Detailed Description




**Template parameters:**


* `TReader` Underlying reader type 




    
## Public Functions Documentation




### function DebounceDecor 

_Constructs a_ [_**DebounceDecor**_](classeva_1_1_debounce_decor.md) _._
```C++
template<typename... Args>
inline eva::DebounceDecor::DebounceDecor (
    Args... args
) 
```





**Parameters:**


* `args` Additional arguments passed to TReader constructor 




        

<hr>



### function getValue 

_Gets debounced value._ 
```C++
inline signed short eva::DebounceDecor::getValue () 
```





**Returns:**

Stable reading after debounce period 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaReaderDecors.h`

