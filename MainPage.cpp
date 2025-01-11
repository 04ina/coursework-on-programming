#include "headers/MainPage.h"
#include <iostream> 

void MainPage::printRawData(void)
{
    char *data = this->rawContent->data;

    for(int i = 0; i < RAW_PAGE_SIZE; i++)
    {
        std::cout << (((unsigned int) data[i]) & 0x000000ff) << " ";
    }
}