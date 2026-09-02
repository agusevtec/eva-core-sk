

# Class eva::BinarizeEqDecor

**template &lt;class TReader, int tActivatesOn&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**BinarizeEqDecor**](classeva_1_1_binarize_eq_decor.md)



_Decorator that converts reading to binary based on level equality._ [More...](#detailed-description)

* `#include <evaReaderDecors.h>`



Inherits the following classes: TReader


Inherited by the following classes: [eva::Switch](classeva_1_1_switch.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BinarizeEqDecor**](#function-binarizeeqdecor) (Args... args) <br>_Constructs a_ [_**BinarizeEqDecor**_](classeva_1_1_binarize_eq_decor.md) _._ |
|  signed short | [**getValue**](#function-getvalue) () <br>_Gets binary value based on equality check._  |




























## Detailed Description




**Template parameters:**


* `TReader` Underlying reader type 
* `tActivatesOn` Value that maps to active state (1) 




    
## Public Functions Documentation




### function BinarizeEqDecor 

_Constructs a_ [_**BinarizeEqDecor**_](classeva_1_1_binarize_eq_decor.md) _._
```C++
template<typename... Args>
inline eva::BinarizeEqDecor::BinarizeEqDecor (
    Args... args
) 
```





**Parameters:**


* `args` Additional arguments passed to TReader constructor 




        

<hr>



### function getValue 

_Gets binary value based on equality check._ 
```C++
inline signed short eva::BinarizeEqDecor::getValue () 
```





**Returns:**

1 if value equals tActivatesOn, 0 otherwise 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaReaderDecors.h`

