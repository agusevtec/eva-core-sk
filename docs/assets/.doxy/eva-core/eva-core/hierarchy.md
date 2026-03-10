
# Class Hierarchy

This inheritance list is sorted roughly, but not completely, alphabetically:


* **class** [**eva::AnalogPinReader**](classeva_1_1_analog_pin_reader.md) _Reads analog pin value._     
    * **class** [**eva::Joystick**](classeva_1_1_joystick.md) [_**Joystick**_](classeva_1_1_joystick.md) _axis reader with trim adjustment._
    * **class** [**eva::Joystick**](classeva_1_1_joystick.md) [_**Joystick**_](classeva_1_1_joystick.md) _axis reader with trim adjustment._
    * **class** [**eva::Slider**](classeva_1_1_slider.md) _Maps analog readings to 0-255 range._ 
* **class** [**eva::Indicator**](classeva_1_1_indicator.md) _Basic indicator (LED) control._     
    * **class** [**eva::BlinkingIndicator**](classeva_1_1_blinking_indicator.md) [_**Indicator**_](classeva_1_1_indicator.md) _that blinks with specified period and duty cycle._    
        * **class** [**eva::CountdownIndicator**](classeva_1_1_countdown_indicator.md) [_**Indicator**_](classeva_1_1_indicator.md) _that blinks a specified number of times then notifies listener._
* **class** [**eva::IHandler**](classeva_1_1_i_handler.md) _Interface for message handlers._     
    * **class** [**eva::BlinkingIndicator**](classeva_1_1_blinking_indicator.md) [_**Indicator**_](classeva_1_1_indicator.md) _that blinks with specified period and duty cycle._    
        * **class** [**eva::CountdownIndicator**](classeva_1_1_countdown_indicator.md) [_**Indicator**_](classeva_1_1_indicator.md) _that blinks a specified number of times then notifies listener._
    * **class** [**eva::Handler**](classeva_1_1_handler.md) [_**Handler**_](classeva_1_1_handler.md) _that calls a member method._
    * **class** [**eva::HandlerF**](classeva_1_1_handler_f.md) [_**Handler**_](classeva_1_1_handler.md) _that calls a free function._
* **class** [**eva::Tickable**](classeva_1_1_tickable.md) _Base class for objects that need periodic updates._     
    * **class** [**eva::Switch**](classeva_1_1_switch.md) _Universal switch/button class for multi-valued input sources._     
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
    * **class** [**eva::Switch**](classeva_1_1_switch.md) _Universal switch/button class for multi-valued input sources._     
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
    * **class** [**eva::DelayTimer**](classeva_1_1_delay_timer.md) _One-shot timer that fires after a delay._     
        * **class** [**eva::ContdownTimer**](classeva_1_1_contdown_timer.md) _Timer that fires repeatedly at fixed intervals._ 
        * **class** [**eva::RepeatTimer**](classeva_1_1_repeat_timer.md) _Timer that fires repeatedly at fixed intervals._ 
    * **class** [**eva::Switch**](classeva_1_1_switch.md) _Universal switch/button class for multi-valued input sources._     
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
* **class** [**eva::DigitalPinReader**](classeva_1_1_digital_pin_reader.md) _Reads digital pin value._ 
* **class** [**eva::IReader**](classeva_1_1_i_reader.md) _Interface for value readers._     
    * **class** [**eva::IReaderAdapter**](classeva_1_1_i_reader_adapter.md) _Adapter that converts any class with getValue() into an_ [_**IReader**_](classeva_1_1_i_reader.md) _._
* **class** [**eva::List**](classeva_1_1_list.md) _Simple singly-linked list container._ 
* **struct** [**eva::CallbackInfo**](structeva_1_1_callback_info.md) 
* **struct** [**eva::ListIterator**](structeva_1_1_list_iterator.md) _Iterator node for_ [_**List**_](classeva_1_1_list.md) _._
* **class** **READER**    
    * **class** [**eva::BinarizeDecor**](classeva_1_1_binarize_decor.md) _Decorator that converts analog reading to binary based on level._     
        * **class** [**eva::Switch**](classeva_1_1_switch.md) _Universal switch/button class for multi-valued input sources._     
            * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
            * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
            * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
    * **class** [**eva::Switch**](classeva_1_1_switch.md) _Universal switch/button class for multi-valued input sources._     
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
    * **class** [**eva::Joystick**](classeva_1_1_joystick.md) [_**Joystick**_](classeva_1_1_joystick.md) _axis reader with trim adjustment._
    * **class** [**eva::PolarizeDecor**](classeva_1_1_polarize_decor.md) _Decorator that normalizes readings to -1, 0, 1 based on threshold._ 
    * **class** [**eva::QuantizeDecor**](classeva_1_1_quantize_decor.md) _Decorator that quantizes analog readings to discrete levels._     
        * **class** [**eva::Switch**](classeva_1_1_switch.md) _Universal switch/button class for multi-valued input sources._     
            * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
            * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
            * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
    * **class** [**eva::Slider**](classeva_1_1_slider.md) _Maps analog readings to 0-255 range._ 
    * **class** [**eva::StabilizeDecor**](classeva_1_1_stabilize_decor.md) _Decorator that stabilizes readings by requiring value to be stable for a period._ 
    * **class** [**eva::Switch**](classeva_1_1_switch.md) _Universal switch/button class for multi-valued input sources._     
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
        * **class** [**eva::Button**](classeva_1_1_button.md) [_**Button**_](classeva_1_1_button.md) _with press/release and click detection._
* **class** **T**    
    * **class** [**eva::IReaderAdapter**](classeva_1_1_i_reader_adapter.md) _Adapter that converts any class with getValue() into an_ [_**IReader**_](classeva_1_1_i_reader.md) _._

