#include "headers/RawPage.h"

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

RawPage::RawPage(void)
{
    this->data = new char[RAW_PAGE_SIZE];
}

RawPage::~RawPage(void)
{
    delete [] this->data;
}

void RawPage::read(unsigned int relOid, ForkType fork, unsigned int pageNumber)
{
    RelFile relFile = RelFile(relOid, fork);
    bool found;

    relFile.openForRead(); 
    
    found = relFile.readRawPage(pageNumber, this->data);
    if (!found)
    {
        assert(0);
    }

    relFile.close();
}

void RawPage::parseHeader(PageHeader *pageHeader)
{
    memcpy((char *) &pageHeader->data, this->data, sizeof(PageHeaderData));
}