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

    /**
     * @brief Interface for message handlers
     */
    class IHandler
    {
    public:
        virtual void invoke(void *msgSender, CallbackInfo cbInfo) = 0;
    };

    /**
     * @brief Handler that calls a member method
     * @tparam T Class type of the receiver
     */
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

    /**
     * @brief Handler that calls a free function
     */
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
