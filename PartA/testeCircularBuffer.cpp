#include "CircularBuffer.h"
#include <iostream>

int main(void)
{
    CircularBuffer buffer = CircularBuffer(4);

    buffer.putChar('a');
    std::cout << buffer.isFull() << std::endl;
    buffer.putChar('b');
    std::cout << buffer.isFull() << std::endl;
    buffer.putChar('c');
    std::cout << buffer.isFull() << std::endl;
    buffer.putChar('d');
    std::cout << buffer.isFull() << std::endl;
    buffer.putChar('e');
    std::cout << buffer.isFull() << std::endl;
    buffer.putChar('f');
    
    std::cout << "Loop" << std::endl;
    for (int i = 0; i<9; i++) 
    {
        std::cout << buffer.getChar() << std::endl;
        std::cout << buffer.isEmpty() << std::endl;
    }
    return 0;
}
