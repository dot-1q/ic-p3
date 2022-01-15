#pragma once
#include <iostream>
#include <memory>

class CircularBuffer 
{
    private:
        std::unique_ptr<char[]> data;
        int head = 0;
        int read_from = 0; 
        int tail = 0;
        int size;

    public:
        CircularBuffer(int size) : data(std::unique_ptr<char []>(std::make_unique<char[]>(size))), size(size){};
        void putChar(char character);
        void resetBuffer();
        char getChar();
        // similar to getChar, but returns the char at the index of the data array
        char getCharAt(int index);
        // similar to getChar, but doesn't consume the character, simply returns it
        char getLast();
        // Read the content of the buffer, starting from the last place we read, so that we keep a correct
        // window of where we should be considering text
        std::string readBuffer();
        int bufferSize();
};
