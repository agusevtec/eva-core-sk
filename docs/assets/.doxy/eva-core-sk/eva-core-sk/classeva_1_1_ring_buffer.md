

# Class eva::RingBuffer

**template &lt;typename T, unsigned char N&gt;**



[**ClassList**](annotated.md) **>** [**eva**](namespaceeva.md) **>** [**RingBuffer**](classeva_1_1_ring_buffer.md)



_Fixed-capacity circular ring buffer._ [More...](#detailed-description)

* `#include <evaRingBuffer.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**RingBuffer**](#function-ringbuffer) () <br> |
|  T | [**get**](#function-get) (unsigned char index) const<br> |
|  bool | [**isEmpty**](#function-isempty) () const<br> |
|  bool | [**isFull**](#function-isfull) () const<br> |
|  void | [**put**](#function-put) (const T & value) <br> |
|  unsigned char | [**size**](#function-size) () const<br> |




























## Detailed Description




**Template parameters:**


* `T` Element type 
* `N` Buffer capacity 




    
## Public Functions Documentation




### function RingBuffer 

```C++
inline eva::RingBuffer::RingBuffer () 
```




<hr>



### function get 

```C++
inline T eva::RingBuffer::get (
    unsigned char index
) const
```




<hr>



### function isEmpty 

```C++
inline bool eva::RingBuffer::isEmpty () const
```




<hr>



### function isFull 

```C++
inline bool eva::RingBuffer::isFull () const
```




<hr>



### function put 

```C++
inline void eva::RingBuffer::put (
    const T & value
) 
```




<hr>



### function size 

```C++
inline unsigned char eva::RingBuffer::size () const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evaRingBuffer.h`

