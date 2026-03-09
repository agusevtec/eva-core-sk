

# Namespace eva



[**Namespace List**](namespaces.md) **>** [**eva**](namespaceeva.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md) &lt;PIN, PIN\_MODE&gt;<br>_Reads analog pin value._  |
| class | [**BinarizeDecor**](classeva_1_1_binarize_decor.md) &lt;class READER, ACTICATES\_ON&gt;<br>_Decorator that converts analog reading to binary based on level._  |
| class | [**BlinkingIndicator**](classeva_1_1_blinking_indicator.md) <br>[_**Indicator**_](classeva_1_1_indicator.md) _that blinks with specified period and duty cycle._ |
| class | [**Button**](classeva_1_1_button.md) &lt;class READER&gt;<br>_Multi-state button that identifies which button was pressed via level code._  |
| class | [**CountdownIndicator**](classeva_1_1_countdown_indicator.md) <br>[_**Indicator**_](classeva_1_1_indicator.md) _that blinks a specified number of times then notifies listener._ |
| class | [**DelayTimer**](classeva_1_1_delay_timer.md) <br>_One-shot timer that fires after a delay._  |
| class | [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md) &lt;PIN, PIN\_MODE&gt;<br>_Reads digital pin value._  |
| class | [**Handler**](classeva_1_1_handler.md) &lt;class T&gt;<br>[_**Handler**_](classeva_1_1_handler.md) _that calls a member method._ |
| class | [**HandlerF**](classeva_1_1_handler_f.md) <br>[_**Handler**_](classeva_1_1_handler.md) _that calls a free function._ |
| class | [**IHandler**](classeva_1_1_i_handler.md) <br>_Interface for message handlers._  |
| class | [**IReader**](classeva_1_1_i_reader.md) <br>_Interface for value readers._  |
| class | [**IReaderAdapter**](classeva_1_1_i_reader_adapter.md) &lt;class T&gt;<br>_Adapter that converts any class with getValue() into an_ [_**IReader**_](classeva_1_1_i_reader.md) _._ |
| class | [**Indicator**](classeva_1_1_indicator.md) <br>_Basic indicator (LED) control._  |
| class | [**Joystick**](classeva_1_1_joystick.md) &lt;class READER, MIN, MIDDLE, MAX&gt;<br>[_**Joystick**_](classeva_1_1_joystick.md) _axis reader with trim adjustment._ |
| class | [**List**](classeva_1_1_list.md) &lt;class ItemClass&gt;<br>_Simple singly-linked list container._  |
| struct | [**ListIterator**](structeva_1_1_list_iterator.md) &lt;class ItemClass&gt;<br>_Iterator node for_ [_**List**_](classeva_1_1_list.md) _._ |
| class | [**PolarizeDecor**](classeva_1_1_polarize_decor.md) &lt;class READER, THRESHOLD&gt;<br>_Decorator that normalizes readings to -1, 0, 1 based on threshold._  |
| class | [**QuantizeDecor**](classeva_1_1_quantize_decor.md) &lt;class READER, LEVELS&gt;<br>_Decorator that quantizes analog readings to discrete levels._  |
| class | [**RepeatTimer**](classeva_1_1_repeat_timer.md) <br>_Timer that fires repeatedly at fixed intervals._  |
| class | [**Slider**](classeva_1_1_slider.md) &lt;class READER, MIN, MAX&gt;<br>_Maps analog readings to 0-255 range._  |
| class | [**StabilizeDecor**](classeva_1_1_stabilize_decor.md) &lt;class READER&gt;<br>_Decorator that stabilizes readings by requiring value to be stable for a period._  |
| class | [**Tickable**](classeva_1_1_tickable.md) <br>_Base class for objects that need periodic updates._  |
| class | [**Toggle**](classeva_1_1_toggle.md) &lt;class READER&gt;<br>[_**Toggle**_](classeva_1_1_toggle.md) _- легковесная версия_[_**Button**_](classeva_1_1_button.md) _без детекции кликов_ |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef [**Button**](classeva_1_1_button.md)&lt; [**BinarizeDecor**](classeva_1_1_binarize_decor.md)&lt; [**StabilizeDecor**](classeva_1_1_stabilize_decor.md)&lt; [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, ACTIVATES\_ON &gt; &gt; | [**PinButton**](#typedef-pinbutton)  <br>[_**Button**_](classeva_1_1_button.md) _connected directly to a digital pin Includes stabilization and binarization decorators. Debounces input and generates events based on button state changes. Long click threshold is fixed at 750ms._ |
| typedef [**Joystick**](classeva_1_1_joystick.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt;, MIN, MIDDLE, MAX &gt; | [**PinJoystick**](#typedef-pinjoystick)  <br>_Pin-based joystick with custom center position._  |
| typedef [**Button**](classeva_1_1_button.md)&lt; [**QuantizeDecor**](classeva_1_1_quantize_decor.md)&lt; [**StabilizeDecor**](classeva_1_1_stabilize_decor.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, LEVELS... &gt; &gt; | [**PinMultiButton**](#typedef-pinmultibutton)  <br>_Multiple buttons on single ADC pin using resistor ladder._  |
| typedef [**Button**](classeva_1_1_button.md)&lt; [**BinarizeDecor**](classeva_1_1_binarize_decor.md)&lt; [**StabilizeDecor**](classeva_1_1_stabilize_decor.md)&lt; [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)&lt; PIN, INPUT\_PULLUP &gt; &gt;, LOW &gt; &gt; | [**PinPullUpButton**](#typedef-pinpullupbutton)  <br> |
| typedef [**Slider**](classeva_1_1_slider.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt;, MIN, MAX &gt; | [**PinSlider**](#typedef-pinslider)  <br>_Pin-based slider mapping analog readings to 0-255 range._  |
| typedef [**Toggle**](classeva_1_1_toggle.md)&lt; [**BinarizeDecor**](classeva_1_1_binarize_decor.md)&lt; [**StabilizeDecor**](classeva_1_1_stabilize_decor.md)&lt; [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, ACTIVE\_LEVEL &gt; &gt; | [**PinSwitch**](#typedef-pinswitch)  <br>_Pin-based switch with specified active level._  |
| typedef [**Joystick**](classeva_1_1_joystick.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt;, MIN,(MAX - MIN)/2, MAX &gt; | [**PinSymmetricJoystick**](#typedef-pinsymmetricjoystick)  <br>_Pin-based joystick with symmetric range (MIN to MAX, center at midpoint)._  |
| typedef PinSwitch&lt; PIN, INPUT, HIGH &gt; | [**PulldownSwitch**](#typedef-pulldownswitch)  <br>_Pull-down switch (button connected to VCC)._  |
| typedef PinSwitch&lt; PIN, INPUT\_PULLUP, LOW &gt; | [**PullupSwitch**](#typedef-pullupswitch)  <br>_Pull-up switch (button connected to GND)._  |
| typedef [**Toggle**](classeva_1_1_toggle.md)&lt; [**BinarizeDecor**](classeva_1_1_binarize_decor.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, INPUT &gt;, THRESHOLD &gt; &gt; | [**ThresholdSwitch**](#typedef-thresholdswitch)  <br>_Threshold-based switch using analog input._  |






## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const unsigned long | [**ON\_ACTIVE**](#variable-on_active)   = `ON\_PRESS`<br> |
|  const unsigned long | [**ON\_CHANGE**](#variable-on_change)   = `0x0100`<br> |
|  const unsigned long | [**ON\_INACTIVE**](#variable-on_inactive)   = `ON\_RELEASE`<br> |
|  const unsigned long | [**ON\_LONGCLICK**](#variable-on_longclick)   = `0x1000`<br> |
|  const unsigned long | [**ON\_PRESS**](#variable-on_press)   = `0x0200`<br> |
|  const unsigned long | [**ON\_RELEASE**](#variable-on_release)   = `0x0400`<br> |
|  const unsigned long | [**ON\_SHORTCLICK**](#variable-on_shortclick)   = `0x0800`<br> |
|  const unsigned long | [**ON\_UNCLASSIFIED**](#variable-on_unclassified)   = `0x0000`<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**tac**](#function-tac) () <br>_Triggers all tickable objects to update._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  bool | [**in\_beetween**](#function-in_beetween) (signed short x, signed short a, signed short b) <br> |


























## Public Types Documentation




### typedef PinButton 

[_**Button**_](classeva_1_1_button.md) _connected directly to a digital pin Includes stabilization and binarization decorators. Debounces input and generates events based on button state changes. Long click threshold is fixed at 750ms._
```C++
using eva::PinButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;
```





**Template parameters:**


* `PIN` 
* `PIN_MODE` 
* `ACTIVATES_ON` - the level of a signal corresponding to the pressed state (LOW OR HIGH) 



**Returns:**

[**Button**](classeva_1_1_button.md)& 





        

<hr>



### typedef PinJoystick 

_Pin-based joystick with custom center position._ 
```C++
using eva::PinJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN, MIDDLE, MAX>;
```





**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (usually INPUT) 
* `MIN` Minimum analog reading 
* `MIDDLE` Center position reading 
* `MAX` Maximum analog reading 




        

<hr>



### typedef PinMultiButton 

_Multiple buttons on single ADC pin using resistor ladder._ 
```C++
using eva::PinMultiButton = Button<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
```



Hardware connection: ADC IN --+R1+R2+ ... -Rn-+ (pullup) \| \| \| \| \ \ \ \ \| \| \| \| GND --+---+---+ ... -+


Each button produces different ADC value which is mapped to levelCode. Debounces input and generates events based on button state changes. 

**Template parameters:**


* `PIN` Arduino analog pin number 
* `PIN_MODE` Pin mode (usually INPUT) 
* `LEVELS` Threshold values for different buttons 




        

<hr>



### typedef PinPullUpButton 

```C++
using eva::PinPullUpButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;
```




<hr>



### typedef PinSlider 

_Pin-based slider mapping analog readings to 0-255 range._ 
```C++
using eva::PinSlider = Slider<AnalogPinReader<PIN, PIN_MODE>, MIN, MAX>;
```





**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (usually INPUT) 
* `MIN` Minimum analog reading 
* `MAX` Maximum analog reading 




        

<hr>



### typedef PinSwitch 

_Pin-based switch with specified active level._ 
```C++
using eva::PinSwitch = Toggle<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVE_LEVEL>>;
```





**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (INPUT\_PULLUP, INPUT, etc.) 
* `ACTIVE_LEVEL` Level that means active (LOW or HIGH) 




        

<hr>



### typedef PinSymmetricJoystick 

_Pin-based joystick with symmetric range (MIN to MAX, center at midpoint)._ 
```C++
using eva::PinSymmetricJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN, (MAX - MIN) / 2, MAX>;
```





**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (usually INPUT) 
* `MIN` Minimum analog reading 
* `MAX` Maximum analog reading 




        

<hr>



### typedef PulldownSwitch 

_Pull-down switch (button connected to VCC)._ 
```C++
using eva::PulldownSwitch = PinSwitch<PIN, INPUT, HIGH>;
```





**Template parameters:**


* `PIN` Arduino pin number with INPUT 




        

<hr>



### typedef PullupSwitch 

_Pull-up switch (button connected to GND)._ 
```C++
using eva::PullupSwitch = PinSwitch<PIN, INPUT_PULLUP, LOW>;
```





**Template parameters:**


* `PIN` Arduino pin number with INPUT\_PULLUP 




        

<hr>



### typedef ThresholdSwitch 

_Threshold-based switch using analog input._ 
```C++
using eva::ThresholdSwitch = Toggle<BinarizeDecor<AnalogPinReader<PIN, INPUT>, THRESHOLD>>;
```





**Template parameters:**


* `PIN` Arduino analog pin number 
* `THRESHOLD` Value that separates active/inactive states 




        

<hr>
## Public Static Attributes Documentation




### variable ON\_ACTIVE 

```C++
const unsigned long eva::ON_ACTIVE;
```




<hr>



### variable ON\_CHANGE 

```C++
const unsigned long eva::ON_CHANGE;
```




<hr>



### variable ON\_INACTIVE 

```C++
const unsigned long eva::ON_INACTIVE;
```




<hr>



### variable ON\_LONGCLICK 

```C++
const unsigned long eva::ON_LONGCLICK;
```




<hr>



### variable ON\_PRESS 

```C++
const unsigned long eva::ON_PRESS;
```




<hr>



### variable ON\_RELEASE 

```C++
const unsigned long eva::ON_RELEASE;
```




<hr>



### variable ON\_SHORTCLICK 

```C++
const unsigned long eva::ON_SHORTCLICK;
```




<hr>



### variable ON\_UNCLASSIFIED 

```C++
const unsigned long eva::ON_UNCLASSIFIED;
```




<hr>
## Public Functions Documentation




### function tac 

_Triggers all tickable objects to update._ 
```C++
void eva::tac () 
```




<hr>
## Public Static Functions Documentation




### function in\_beetween 

```C++
static inline bool eva::in_beetween (
    signed short x,
    signed short a,
    signed short b
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaBlinkingIndicator.h`

