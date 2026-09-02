

# Class eva::AnalogPinReader

**template &lt;int tPin, int tPinMode&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)



_Reads analog pin value._ [More...](#detailed-description)

* `#include <evaStdReaders.h>`





Inherited by the following classes: [eva::Joystick](classeva_1_1_joystick.md),  [eva::Joystick](classeva_1_1_joystick.md),  [eva::Slider](classeva_1_1_slider.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**AnalogPinReader**](#function-analogpinreader) () <br>_Constructs an_ [_**AnalogPinReader**_](classeva_1_1_analog_pin_reader.md) _and configures pin mode._ |
|  signed short | [**getValue**](#function-getvalue) () <br>_Reads analog pin value._  |
|  bool | [**isValid**](#function-isvalid) () <br>_Checks if reader is valid._  |




























## Detailed Description




**Template parameters:**


* `tPin` Arduino analog pin number 
* `tPinMode` Pin mode (usually INPUT) 




    
## Public Functions Documentation




### function AnalogPinReader 

_Constructs an_ [_**AnalogPinReader**_](classeva_1_1_analog_pin_reader.md) _and configures pin mode._
```C++
inline eva::AnalogPinReader::AnalogPinReader () 
```




<hr>



### function getValue 

_Reads analog pin value._ 
```C++
inline signed short eva::AnalogPinReader::getValue () 
```





**Returns:**

ADC reading (0-1023) 





        

<hr>



### function isValid 

_Checks if reader is valid._ 
```C++
inline bool eva::AnalogPinReader::isValid () 
```





**Returns:**

Always true for analog pin reader 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaStdReaders.h`

