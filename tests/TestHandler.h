#pragma once

#include <evaHandler.h>

// Тестовый обработчик событий
class TestHandler : public eva::IHandler {
public:
    void* lastSender = nullptr;
    long lastArgs = 0;
    int callCount = 0;
    
    void invoke(void* sender, long args) override {
        lastSender = sender;
        lastArgs = args;
        callCount++;
    }
    
    void reset() {
        lastSender = nullptr;
        lastArgs = 0;
        callCount = 0;
    }
};