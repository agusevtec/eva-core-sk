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