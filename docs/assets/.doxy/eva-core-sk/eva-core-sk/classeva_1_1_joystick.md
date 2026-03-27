

# Class eva::Joystick

**template &lt;class READER, unsigned short MIN\_POS, unsigned short MIDDLE\_POS, unsigned short MAX\_POS&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Joystick**](classeva_1_1_joystick.md)



[_**Joystick**_](classeva_1_1_joystick.md) _axis reader (range 1000-1500-2000) with trim adjustment._[More...](#detailed-description)

* `#include <evaJoystick.h>`



Inherits the following classes: READER


































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**addTrim**](#function-addtrim) (short trimIncrement) <br>_adds trim adjustment value_  |
|  signed short | [**getDeadZone**](#function-getdeadzone) () <br>_Gets current deadZone value._  |
|  signed short | [**getTrim**](#function-gettrim) () <br>_Gets current trim value._  |
|  signed short | [**getValue**](#function-getvalue) () <br>_Gets normalized joystick position (1000 to 2000)._  |
|  void | [**setDeadZone**](#function-setdeadzone) (short deadZone) <br> |
|  void | [**setTrim**](#function-settrim) (short trim) <br>_Sets trim adjustment value._  |




























## Detailed Description




**Template parameters:**


* `READER` Underlying reader type 
* `MIN_POS` Minimum analog value 
* `MIDDLE_POS` Center value 
* `MAX_POS` Maximum analog value 




    
## Public Functions Documentation




### function addTrim 

_adds trim adjustment value_ 
```C++
inline void eva::Joystick::addTrim (
    short trimIncrement
) 
```





**Parameters:**


* `trim` Trim value 




        

<hr>



### function getDeadZone 

_Gets current deadZone value._ 
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

deadZone value 





        

<hr>



### function getValue 

_Gets normalized joystick position (1000 to 2000)._ 
```C++
inline signed short eva::Joystick::getValue () 
```





**Returns:**

Signed char value 





        

<hr>



### function setDeadZone 

```C++
inline void eva::Joystick::setDeadZone (
    short deadZone
) 
```




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

