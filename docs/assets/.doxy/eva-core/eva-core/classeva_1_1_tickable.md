

# Class eva::Tickable



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Tickable**](classeva_1_1_tickable.md)



_Base class for objects that need periodic updates._ 

* `#include <evaTickable.h>`





Inherited by the following classes: [eva::Toggle](classeva_1_1_toggle.md),  [eva::Toggle](classeva_1_1_toggle.md),  [eva::DelayTimer](classeva_1_1_delay_timer.md),  [eva::Toggle](classeva_1_1_toggle.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Tickable**](#function-tickable) () <br> |
|  unsigned long | [**millis**](#function-millis) () <br> |
|  void | [**tac**](#function-tac) () <br>_Triggers tick on this and all linked tickables._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  Tickable \* | [**chain**](#function-chain) (Tickable \* mount=0) <br>_Gets or sets the head of the tickable chain._  |


























## Public Functions Documentation




### function Tickable 

```C++
eva::Tickable::Tickable () 
```




<hr>



### function millis 

```C++
inline unsigned long eva::Tickable::millis () 
```




<hr>



### function tac 

_Triggers tick on this and all linked tickables._ 
```C++
void eva::Tickable::tac () 
```




<hr>
## Public Static Functions Documentation




### function chain 

_Gets or sets the head of the tickable chain._ 
```C++
static Tickable * eva::Tickable::chain (
    Tickable * mount=0
) 
```





**Parameters:**


* `mount` If provided, adds to chain; if null, returns chain head 



**Returns:**

Head of chain 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaTickable.h`

