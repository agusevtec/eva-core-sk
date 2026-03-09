#ifndef EVAHANDLER_H
#define EVAHANDLER_H

#pragma once
namespace eva
{


    /**
     * @brief Interface for message handlers
     */
    class IHandler
    {
    public:
        virtual void invoke(void *msgSender, unsigned char eventType, signed short eventArg) = 0;
    };

    /**
     * @brief Handler that calls a member method
     * @tparam T Class type of the receiver
     */
    template <class T>
    class Handler : public IHandler
    {
    public:
        Handler(T *msgReceiver, void (T::*method)(void *, unsigned char, signed short))
            : msgReceiver(msgReceiver), method(method)
        {
        }

        void invoke(void *msgSender, unsigned char eventType, signed short eventArg) override
        {
            (this->msgReceiver->*method)(msgSender, eventType, eventArg);
        }

    private:
        void (T::*method)(void *, unsigned char, signed short);
        T *msgReceiver;
    };

    /**
     * @brief Handler that calls a free function
     */
    class HandlerF : public IHandler
    {
    public:
        HandlerF(void (*function)(void *, unsigned char, signed short))
            : function(function)
        {
        }

        void invoke(void *msgSender, unsigned char eventType, signed short eventArg) override
        {
            (*function)(msgSender, eventType, eventArg);
        }

    private:
        void (*function)(void *, unsigned char, signed short);
    };
}
#endif
