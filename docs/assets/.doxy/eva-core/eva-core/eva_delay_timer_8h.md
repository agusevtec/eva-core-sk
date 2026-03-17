

# File evaDelayTimer.h



[**FileList**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaDelayTimer.h**](eva_delay_timer_8h.md)

[Go to the source code of this file](eva_delay_timer_8h_source.md)



* `#include "evaTickable.h"`
* `#include "evaHandler.h"`













## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**eva**](namespaceeva.md) <br> |


## Classes

| Type | Name |
| ---: | :--- |
| class | [**DelayTimer**](classeva_1_1_delay_timer.md) <br>_One-shot timer that fires after a delay._  |

















































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**IS\_BEFORE**](eva_delay_timer_8h.md#define-is_before) (t1, t2) `(((t2) - (t1)) &lt;= 0x7FFFFFFFUL)`<br> |

## Macro Definition Documentation





### define IS\_BEFORE 

```C++
#define IS_BEFORE (
    t1,
    t2
) `(((t2) - (t1)) <= 0x7FFFFFFFUL)`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaDelayTimer.h`

