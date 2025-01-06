#include "headers/PageHandler.h"
#include "headers/VMPage.h"
#include "headers/FSMPage.h"

#include <stdlib.h>
#include <stdio.h>

void PageHandler::setOutput(FILE *output)
{
    this->output = output;
}

void PageHandler::setInput(FILE *input)
{
    this->input = input;
}

bool PageHandler::printRawFSMPage(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    if (this->output == NULL)
    {
        fprintf(stdout, "The page_header output is not specified");
        return false;
    }

    FILE *output = this->output;
    
    FSMPage fsmPage = FSMPage(relOid, fork, pageNumber);

    fsmPage.printRawData(output);

    return true;
}

bool PageHandler::printRawVMPage(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    if (this->output == NULL)
    {
        fprintf(stdout, "The page_header output is not specified");
        return false;
    }

    FILE *output = this->output;

    VMPage vmPage = VMPage(relOid, fork, pageNumber);
    
    vmPage.printRawData(output);

    return true;
}