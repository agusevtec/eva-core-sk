

# Class eva::BinarizeLtDecor

**template &lt;class TReader, int THRESHOLD&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**BinarizeLtDecor**](classeva_1_1_binarize_lt_decor.md)



_Decorator that converts analog reading to binary based on 'less than' threshold condition._ [More...](#detailed-description)

* `#include <evaReaderDecors.h>`



Inherits the following classes: TReader


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BinarizeLtDecor**](#function-binarizeltdecor) (Args... args) <br>_Constructs a_ [_**BinarizeLtDecor**_](classeva_1_1_binarize_lt_decor.md) _._ |
|  signed short | [**getValue**](#function-getvalue) () <br>_Gets binary value based on less than comparison._  |




























## Detailed Description




**Template parameters:**


* `TReader` Underlying reader type 
* `THRESHOLD` Threshold value 




    
## Public Functions Documentation




### function BinarizeLtDecor 

_Constructs a_ [_**BinarizeLtDecor**_](classeva_1_1_binarize_lt_decor.md) _._
```C++
template<typename... Args>
inline eva::BinarizeLtDecor::BinarizeLtDecor (
    Args... args
) 
```





**Parameters:**


* `args` Additional arguments passed to TReader constructor 




        

<hr>



### function getValue 

_Gets binary value based on less than comparison._ 
```C++
inline signed short eva::BinarizeLtDecor::getValue () 
```





**Returns:**

1 if value &lt;= THRESHOLD, 0 otherwise 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaReaderDecors.h`

