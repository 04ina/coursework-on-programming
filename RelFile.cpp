#include "headers/RelFile.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>


#define MAX_REL_FILE_NAME_SIZE 100

#define RAW_PAGE_SIZE 8192

#define INVALID_REL_FILE (RelFile) 0

RelFile::RelFile(RelOid relOid, ForkType fork)
{
    this->fork = fork;
    this->relOid = relOid;
}

void RelFile::getParseName(String *fileName)
{
    sprintf(fileName->ptr, "%d", (int) this->relOid);

    switch (this->fork)
    {
        case MAIN_FORK:
            break;
        case FSM_FORK:
            strcat(fileName->ptr, "_fsm");
            break;
        case VM_FORK:
            strcat(fileName->ptr, "_vm");
            break;
        case INIT_FORK:
            strcat(fileName->ptr, "_init");
            break;
        default:
            assert(0);
    }
}

bool RelFile::readRawPage(unsigned int pageNumber, char *rawPage)
{
    int result;

    result = fseek(this->file, RAW_PAGE_SIZE * pageNumber, SEEK_SET);

    if (result != 0)
    {
        /* page not found */
        return false;
    }

    fread((char *) rawPage, RAW_PAGE_SIZE, 1, this->file);

    fseek(this->file, 0, SEEK_END);

    return true;
}

void RelFile::openForRead(void) 
{
    String fileName = String(MAX_REL_FILE_NAME_SIZE);

    this->getParseName(&fileName);

    this->file = fopen(fileName.ptr, "r");
}

void RelFile::close(void) 
{
    fclose(this->file);
}