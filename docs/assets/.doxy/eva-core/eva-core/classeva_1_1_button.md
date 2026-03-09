

# Class eva::Button

**template &lt;class READER&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Button**](classeva_1_1_button.md)



_Multi-state button that identifies which button was pressed via level code._ [More...](#detailed-description)

* `#include <evaButton.h>`



Inherits the following classes: [eva::Toggle](classeva_1_1_toggle.md)












































































## Public Functions inherited from eva::Toggle

See [eva::Toggle](classeva_1_1_toggle.md)

| Type | Name |
| ---: | :--- |
|   | [**Toggle**](classeva_1_1_toggle.md#function-toggle-12) () <br> |
|   | [**Toggle**](classeva_1_1_toggle.md#function-toggle-22) ([**IHandler**](classeva_1_1_i_handler.md) \* listener, unsigned short eventMask) <br> |
|  Toggle \* | [**enable**](classeva_1_1_toggle.md#function-enable) (bool enabled) <br>_Enables or disables the toggle._  |
|  signed short | [**getValue**](classeva_1_1_toggle.md#function-getvalue) () <br>_Gets the button level code identifying which button was pressed._  |
|  Toggle \* | [**setListener**](classeva_1_1_toggle.md#function-setlistener) ([**IHandler**](classeva_1_1_i_handler.md) \* listener, unsigned short eventMask) <br>_Sets the Listener for switch events._  |


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
















## Protected Attributes inherited from eva::Toggle

See [eva::Toggle](classeva_1_1_toggle.md)

| Type | Name |
| ---: | :--- |
|  bool | [**isEnabled**](classeva_1_1_toggle.md#variable-isenabled)   = `true`<br> |
|  unsigned char | [**levelCode**](classeva_1_1_toggle.md#variable-levelcode)   = `0`<br> |
|  [**IHandler**](classeva_1_1_i_handler.md) \* | [**listener**](classeva_1_1_toggle.md#variable-listener)   = `nullptr`<br> |
















































## Protected Functions inherited from eva::Toggle

See [eva::Toggle](classeva_1_1_toggle.md)

| Type | Name |
| ---: | :--- |
|  void | [**notify**](classeva_1_1_toggle.md#function-notify) (unsigned short eventTypeMask) <br> |
| virtual void | [**tick**](classeva_1_1_toggle.md#function-tick) () override<br> |










## Detailed Description


Generic button class that works with any multi-valued input source. The input reader can return different numeric codes representing different states. Typical applications:
* Resistor ladder buttons on single ADC pin
* Custom encoding schemes
* Multiplexed inputs




Events include the level code in argsMask, allowing identification of which specific button triggered the event. Long click threshold is fixed at 750ms.




**Template parameters:**


* `READER` Input reader type that returns numeric codes (0 = no button, &gt;0 = button index) 




    

------------------------------
The documentation for this class was generated from the following file `src/evaButton.h`

