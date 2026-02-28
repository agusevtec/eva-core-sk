

# Class eva::HandlerF



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**HandlerF**](classeva_1_1_handler_f.md)



[_**Handler**_](classeva_1_1_handler.md) _that calls a free function._

* `#include <evaHandler.h>`



Inherits the following classes: [eva::IHandler](classeva_1_1_i_handler.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**HandlerF**](#function-handlerf) (void(\*)(void \*, long) function) <br> |
| virtual void | [**invoke**](#function-invoke) (void \* msgSender, long argsMask) override<br> |


## Public Functions inherited from eva::IHandler

See [eva::IHandler](classeva_1_1_i_handler.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**invoke**](classeva_1_1_i_handler.md#function-invoke) (void \* msgSender, long argsMask) = 0<br> |






















































## Public Functions Documentation




### function HandlerF 

```C++
inline eva::HandlerF::HandlerF (
    void(*)(void *, long) function
) 
```




<hr>



### function invoke 

```C++
inline virtual void eva::HandlerF::invoke (
    void * msgSender,
    long argsMask
) override
```



Implements [*eva::IHandler::invoke*](classeva_1_1_i_handler.md#function-invoke)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaHandler.h`

