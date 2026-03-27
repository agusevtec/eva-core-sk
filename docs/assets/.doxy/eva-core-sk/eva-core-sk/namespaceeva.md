

# Namespace eva



[**Namespace List**](namespaces.md) **>** [**eva**](namespaceeva.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md) &lt;PIN, PIN\_MODE&gt;<br>_Reads analog pin value._  |
| class | [**BinarizeEqDecor**](classeva_1_1_binarize_eq_decor.md) &lt;class READER, ACTIVATES\_ON&gt;<br>_Decorator that converts reading to binary based on level._  |
| class | [**BinarizeGtDecor**](classeva_1_1_binarize_gt_decor.md) &lt;class READER, THRESHOLD&gt;<br>_Decorator that converts analog reading to binary based on 'greater then' threshold condition._  |
| class | [**BinarizeLtDecor**](classeva_1_1_binarize_lt_decor.md) &lt;class READER, THRESHOLD&gt;<br>_Decorator that converts analog reading to binary based on 'less then' threshold condition._  |
| class | [**BlinkingIndicator**](classeva_1_1_blinking_indicator.md) <br>[_**Indicator**_](classeva_1_1_indicator.md) _that blinks with specified period and duty cycle._ |
| class | [**Button**](classeva_1_1_button.md) &lt;class READER&gt;<br>[_**Button**_](classeva_1_1_button.md) _with press/release and click detection._ |
| struct | [**CallbackInfo**](structeva_1_1_callback_info.md) <br> |
| class | [**CountdownIndicator**](classeva_1_1_countdown_indicator.md) <br>[_**Indicator**_](classeva_1_1_indicator.md) _that blinks a specified number of times then notifies listener._ |
| class | [**CountdownTimer**](classeva_1_1_countdown_timer.md) <br>_Timer that fires repeatedly at fixed intervals._  |
| class | [**DebounceDecor**](classeva_1_1_debounce_decor.md) &lt;class READER&gt;<br>_Decorator that stabilizes readings by requiring value to be stable for a period._  |
| class | [**DelayTimer**](classeva_1_1_delay_timer.md) <br>_One-shot timer that fires after a delay._  |
| class | [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md) &lt;PIN, PIN\_MODE&gt;<br>_Reads digital pin value._  |
| class | [**Handler**](classeva_1_1_handler.md) &lt;class T&gt;<br>[_**Handler**_](classeva_1_1_handler.md) _that calls a member method._ |
| class | [**HandlerF**](classeva_1_1_handler_f.md) <br>[_**Handler**_](classeva_1_1_handler.md) _that calls a free function._ |
| class | [**Heartbeat**](classeva_1_1_heartbeat.md) <br>_Base class for components that need periodic updates._  |
| class | [**IHandler**](classeva_1_1_i_handler.md) <br>_Interface for message handlers._  |
| class | [**IReader**](classeva_1_1_i_reader.md) <br>_Interface for value readers._  |
| class | [**IReaderAdapter**](classeva_1_1_i_reader_adapter.md) &lt;class T&gt;<br>_Adapter that converts any class with getValue() into an_ [_**IReader**_](classeva_1_1_i_reader.md) _._ |
| class | [**Indicator**](classeva_1_1_indicator.md) <br>_Basic indicator (LED) control._  |
| class | [**Joystick**](classeva_1_1_joystick.md) &lt;class READER, MIN\_POS, MIDDLE\_POS, MAX\_POS&gt;<br>[_**Joystick**_](classeva_1_1_joystick.md) _axis reader (range 1000-1500-2000) with trim adjustment._ |
| class | [**List**](classeva_1_1_list.md) &lt;class ItemClass&gt;<br>_Simple singly-linked list container._  |
| struct | [**ListIterator**](structeva_1_1_list_iterator.md) &lt;class ItemClass&gt;<br>_Iterator node for_ [_**List**_](classeva_1_1_list.md) _._ |
| class | [**QuantizeDecor**](classeva_1_1_quantize_decor.md) &lt;class READER, LEVELS&gt;<br>_Decorator that quantizes analog readings to discrete levels._  |
| class | [**RepeatTimer**](classeva_1_1_repeat_timer.md) <br>_Timer that fires repeatedly at fixed intervals._  |
| class | [**ScrollButton**](classeva_1_1_scroll_button.md) &lt;class READER&gt;<br>[_**Button**_](classeva_1_1_button.md) _with auto-repeat (typematic) functionality._ |
| class | [**Slider**](classeva_1_1_slider.md) &lt;class READER, MIN\_POS, MAX\_POS&gt;<br>_Maps analog readings to 1000-2000 range._  |
| class | [**Switch**](classeva_1_1_switch.md) &lt;class READER&gt;<br>_Universal switch/button class for multi-valued input sources._  |
| class | [**Tickable**](classeva_1_1_tickable.md) <br>_Base class for objects that need periodic updates._  |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef [**Button**](classeva_1_1_button.md)&lt; [**BinarizeEqDecor**](classeva_1_1_binarize_eq_decor.md)&lt; [**DebounceDecor**](classeva_1_1_debounce_decor.md)&lt; [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, ACTIVATES\_ON &gt; &gt; | [**PinButton**](#typedef-pinbutton)  <br>_Digital pin button with debouncing and level normalization._  |
| typedef [**Joystick**](classeva_1_1_joystick.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt;, MIN\_POS, MIDDLE\_POS, MAX\_POS &gt; | [**PinJoystick**](#typedef-pinjoystick)  <br>_Pin-based joystick with custom center position._  |
| typedef [**Button**](classeva_1_1_button.md)&lt; [**QuantizeDecor**](classeva_1_1_quantize_decor.md)&lt; [**DebounceDecor**](classeva_1_1_debounce_decor.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, LEVELS... &gt; &gt; | [**PinMultiButton**](#typedef-pinmultibutton)  <br>_Multiple buttons on a single ADC pin using resistor ladder._  |
| typedef [**Switch**](classeva_1_1_switch.md)&lt; [**QuantizeDecor**](classeva_1_1_quantize_decor.md)&lt; [**DebounceDecor**](classeva_1_1_debounce_decor.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, LEVELS... &gt; &gt; | [**PinMultiSwitch**](#typedef-pinmultiswitch)  <br>_Multiple switches on a single ADC pin using resistor ladder._  |
| typedef [**Button**](classeva_1_1_button.md)&lt; [**BinarizeEqDecor**](classeva_1_1_binarize_eq_decor.md)&lt; [**DebounceDecor**](classeva_1_1_debounce_decor.md)&lt; [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, ACTIVATES\_ON &gt; &gt; | [**PinScrollButton**](#typedef-pinscrollbutton)  <br>_Digital pin key-button with debouncing and level normalization._  |
| typedef [**ScrollButton**](classeva_1_1_scroll_button.md)&lt; [**QuantizeDecor**](classeva_1_1_quantize_decor.md)&lt; [**DebounceDecor**](classeva_1_1_debounce_decor.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, LEVELS... &gt; &gt; | [**PinScrollMultiButton**](#typedef-pinscrollmultibutton)  <br>_Multiple key-buttons on a single ADC pin using resistor ladder._  |
| typedef [**Slider**](classeva_1_1_slider.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt;, MIN\_POS, MAX\_POS &gt; | [**PinSlider**](#typedef-pinslider)  <br>_Pin-based slider mapping analog readings to 0-255 range._  |
| typedef [**Switch**](classeva_1_1_switch.md)&lt; [**BinarizeEqDecor**](classeva_1_1_binarize_eq_decor.md)&lt; [**DebounceDecor**](classeva_1_1_debounce_decor.md)&lt; [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)&lt; PIN, PIN\_MODE &gt; &gt;, ACTIVE\_LEVEL &gt; &gt; | [**PinSwitch**](#typedef-pinswitch)  <br>_Digital pin switch with debouncing and level normalization._  |
| typedef [**Joystick**](classeva_1_1_joystick.md)&lt; [**AnalogPinReader**](classeva_1_1_analog_pin_reader.md)&lt; PIN, PIN\_MODE &gt;, MIN\_POS,(MAX\_POS+MIN\_POS)/2, MAX\_POS &gt; | [**PinSymmetricJoystick**](#typedef-pinsymmetricjoystick)  <br>_Pin-based joystick with symmetric range (MIN\_POS to MAX\_POS, center at midpoint)._  |
| typedef [**Button**](classeva_1_1_button.md)&lt; [**BinarizeEqDecor**](classeva_1_1_binarize_eq_decor.md)&lt; [**DebounceDecor**](classeva_1_1_debounce_decor.md)&lt; [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)&lt; PIN, INPUT\_PULLUP &gt; &gt;, LOW &gt; &gt; | [**PullUpButton**](#typedef-pullupbutton)  <br>_Pull-up button (active LOW, connect to GND)._  |
| typedef [**ScrollButton**](classeva_1_1_scroll_button.md)&lt; [**BinarizeEqDecor**](classeva_1_1_binarize_eq_decor.md)&lt; [**DebounceDecor**](classeva_1_1_debounce_decor.md)&lt; [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md)&lt; PIN, INPUT\_PULLUP &gt; &gt;, LOW &gt; &gt; | [**PullupScrollButton**](#typedef-pullupscrollbutton)  <br>_Pull-up key-button (active LOW, connect to GND)._  |
| typedef PinSwitch&lt; PIN, INPUT\_PULLUP, LOW &gt; | [**PullupSwitch**](#typedef-pullupswitch)  <br>_Pull-up switch (active LOW, connect to GND)._  |






## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const unsigned short | [**DEBOUNCE\_DELAY**](#variable-debounce_delay)   = `120`<br> |
|  const unsigned short | [**LONGPRESS\_DELAY**](#variable-longpress_delay)   = `750`<br> |
|  const unsigned char | [**ON\_CHANGE**](#variable-on_change)   = `0x04`<br> |
|  const unsigned char | [**ON\_LONGCLICK**](#variable-on_longclick)   = `0x10`<br> |
|  const unsigned char | [**ON\_LONGPRESS**](#variable-on_longpress)   = `0x20`<br> |
|  const unsigned char | [**ON\_PRESS**](#variable-on_press)   = `0x01`<br> |
|  const unsigned char | [**ON\_RELEASE**](#variable-on_release)   = `0x02`<br> |
|  const unsigned char | [**ON\_REPEATKEY**](#variable-on_repeatkey)   = `0x40`<br> |
|  const unsigned char | [**ON\_SHORTCLICK**](#variable-on_shortclick)   = `0x08`<br> |
|  const unsigned short | [**REPEAT\_DELAY**](#variable-repeat_delay)   = `300`<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**tac**](#function-tac) () <br>_Triggers all tickable objects to update._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  bool | [**in\_between**](#function-in_between) (signed short x, signed short a, signed short b) <br> |


























## Public Types Documentation




### typedef PinButton 

_Digital pin button with debouncing and level normalization._ 
```C++
using eva::PinButton = Button<BinarizeEqDecor<DebounceDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;
```



Combines:
* [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md) for raw pin reading
* [**DebounceDecor**](classeva_1_1_debounce_decor.md) for debouncing (120ms stability)
* [**BinarizeEqDecor**](classeva_1_1_binarize_eq_decor.md) for mapping to active/inactive based on specified level




Long click threshold is fixed at 750ms.




**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (INPUT, INPUT\_PULLUP, etc.) 
* `ACTIVATES_ON` Level that means "pressed" (LOW or HIGH) 




        

<hr>



### typedef PinJoystick 

_Pin-based joystick with custom center position._ 
```C++
using eva::PinJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN_POS, MIDDLE_POS, MAX_POS>;
```





**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (usually INPUT) 
* `MIN_POS` Minimum analog reading 
* `MIDDLE_POS` Center position reading 
* `MAX_POS` Maximum analog reading 




        

<hr>



### typedef PinMultiButton 

_Multiple buttons on a single ADC pin using resistor ladder._ 
```C++
using eva::PinMultiButton = Button<QuantizeDecor<DebounceDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
```



Hardware connection: 
```C++
 ADC Pin  -----+--R1--+--R2--+-- ... -Rn-+
(analog in)    |      |      |           |
                \      \      \           \
               |      |      |           |
   GND    -----+------+------+-- ... ----+
```



Each button produces a different ADC value when pressed. The [**QuantizeDecor**](classeva_1_1_quantize_decor.md) maps these values to discrete button codes (1, 2, 3...). [**DebounceDecor**](classeva_1_1_debounce_decor.md) provides debouncing.


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
using eva::PinMultiSwitch = Switch<QuantizeDecor<DebounceDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
```



Hardware connection: 
```C++
 ADC Pin  -----+--R1--+--R2--+-- ... -Rn-+
(analog in)    |      |      |           |
                \      \      \           \
               |      |      |           |
   GND    -----+------+------+-- ... ----+
```



Each switch produces a different ADC value when activated. The [**QuantizeDecor**](classeva_1_1_quantize_decor.md) maps these values to discrete level codes (1, 2, 3...). [**DebounceDecor**](classeva_1_1_debounce_decor.md) provides debouncing.




**Template parameters:**


* `PIN` Arduino analog pin number 
* `PIN_MODE` Pin mode (usually INPUT) 
* `LEVELS` Threshold values for each switch (expected ADC readings) 




        

<hr>



### typedef PinScrollButton 

_Digital pin key-button with debouncing and level normalization._ 
```C++
using eva::PinScrollButton = Button<BinarizeEqDecor<DebounceDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVATES_ON>>;
```



Combines:
* [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md) for raw pin reading
* [**DebounceDecor**](classeva_1_1_debounce_decor.md) for debouncing (120ms stability)
* [**BinarizeEqDecor**](classeva_1_1_binarize_eq_decor.md) for mapping to active/inactive based on specified level




Long click threshold is fixed at 750ms.




**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (INPUT, INPUT\_PULLUP, etc.) 
* `ACTIVATES_ON` Level that means "pressed" (LOW or HIGH) 




        

<hr>



### typedef PinScrollMultiButton 

_Multiple key-buttons on a single ADC pin using resistor ladder._ 
```C++
using eva::PinScrollMultiButton = ScrollButton<QuantizeDecor<DebounceDecor<AnalogPinReader<PIN, PIN_MODE>>, LEVELS...>>;
```



Hardware connection: 
```C++
 ADC Pin  -----+--R1--+--R2--+-- ... -Rn-+
(analog in)    |      |      |           |
                \      \      \           \
               |      |      |           |
   GND    -----+------+------+-- ... ----+
```



Each button produces a different ADC value when pressed. The [**QuantizeDecor**](classeva_1_1_quantize_decor.md) maps these values to discrete button codes (1, 2, 3...). [**DebounceDecor**](classeva_1_1_debounce_decor.md) provides debouncing.


Generates standard button events for each button, with the button number encoded in the event mask.




**Template parameters:**


* `PIN` Arduino analog pin number 
* `PIN_MODE` Pin mode (usually INPUT) 
* `LEVELS` Threshold values for each button (expected ADC readings)



**See also:** PinMultiSwitch For use cases without click detection 



        

<hr>



### typedef PinSlider 

_Pin-based slider mapping analog readings to 0-255 range._ 
```C++
using eva::PinSlider = Slider<AnalogPinReader<PIN, PIN_MODE>, MIN_POS, MAX_POS>;
```





**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (usually INPUT) 
* `MIN_POS` Minimum analog reading 
* `MAX_POS` Maximum analog reading 




        

<hr>



### typedef PinSwitch 

_Digital pin switch with debouncing and level normalization._ 
```C++
using eva::PinSwitch = Switch<BinarizeEqDecor<DebounceDecor<DigitalPinReader<PIN, PIN_MODE>>, ACTIVE_LEVEL>>;
```



Combines:
* [**DigitalPinReader**](classeva_1_1_digital_pin_reader.md) for raw pin reading
* [**DebounceDecor**](classeva_1_1_debounce_decor.md) for debouncing (120ms stability)
* [**BinarizeEqDecor**](classeva_1_1_binarize_eq_decor.md) for mapping to active/inactive based on specified level






**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (INPUT, INPUT\_PULLUP, etc.) 
* `ACTIVE_LEVEL` Level that means active (LOW or HIGH) 




        

<hr>



### typedef PinSymmetricJoystick 

_Pin-based joystick with symmetric range (MIN\_POS to MAX\_POS, center at midpoint)._ 
```C++
using eva::PinSymmetricJoystick = Joystick<AnalogPinReader<PIN, PIN_MODE>, MIN_POS, (MAX_POS + MIN_POS) / 2, MAX_POS>;
```





**Template parameters:**


* `PIN` Arduino pin number 
* `PIN_MODE` Pin mode (usually INPUT) 
* `MIN_POS` Minimum analog reading 
* `MAX_POS` Maximum analog reading 




        

<hr>



### typedef PullUpButton 

_Pull-up button (active LOW, connect to GND)._ 
```C++
using eva::PullUpButton = Button<BinarizeEqDecor<DebounceDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;
```



Convenience alias for the most common Arduino button wiring:
* Pin set to INPUT\_PULLUP
* [**Button**](classeva_1_1_button.md) connects pin to GND when pressed




Generates all button events with proper debouncing.




**Template parameters:**


* `PIN` Arduino pin number 




        

<hr>



### typedef PullupScrollButton 

_Pull-up key-button (active LOW, connect to GND)._ 
```C++
using eva::PullupScrollButton = ScrollButton<BinarizeEqDecor<DebounceDecor<DigitalPinReader<PIN, INPUT_PULLUP>>, LOW>>;
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




### variable DEBOUNCE\_DELAY 

```C++
const unsigned short eva::DEBOUNCE_DELAY;
```




<hr>



### variable LONGPRESS\_DELAY 

```C++
const unsigned short eva::LONGPRESS_DELAY;
```




<hr>



### variable ON\_CHANGE 

```C++
const unsigned char eva::ON_CHANGE;
```




<hr>



### variable ON\_LONGCLICK 

```C++
const unsigned char eva::ON_LONGCLICK;
```




<hr>



### variable ON\_LONGPRESS 

```C++
const unsigned char eva::ON_LONGPRESS;
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



### variable ON\_REPEATKEY 

```C++
const unsigned char eva::ON_REPEATKEY;
```




<hr>



### variable ON\_SHORTCLICK 

```C++
const unsigned char eva::ON_SHORTCLICK;
```




<hr>



### variable REPEAT\_DELAY 

```C++
const unsigned short eva::REPEAT_DELAY;
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




### function in\_between 

```C++
static inline bool eva::in_between (
    signed short x,
    signed short a,
    signed short b
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaBlinkingIndicator.h`

