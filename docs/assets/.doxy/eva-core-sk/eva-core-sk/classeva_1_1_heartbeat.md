

# Class eva::Heartbeat



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Heartbeat**](classeva_1_1_heartbeat.md)



_Base class for components that need periodic updates._ [More...](#detailed-description)

* `#include <evaHeartbeat.h>`



Inherits the following classes: [eva::Tickable](classeva_1_1_tickable.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Heartbeat**](#function-heartbeat) (unsigned long periodMs) <br>_Constructor with fixed period._  |
|  unsigned long | [**getPeriod**](#function-getperiod) () const<br>_Get the heartbeat period._  |
| virtual void | [**tick**](#function-tick) () override<br>_Update method - call this regularly from main loop. Checks if period has elapsed and calls_ [_**onHeartbeat()**_](classeva_1_1_heartbeat.md#function-onheartbeat) _if needed._ |
| virtual  | [**~Heartbeat**](#function-heartbeat) () = default<br>_Virtual destructor._  |


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










































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**onHeartbeat**](#function-onheartbeat) () = 0<br>_Virtual method to be overridden by derived classes. Called at each heartbeat interval._  |








## Detailed Description


Provides a simple heartbeat mechanism with fixed period. Derived classes must implement [**onHeartbeat()**](classeva_1_1_heartbeat.md#function-onheartbeat) which will be called at regular intervals.


The period is set at construction and cannot be changed (immutable). 


    
## Public Functions Documentation




### function Heartbeat 

_Constructor with fixed period._ 
```C++
eva::Heartbeat::Heartbeat (
    unsigned long periodMs
) 
```





**Parameters:**


* `periodMs` [**Heartbeat**](classeva_1_1_heartbeat.md) period in milliseconds. 




        

<hr>



### function getPeriod 

_Get the heartbeat period._ 
```C++
unsigned long eva::Heartbeat::getPeriod () const
```





**Returns:**

Period in milliseconds (immutable). 





        

<hr>



### function tick 

_Update method - call this regularly from main loop. Checks if period has elapsed and calls_ [_**onHeartbeat()**_](classeva_1_1_heartbeat.md#function-onheartbeat) _if needed._
```C++
virtual void eva::Heartbeat::tick () override
```



Implements [*eva::Tickable::tick*](classeva_1_1_tickable.md#function-tick)


<hr>



### function ~Heartbeat 

_Virtual destructor._ 
```C++
virtual eva::Heartbeat::~Heartbeat () = default
```




<hr>
## Protected Functions Documentation




### function onHeartbeat 

_Virtual method to be overridden by derived classes. Called at each heartbeat interval._ 
```C++
virtual void eva::Heartbeat::onHeartbeat () = 0
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaHeartbeat.h`

