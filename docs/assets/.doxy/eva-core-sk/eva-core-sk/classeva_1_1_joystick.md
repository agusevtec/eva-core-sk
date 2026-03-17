

# Class eva::Joystick

**template &lt;class READER, int MIN, int MIDDLE, int MAX&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Joystick**](classeva_1_1_joystick.md)



[_**Joystick**_](classeva_1_1_joystick.md) _axis reader with trim adjustment._[More...](#detailed-description)

* `#include <evaJoystick.h>`



Inherits the following classes: READER


































## Public Functions

| Type | Name |
| ---: | :--- |
|  signed short | [**getTrim**](#function-gettrim) () <br>_Gets current trim value._  |
|  signed char | [**getValue**](#function-getvalue) () <br>_Gets normalized joystick position (-127 to 127)._  |
|  void | [**setTrim**](#function-settrim) (short trim) <br>_Sets trim adjustment value._  |




























## Detailed Description




**Template parameters:**


* `READER` Underlying reader type 
* `MIN` Minimum analog value 
* `MIDDLE` Center value 
* `MAX` Maximum analog value 




    
## Public Functions Documentation




### function getTrim 

_Gets current trim value._ 
```C++
inline signed short eva::Joystick::getTrim () 
```





**Returns:**

Trim value 





        

<hr>



### function getValue 

_Gets normalized joystick position (-127 to 127)._ 
```C++
inline signed char eva::Joystick::getValue () 
```





**Returns:**

Signed char value 





        

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

