

# File evaIReader.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaIReader.h**](eva_i_reader_8h.md)

[Go to the documentation of this file](eva_i_reader_8h.md)


```C++
#pragma once

namespace eva
{
    class IReader
    {
    public:
        virtual signed short getValue() = 0;
        virtual bool isValid() = 0;
    };

    template <class T>
    class IReaderAdapter : public IReader, public T
    {
    public:
        virtual signed short getValue() override
        {
            return T::getValue();
        }
        virtual bool isValid() override
        {
            return T::isValid();
        }
    };
};
```


