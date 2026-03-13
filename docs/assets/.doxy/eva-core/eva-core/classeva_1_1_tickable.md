

# Class eva::Tickable



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Tickable**](classeva_1_1_tickable.md)



_Base class for objects that need periodic updates._ 

* `#include <evaTickable.h>`





Inherited by the following classes: [eva::Switch](classeva_1_1_switch.md),  [eva::Switch](classeva_1_1_switch.md),  [eva::DelayTimer](classeva_1_1_delay_timer.md),  [eva::Switch](classeva_1_1_switch.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Tickable**](#function-tickable-13) () <br> |
|   | [**Tickable**](#function-tickable-23) (const Tickable &) = delete<br> |
|   | [**Tickable**](#function-tickable-33) (Tickable &&) = delete<br> |
|  Tickable & | [**operator=**](#function-operator) (const Tickable &) = delete<br> |
|  Tickable & | [**operator=**](#function-operator_1) (Tickable &&) = delete<br> |
| virtual  | [**~Tickable**](#function-tickable) () <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**tac**](#function-tac) () <br>_Triggers tick on this and all linked tickables._  |


























## Public Functions Documentation




### function Tickable [1/3]

```C++
eva::Tickable::Tickable () 
```




<hr>



### function Tickable [2/3]

```C++
eva::Tickable::Tickable (
    const Tickable &
) = delete
```




<hr>



### function Tickable [3/3]

```C++
eva::Tickable::Tickable (
    Tickable &&
) = delete
```




<hr>



### function operator= 

```C++
Tickable & eva::Tickable::operator= (
    const Tickable &
) = delete
```




<hr>



### function operator= 

```C++
Tickable & eva::Tickable::operator= (
    Tickable &&
) = delete
```




<hr>



### function ~Tickable 

```C++
virtual eva::Tickable::~Tickable () 
```




<hr>
## Public Static Functions Documentation




### function tac 

_Triggers tick on this and all linked tickables._ 
```C++
static void eva::Tickable::tac () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaTickable.h`

