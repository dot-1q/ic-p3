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
        // Simply returns the last character added to the circular buffer
        char getLast();
        // Read the content of the buffer, starting from the last place we read, so that we keep a correct
        // window of where we should be considering text
        std::string readBuffer();
        int bufferSize();
};
