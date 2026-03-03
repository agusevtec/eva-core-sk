

# Class eva::MultiButton

**template &lt;class READER&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**MultiButton**](classeva_1_1_multi_button.md)



_Multi-state button that identifies which button was pressed via level code._ [More...](#detailed-description)

* `#include <evaMultiButton.h>`



Inherits the following classes: [eva::Button](classeva_1_1_button.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
|  signed short | [**getValue**](#function-getvalue) () <br>_Gets the button level code identifying which button was pressed._  |




## Public Functions inherited from eva::Toggle

See [eva::Toggle](classeva_1_1_toggle.md)

| Type | Name |
| ---: | :--- |
|   | [**Toggle**](classeva_1_1_toggle.md#function-toggle-12) () <br> |
|   | [**Toggle**](classeva_1_1_toggle.md#function-toggle-22) ([**IHandler**](classeva_1_1_i_handler.md) \* listener, unsigned short eventMask) <br> |
|  Toggle \* | [**enable**](classeva_1_1_toggle.md#function-enable) (bool enabled) <br>_Enables or disables the toggle._  |
|  signed short | [**getValue**](classeva_1_1_toggle.md#function-getvalue) () <br>_Current state of the switch._  |
|  Toggle \* | [**setListener**](classeva_1_1_toggle.md#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener, unsigned short eventMask) <br>_Sets the Listener for switch events._  |


## Public Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|   | [**Tickable**](classeva_1_1_tickable.md#function-tickable) () <br> |
|  unsigned long | [**millis**](classeva_1_1_tickable.md#function-millis) () <br> |
|  void | [**tac**](classeva_1_1_tickable.md#function-tac) () <br>_Triggers tick on this and all linked tickables._  |








## Public Static Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|  Tickable \* | [**chain**](classeva_1_1_tickable.md#function-chain) (Tickable \* mount=0) <br>_Gets or sets the head of the tickable chain._  |




















## Protected Attributes inherited from eva::Button

See [eva::Button](classeva_1_1_button.md)

| Type | Name |
| ---: | :--- |
|  unsigned long | [**pressTime**](classeva_1_1_button.md#variable-presstime)  <br> |


## Protected Attributes inherited from eva::Toggle

See [eva::Toggle](classeva_1_1_toggle.md)

| Type | Name |
| ---: | :--- |
|  unsigned char | [**encodedState**](classeva_1_1_toggle.md#variable-encodedstate)   = `0`<br> |
|  [**IHandler**](classeva_1_1_i_handler.md) \* | [**listener**](classeva_1_1_toggle.md#variable-listener)   = `nullptr`<br> |
































































## Protected Functions inherited from eva::Toggle

See [eva::Toggle](classeva_1_1_toggle.md)

| Type | Name |
| ---: | :--- |
|  void | [**notify**](classeva_1_1_toggle.md#function-notify) (unsigned short eventTypeMask) <br> |
| virtual short | [**tick**](classeva_1_1_toggle.md#function-tick) () override<br> |












## Detailed Description


Generic button class that works with any multi-valued input source. The input reader can return different numeric codes representing different states. Typical applications:
* Resistor ladder buttons on single ADC pin
* Custom encoding schemes
* Multiplexed inputs




Events include the level code in argsMask, allowing identification of which specific button triggered the event. Long click threshold is fixed at 750ms.




**Template parameters:**


* `READER` Input reader type that returns numeric codes (0 = no button, &gt;0 = button index) 




    
## Public Functions Documentation




### function getValue 

_Gets the button level code identifying which button was pressed._ 
```C++
inline signed short eva::MultiButton::getValue () 
```





**Returns:**

Level code (0 for no button, &gt;0 for specific button) 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaMultiButton.h`

