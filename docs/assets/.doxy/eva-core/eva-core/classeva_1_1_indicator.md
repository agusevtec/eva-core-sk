

# Class eva::Indicator



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Indicator**](classeva_1_1_indicator.md)



_Basic indicator (LED) control._ 

* `#include <evaIndicator.h>`





Inherited by the following classes: [eva::BlinkingIndicator](classeva_1_1_blinking_indicator.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Indicator**](#function-indicator) (unsigned pin, int activationLevel=HIGH) <br>_Constructor._  |
|  void | [**off**](#function-off) () <br>_Turns the indicator off._  |
|  void | [**on**](#function-on) () <br>_Turns the indicator on._  |




























## Public Functions Documentation




### function Indicator 

_Constructor._ 
```C++
eva::Indicator::Indicator (
    unsigned pin,
    int activationLevel=HIGH
) 
```





**Parameters:**


* `pin` Arduino pin number 
* `activationLevel` Level that turns indicator on (LOW, HIGH, or PWM value) 




        

<hr>



### function off 

_Turns the indicator off._ 
```C++
void eva::Indicator::off () 
```




<hr>



### function on 

_Turns the indicator on._ 
```C++
void eva::Indicator::on () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaIndicator.h`

