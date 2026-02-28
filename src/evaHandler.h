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
        virtual void invoke(void *msgSender, long argsMask) = 0;
    };

    /**
     * @brief Handler that calls a member method
     * @tparam T Class type of the receiver
     */
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

    /**
     * @brief Handler that calls a free function
     */
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
