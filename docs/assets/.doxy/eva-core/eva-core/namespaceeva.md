

# Namespace eva



[**Namespace List**](namespaces.md) **>** [**eva**](namespaceeva.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md) &lt;PIN, PIN\_MODE&gt;<br>_Reads analog pin value._  |
| class | [**BinarizeDecor**](classeva_1_1_binarize_decor.md) &lt;class READER, ACTICATES\_ON&gt;<br>_Decorator that converts analog reading to binary based on level._  |
| class | [**BlinkingIndicator**](classeva_1_1_blinking_indicator.md) <br>[_**Indicator**_](classeva_1_1_indicator.md) _that blinks with specified period and duty cycle._ |
| class | [**Button**](classeva_1_1_button.md) &lt;class READER&gt;<br>[_**Button**_](classeva_1_1_button.md) _with press/release and click detection._ |
| struct | [**CallbackInfo**](structeva_1_1_callback_info.md) <br> |
| class | [**CountdownIndicator**](classeva_1_1_countdown_indicator.md) <br>[_**Indicator**_](classeva_1_1_indicator.md) _that blinks a specified number of times then notifies listener._ |
| class | [**CountdownTimer**](classeva_1_1_countdown_timer.md) <br>_Timer that fires repeatedly at fixed intervals._  |
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
| class | [**Switch**](classeva_1_1_switch.md) &lt;class READER&gt;<br>_Universal switch/button class for multi-valued input sources._  |
| class | [**Tickable**](classeva_1_1_tickable.md) <br>_Base class for objects that need periodic updates._  |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef [**Button**](classeva_1_1_button.md)&lt; [**BinarizeDecor**](classeva_1_1_binarize_decor.md)&lt; [**StabilizeDecor**](classeva_1_1_stabilize_decor.md)&lt; [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, ACTIVATES\_ON &gt; &gt; | [**PinButton**](#typedef-pinbutton)  <br>_Digital pin button with debouncing and level normalization._  |
| typedef [**Joystick**](classeva_1_1_joystick.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt;, MIN, MIDDLE, MAX &gt; | [**PinJoystick**](#typedef-pinjoystick)  <br>_Pin-based joystick with custom center position._  |
| typedef [**Button**](classeva_1_1_button.md)&lt; [**QuantizeDecor**](classeva_1_1_quantize_decor.md)&lt; [**StabilizeDecor**](classeva_1_1_stabilize_decor.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, LEVELS... &gt; &gt; | [**PinMultiButton**](#typedef-pinmultibutton)  <br>_Multiple buttons on a single ADC pin using resistor ladder._  |
| typedef [**Switch**](classeva_1_1_switch.md)&lt; [**QuantizeDecor**](classeva_1_1_quantize_decor.md)&lt; [**StabilizeDecor**](classeva_1_1_stabilize_decor.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, LEVELS... &gt; &gt; | [**PinMultiSwitch**](#typedef-pinmultiswitch)  <br>_Multiple switches on a single ADC pin using resistor ladder._  |
| typedef [**Slider**](classeva_1_1_slider.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt;, MIN, MAX &gt; | [**PinSlider**](#typedef-pinslider)  <br>_Pin-based slider mapping analog readings to 0-255 range._  |
| typedef [**Switch**](classeva_1_1_switch.md)&lt; [**BinarizeDecor**](classeva_1_1_binarize_decor.md)&lt; [**StabilizeDecor**](classeva_1_1_stabilize_decor.md)&lt; [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, ACTIVE\_LEVEL &gt; &gt; | [**PinSwitch**](#typedef-pinswitch)  <br>_Digital pin switch with debouncing and level normalization._  |
| typedef [**Joystick**](classeva_1_1_joystick.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt;, MIN,(MAX - MIN)/2, MAX &gt; | [**PinSymmetricJoystick**](#typedef-pinsymmetricjoystick)  <br>_Pin-based joystick with symmetric range (MIN to MAX, center at midpoint)._  |
| typedef [**Button**](classeva_1_1_button.md)&lt; [**BinarizeDecor**](classeva_1_1_binarize_decor.md)&lt; [**StabilizeDecor**](classeva_1_1_stabilize_decor.md)&lt; [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)&lt; PIN, INPUT\_PULLUP &gt; &gt;, LOW &gt; &gt; | [**PullUpButton**](#typedef-pullupbutton)  <br>_Pull-up button (active LOW, connect to GND)._  |
| typedef PinSwitch&lt; PIN, INPUT\_PULLUP, LOW &gt; | [**PullupSwitch**](#typedef-pullupswitch)  <br>_Pull-up switch (active LOW, connect to GND)._  |






## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const unsigned char | [**ON\_ACTIVE**](#variable-on_active)   = `ON\_PRESS`<br> |
|  const unsigned char | [**ON\_CHANGED**](#variable-ON_CHANGE)   = `0x1`<br> |
|  const unsigned char | [**ON\_INACTIVE**](#variable-on_inactive)   = `ON\_RELEASE`<br> |
|  const unsigned char | [**ON\_LONGCLICK**](#variable-on_longclick)   = `0x10`<br> |
|  const unsigned char | [**ON\_PRESS**](#variable-on_press)   = `0x02`<br> |
|  const unsigned char | [**ON\_RELEASE**](#variable-on_release)   = `0x04`<br> |
|  const unsigned char | [**ON\_SHORTCLICK**](#variable-on_shortclick)   = `0x08`<br> |














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

_Digital pin button with debouncing and level normalization._ 
```C++
using eva::PinButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;
```



Combines:
* [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md) for raw pin reading
* [**StabilizeDecor**](classeva_1_1_stabilize_decor.md) for debouncing (120ms stability)
* [**BinarizeDecor**](classeva_1_1_binarize_decor.md) for mapping to active/inactive based on specified level




Generates standard button events: PRESS, RELEASE, SHORTCLICK, LONGCLICK. Long click threshold is fixed at 750ms.




**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (INPUT, INPUT\_PULLUP, etc.) 
* `ACTIVATES_ON` Level that means "pressed" (LOW or HIGH) 




        

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

_Multiple buttons on a single ADC pin using resistor ladder._ 
```C++
using eva::PinMultiButton = Button<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
```



Hardware connection: 
```C++
 ADC Pin  -----+--R1--+--R2--+-- ... -Rn-+
(analog in)    |      |      |           |
                \      \      \           \
               |      |      |           |
   GND    -----+------+------+-- ... ----+
```



Each button produces a different ADC value when pressed. The [**QuantizeDecor**](classeva_1_1_quantize_decor.md) maps these values to discrete button codes (1, 2, 3...). [**StabilizeDecor**](classeva_1_1_stabilize_decor.md) provides debouncing.


Generates standard button events for each button, with the button number encoded in the event mask.




**Template parameters:**


* `PIN` Arduino analog pin number 
* `PIN_MODE` Pin mode (usually INPUT) 
* `LEVELS` Threshold values for each button (expected ADC readings)



**See also:** PinMultiSwitch For use cases without click detection 



        

<hr>



### typedef PinMultiSwitch 

_Multiple switches on a single ADC pin using resistor ladder._ 
```C++
using eva::PinMultiSwitch = Switch<QuantizeDecor<StabilizeDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
```



Hardware connection: 
```C++
 ADC Pin  -----+--R1--+--R2--+-- ... -Rn-+
(analog in)    |      |      |           |
                \      \      \           \
               |      |      |           |
   GND    -----+------+------+-- ... ----+
```



Each switch produces a different ADC value when activated. The [**QuantizeDecor**](classeva_1_1_quantize_decor.md) maps these values to discrete level codes (1, 2, 3...). [**StabilizeDecor**](classeva_1_1_stabilize_decor.md) provides debouncing.




**Template parameters:**


* `PIN` Arduino analog pin number 
* `PIN_MODE` Pin mode (usually INPUT) 
* `LEVELS` Threshold values for each switch (expected ADC readings) 




        

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

_Digital pin switch with debouncing and level normalization._ 
```C++
using eva::PinSwitch = Switch<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVE_LEVEL>>;
```



Combines:
* [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md) for raw pin reading
* [**StabilizeDecor**](classeva_1_1_stabilize_decor.md) for debouncing (120ms stability)
* [**BinarizeDecor**](classeva_1_1_binarize_decor.md) for mapping to active/inactive based on specified level






**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (INPUT, INPUT\_PULLUP, etc.) 
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



### typedef PullUpButton 

_Pull-up button (active LOW, connect to GND)._ 
```C++
using eva::PullUpButton = Button<BinarizeDecor<StabilizeDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;
```



Convenience alias for the most common Arduino button wiring:
* Pin set to INPUT\_PULLUP
* [**Button**](classeva_1_1_button.md) connects pin to GND when pressed




Generates all button events with proper debouncing.




**Template parameters:**


* `PIN` Arduino pin number 




        

<hr>



### typedef PullupSwitch 

_Pull-up switch (active LOW, connect to GND)._ 
```C++
using eva::PullupSwitch = PinSwitch<PIN, INPUT_PULLUP, LOW>;
```



Convenience alias for the most common Arduino switch wiring:
* Pin set to INPUT\_PULLUP
* [**Switch**](classeva_1_1_switch.md) connects pin to GND when pressed






**Template parameters:**


* `PIN` Arduino pin number 




        

<hr>
## Public Static Attributes Documentation




### variable ON\_ACTIVE 

```C++
const unsigned char eva::ON_ACTIVE;
```




<hr>



### variable ON\_CHANGED 

```C++
const unsigned char eva::ON_CHANGE;
```




<hr>



### variable ON\_INACTIVE 

```C++
const unsigned char eva::ON_INACTIVE;
```




<hr>



### variable ON\_LONGCLICK 

```C++
const unsigned char eva::ON_LONGCLICK;
```




<hr>



### variable ON\_PRESS 

```C++
const unsigned char eva::ON_PRESS;
```




<hr>



### variable ON\_RELEASE 

```C++
const unsigned char eva::ON_RELEASE;
```




<hr>



### variable ON\_SHORTCLICK 

```C++
const unsigned char eva::ON_SHORTCLICK;
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

