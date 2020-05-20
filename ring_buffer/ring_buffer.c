/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include "ring_buffer.h"
#include <stdlib.h>


bool RingBuffer_Init(RingBuffer *ringBuffer, char *dataBuffer, size_t dataBufferSize) {
    assert(ringBuffer);
    assert(dataBuffer);
    assert(dataBufferSize > 0);

    if ((ringBuffer) && (dataBuffer) && (dataBufferSize > 0)) {

        ringBuffer->head = 0;
        ringBuffer->tail = 0;
        ringBuffer->isFull = false;
        ringBuffer->buffer = dataBuffer;
        ringBuffer->size = dataBufferSize;
        return true;
    }

    return false;
}

bool RingBuffer_Clear(RingBuffer *ringBuffer) {
    assert(ringBuffer);

    if (ringBuffer) {
        ringBuffer->head = 0;
        ringBuffer->tail = 0;
        ringBuffer->isFull = false;

        if (ringBuffer->tail == 0 && ringBuffer->head == 0 && !ringBuffer->isFull)
        return true;
    }
    return false;
}

bool RingBuffer_IsEmpty(const RingBuffer *ringBuffer) {
    assert(ringBuffer);

    if (ringBuffer->tail == ringBuffer->head && !ringBuffer->isFull)
        return true;

    else
        return false;
}

size_t RingBuffer_GetLen(const RingBuffer *ringBuffer) {
    assert(ringBuffer);

    if (ringBuffer) {
        if (ringBuffer->isFull)
            return ringBuffer->size;

        else if (ringBuffer->head > ringBuffer->tail)
            return ringBuffer->head - ringBuffer->tail;

        else if (ringBuffer->head < ringBuffer->tail)
            return ringBuffer->size - ringBuffer->tail + ringBuffer->head;

    }
    return 0;

}

size_t RingBuffer_GetCapacity(const RingBuffer *ringBuffer) {
    assert(ringBuffer);

    if (ringBuffer) {
        return ringBuffer->size;
    }

    return 0;
}


bool RingBuffer_PutChar(RingBuffer *ringBuffer, char c) {
    assert(ringBuffer);

    if (ringBuffer) {
        if (ringBuffer->isFull)
            return false;

        *(ringBuffer->buffer + ringBuffer->head) = c;
        ringBuffer->head++;

        if (ringBuffer->head == ringBuffer->size)
            ringBuffer->head =0;

        if (ringBuffer->head == ringBuffer->tail)
            ringBuffer->isFull = true;

        return true;
    }
    return false;
}

bool RingBuffer_GetChar(RingBuffer *ringBuffer, char *c) {
    assert(ringBuffer);
    assert(c);

    if ((ringBuffer) && (c)) {
        if (RingBuffer_GetLen(ringBuffer) == 0)
            return false;

        *c = *(ringBuffer->buffer + ringBuffer->tail);
        ringBuffer->tail++;

        if (ringBuffer->tail == ringBuffer->size)
            ringBuffer->tail = 0;

        ringBuffer->isFull = false;
        return true;

    }
    return false;
}
