

# Class eva::DigitalMutablePinReader



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**DigitalMutablePinReader**](classeva_1_1_digital_mutable_pin_reader.md)



_Reads digital pin value with runtime pin configuration._ 

* `#include <evaStdReaders.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DigitalMutablePinReader**](#function-digitalmutablepinreader) (uint8\_t aPin, uint8\_t aMode) <br>_Constructs a_ [_**DigitalMutablePinReader**_](classeva_1_1_digital_mutable_pin_reader.md) _and configures pin._ |
|  signed short | [**getValue**](#function-getvalue) () <br>_Reads digital pin value._  |
|  bool | [**isValid**](#function-isvalid) () <br>_Checks if reader is valid._  |




























## Public Functions Documentation




### function DigitalMutablePinReader 

_Constructs a_ [_**DigitalMutablePinReader**_](classeva_1_1_digital_mutable_pin_reader.md) _and configures pin._
```C++
eva::DigitalMutablePinReader::DigitalMutablePinReader (
    uint8_t aPin,
    uint8_t aMode
) 
```





**Parameters:**


* `aPin` Arduino digital pin number 
* `aMode` Pin mode 




        

<hr>



### function getValue 

_Reads digital pin value._ 
```C++
signed short eva::DigitalMutablePinReader::getValue () 
```





**Returns:**

HIGH or LOW 





        

<hr>



### function isValid 

_Checks if reader is valid._ 
```C++
bool eva::DigitalMutablePinReader::isValid () 
```





**Returns:**

Always true 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaStdReaders.h`

