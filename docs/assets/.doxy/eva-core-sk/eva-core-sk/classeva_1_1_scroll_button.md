

# Class eva::ScrollButton

**template &lt;class TReader&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**ScrollButton**](classeva_1_1_scroll_button.md)



[_**Button**_](classeva_1_1_button.md) _with auto-repeat (typematic) functionality._[More...](#detailed-description)

* `#include <evaScrollButton.h>`



Inherits the following classes: [eva::Button](classeva_1_1_button.md)


































































































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




















## Protected Attributes inherited from eva::Button

See [eva::Button](classeva_1_1_button.md)

| Type | Name |
| ---: | :--- |
|  unsigned long | [**pressTime**](classeva_1_1_button.md#variable-presstime)   = `0`<br> |


## Protected Attributes inherited from eva::Switch

See [eva::Switch](classeva_1_1_switch.md)

| Type | Name |
| ---: | :--- |
|  unsigned char | [**curiosity**](classeva_1_1_switch.md#variable-curiosity)   = `0`<br> |
|  signed char | [**levelCode**](classeva_1_1_switch.md#variable-levelcode)   = `0`<br> |
|  [**IHandler**](classeva_1_1_i_handler.md) \* | [**listener**](classeva_1_1_switch.md#variable-listener)   = `nullptr`<br> |






























































## Protected Functions inherited from eva::Button

See [eva::Button](classeva_1_1_button.md)

| Type | Name |
| ---: | :--- |
|  bool | [**checkLongPress**](classeva_1_1_button.md#function-checklongpress) (unsigned long now) <br> |
|  void | [**handleActivating**](classeva_1_1_button.md#function-handleactivating) (unsigned long now) <br> |
|  void | [**handleDeactivating**](classeva_1_1_button.md#function-handledeactivating) (unsigned char wasLevelCode, unsigned long now) <br> |
|  void | [**handleLongPress**](classeva_1_1_button.md#function-handlelongpress) () <br> |


## Protected Functions inherited from eva::Switch

See [eva::Switch](classeva_1_1_switch.md)

| Type | Name |
| ---: | :--- |
|  bool | [**checkActivating**](classeva_1_1_switch.md#function-checkactivating) (unsigned char wasLevelCode) <br>_inactive or different -&gt; active_  |
|  bool | [**checkChanging**](classeva_1_1_switch.md#function-checkchanging) (unsigned char wasLevelCode) <br> |
|  bool | [**checkDeactivating**](classeva_1_1_switch.md#function-checkdeactivating) (unsigned char wasLevelCode) <br>_active -&gt; inactive or different state_  |
|  void | [**handleActivating**](classeva_1_1_switch.md#function-handleactivating) () <br> |
|  void | [**handleChanging**](classeva_1_1_switch.md#function-handlechanging) () <br> |
|  void | [**handleDeactivating**](classeva_1_1_switch.md#function-handledeactivating) (unsigned char wasLevelCode) <br> |
|  void | [**notify**](classeva_1_1_switch.md#function-notify) (unsigned short eventType, signed short eventCode) <br> |
|  bool | [**updateState**](classeva_1_1_switch.md#function-updatestate) () <br> |












## Detailed Description


This class extends [**Button**](classeva_1_1_button.md) by adding periodic ON\_REPEAT events while the button is held down. The naming reflects the primary use case (keyboard-like repeat).



* ON\_CHANGE - Any state change
* ON\_PRESS - [**Button**](classeva_1_1_button.md) becomes active (switch to active state)
* ON\_RELEASE - [**Button**](classeva_1_1_button.md) becomes inactive (switch to inactive state)
* ON\_SHORTCLICK - Press and release within LONGPRESS\_DELAY
* ON\_LONGCLICK - Press and hold longer than LONGPRESS\_DELAY then release
* ON\_LONGPRESS - Press and hold longer than LONGPRESS\_DELAY (no release)
* ON\_REPEATKEY - Periodic events while holding (after LONGPRESS\_DELAY)






**Template parameters:**


* `TReader` Input reader type that returns numeric codes (0 = no button, &gt;0 = button identifier)



**See also:** [**Button**](classeva_1_1_button.md) Base class for click detection 



    

------------------------------
The documentation for this class was generated from the following file `src/evaScrollButton.h`

