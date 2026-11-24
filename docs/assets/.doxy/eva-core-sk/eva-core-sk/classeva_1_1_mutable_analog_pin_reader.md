

# Class eva::MutableAnalogPinReader



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**MutableAnalogPinReader**](classeva_1_1_mutable_analog_pin_reader.md)



_Reads analog pin value with runtime pin configuration._ 

* `#include <evaStdReaders.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**MutableAnalogPinReader**](#function-mutableanalogpinreader) (uint8\_t aPin, uint8\_t aMode) <br>_Constructs an AnalogMutablePinReader and configures pin._  |
|  signed short | [**getValue**](#function-getvalue) () <br>_Reads analog pin value._  |
|  bool | [**isValid**](#function-isvalid) () <br>_Checks if reader is valid._  |




























## Public Functions Documentation




### function MutableAnalogPinReader 

_Constructs an AnalogMutablePinReader and configures pin._ 
```C++
eva::MutableAnalogPinReader::MutableAnalogPinReader (
    uint8_t aPin,
    uint8_t aMode
) 
```





**Parameters:**


* `aPin` Arduino analog pin number 
* `aMode` Pin mode 




        

<hr>



### function getValue 

_Reads analog pin value._ 
```C++
signed short eva::MutableAnalogPinReader::getValue () 
```





**Returns:**

ADC reading (0-1023) 





        

<hr>



### function isValid 

_Checks if reader is valid._ 
```C++
bool eva::MutableAnalogPinReader::isValid () 
```





**Returns:**

Always true 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaStdReaders.h`

