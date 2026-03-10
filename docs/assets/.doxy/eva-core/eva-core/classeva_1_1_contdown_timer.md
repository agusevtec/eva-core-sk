

# Class eva::ContdownTimer



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**ContdownTimer**](classeva_1_1_contdown_timer.md)



_Timer that fires repeatedly at fixed intervals._ 

* `#include <evaCountdownTimer.h>`



Inherits the following classes: [eva::DelayTimer](classeva_1_1_delay_timer.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DelayTimer**](#function-delaytimer-12) () <br> |
|   | [**DelayTimer**](#function-delaytimer-22) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br> |
|  [**ContdownTimer**](classeva_1_1_contdown_timer.md) \* | [**setListener**](#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener) <br> |
|  void | [**start**](#function-start-12) (unsigned short period, unsigned short count, [**IHandler**](classeva_1_1_i_handler.md) \* listener=nullptr) <br>_Starts or restarts the repeating timer._  |
|  void | [**start**](#function-start-22) (unsigned short period, unsigned short count) <br> |


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
eva::ContdownTimer::DelayTimer () 
```




<hr>



### function DelayTimer [2/2]

```C++
eva::ContdownTimer::DelayTimer (
    IHandler * listener
) 
```




<hr>



### function setListener 

```C++
ContdownTimer * eva::ContdownTimer::setListener (
    IHandler * listener
) 
```




<hr>



### function start [1/2]

_Starts or restarts the repeating timer._ 
```C++
void eva::ContdownTimer::start (
    unsigned short period,
    unsigned short count,
    IHandler * listener=nullptr
) 
```





**Parameters:**


* `period` Interval in milliseconds 
* `listener` [**Handler**](classeva_1_1_handler.md) to invoke on each tick 




        

<hr>



### function start [2/2]

```C++
void eva::ContdownTimer::start (
    unsigned short period,
    unsigned short count
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaCountdownTimer.h`

