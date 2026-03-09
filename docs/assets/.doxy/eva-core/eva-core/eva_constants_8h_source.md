

# File evaConstants.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaConstants.h**](eva_constants_8h.md)

[Go to the documentation of this file](eva_constants_8h.md)


```C++
#ifndef EVACONSTANS_H_
#define EVACONSTANS_H_
#pragma once
namespace eva
{
    static const unsigned long ON_UNCLASSIFIED = 0x0000;
    static const unsigned long ON_CHANGE = 0x0100;
    static const unsigned long ON_PRESS = 0x0200;
    static const unsigned long ON_RELEASE = 0x0400;
    static const unsigned long ON_SHORTCLICK = 0x0800;
    static const unsigned long ON_LONGCLICK = 0x1000;

    static const unsigned long ON_ACTIVE = ON_PRESS;
    static const unsigned long ON_INACTIVE = ON_RELEASE;
}

#endif
```


