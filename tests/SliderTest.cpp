#include <AUnit.h>
#include "MockReader.h"
#include <evaSlider.h>

using namespace aunit;
using namespace eva;

test(slider_works) {
    Slider<MockReader, 0, 1000> slider;
    
    slider.setValue(0);
    assertEqual(slider.getValue(), 1000);

    slider.setValue(500);
    assertEqual(slider.getValue(), 1500);
    
    slider.setValue(1000);
    assertEqual(slider.getValue(), 2000);
}

test(slider_works_with_different_range) {
    Slider<MockReader, 100, 900> slider;

    slider.setValue(100);
    assertEqual(slider.getValue(), 1000);
    
    slider.setValue(900);
    assertEqual(slider.getValue(), 2000);
    
    slider.setValue(500);
    assertEqual(slider.getValue(), 1500);
}

test(slider_works_with_reversed_range) {
    Slider<MockReader, 400, 100> slider;
    
    slider.setValue(100);
    assertEqual(slider.getValue(), 2000);
    
    slider.setValue(400);
    assertEqual(slider.getValue(), 1000);
    
    slider.setValue(250);
    assertEqual(slider.getValue(), 1500);
}

