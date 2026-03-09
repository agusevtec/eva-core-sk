

# Class eva::CountdownIndicator



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**CountdownIndicator**](classeva_1_1_countdown_indicator.md)



[_**Indicator**_](classeva_1_1_indicator.md) _that blinks a specified number of times then notifies listener._

* `#include <evaCountdownIndicator.h>`



Inherits the following classes: [eva::BlinkingIndicator](classeva_1_1_blinking_indicator.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**on**](#function-on-13) (unsigned short period, unsigned short dutycyclePercent, unsigned char count, [**IHandler**](classeva_1_1_i_handler.md) \* listener=0) <br>_Starts countdown blinking._  |
|  void | [**on**](#function-on-23) () <br>_Turns on the indicator continuously._  |
|  void | [**on**](#function-on-33) (unsigned short period, unsigned char dutycyclePercent) <br>_Turns on the indicator with blinking pattern._  |


## Public Functions inherited from eva::BlinkingIndicator

See [eva::BlinkingIndicator](classeva_1_1_blinking_indicator.md)

| Type | Name |
| ---: | :--- |
|   | [**Indicator**](classeva_1_1_blinking_indicator.md#function-indicator) (unsigned pin, int activationLevel=HIGH) <br>_Constructor._  |
|  void | [**off**](classeva_1_1_blinking_indicator.md#function-off) () <br>_Turns off the indicator._  |
|  void | [**on**](classeva_1_1_blinking_indicator.md#function-on-12) () <br>_Turns on the indicator continuously._  |
|  void | [**on**](classeva_1_1_blinking_indicator.md#function-on-22) (unsigned short period, unsigned char dutycyclePercent) <br>_Turns on the indicator with blinking pattern._  |


## Public Functions inherited from eva::Indicator

See [eva::Indicator](classeva_1_1_indicator.md)

| Type | Name |
| ---: | :--- |
|   | [**Indicator**](classeva_1_1_indicator.md#function-indicator) (unsigned pin, int activationLevel=HIGH) <br>_Constructor._  |
|  void | [**off**](classeva_1_1_indicator.md#function-off) () <br>_Turns the indicator off._  |
|  void | [**on**](classeva_1_1_indicator.md#function-on) () <br>_Turns the indicator on._  |


## Public Functions inherited from eva::IHandler

See [eva::IHandler](classeva_1_1_i_handler.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**invoke**](classeva_1_1_i_handler.md#function-invoke) (void \* msgSender, long argsMask) = 0<br> |




























## Protected Attributes inherited from eva::BlinkingIndicator

See [eva::BlinkingIndicator](classeva_1_1_blinking_indicator.md)

| Type | Name |
| ---: | :--- |
|  unsigned char | [**dutycyclePercent**](classeva_1_1_blinking_indicator.md#variable-dutycyclepercent)  <br> |
|  [**DelayTimer**](classeva_1_1_delay_timer.md) | [**dutycycleTimer**](classeva_1_1_blinking_indicator.md#variable-dutycycletimer)  <br> |
|  [**DelayTimer**](classeva_1_1_delay_timer.md) | [**heartbeatTimer**](classeva_1_1_blinking_indicator.md#variable-heartbeattimer)  <br> |
|  unsigned short | [**period**](classeva_1_1_blinking_indicator.md#variable-period)  <br> |
































































## Protected Functions inherited from eva::BlinkingIndicator

See [eva::BlinkingIndicator](classeva_1_1_blinking_indicator.md)

| Type | Name |
| ---: | :--- |
|  void | [**startCycle**](classeva_1_1_blinking_indicator.md#function-startcycle) () <br> |














## Public Functions Documentation




### function on [1/3]

_Starts countdown blinking._ 
```C++
void eva::CountdownIndicator::on (
    unsigned short period,
    unsigned short dutycyclePercent,
    unsigned char count,
    IHandler * listener=0
) 
```





**Parameters:**


* `period` Blinking period in milliseconds 
* `dutycyclePercent` On-time percentage 
* `count` Number of blinks before stopping 
* `listener` [**Handler**](classeva_1_1_handler.md) to notify when countdown completes 




        

<hr>



### function on [2/3]

_Turns on the indicator continuously._ 
```C++
void eva::CountdownIndicator::on () 
```




<hr>



### function on [3/3]

_Turns on the indicator with blinking pattern._ 
```C++
void eva::CountdownIndicator::on (
    unsigned short period,
    unsigned char dutycyclePercent
) 
```





**Parameters:**


* `period` Blinking period in milliseconds 
* `dutycyclePercent` On-time percentage (0-100) 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaCountdownIndicator.h`

