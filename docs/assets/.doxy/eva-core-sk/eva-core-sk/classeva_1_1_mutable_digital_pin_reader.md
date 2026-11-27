

# Class eva::MutableDigitalPinReader



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**MutableDigitalPinReader**](classeva_1_1_mutable_digital_pin_reader.md)



_Reads digital pin value with runtime pin configuration._ 

* `#include <evaPinReaders.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**MutableDigitalPinReader**](#function-mutabledigitalpinreader) (uint8\_t aPin, uint8\_t aMode) <br>_Constructs a DigitalMutablePinReader and configures pin._  |
|  signed short | [**getValue**](#function-getvalue) () <br>_Reads digital pin value._  |
|  bool | [**isValid**](#function-isvalid) () <br>_Checks if reader is valid._  |




























## Public Functions Documentation




### function MutableDigitalPinReader 

_Constructs a DigitalMutablePinReader and configures pin._ 
```C++
eva::MutableDigitalPinReader::MutableDigitalPinReader (
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
signed short eva::MutableDigitalPinReader::getValue () 
```





**Returns:**

HIGH or LOW 





        

<hr>



### function isValid 

_Checks if reader is valid._ 
```C++
bool eva::MutableDigitalPinReader::isValid () 
```





**Returns:**

Always true 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaPinReaders.h`

