#pragma once

namespace eva {

// Простой мок-ридер с возможностью установить значение
class MockReader {
private:
    signed short value = 0;
    
public:
    signed short getValue() { 
        return value; 
    }
    
    void setValue(signed short v) { 
        value = v; 
    }
};

} // namespace eva