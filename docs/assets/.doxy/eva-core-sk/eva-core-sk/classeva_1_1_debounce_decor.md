

# Class eva::DebounceDecor

**template &lt;class TReader, int tDebounceDelay&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**DebounceDecor**](classeva_1_1_debounce_decor.md)



_Rate-limiting decorator for contact-bounce suppression._ [More...](#detailed-description)

* `#include <evaReaderDecors.h>`



Inherits the following classes: TReader


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DebounceDecor**](#function-debouncedecor) (Args... args) <br>_Constructs a_ [_**DebounceDecor**_](classeva_1_1_debounce_decor.md) _._ |
|  signed short | [**getValue**](#function-getvalue) () <br>_Gets debounced value._  |




























## Detailed Description


The first change of the underlying reading is accepted immediately; after that, further changes are ignored for tDebounceDelay ms. Readings taken during that window return the accepted value without polling the underlying reader.


Note: this is NOT a "value must stay stable for tDebounceDelay ms" debounce. Short glitches that occur right after an accepted change are filtered out by the lock window, but a glitch that arrives when no lock is active will be accepted as a new value.




**Template parameters:**


* `TReader` Underlying reader type 
* `tDebounceDelay` Lock window after an accepted change, ms 




    
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

