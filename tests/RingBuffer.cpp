#include <AUnit.h>
#include <evaRingBuffer.h>

test(RingBuffer_InitialState)
{
    eva::RingBuffer<int, 4> buffer;

    assertTrue(buffer.isEmpty());
    assertFalse(buffer.isFull());
    assertEqual(buffer.size(), (unsigned char)0);
}

test(RingBuffer_PushAndIsEmpty)
{
    eva::RingBuffer<int, 4> buffer;

    buffer.put(10);
    assertFalse(buffer.isEmpty());
    assertFalse(buffer.isFull());
    assertEqual(buffer.size(), (unsigned char)1);
    assertEqual(buffer.get(0), 10);
}

test(RingBuffer_OverflowAndWrapAround)
{
    eva::RingBuffer<int, 3> buffer;

    buffer.put(100);
    buffer.put(200);
    buffer.put(300);

    assertTrue(buffer.isFull());
    assertEqual(buffer.size(), (unsigned char)3);
    
    assertEqual(buffer.get(0), 100);
    assertEqual(buffer.get(1), 200);
    assertEqual(buffer.get(2), 300);

    buffer.put(400);

    assertTrue(buffer.isFull());
    assertEqual(buffer.size(), (unsigned char)3);
    assertEqual(buffer.get(0), 200);
    assertEqual(buffer.get(1), 300);
    assertEqual(buffer.get(2), 400);
}
