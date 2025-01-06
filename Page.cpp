#include "headers/Page.h"

#include <stdbool.h>
#include "stdlib.h"

#include "headers/RawPage.h"

Page::~Page(void) 
{
    delete this->rawContent;
    delete this->header;
}

Page::Page(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    this->rawContent = new RawPage();
    this->header = new PageHeader();
    bool found;

    rawContent->read(relOid, fork, pageNumber);

    rawContent->parseHeader(this->header);

    this->number = pageNumber;
    this->fork = fork;
    this->relOid = relOid;
}
