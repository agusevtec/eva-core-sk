#pragma once

#include <evaHandler.h>

class MockHandler : public eva::IHandler {
public:
    void* lastSender = nullptr;
    unsigned short lastEventType = 0;
    signed short lastArgs = 0;
    int callCount = 0;
    
    void invoke(void* sender, eva::CallbackInfo cbInfo) override {
        lastSender = sender;
        lastEventType = cbInfo.eventType;
        lastArgs = cbInfo.eventArg;
        callCount++;
    }
    
    void reset() {
        lastSender = nullptr;
        lastArgs = 0;
        callCount = 0;
    }
};