#include <AUnit.h>
#include "MockReader.h"
#include <evaSlider.h>

using namespace aunit;
using namespace eva;

test(slider_returns_0_at_min) {
    Slider<MockReader, 0, 1023> slider;
    
    slider.setValue(0);
    assertEqual(slider.getValue(), 0);
}

test(slider_returns_255_at_max) {
    Slider<MockReader, 0, 1023> slider;
    
    slider.setValue(1023);
    assertEqual(slider.getValue(), 255);
}

test(slider_returns_128_at_midpoint) {
    Slider<MockReader, 0, 1000> slider;
    
    slider.setValue(500);
    assertEqual(slider.getValue(), 127);
}

test(slider_returns_64_at_quarter) {
    Slider<MockReader, 0, 1023> slider;
    
    slider.setValue(256);
    assertEqual(slider.getValue(), 64);
}

test(slider_saturates_at_max) {
    Slider<MockReader, 0, 1023> slider;
    
    slider.setValue(2000);
    assertEqual(slider.getValue(), 255);
}

test(slider_saturates_at_min) {
    Slider<MockReader, 0, 1023> slider;
    
    slider.setValue(-100);
    assertEqual(slider.getValue(), 0);
}

test(slider_works_with_different_range) {
    Slider<MockReader, 100, 900> slider;
    
    slider.setValue(100);
    assertEqual(slider.getValue(), 0);
    
    slider.setValue(900);
    assertEqual(slider.getValue(), 255);
    
    slider.setValue(500);
    assertEqual(slider.getValue(), 128);
}