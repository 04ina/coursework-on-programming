/*------------------------------------------------------------------------- 
 *
 * PageHandler.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef PAGE_HANDLER_H
#define PAGE_HANDLER_H

#include "RelFile.h"
#include "RawPage.h"
#include "VMPage.h"
#include "FSMPage.h"

/*
 * Класс, представляющий собой интерфейс работы с страницами.
 */
class PageHandler
{
    private:
        FILE *output;
        FILE *input;

    public:
        /*
         * Установка I/O 
         */
        void setOutput(FILE *output);
        void setInput(FILE *input);

        /*
         * Вывод сырой информации о сырых страницах, находящихся в различных слоях 
         */
        bool 
        printRawPage(unsigned int relOid, ForkType fork, PageNumber pageNumber);
        
        bool 
        printHeader(unsigned int relOid, ForkType fork, PageNumber pageNumber);

        bool 
        print_pg_lsn(unsigned int relOid, ForkType fork, PageNumber pageNumber);

        bool 
        print_pd_checksum(unsigned int relOid, ForkType fork, PageNumber pageNumber);

        bool 
        print_pg_flags(unsigned int relOid, ForkType fork, PageNumber pageNumber);

        bool 
        print_pd_lower(unsigned int relOid, ForkType fork, PageNumber pageNumber);

        bool 
        print_pd_upper(unsigned int relOid, ForkType fork, PageNumber pageNumber);

        bool 
        print_pd_special(unsigned int relOid, ForkType fork, PageNumber pageNumber);

        bool 
        print_pd_pagesize_version(unsigned int relOid, ForkType fork, PageNumber pageNumber);

        bool 
        print_pd_prune_xid(unsigned int relOid, ForkType fork, PageNumber pageNumber);
};


#endif  /* PAGE_HANDLER_H */