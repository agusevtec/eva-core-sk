

# Class eva::DigitalPinReader

**template &lt;int tPin, int tPinMode&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)



_Reads digital pin value._ [More...](#detailed-description)

* `#include <evaStdReaders.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DigitalPinReader**](#function-digitalpinreader) () <br>_Constructs a_ [_**DigitalPinReader**_](classeva_1_1_digital_pin_reader.md) _and configures pin mode._ |
|  signed short | [**getValue**](#function-getvalue) () <br>_Reads digital pin value._  |
|  bool | [**isValid**](#function-isvalid) () <br>_Checks if reader is valid._  |




























## Detailed Description




**Template parameters:**


* `tPin` Arduino pin number 
* `tPinMode` Pin mode (INPUT, INPUT\_PULLUP, etc.) 




    
## Public Functions Documentation




### function DigitalPinReader 

_Constructs a_ [_**DigitalPinReader**_](classeva_1_1_digital_pin_reader.md) _and configures pin mode._
```C++
inline eva::DigitalPinReader::DigitalPinReader () 
```




<hr>



### function getValue 

_Reads digital pin value._ 
```C++
inline signed short eva::DigitalPinReader::getValue () 
```





**Returns:**

HIGH or LOW 





        

<hr>



### function isValid 

_Checks if reader is valid._ 
```C++
inline bool eva::DigitalPinReader::isValid () 
```





**Returns:**

Always true for digital pin reader 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaStdReaders.h`

