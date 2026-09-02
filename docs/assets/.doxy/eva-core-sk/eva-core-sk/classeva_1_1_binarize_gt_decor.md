

# Class eva::BinarizeGtDecor

**template &lt;class TReader, int THRESHOLD&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**BinarizeGtDecor**](classeva_1_1_binarize_gt_decor.md)



_Decorator that converts analog reading to binary based on 'greater than' threshold condition._ [More...](#detailed-description)

* `#include <evaReaderDecors.h>`



Inherits the following classes: TReader


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BinarizeGtDecor**](#function-binarizegtdecor) (Args... args) <br>_Constructs a_ [_**BinarizeGtDecor**_](classeva_1_1_binarize_gt_decor.md) _._ |
|  signed short | [**getValue**](#function-getvalue) () <br>_Gets binary value based on greater than comparison._  |




























## Detailed Description




**Template parameters:**


* `TReader` Underlying reader type 
* `THRESHOLD` Threshold value 




    
## Public Functions Documentation




### function BinarizeGtDecor 

_Constructs a_ [_**BinarizeGtDecor**_](classeva_1_1_binarize_gt_decor.md) _._
```C++
template<typename... Args>
inline eva::BinarizeGtDecor::BinarizeGtDecor (
    Args... args
) 
```





**Parameters:**


* `args` Additional arguments passed to TReader constructor 




        

<hr>



### function getValue 

_Gets binary value based on greater than comparison._ 
```C++
inline signed short eva::BinarizeGtDecor::getValue () 
```





**Returns:**

1 if value &gt;= THRESHOLD, 0 otherwise 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaReaderDecors.h`

