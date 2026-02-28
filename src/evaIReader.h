#ifndef EVAIREADER_H
#define EVAIREADER_H

#pragma once

namespace eva
{
    class IReader
    {
    public:
        virtual signed short getValue() = 0;
    };

    template <class T>
    class IReaderAdapter : public IReader, public T
    {
    public:
        virtual signed short getValue() override
        {
            return T::getValue();
        }
    };
};

#endif
