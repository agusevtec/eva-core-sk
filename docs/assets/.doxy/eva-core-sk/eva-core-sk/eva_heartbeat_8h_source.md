

# File evaHeartbeat.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaHeartbeat.h**](eva_heartbeat_8h.md)

[Go to the documentation of this file](eva_heartbeat_8h.md)


```C++
#pragma once
#include <evaTickable.h>

namespace eva
{
    class Heartbeat : public Tickable
    {
    private:
        const unsigned long periodMs;
        unsigned long lastBeatMs;

    protected:
        virtual void onHeartbeat() = 0;

    public:
        Heartbeat(unsigned long periodMs);

        virtual ~Heartbeat() = default;

        void tick() override;

        unsigned long getPeriod() const;
    };

}
```


