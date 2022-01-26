#pragma once
#include <iostream>
#include <memory>

/**
 * @brief Circular Buffer used for loading text from a file.
 * 
 */
class CircularBuffer 
{
    private:
        std::unique_ptr<char[]> data;   /*!< Runtime resizable array of data */
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
         * @brief Loads a Char type onto the buffer's tail.
         * 
         * @param character to be inserted.
         */
        void putChar(char character);
        /**
         * @brief Clears the buffer.
         * 
         */
        void resetBuffer();
        /**
         * @brief Returns the last character added to the circular buffer
         * 
         */
        char getLast();
        /**
         * @brief Returns the last char without consuming it.
         * @brief Read the content of the buffer, starting from the last place read, so that it keeps a correct window of where it should be considered text.
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
