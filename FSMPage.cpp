#include "headers/FSMPage.h"

void FSMPage::printRawData(FILE *output)
{
    for(int i = 0; i < RAW_PAGE_SIZE; i++)
    {
        fprintf(output, "%u ", 
                this->rawContent->data[i] & 0x000000FF);
    }
}