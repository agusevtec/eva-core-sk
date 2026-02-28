

# Class eva::RepeatTimer



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**RepeatTimer**](classeva_1_1_repeat_timer.md)



_Timer that fires repeatedly at fixed intervals._ 

* `#include <evaRepeatTimer.h>`



Inherits the following classes: [eva::DelayTimer](classeva_1_1_delay_timer.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DelayTimer**](#function-delaytimer) () <br> |
|   | [**RepeatTimer**](#function-repeattimer) (unsigned period, [**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Constructor that starts the timer._  |
|  void | [**start**](#function-start) (unsigned period, [**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Starts or restarts the repeating timer._  |


## Public Functions inherited from eva::DelayTimer

See [eva::DelayTimer](classeva_1_1_delay_timer.md)

| Type | Name |
| ---: | :--- |
|   | [**DelayTimer**](classeva_1_1_delay_timer.md#function-delaytimer) () <br> |
|  void | [**start**](classeva_1_1_delay_timer.md#function-start) (unsigned delay, [**IHandler**](classeva_1_1_i_handler.md) \* listener=0) <br>_Starts the timer._  |
|  void | [**stop**](classeva_1_1_delay_timer.md#function-stop) () <br>_Stops the timer._  |


## Public Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|   | [**Tickable**](classeva_1_1_tickable.md#function-tickable) () <br> |
|  void | [**tac**](classeva_1_1_tickable.md#function-tac) () <br>_Triggers tick on this and all linked tickables._  |






## Public Static Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|  Tickable \* | [**chain**](classeva_1_1_tickable.md#function-chain) (Tickable \* mount=0) <br>_Gets or sets the head of the tickable chain._  |
















## Protected Attributes inherited from eva::DelayTimer

See [eva::DelayTimer](classeva_1_1_delay_timer.md)

| Type | Name |
| ---: | :--- |
|  [**IHandler**](classeva_1_1_i_handler.md) \* | [**listener**](classeva_1_1_delay_timer.md#variable-listener)  <br> |
|  unsigned long | [**nextFire**](classeva_1_1_delay_timer.md#variable-nextfire)  <br> |
















































## Protected Functions inherited from eva::DelayTimer

See [eva::DelayTimer](classeva_1_1_delay_timer.md)

| Type | Name |
| ---: | :--- |
| virtual short | [**tick**](classeva_1_1_delay_timer.md#function-tick) () override<br> |










## Public Functions Documentation




### function DelayTimer 

```C++
eva::RepeatTimer::DelayTimer () 
```




<hr>



### function RepeatTimer 

_Constructor that starts the timer._ 
```C++
eva::RepeatTimer::RepeatTimer (
    unsigned period,
    IHandler * listener
) 
```





**Parameters:**


* `period` Interval in milliseconds 
* `listener` [**Handler**](classeva_1_1_handler.md) to invoke on each tick 




        

<hr>



### function start 

_Starts or restarts the repeating timer._ 
```C++
void eva::RepeatTimer::start (
    unsigned period,
    IHandler * listener
) 
```





**Parameters:**


* `period` Interval in milliseconds 
* `listener` [**Handler**](classeva_1_1_handler.md) to invoke on each tick 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/Общий/Desktop/eva-core-sk/src/evaRepeatTimer.h`

