

# Class eva::Handler

**template &lt;class T&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**Handler**](classeva_1_1_handler.md)



[_**Handler**_](classeva_1_1_handler.md) _that calls a member method._[More...](#detailed-description)

* `#include <evaHandler.h>`



Inherits the following classes: [eva::IHandler](classeva_1_1_i_handler.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Handler**](#function-handler) (T \* msgReceiver, void(T::\*)(void \*, [**CallbackInfo**](structeva_1_1_callback_info.md)) method) <br> |
| virtual void | [**invoke**](#function-invoke) (void \* msgSender, [**CallbackInfo**](structeva_1_1_callback_info.md) cbInfo) override<br> |


## Public Functions inherited from eva::IHandler

See [eva::IHandler](classeva_1_1_i_handler.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**invoke**](classeva_1_1_i_handler.md#function-invoke) (void \* msgSender, [**CallbackInfo**](structeva_1_1_callback_info.md) cbInfo) = 0<br> |






















































## Detailed Description




**Template parameters:**


* `T` Class type of the receiver 




    
## Public Functions Documentation




### function Handler 

```C++
inline eva::Handler::Handler (
    T * msgReceiver,
    void(T::*)(void *, CallbackInfo ) method
) 
```




<hr>



### function invoke 

```C++
inline virtual void eva::Handler::invoke (
    void * msgSender,
    CallbackInfo cbInfo
) override
```



Implements [*eva::IHandler::invoke*](classeva_1_1_i_handler.md#function-invoke)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaHandler.h`

