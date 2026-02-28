

# Class eva::BlinkingIndicator



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**BlinkingIndicator**](classeva_1_1_blinking_indicator.md)



[_**Indicator**_](classeva_1_1_indicator.md) _that blinks with specified period and duty cycle._

* `#include <evaBlinkingIndicator.h>`



Inherits the following classes: [eva::Indicator](classeva_1_1_indicator.md),  [eva::IHandler](classeva_1_1_i_handler.md)


Inherited by the following classes: [eva::CountdownIndicator](classeva_1_1_countdown_indicator.md)








































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Indicator**](#function-indicator) (unsigned pin, int activationLevel=HIGH) <br>_Constructor._  |
|  void | [**off**](#function-off) () <br>_Turns off the indicator._  |
|  void | [**on**](#function-on-12) () <br>_Turns on the indicator continuously._  |
|  void | [**on**](#function-on-22) (unsigned short period, unsigned char dutycyclePercent) <br>_Turns on the indicator with blinking pattern._  |


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




















## Protected Attributes

| Type | Name |
| ---: | :--- |
|  unsigned char | [**dutycyclePercent**](#variable-dutycyclepercent)  <br> |
|  [**DelayTimer**](classeva_1_1_delay_timer.md) | [**dutycycleTimer**](#variable-dutycycletimer)  <br> |
|  [**DelayTimer**](classeva_1_1_delay_timer.md) | [**heartbeatTimer**](#variable-heartbeattimer)  <br> |
|  unsigned short | [**period**](#variable-period)  <br> |
















































## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**startCycle**](#function-startcycle) () <br> |












## Public Functions Documentation




### function Indicator 

_Constructor._ 
```C++
eva::BlinkingIndicator::Indicator (
    unsigned pin,
    int activationLevel=HIGH
) 
```





**Parameters:**


* `pin` Arduino pin number 
* `activationLevel` Level that turns indicator on (LOW, HIGH, or PWM value) 




        

<hr>



### function off 

_Turns off the indicator._ 
```C++
void eva::BlinkingIndicator::off () 
```




<hr>



### function on [1/2]

_Turns on the indicator continuously._ 
```C++
void eva::BlinkingIndicator::on () 
```




<hr>



### function on [2/2]

_Turns on the indicator with blinking pattern._ 
```C++
void eva::BlinkingIndicator::on (
    unsigned short period,
    unsigned char dutycyclePercent
) 
```





**Parameters:**


* `period` Blinking period in milliseconds 
* `dutycyclePercent` On-time percentage (0-100) 




        

<hr>
## Protected Attributes Documentation




### variable dutycyclePercent 

```C++
unsigned char eva::BlinkingIndicator::dutycyclePercent;
```




<hr>



### variable dutycycleTimer 

```C++
DelayTimer eva::BlinkingIndicator::dutycycleTimer;
```




<hr>



### variable heartbeatTimer 

```C++
DelayTimer eva::BlinkingIndicator::heartbeatTimer;
```




<hr>



### variable period 

```C++
unsigned short eva::BlinkingIndicator::period;
```




<hr>
## Protected Functions Documentation




### function startCycle 

```C++
void eva::BlinkingIndicator::startCycle () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/Общий/Desktop/eva-core-sk/src/evaBlinkingIndicator.h`

