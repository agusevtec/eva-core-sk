

# File evaCommon.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaCommon.h**](eva_common_8h.md)

[Go to the documentation of this file](eva_common_8h.md)


```C++
#ifndef EVACOMMON_H
#define EVACOMMON_H

#pragma once
#ifndef DEBOUNCE_DELAY
    #define DEBOUNCE_DELAY 120
#endif

#ifndef LONGPRESS_DELAY
    #define LONGPRESS_DELAY 750
#endif

#ifndef REPEAT_DELAY
    #define REPEAT_DELAY 400
#endif

#define SIGN(x) (((x) > 0) - ((x) < 0))
#define IS_BEFORE(t1, t2) (((t2) - (t1)) <= 0x7FFFFFFFUL)

#endif
```


