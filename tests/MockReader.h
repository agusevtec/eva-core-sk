#pragma once

class MockReader {
private:
    signed short value = 0;
    bool valid = true;
    
public:
    signed short getValue() { 
        return value; 
    }
    
    void setValue(signed short v) { 
        value = v; 
    }
    
    bool isValid() {
        return valid;
    }
    
    void setValid(bool v) {
        valid = v;
    }
};
