#pragma once
#include <iostream>
#include <memory>

/**
 * @brief Circular Buffer used for saving the context. It always inserts new chars in a circular fashion, and reads it's content the same way. 
 * 
 */
class CircularBuffer 
{
    private:
        std::unique_ptr<char[]> data;   /*!< Array wich will store the data */
        int head = 0;                   /*!< Head of the buffer */
        int tail = 0;                   /*!< Tail of the buffer */
        int size;                       /*!< Size of the buffer */

    public:
        /**
         * @brief Construct a new Circular Buffer object.
         * 
         * @param size of the buffer to be allocated.
         */
        CircularBuffer(int size) : data(std::unique_ptr<char []>(std::make_unique<char[]>(size))), size(size){};
        /**
         * @brief Inserts a Char type onto the buffer's tail.
         * 
         * @param character to be inserted.
         */
        void putChar(char character);
        /**
         * @brief Resets the buffer positional counters.
         * 
         */
        void resetBuffer();
        /**
         * @brief Returns the last character added to the circular buffer
         * 
         * @return char 
         */
        char getLast();
        /**
         * @brief Read the content of the buffer, starting from the last place read, so that it reads in a 
         * circular fashion. It's usefull because we don't want read the buffer always from the start, since 
         * we are interested in getting the context (wich are the last characters up to the one inserted) later on.
         * 
         * @return std::string  
         */
        std::string readBuffer();
        /**
         * @brief Returns the buffer size.
         * 
         * @return int Buffer size.
         */
        int bufferSize();
};
