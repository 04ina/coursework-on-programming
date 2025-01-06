/*------------------------------------------------------------------------- 
 *
 * AdvString.cpp
 * 
 *------------------------------------------------------------------------- 
 */

#include "headers/AdvString.h"

String::String(size_t size)
{
    this->size = size;

    this->ptr = new char[size];
}

String::~String(void)
{
    delete [] (this->ptr);
}