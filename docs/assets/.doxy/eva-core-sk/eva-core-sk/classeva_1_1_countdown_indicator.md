

# Class eva::CountdownIndicator



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**CountdownIndicator**](classeva_1_1_countdown_indicator.md)



[_**Indicator**_](classeva_1_1_indicator.md) _that blinks a specified number of times then notifies listener._[More...](#detailed-description)

* `#include <evaCountdownIndicator.h>`



Inherits the following classes: [eva::BlinkingIndicator](classeva_1_1_blinking_indicator.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**on**](#function-on-14) (unsigned short period, unsigned char dutycyclePercent, unsigned char count) <br>_Starts countdown blinking._  |
|  void | [**on**](#function-on-24) (unsigned short period, unsigned char dutycyclePercent, unsigned char count, [**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Starts countdown blinking._  |
|  void | [**on**](#function-on-34) () <br>_Turns on the indicator continuously._  |
|  void | [**on**](#function-on-44) (unsigned short period, unsigned char dutycyclePercent) <br>_Turns on the indicator with blinking pattern._  |
|  [**CountdownIndicator**](classeva_1_1_countdown_indicator.md) \* | [**setListener**](#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Assigns or changes the event listener._  |


## Public Functions inherited from eva::BlinkingIndicator

See [eva::BlinkingIndicator](classeva_1_1_blinking_indicator.md)

| Type | Name |
| ---: | :--- |
|   | [**Indicator**](classeva_1_1_blinking_indicator.md#function-indicator) (unsigned pin, int activationLevel=HIGH) <br>_Constructs a_ [_**BlinkingIndicator**_](classeva_1_1_blinking_indicator.md) _._ |
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
| virtual void | [**invoke**](classeva_1_1_i_handler.md#function-invoke) (void \* msgSender, [**CallbackInfo**](structeva_1_1_callback_info.md) cbInfo) = 0<br> |




























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














## Detailed Description


Note: This class serves as a demonstration of library concepts and is intentionally kept simple for clarity. Performance optimization was not the primary focus. It is recommended for prototyping stages to validate your application logic. For production use with strict timing requirements, consider implementing a custom solution based on your specific needs. 


    
## Public Functions Documentation




### function on [1/4]

_Starts countdown blinking._ 
```C++
void eva::CountdownIndicator::on (
    unsigned short period,
    unsigned char dutycyclePercent,
    unsigned char count
) 
```





**Parameters:**


* `period` Blinking period in milliseconds 
* `dutycyclePercent` On-time percentage 
* `count` Number of blinks before stopping 




        

<hr>



### function on [2/4]

_Starts countdown blinking._ 
```C++
void eva::CountdownIndicator::on (
    unsigned short period,
    unsigned char dutycyclePercent,
    unsigned char count,
    IHandler * listener
) 
```





**Parameters:**


* `period` Blinking period in milliseconds 
* `dutycyclePercent` On-time percentage 
* `count` Number of blinks before stopping 
* `listener` [**Handler**](classeva_1_1_handler.md) to notify when countdown completes 




        

<hr>



### function on [3/4]

_Turns on the indicator continuously._ 
```C++
void eva::CountdownIndicator::on () 
```




<hr>



### function on [4/4]

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



### function setListener 

_Assigns or changes the event listener._ 
```C++
CountdownIndicator * eva::CountdownIndicator::setListener (
    IHandler * listener
) 
```





**Parameters:**


* `listener` Pointer to [**IHandler**](classeva_1_1_i_handler.md) implementation that will receive timer events 



**Returns:**

Pointer to this [**DelayTimer**](classeva_1_1_delay_timer.md) instance for method chaining 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaCountdownIndicator.h`

