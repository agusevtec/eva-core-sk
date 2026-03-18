

# Class eva::RepeatTimer



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**RepeatTimer**](classeva_1_1_repeat_timer.md)



_Timer that fires repeatedly at fixed intervals._ 

* `#include <evaRepeatTimer.h>`



Inherits the following classes: [eva::DelayTimer](classeva_1_1_delay_timer.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DelayTimer**](#function-delaytimer-12) () <br> |
|   | [**DelayTimer**](#function-delaytimer-22) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br> |
|   | [**RepeatTimer**](#function-repeattimer) (unsigned short period, [**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Constructor that starts the timer._  |
|  [**RepeatTimer**](classeva_1_1_repeat_timer.md#function-repeattimer) \* | [**setListener**](#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Assigns or changes the event listener._  |
|  [**RepeatTimer**](classeva_1_1_repeat_timer.md#function-repeattimer) \* | [**setPeriod**](#function-setperiod) (unsigned short period) <br>_Changes the timer period._  |
|  void | [**start**](#function-start-13) (unsigned short period, [**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Starts or restarts the repeating timer._  |
|  void | [**start**](#function-start-23) (unsigned short period) <br>_Starts or restarts the countdown timer._  |
|  void | [**start**](#function-start-33) () <br>_Starts or restarts the countdown timer._  |


## Public Functions inherited from eva::DelayTimer

See [eva::DelayTimer](classeva_1_1_delay_timer.md)

| Type | Name |
| ---: | :--- |
|   | [**DelayTimer**](classeva_1_1_delay_timer.md#function-delaytimer-12) () <br> |
|   | [**DelayTimer**](classeva_1_1_delay_timer.md#function-delaytimer-22) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br> |
|  bool | [**isRunning**](classeva_1_1_delay_timer.md#function-isrunning) () <br>_Checks if the timer is currently active._  |
|  DelayTimer \* | [**setListener**](classeva_1_1_delay_timer.md#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Assigns or changes the event listener._  |
|  void | [**start**](classeva_1_1_delay_timer.md#function-start-12) (unsigned short delay, [**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Starts the timer._  |
|  void | [**start**](classeva_1_1_delay_timer.md#function-start-22) (unsigned short delay) <br>_Starts the timer._  |
|  void | [**stop**](classeva_1_1_delay_timer.md#function-stop) () <br>_Stops the timer._  |


## Public Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|   | [**Tickable**](classeva_1_1_tickable.md#function-tickable-13) () <br> |
|   | [**Tickable**](classeva_1_1_tickable.md#function-tickable-23) (const Tickable &) = delete<br> |
|   | [**Tickable**](classeva_1_1_tickable.md#function-tickable-33) (Tickable &&) = delete<br> |
|  Tickable & | [**operator=**](classeva_1_1_tickable.md#function-operator) (const Tickable &) = delete<br> |
|  Tickable & | [**operator=**](classeva_1_1_tickable.md#function-operator_1) (Tickable &&) = delete<br> |
| virtual  | [**~Tickable**](classeva_1_1_tickable.md#function-tickable) () <br> |






## Public Static Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|  void | [**tac**](classeva_1_1_tickable.md#function-tac) () <br>_Triggers tick on this and all linked tickables._  |
















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
|  bool | [**checkTimeElapsed**](classeva_1_1_delay_timer.md#function-checktimeelapsed) () <br> |
| virtual void | [**tick**](classeva_1_1_delay_timer.md#function-tick) () override<br> |










## Public Functions Documentation




### function DelayTimer [1/2]

```C++
eva::RepeatTimer::DelayTimer () 
```




<hr>



### function DelayTimer [2/2]

```C++
eva::RepeatTimer::DelayTimer (
    IHandler * listener
) 
```




<hr>



### function RepeatTimer 

_Constructor that starts the timer._ 
```C++
eva::RepeatTimer::RepeatTimer (
    unsigned short period,
    IHandler * listener
) 
```





**Parameters:**


* `period` Interval in milliseconds 
* `listener` [**Handler**](classeva_1_1_handler.md) to invoke on each tick 




        

<hr>



### function setListener 

_Assigns or changes the event listener._ 
```C++
RepeatTimer * eva::RepeatTimer::setListener (
    IHandler * listener
) 
```





**Parameters:**


* `listener` Pointer to [**IHandler**](classeva_1_1_i_handler.md) implementation that will receive timer events 



**Returns:**

Pointer to this [**RepeatTimer**](classeva_1_1_repeat_timer.md) instance for method chaining 





        

<hr>



### function setPeriod 

_Changes the timer period._ 
```C++
RepeatTimer * eva::RepeatTimer::setPeriod (
    unsigned short period
) 
```





**Parameters:**


* `period` New interval in milliseconds 



**Returns:**

Pointer to this [**RepeatTimer**](classeva_1_1_repeat_timer.md) instance for method chaining 





        

<hr>



### function start [1/3]

_Starts or restarts the repeating timer._ 
```C++
void eva::RepeatTimer::start (
    unsigned short period,
    IHandler * listener
) 
```





**Parameters:**


* `period` Interval in milliseconds 
* `listener` [**Handler**](classeva_1_1_handler.md) to invoke on each tick 




        

<hr>



### function start [2/3]

_Starts or restarts the countdown timer._ 
```C++
void eva::RepeatTimer::start (
    unsigned short period
) 
```





**Parameters:**


* `period` Interval in milliseconds

Listener must be assigned via constructor or [**setListener()**](classeva_1_1_repeat_timer.md#function-setlistener). Use overloaded version with listener parameter if not pre-assigned. 


        

<hr>



### function start [3/3]

_Starts or restarts the countdown timer._ 
```C++
void eva::RepeatTimer::start () 
```





**Parameters:**


* `period` Interval in milliseconds

Listener and period must be assigned via constructor or [**setListener()**](classeva_1_1_repeat_timer.md#function-setlistener) and [**setPeriod()**](classeva_1_1_repeat_timer.md#function-setperiod). Use overloaded versions if not pre-assigned. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaRepeatTimer.h`

