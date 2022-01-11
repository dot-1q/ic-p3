#include "CircularBuffer.h"

void CircularBuffer::putChar(char character)
{
    if(!isFull())
    {
        this->data[this->tail] = character;
        this->tail = (this->tail+1) % this->size;
        this->count++;
    }
}

char CircularBuffer::getChar()
{
    if(!isEmpty())
    {
        char out_char = this->data[this->head]; 
        this->data[this->head] = '\0';
        this->head = (this->head+1) % this->size;
        this->count--;
        return out_char;
    }
    return '\0';
}

void CircularBuffer::resetBuffer()
{
    this->head = 0;
    this->tail = 0;
    this->count = 0;
}

int CircularBuffer::bufferSize()
{
   return this->size; 
}

bool CircularBuffer::isEmpty()
{
    return this->count == 0;
}

bool CircularBuffer::isFull()
{
    return this->count == this->size;
}

