

# Class eva::Button

**template &lt;class READER&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Button**](classeva_1_1_button.md)



[_**Button**_](classeva_1_1_button.md) _with press/release and click detection._[More...](#detailed-description)

* `#include <evaButton.h>`



Inherits the following classes: [eva::Switch](classeva_1_1_switch.md)


Inherited by the following classes: [eva::KeyButton](classeva_1_1_key_button.md)










































































## Public Functions inherited from eva::Switch

See [eva::Switch](classeva_1_1_switch.md)

| Type | Name |
| ---: | :--- |
|   | [**Switch**](classeva_1_1_switch.md#function-switch-12) () <br> |
|   | [**Switch**](classeva_1_1_switch.md#function-switch-22) ([**IHandler**](classeva_1_1_i_handler.md) \* listener, unsigned short eventMask) <br> |
|  Switch \* | [**enable**](classeva_1_1_switch.md#function-enable) (bool enabled) <br>_Enables or disables the switch._  |
|  signed short | [**getValue**](classeva_1_1_switch.md#function-getvalue) () <br>_Gets the current level code._  |
|  Switch \* | [**setListener**](classeva_1_1_switch.md#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener, unsigned short eventMask) <br>_Sets the event listener for this switch._  |


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
|  unsigned long | [**pressTime**](#variable-presstime)   = `0`<br> |


## Protected Attributes inherited from eva::Switch

See [eva::Switch](classeva_1_1_switch.md)

| Type | Name |
| ---: | :--- |
|  unsigned char | [**curiosity**](classeva_1_1_switch.md#variable-curiosity)   = `0`<br> |
|  signed char | [**levelCode**](classeva_1_1_switch.md#variable-levelcode)   = `0`<br> |
|  [**IHandler**](classeva_1_1_i_handler.md) \* | [**listener**](classeva_1_1_switch.md#variable-listener)   = `nullptr`<br> |














































## Protected Functions

| Type | Name |
| ---: | :--- |
|  bool | [**checkLongPress**](#function-checklongpress) (unsigned long now) <br> |
|  void | [**handleActivating**](#function-handleactivating) (unsigned long now) <br> |
|  void | [**handleDeactivating**](#function-handledeactivating) (unsigned char wasLevelCode, unsigned long now) <br> |
|  void | [**handleLongPress**](#function-handlelongpress) () <br> |


## Protected Functions inherited from eva::Switch

See [eva::Switch](classeva_1_1_switch.md)

| Type | Name |
| ---: | :--- |
|  bool | [**checkActivating**](classeva_1_1_switch.md#function-checkactivating) (unsigned char wasLevelCode) <br>_inactive or different -&gt; active_  |
|  bool | [**checkDeactivating**](classeva_1_1_switch.md#function-checkdeactivating) (unsigned char wasLevelCode) <br>_active -&gt; inactive or different state_  |
|  void | [**handleActivating**](classeva_1_1_switch.md#function-handleactivating) () <br> |
|  void | [**handleDeactivating**](classeva_1_1_switch.md#function-handledeactivating) (unsigned char wasLevelCode) <br> |
|  void | [**notify**](classeva_1_1_switch.md#function-notify) (unsigned short eventType, signed short eventCode) <br> |
|  void | [**updateState**](classeva_1_1_switch.md#function-updatestate) () <br> |










## Detailed Description


Extends [**Switch**](classeva_1_1_switch.md) with timing-based events: short click and long click. For basic active/inactive behavior, use [**Switch**](classeva_1_1_switch.md) directly.


The class works with any reader that returns numeric codes:
* 0 means "no button pressed"
* Positive values identify specific buttons




Events include both the event type and the button code in argsMask, allowing identification of which specific button triggered the event: in addition to [**Switch**](classeva_1_1_switch.md) - ON\_SHORTCLICK, ON\_LONGCLICK, ON\_LONGPRESS.


Long click threshold is fixed at 750ms.




**Template parameters:**


* `READER` Input reader type that returns numeric codes (0 = no button, &gt;0 = button identifier)



**See also:** [**Switch**](classeva_1_1_switch.md) Base class for active/inactive state management 


**See also:** PinButton Digital pin button with debouncing (typical use) 


**See also:** PullUpButton Pull-up button convenience alias 


**See also:** PinMultiButton Multiple buttons on one ADC pin 



    
## Protected Attributes Documentation




### variable pressTime 

```C++
unsigned long eva::Button< READER >::pressTime;
```




<hr>
## Protected Functions Documentation




### function checkLongPress 

```C++
inline bool eva::Button::checkLongPress (
    unsigned long now
) 
```




<hr>



### function handleActivating 

```C++
inline void eva::Button::handleActivating (
    unsigned long now
) 
```




<hr>



### function handleDeactivating 

```C++
inline void eva::Button::handleDeactivating (
    unsigned char wasLevelCode,
    unsigned long now
) 
```




<hr>



### function handleLongPress 

```C++
inline void eva::Button::handleLongPress () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaButton.h`

