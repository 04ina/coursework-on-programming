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
        VMPage(unsigned int relOid, ForkType fork, PageNumber pageNumber): Page(relOid, fork, pageNumber) {}

        void printRawData(FILE *output);
};

#endif  /* VMPAGE_H*/