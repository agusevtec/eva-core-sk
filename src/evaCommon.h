#ifndef EVACOMMON_H
#define EVACOMMON_H

#pragma once

#define SIGN(x) (((x) > 0) - ((x) < 0))
#define IS_BEFORE(t1, t2) (((t2) - (t1)) <= 0x7FFFFFFFUL)

#endif