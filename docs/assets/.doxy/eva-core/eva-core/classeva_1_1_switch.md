

# Class eva::Switch

**template &lt;class READER&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Switch**](classeva_1_1_switch.md)



_Universal switch/button class for multi-valued input sources._ [More...](#detailed-description)

* `#include <evaSwitch.h>`



Inherits the following classes: READER,  [eva::Tickable](classeva_1_1_tickable.md)


Inherited by the following classes: [eva::Button](classeva_1_1_button.md),  [eva::Button](classeva_1_1_button.md),  [eva::Button](classeva_1_1_button.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Switch**](#function-switch-12) () <br> |
|   | [**Switch**](#function-switch-22) ([**IHandler**](classeva_1_1_i_handler.md) \* listener, unsigned short eventMask) <br> |
|  Switch \* | [**enable**](#function-enable) (bool enabled) <br>_Enables or disables the switch._  |
|  signed short | [**getValue**](#function-getvalue) () <br>_Gets the current level code._  |
|  Switch \* | [**setListener**](#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener, unsigned short eventMask) <br>_Sets the event listener for this switch._  |


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










## Protected Attributes

| Type | Name |
| ---: | :--- |
|  unsigned char | [**curiosity**](#variable-curiosity)   = `0`<br> |
|  signed char | [**levelCode**](#variable-levelcode)   = `0`<br> |
|  [**IHandler**](classeva_1_1_i_handler.md) \* | [**listener**](#variable-listener)   = `nullptr`<br> |
































## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**notify**](#function-notify) (unsigned short eventType, signed short eventCode) <br> |
| virtual void | [**tick**](#function-tick) () override<br> |








## Detailed Description


This class handles both switch and button behavior within the same component. The difference is purely semantic:
* React to ON\_ACTIVE/ON\_INACTIVE for switch-like behavior
* React to ON\_PRESS/ON\_RELEASE for button-like behavior




Typical applications:
* Simple on/off switches (binary reader)
* Push buttons with press/release detection
* Resistor ladder buttons on a single ADC pin
* Custom encoding schemes (rotary encoders, keypads)
* Multiplexed inputs




Events include both the event type and the level code in argsMask, allowing identification of which specific input triggered the event.




**Template parameters:**


* `READER` Input reader type that returns numeric codes (0 = inactive, &gt;0 = active state identifier) 



**See also:** PinSwitch Digital pin switches with debouncing (typical use) 


**See also:** PullUpSwitch Pull-up switches convenience alias 


**See also:** PinMultiSwitch Multiple switches on one ADC pin 



    
## Public Functions Documentation




### function Switch [1/2]

```C++
inline eva::Switch::Switch () 
```




<hr>



### function Switch [2/2]

```C++
inline eva::Switch::Switch (
    IHandler * listener,
    unsigned short eventMask
) 
```




<hr>



### function enable 

_Enables or disables the switch._ 
```C++
inline Switch * eva::Switch::enable (
    bool enabled
) 
```



When disabled, the switch stops generating events.




**Parameters:**


* `enabled` True to enable, false to disable 



**Returns:**

Pointer to this for method chaining 





        

<hr>



### function getValue 

_Gets the current level code._ 
```C++
inline signed short eva::Switch::getValue () 
```





**Returns:**

Level code (0 for inactive, positive value for active state) 





        

<hr>



### function setListener 

_Sets the event listener for this switch._ 
```C++
inline Switch * eva::Switch::setListener (
    IHandler * listener,
    unsigned short eventMask
) 
```





**Parameters:**


* `listener` Callback object implementing [**IHandler**](classeva_1_1_i_handler.md) 
* `eventMask` Bitmask of events to listen for (ON\_PRESS, ON\_RELEASE, ON\_CHANGE) 



**Returns:**

Pointer to this for method chaining 





        

<hr>
## Protected Attributes Documentation




### variable curiosity 

```C++
unsigned char eva::Switch< READER >::curiosity;
```




<hr>



### variable levelCode 

```C++
signed char eva::Switch< READER >::levelCode;
```




<hr>



### variable listener 

```C++
IHandler* eva::Switch< READER >::listener;
```




<hr>
## Protected Functions Documentation




### function notify 

```C++
inline void eva::Switch::notify (
    unsigned short eventType,
    signed short eventCode
) 
```




<hr>



### function tick 

```C++
inline virtual void eva::Switch::tick () override
```



Implements [*eva::Tickable::tick*](classeva_1_1_tickable.md#function-tick)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaSwitch.h`

