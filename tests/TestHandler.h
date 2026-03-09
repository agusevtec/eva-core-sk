#pragma once

#include <evaHandler.h>

// Тестовый обработчик событий
class TestHandler : public eva::IHandler {
public:
    void* lastSender = nullptr;
    char lastEventType = 0;
    signed short lastArgs = 0;
    int callCount = 0;
    
    void invoke(void* sender, unsigned char eventType, signed short eventArg) override {
        lastSender = sender;
        lastEventType = eventType;
        lastArgs = eventArg;
        callCount++;
    }
    
    void reset() {
        lastSender = nullptr;
        lastArgs = 0;
        callCount = 0;
    }
};