/*------------------------------------------------------------------------- 
 *
 * Page.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef PAGE_H
#define PAGE_H

#include "RawPage.h"
#include "PageHeader.h"
#include "RelFile.h"

typedef unsigned int PageNumber;

/*
 * Класс старницы отнгошения. Используется как наследуемый класс. 
 */
class Page
{
    public:
        PageHeader *header;
        RawPage    *rawContent;

        PageNumber number;
        ForkType fork;
        unsigned int relOid;

        Page(unsigned int rel_oid, ForkType fork, PageNumber page_number);

        ~Page(void);
}; 

#endif  /* PAGE_H */