#include "headers/FSMPage.h"
#include <iostream> 

void FSMPage::printRawData()
{
    char *data = this->rawContent->data;

    for(int i = 0; i < RAW_PAGE_SIZE; i++)
    {
        std::cout << (((unsigned int) data[i]) & 0x000000ff) << " ";
    }
}