

# Class eva::QuantizeDecor

**template &lt;class TReader, signed short... LEVELS&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**QuantizeDecor**](classeva_1_1_quantize_decor.md)



_Decorator that quantizes analog readings to discrete levels._ 

* `#include <evaReaderDecors.h>`



Inherits the following classes: TReader


Inherited by the following classes: [eva::Switch](classeva_1_1_switch.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|  signed short | [**getLevel**](#function-getlevel) (unsigned char index) <br>_Gets threshold value for a level._  |
|  signed short | [**getValue**](#function-getvalue) () <br>_Gets quantized level index._  |




























## Public Functions Documentation




### function getLevel 

_Gets threshold value for a level._ 
```C++
inline signed short eva::QuantizeDecor::getLevel (
    unsigned char index
) 
```





**Parameters:**


* `index` Level index 



**Returns:**

Threshold value 





        

<hr>



### function getValue 

_Gets quantized level index._ 
```C++
inline signed short eva::QuantizeDecor::getValue () 
```





**Returns:**

Level index (0 for no input, 1..n for specific levels) 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaReaderDecors.h`

