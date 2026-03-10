

# Class eva::Button

**template &lt;class READER&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Button**](classeva_1_1_button.md)



[_**Button**_](classeva_1_1_button.md) _with press/release and click detection._[More...](#detailed-description)

* `#include <evaButton.h>`



Inherits the following classes: [eva::Switch](classeva_1_1_switch.md)












































































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
|   | [**Tickable**](classeva_1_1_tickable.md#function-tickable) () <br> |
|  void | [**tac**](classeva_1_1_tickable.md#function-tac) () <br>_Triggers tick on this and all linked tickables._  |
| virtual  | [**~Tickable**](classeva_1_1_tickable.md#function-tickable) () <br> |






## Public Static Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|  Tickable \* | [**chain**](classeva_1_1_tickable.md#function-chain) () <br>_Gets or sets the head of the tickable chain._  |
















## Protected Attributes inherited from eva::Switch

See [eva::Switch](classeva_1_1_switch.md)

| Type | Name |
| ---: | :--- |
|  unsigned char | [**curiosity**](classeva_1_1_switch.md#variable-curiosity)   = `0`<br> |
|  signed char | [**levelCode**](classeva_1_1_switch.md#variable-levelcode)   = `0`<br> |
|  [**IHandler**](classeva_1_1_i_handler.md) \* | [**listener**](classeva_1_1_switch.md#variable-listener)   = `nullptr`<br> |
















































## Protected Functions inherited from eva::Switch

See [eva::Switch](classeva_1_1_switch.md)

| Type | Name |
| ---: | :--- |
|  void | [**notify**](classeva_1_1_switch.md#function-notify) (unsigned short eventType, signed short eventCode) <br> |
| virtual void | [**tick**](classeva_1_1_switch.md#function-tick) () override<br> |










## Detailed Description


Extends [**Switch**](classeva_1_1_switch.md) with timing-based events: short click and long click. For basic active/inactive behavior, use [**Switch**](classeva_1_1_switch.md) directly.


The class works with any reader that returns numeric codes:
* 0 means "no button pressed"
* Positive values identify specific buttons




Events include both the event type and the button code in argsMask, allowing identification of which specific button triggered the event.


Long click threshold is fixed at 750ms.




**Template parameters:**


* `READER` Input reader type that returns numeric codes (0 = no button, &gt;0 = button identifier)



**See also:** [**Switch**](classeva_1_1_switch.md) Base class for active/inactive state management 


**See also:** PinButton Digital pin button with debouncing (typical use) 


**See also:** PullUpButton Pull-up button convenience alias 


**See also:** PinMultiButton Multiple buttons on one ADC pin 



    

------------------------------
The documentation for this class was generated from the following file `src/evaButton.h`

