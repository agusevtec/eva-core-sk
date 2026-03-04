#include <AUnit.h>
#include "MockReader.h"
#include <evaReaderDecors.h>

using namespace aunit;
using namespace eva;

test(binarize_decor_returns_1_when_value_matches) {
    BinarizeDecor<MockReader, 1> reader;
    
    reader.setValue(1);
    assertEqual(reader.getValue(), 1);
    
    reader.setValue(0);
    assertEqual(reader.getValue(), 0);
    
    reader.setValue(2);
    assertEqual(reader.getValue(), 0);
}

test(polarize_decor_returns_minus1_0_1) {
    PolarizeDecor<MockReader, 100> reader;
    
    reader.setValue(150);
    assertEqual(reader.getValue(), 1);
    
    reader.setValue(50);
    assertEqual(reader.getValue(), 0);
    
    reader.setValue(-50);
    assertEqual(reader.getValue(), 0);

    reader.setValue(-150);
    assertEqual(reader.getValue(), -1);
}

test(quantize_decor_returns_level_index) {
    QuantizeDecor<MockReader, 0, 100, 200, 300> reader;
    
    reader.setValue(22);
    assertEqual(reader.getValue(), 0);
    
    reader.setValue(120);
    assertEqual(reader.getValue(), 1);
    
    reader.setValue(250);
    assertEqual(reader.getValue(), 2);
    
    reader.setValue(330);
    assertEqual(reader.getValue(), 3);
}

test(quantize_decor_handles_boundaries) {
    QuantizeDecor<MockReader, 1000, 750, 500, 250> reader;
    
    reader.setValue(1020);
    assertEqual(reader.getValue(), 0);
    
    reader.setValue(700);
    assertEqual(reader.getValue(), 1);
    
    reader.setValue(520);
    assertEqual(reader.getValue(), 2);
    
    reader.setValue(300);
    assertEqual(reader.getValue(), 3);
}