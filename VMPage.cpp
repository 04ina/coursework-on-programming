#include "headers/VMPage.h"
#include <iostream> 

void VMPage::printRawData()
{
    char *data = this->rawContent->data;

    for(int i = 0; i < RAW_PAGE_SIZE; i++)
    {
        std::cout << ((((unsigned int) data[i]) & 0xF0) >> 4) << "_" << (((unsigned int) data[i]) & 0x0F) << "  ";
    }
}