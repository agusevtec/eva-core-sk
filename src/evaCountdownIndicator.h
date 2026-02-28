#ifndef COUNTDOWNINDICATOR_H
#define COUNTDOWNINDICATOR_H

#pragma once

#include "evaBlinkingIndicator.h"

namespace eva
{
    class CountdownIndicator : public BlinkingIndicator
    {
    public:
        using BlinkingIndicator::BlinkingIndicator;
        void on(unsigned short period, unsigned short dutycyclePercent, unsigned char count, IHandler *listener);

    private:
        void invoke(void *msgSender, long args) override;

    private:
        unsigned char countdown;
        IHandler *listener;
    };
}

#endif