

# Class eva::DelayTimer



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**DelayTimer**](classeva_1_1_delay_timer.md)



_One-shot timer that fires after a delay._ 

* `#include <evaDelayTimer.h>`



Inherits the following classes: [eva::Tickable](classeva_1_1_tickable.md)


Inherited by the following classes: [eva::CountdownTimer](classeva_1_1_countdown_timer.md),  [eva::RepeatTimer](classeva_1_1_repeat_timer.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DelayTimer**](#function-delaytimer-12) () <br>_Constructs a_ [_**DelayTimer**_](classeva_1_1_delay_timer.md) _with no listener._ |
|   | [**DelayTimer**](#function-delaytimer-22) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Constructs a_ [_**DelayTimer**_](classeva_1_1_delay_timer.md) _with a listener._ |
|  bool | [**isRunning**](#function-isrunning) () <br>_Checks if the timer is currently active._  |
|  [**DelayTimer**](classeva_1_1_delay_timer.md#function-delaytimer-12) \* | [**setListener**](#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Assigns or changes the event listener._  |
|  void | [**start**](#function-start-12) (unsigned short delay, [**IHandler**](classeva_1_1_i_handler.md) \* listener) <br>_Starts the timer._  |
|  void | [**start**](#function-start-22) (unsigned short delay) <br>_Starts the timer._  |
|  void | [**stop**](#function-stop) () <br>_Stops the timer._  |


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










## Protected Attributes

| Type | Name |
| ---: | :--- |
|  [**IHandler**](classeva_1_1_i_handler.md) \* | [**listener**](#variable-listener)  <br> |
|  unsigned long | [**nextFire**](#variable-nextfire)  <br> |
































## Protected Functions

| Type | Name |
| ---: | :--- |
|  bool | [**checkTimeElapsed**](#function-checktimeelapsed) () <br> |
| virtual void | [**tick**](#function-tick) () override<br> |








## Public Functions Documentation




### function DelayTimer [1/2]

_Constructs a_ [_**DelayTimer**_](classeva_1_1_delay_timer.md) _with no listener._
```C++
eva::DelayTimer::DelayTimer () 
```




<hr>



### function DelayTimer [2/2]

_Constructs a_ [_**DelayTimer**_](classeva_1_1_delay_timer.md) _with a listener._
```C++
eva::DelayTimer::DelayTimer (
    IHandler * listener
) 
```





**Parameters:**


* `listener` [**Handler**](classeva_1_1_handler.md) to invoke when timer expires 




        

<hr>



### function isRunning 

_Checks if the timer is currently active._ 
```C++
bool eva::DelayTimer::isRunning () 
```





**Returns:**

true if timer is running and will fire, false otherwise 





        

<hr>



### function setListener 

_Assigns or changes the event listener._ 
```C++
DelayTimer * eva::DelayTimer::setListener (
    IHandler * listener
) 
```





**Parameters:**


* `listener` Pointer to [**IHandler**](classeva_1_1_i_handler.md) implementation that will receive timer events 



**Returns:**

Pointer to this [**DelayTimer**](classeva_1_1_delay_timer.md) instance for method chaining 





        

<hr>



### function start [1/2]

_Starts the timer._ 
```C++
void eva::DelayTimer::start (
    unsigned short delay,
    IHandler * listener
) 
```





**Parameters:**


* `delay` Delay in milliseconds 
* `listener` [**Handler**](classeva_1_1_handler.md) to invoke when timer expires 




        

<hr>



### function start [2/2]

_Starts the timer._ 
```C++
void eva::DelayTimer::start (
    unsigned short delay
) 
```





**Parameters:**


* `delay` Delay in milliseconds

Listener must be assigned via constructor or [**setListener()**](classeva_1_1_delay_timer.md#function-setlistener). Use overloaded version with listener parameter if not pre-assigned. 


        

<hr>



### function stop 

_Stops the timer._ 
```C++
void eva::DelayTimer::stop () 
```




<hr>
## Protected Attributes Documentation




### variable listener 

```C++
IHandler* eva::DelayTimer::listener;
```




<hr>



### variable nextFire 

```C++
unsigned long eva::DelayTimer::nextFire;
```




<hr>
## Protected Functions Documentation




### function checkTimeElapsed 

```C++
bool eva::DelayTimer::checkTimeElapsed () 
```




<hr>



### function tick 

```C++
virtual void eva::DelayTimer::tick () override
```



Implements [*eva::Tickable::tick*](classeva_1_1_tickable.md#function-tick)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaDelayTimer.h`

