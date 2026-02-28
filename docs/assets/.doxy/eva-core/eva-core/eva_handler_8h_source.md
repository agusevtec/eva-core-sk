

# File evaHandler.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaHandler.h**](eva_handler_8h.md)

[Go to the documentation of this file](eva_handler_8h.md)


```C++
#ifndef EVAHANDLER_H
#define EVAHANDLER_H

#pragma once
namespace eva
{
    class IHandler
    {
    public:
        virtual void invoke(void *msgSender, long argsMask) = 0;
    };

    template <class T>
    class Handler : public IHandler
    {
    public:
        Handler(T *msgReceiver, void (T::*method)(void *, long))
            : msgReceiver(msgReceiver), method(method)
        {
        }

        void invoke(void *msgSender, long argsMask) override
        {
            (this->msgReceiver->*method)(msgSender, argsMask);
        }

    private:
        void (T::*method)(void *, long);
        T *msgReceiver;
    };

    class HandlerF : public IHandler
    {
    public:
        HandlerF(void (*function)(void *, long))
            : function(function)
        {
        }

        void invoke(void *msgSender, long argsMask) override
        {
            (*function)(msgSender, argsMask);
        }

    private:
        void (*function)(void *, long);
    };
}
#endif
```


