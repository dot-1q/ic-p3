#include "CircularBuffer.h"

void CircularBuffer::putChar(char character)
{
    this->data[this->tail] = character;
    this->tail = (this->tail+1) % this->size;
}

char CircularBuffer::getChar()
{
    char out_char = this->data[this->head]; 
    this->data[this->head] = '\0';
    this->head = (this->head+1) % this->size;
    return out_char;
}

void CircularBuffer::resetBuffer()
{
    this->head = 0;
    this->tail = 0;
}

int CircularBuffer::bufferSize()
{
   return this->size; 
}
