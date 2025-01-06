#include "headers/VMPage.h"

void VMPage::printRawData(FILE *output)
{
    for(int i = 0; i < RAW_PAGE_SIZE; i++)
    {
        fprintf(output, "%x%x", 
                this->rawContent->data[i] & (0xF0),   
                this->rawContent->data[i] & (0x0F));
    }
}