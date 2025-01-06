/*------------------------------------------------------------------------- 
 *
 * RawPage.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef RAW_PAGE_H
#define RAW_PAGE_H

#include "RelFile.h"
#include "PageHeader.h"

#define RAW_PAGE_SIZE 8192

class RawPage
{
    public:
        char *data;

        RawPage(void);

        ~RawPage(void);

        /*
         * Чтение сырой старницы 
         */
        void read(unsigned int relOid, ForkType fork, unsigned int pageNumber);

        /*
         * Парсинг заголовка страницы 
         */
        void parseHeader(PageHeader *pageHeader);
};

#endif  /* RAW_PAGE_H */