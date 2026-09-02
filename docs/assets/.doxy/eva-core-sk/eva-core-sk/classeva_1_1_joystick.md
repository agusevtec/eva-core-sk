

# Class eva::Joystick

**template &lt;class TReader, unsigned short tMinPos, unsigned short tMiddlePos, unsigned short tMaxPos&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Joystick**](classeva_1_1_joystick.md)



[_**Joystick**_](classeva_1_1_joystick.md) _axis reader (range 1000-1500-2000) with trim adjustment._[More...](#detailed-description)

* `#include <evaJoystick.h>`



Inherits the following classes: TReader


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Joystick**](#function-joystick) (short aDeadZone=0, Args... args) <br>_Constructs a_ [_**Joystick**_](classeva_1_1_joystick.md) _with optional dead zone._ |
|  void | [**addTrim**](#function-addtrim) (short trimIncrement) <br>_adds trim adjustment value_  |
|  signed short | [**getDeadZone**](#function-getdeadzone) () <br>_Gets current dead-zone value._  |
|  signed short | [**getTrim**](#function-gettrim) () <br>_Gets current trim value._  |
|  signed short | [**getValue**](#function-getvalue-12) () <br>_Gets normalized joystick position with custom ranges._  |
|  signed short | [**getValue**](#function-getvalue-22) () <br>_Gets normalized joystick position (1000 to 2000)._  |
|  void | [**setDeadZone**](#function-setdeadzone) (short deadZone) <br>_Sets dead-zone value._  |
|  void | [**setTrim**](#function-settrim) (short trim) <br>_Sets trim adjustment value._  |




























## Detailed Description




**Parameters:**


* `deadZone` dead-zone value 



**Template parameters:**


* `TReader` Underlying reader type 
* `tMinPos` Minimum analog value 
* `tMiddlePos` Center value 
* `tMaxPos` Maximum analog value 




    
## Public Functions Documentation




### function Joystick 

_Constructs a_ [_**Joystick**_](classeva_1_1_joystick.md) _with optional dead zone._
```C++
template<typename... Args>
inline eva::Joystick::Joystick (
    short aDeadZone=0,
    Args... args
) 
```





**Parameters:**


* `aDeadZone` Dead-zone value (0-255) 
* `args` Additional arguments passed to TReader constructor 




        

<hr>



### function addTrim 

_adds trim adjustment value_ 
```C++
inline void eva::Joystick::addTrim (
    short trimIncrement
) 
```





**Parameters:**


* `trim` value 




        

<hr>



### function getDeadZone 

_Gets current dead-zone value._ 
```C++
inline signed short eva::Joystick::getDeadZone () 
```





**Returns:**

deadZone value 





        

<hr>



### function getTrim 

_Gets current trim value._ 
```C++
inline signed short eva::Joystick::getTrim () 
```





**Returns:**

trim value 





        

<hr>



### function getValue [1/2]

_Gets normalized joystick position with custom ranges._ 
```C++
template<unsigned short MINPOS, unsigned short MIDDLEPOS, unsigned short MAXPOS>
inline signed short eva::Joystick::getValue () 
```





**Template parameters:**


* `MINPOS` Minimum analog value 
* `MIDDLEPOS` Center analog value 
* `MAXPOS` Maximum analog value 



**Returns:**

Value from 1000 to 2000 





        

<hr>



### function getValue [2/2]

_Gets normalized joystick position (1000 to 2000)._ 
```C++
inline signed short eva::Joystick::getValue () 
```





**Returns:**

Value from 1000 to 2000 





        

<hr>



### function setDeadZone 

_Sets dead-zone value._ 
```C++
inline void eva::Joystick::setDeadZone (
    short deadZone
) 
```





**Parameters:**


* `deadZone` dead-zone value 




        

<hr>



### function setTrim 

_Sets trim adjustment value._ 
```C++
inline void eva::Joystick::setTrim (
    short trim
) 
```





**Parameters:**


* `trim` Trim value 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaJoystick.h`

