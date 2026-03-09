

# Class eva::Toggle

**template &lt;class READER&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Toggle**](classeva_1_1_toggle.md)



[_**Toggle**_](classeva_1_1_toggle.md) _- легковесная версия_[_**Button**_](classeva_1_1_button.md) _без детекции кликов_[More...](#detailed-description)

* `#include <evaToggle.h>`



Inherits the following classes: READER,  [eva::Tickable](classeva_1_1_tickable.md)


Inherited by the following classes: [eva::Button](classeva_1_1_button.md),  [eva::Button](classeva_1_1_button.md),  [eva::Button](classeva_1_1_button.md),  [eva::Button](classeva_1_1_button.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Toggle**](#function-toggle-12) () <br> |
|   | [**Toggle**](#function-toggle-22) ([**IHandler**](classeva_1_1_i_handler.md) \* listener, unsigned short eventMask) <br> |
|  Toggle \* | [**enable**](#function-enable) (bool enabled) <br>_Enables or disables the toggle._  |
|  signed short | [**getValue**](#function-getvalue) () <br>_Gets the button level code identifying which button was pressed._  |
|  Toggle \* | [**setListener**](#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener, unsigned short eventMask) <br>_Sets the Listener for switch events._  |


## Public Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|   | [**Tickable**](classeva_1_1_tickable.md#function-tickable) () <br> |
|  void | [**tac**](classeva_1_1_tickable.md#function-tac) () <br>_Triggers tick on this and all linked tickables._  |
|   | [**~Tickable**](classeva_1_1_tickable.md#function-tickable) () <br> |




## Public Static Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|  Tickable \* | [**chain**](classeva_1_1_tickable.md#function-chain) () <br>_Gets or sets the head of the tickable chain._  |










## Protected Attributes

| Type | Name |
| ---: | :--- |
|  bool | [**isEnabled**](#variable-isenabled)   = `true`<br> |
|  unsigned char | [**levelCode**](#variable-levelcode)   = `0`<br> |
|  [**IHandler**](classeva_1_1_i_handler.md) \* | [**listener**](#variable-listener)   = `nullptr`<br> |
































## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**notify**](#function-notify) (unsigned short eventTypeMask) <br> |
| virtual void | [**tick**](#function-tick) () override<br> |








## Detailed Description


Отличается от [**Button**](classeva_1_1_button.md):
* Не хранит pressTime (экономия 4 байта!)




Идеально для:
* Тумблеров
* Концевых выключателей
* Герконов
* Датчиков движения 




    
## Public Functions Documentation




### function Toggle [1/2]

```C++
inline eva::Toggle::Toggle () 
```




<hr>



### function Toggle [2/2]

```C++
inline eva::Toggle::Toggle (
    IHandler * listener,
    unsigned short eventMask
) 
```




<hr>



### function enable 

_Enables or disables the toggle._ 
```C++
inline Toggle * eva::Toggle::enable (
    bool enabled
) 
```





**Parameters:**


* `enabled` True to enable, false to disable 



**Returns:**

Pointer to this 





        

<hr>



### function getValue 

_Gets the button level code identifying which button was pressed._ 
```C++
inline signed short eva::Toggle::getValue () 
```





**Returns:**

Level code (0 for no button, &gt;0 for specific button) 





        

<hr>



### function setListener 

_Sets the Listener for switch events._ 
```C++
inline Toggle * eva::Toggle::setListener (
    IHandler * listener,
    unsigned short eventMask
) 
```





**Parameters:**


* `listener` - callback method 
* `eventMask` - ON\_ACTIVE, ON\_INACTIVE, ON\_CHANGE 




        

<hr>
## Protected Attributes Documentation




### variable isEnabled 

```C++
bool eva::Toggle< READER >::isEnabled;
```




<hr>



### variable levelCode 

```C++
unsigned char eva::Toggle< READER >::levelCode;
```




<hr>



### variable listener 

```C++
IHandler* eva::Toggle< READER >::listener;
```




<hr>
## Protected Functions Documentation




### function notify 

```C++
inline void eva::Toggle::notify (
    unsigned short eventTypeMask
) 
```




<hr>



### function tick 

```C++
inline virtual void eva::Toggle::tick () override
```



Implements [*eva::Tickable::tick*](classeva_1_1_tickable.md#function-tick)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaToggle.h`

