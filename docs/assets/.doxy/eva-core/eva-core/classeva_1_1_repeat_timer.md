

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
|  [**RepeatTimer**](classeva_1_1_repeat_timer.md#function-repeattimer) \* | [**setListener**](#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br> |
|  [**RepeatTimer**](classeva_1_1_repeat_timer.md#function-repeattimer) \* | [**setPeriod**](#function-setperiod) (unsigned short period) <br> |
|  void | [**start**](#function-start-13) (unsigned short period, [**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Starts or restarts the repeating timer._  |
|  void | [**start**](#function-start-23) (unsigned short period) <br> |
|  void | [**start**](#function-start-33) () <br> |


## Public Functions inherited from eva::DelayTimer

See [eva::DelayTimer](classeva_1_1_delay_timer.md)

| Type | Name |
| ---: | :--- |
|   | [**DelayTimer**](classeva_1_1_delay_timer.md#function-delaytimer-12) () <br> |
|   | [**DelayTimer**](classeva_1_1_delay_timer.md#function-delaytimer-22) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br> |
|  bool | [**isRunning**](classeva_1_1_delay_timer.md#function-isrunning) () <br> |
|  DelayTimer \* | [**setListener**](classeva_1_1_delay_timer.md#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br> |
|  void | [**start**](classeva_1_1_delay_timer.md#function-start-12) (unsigned short delay, [**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Starts the timer._  |
|  void | [**start**](classeva_1_1_delay_timer.md#function-start-22) (unsigned short delay) <br> |
|  void | [**stop**](classeva_1_1_delay_timer.md#function-stop) () <br>_Stops the timer._  |


## Public Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|   | [**Tickable**](classeva_1_1_tickable.md#function-tickable) () <br> |
|  void | [**tac**](classeva_1_1_tickable.md#function-tac) () <br>_Triggers tick on this and all linked tickables._  |
| virtual  | [**~Tickable**](classeva_1_1_tickable.md#function-tickable) () <br> |






## Public Static Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|  Tickable \* | [**chain**](classeva_1_1_tickable.md#function-chain) () <br>_Gets or sets the head of the tickable chain._  |
















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

```C++
RepeatTimer * eva::RepeatTimer::setListener (
    IHandler * listener
) 
```




<hr>



### function setPeriod 

```C++
RepeatTimer * eva::RepeatTimer::setPeriod (
    unsigned short period
) 
```




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

```C++
void eva::RepeatTimer::start (
    unsigned short period
) 
```




<hr>



### function start [3/3]

```C++
void eva::RepeatTimer::start () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaRepeatTimer.h`

