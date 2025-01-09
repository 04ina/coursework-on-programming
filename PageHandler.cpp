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

bool PageHandler::printRawPage(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    if (this->output == NULL)
    {
        fprintf(stdout, "The page_header output is not specified");
        return false;
    }

    FILE *output = this->output;

    switch (fork) 
    {
        case FSM_FORK:
            FSMPage fsmPage = FSMPage(relOid, pageNumber);
            fsmPage.printRawData(output);
            break;
        case VM_FORK:
            VMPage vmPage = VMPage(relOid, pageNumber);
            vmPage.printRawData(output);
            break;
    }   

    return true;
}