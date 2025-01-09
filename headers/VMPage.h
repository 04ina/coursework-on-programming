/*------------------------------------------------------------------------- 
 *
 * VMPage.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef VMPAGE_H
#define VMPAGE_H

#include "Page.h"
#include "stdlib.h"

class VMPage: public Page
{
    public:
        VMPage(unsigned int relOid, PageNumber pageNumber): Page(relOid, VM_FORK, pageNumber) {}

        void printRawData(FILE *output);
};

#endif  /* VMPAGE_H*/