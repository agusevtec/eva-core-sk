

# Class eva::Button

**template &lt;class READER&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Button**](classeva_1_1_button.md)



[_**Button**_](classeva_1_1_button.md) _with press, release, short click and long click detection._[More...](#detailed-description)

* `#include <evaButton.h>`



Inherits the following classes: [eva::Toggle](classeva_1_1_toggle.md)


Inherited by the following classes: [eva::MultiButton](classeva_1_1_multi_button.md),  [eva::MultiButton](classeva_1_1_multi_button.md)










































































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
|  void | [**tac**](classeva_1_1_tickable.md#function-tac) () <br>_Triggers tick on this and all linked tickables._  |






## Public Static Functions inherited from eva::Tickable

See [eva::Tickable](classeva_1_1_tickable.md)

| Type | Name |
| ---: | :--- |
|  Tickable \* | [**chain**](classeva_1_1_tickable.md#function-chain) (Tickable \* mount=0) <br>_Gets or sets the head of the tickable chain._  |














## Protected Attributes

| Type | Name |
| ---: | :--- |
|  unsigned long | [**pressTime**](#variable-presstime)  <br> |


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




**Template parameters:**


* `READER` Input reader type that provides [**getValue()**](classeva_1_1_toggle.md#function-getvalue) 




    
## Protected Attributes Documentation




### variable pressTime 

```C++
unsigned long eva::Button< READER >::pressTime;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaButton.h`

