

# Class eva::Tickable



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Tickable**](classeva_1_1_tickable.md)



_Base class for objects that need periodic updates._ 

* `#include <evaTickable.h>`





Inherited by the following classes: [eva::Switch](classeva_1_1_switch.md),  [eva::Switch](classeva_1_1_switch.md),  [eva::DelayTimer](classeva_1_1_delay_timer.md),  [eva::Switch](classeva_1_1_switch.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Tickable**](#function-tickable) () <br> |
|  void | [**tac**](#function-tac) () <br>_Triggers tick on this and all linked tickables._  |
| virtual  | [**~Tickable**](#function-tickable) () <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  Tickable \* | [**chain**](#function-chain) () <br>_Gets or sets the head of the tickable chain._  |


























## Public Functions Documentation




### function Tickable 

```C++
eva::Tickable::Tickable () 
```




<hr>



### function tac 

_Triggers tick on this and all linked tickables._ 
```C++
void eva::Tickable::tac () 
```




<hr>



### function ~Tickable 

```C++
virtual eva::Tickable::~Tickable () 
```




<hr>
## Public Static Functions Documentation




### function chain 

_Gets or sets the head of the tickable chain._ 
```C++
static Tickable * eva::Tickable::chain () 
```





**Returns:**

Head of chain 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaTickable.h`

