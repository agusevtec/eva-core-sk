

# Class eva::DelayTimer



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**DelayTimer**](classeva_1_1_delay_timer.md)



_One-shot timer that fires after a delay._ 

* `#include <evaDelayTimer.h>`



Inherits the following classes: [eva::Tickable](classeva_1_1_tickable.md)


Inherited by the following classes: [eva::RepeatTimer](classeva_1_1_repeat_timer.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DelayTimer**](#function-delaytimer) () <br> |
|  void | [**start**](#function-start) (unsigned delay, [**IHandler**](classeva_1_1_i_handler.md) \* listener=0) <br>_Starts the timer._  |
|  void | [**stop**](#function-stop) () <br>_Stops the timer._  |


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










## Protected Attributes

| Type | Name |
| ---: | :--- |
|  [**IHandler**](classeva_1_1_i_handler.md) \* | [**listener**](#variable-listener)  <br> |
|  unsigned long | [**nextFire**](#variable-nextfire)  <br> |
































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual short | [**tick**](#function-tick) () override<br> |








## Public Functions Documentation




### function DelayTimer 

```C++
eva::DelayTimer::DelayTimer () 
```




<hr>



### function start 

_Starts the timer._ 
```C++
void eva::DelayTimer::start (
    unsigned delay,
    IHandler * listener=0
) 
```





**Parameters:**


* `delay` Delay in milliseconds 
* `listener` [**Handler**](classeva_1_1_handler.md) to invoke when timer expires 




        

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




### function tick 

```C++
virtual short eva::DelayTimer::tick () override
```



Implements [*eva::Tickable::tick*](classeva_1_1_tickable.md#function-tick)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaDelayTimer.h`

