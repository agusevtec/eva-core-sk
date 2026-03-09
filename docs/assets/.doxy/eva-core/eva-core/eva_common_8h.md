

# File evaCommon.h



[**FileList**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evaCommon.h**](eva_common_8h.md)

[Go to the source code of this file](eva_common_8h_source.md)



































































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**IS\_BEFORE**](eva_common_8h.md#define-is_before) (t1, t2) `(((t2) - (t1)) &lt;= 0x7FFFFFFFUL)`<br> |
| define  | [**SIGN**](eva_common_8h.md#define-sign) (x) `(((x) &gt; 0) - ((x) &lt; 0))`<br> |

## Macro Definition Documentation





### define IS\_BEFORE 

```C++
#define IS_BEFORE (
    t1,
    t2
) `(((t2) - (t1)) <= 0x7FFFFFFFUL)`
```




<hr>



### define SIGN 

```C++
#define SIGN (
    x
) `(((x) > 0) - ((x) < 0))`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaCommon.h`

