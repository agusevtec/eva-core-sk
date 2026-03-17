

# File evaHandler.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaHandler.h**](eva_handler_8h.md)

[Go to the documentation of this file](eva_handler_8h.md)


```C++
#ifndef EVAHANDLER_H
#define EVAHANDLER_H

#pragma once
namespace eva
{

    struct CallbackInfo
    {
        unsigned short eventType;
        signed short eventArg;
    };

    class IHandler
    {
    public:
        virtual void invoke(void *msgSender, CallbackInfo cbInfo) = 0;
    };

    template <class T>
    class Handler : public IHandler
    {
    public:
        Handler(T *msgReceiver, void (T::*method)(void *, CallbackInfo))
            : msgReceiver(msgReceiver), method(method)
        {
        }

        void invoke(void *msgSender, CallbackInfo cbInfo) override
        {
            (this->msgReceiver->*method)(msgSender, cbInfo);
        }

    private:
        void (T::*method)(void *, CallbackInfo);
        T *msgReceiver;
    };

    class HandlerF : public IHandler
    {
    public:
        HandlerF(void (*function)(void *, CallbackInfo))
            : function(function)
        {
        }

        void invoke(void *msgSender, CallbackInfo cbInfo) override
        {
            (*function)(msgSender, cbInfo);
        }

    private:
        void (*function)(void *, CallbackInfo);
    };
}
#endif
```


