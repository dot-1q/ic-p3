#pragma once
#include <iostream>
#include <memory>

class CircularBuffer 
{
    private:
        std::unique_ptr<char[]> data;
        int head = 0;
        int tail = 0;
        int size;

    public:
        CircularBuffer(int size) : data(std::unique_ptr<char []>(std::make_unique<char[]>(size))), size(size){};
        void putChar(char character);
        void resetBuffer();
        char getChar();
        int bufferSize();
};
