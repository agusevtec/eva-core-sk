

# Class eva::Slider

**template &lt;class TReader, unsigned short tMinPos, unsigned short tMaxPos&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Slider**](classeva_1_1_slider.md)



_Maps analog readings to 0-1000 range._ [More...](#detailed-description)

* `#include <evaSlider.h>`



Inherits the following classes: TReader


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Slider**](#function-slider) (Args... args) <br>_Constructs a_ [_**Slider**_](classeva_1_1_slider.md) _._ |
|  signed short | [**getValue**](#function-getvalue-12) (unsigned short aMinPos, unsigned short aMaxPos) <br>_Gets normalized slider position with custom range._  |
|  signed short | [**getValue**](#function-getvalue-22) () <br>_Gets normalized slider position._  |




























## Detailed Description




**Template parameters:**


* `TReader` Underlying reader type 
* `tMinPos` Minimum analog reading 
* `tMaxPos` Maximum analog reading 




    
## Public Functions Documentation




### function Slider 

_Constructs a_ [_**Slider**_](classeva_1_1_slider.md) _._
```C++
template<typename... Args>
inline eva::Slider::Slider (
    Args... args
) 
```





**Parameters:**


* `args` Additional arguments passed to TReader constructor 




        

<hr>



### function getValue [1/2]

_Gets normalized slider position with custom range._ 
```C++
inline signed short eva::Slider::getValue (
    unsigned short aMinPos,
    unsigned short aMaxPos
) 
```





**Parameters:**


* `aMinPos` Minimum analog reading 
* `aMaxPos` Maximum analog reading 



**Returns:**

Value from 0 to 1000 





        

<hr>



### function getValue [2/2]

_Gets normalized slider position._ 
```C++
inline signed short eva::Slider::getValue () 
```





**Returns:**

Value from 0 to 1000 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaSlider.h`

