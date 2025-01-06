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
         * Вывод сырой информации о сырых страницах, находящихся в VM и FSM слоях 
         */
        bool printRawFSMPage(unsigned int relOid, ForkType fork, PageNumber pageNumber);

        bool printRawVMPage(unsigned int relOid, ForkType fork, PageNumber pageNumber);
};



#endif  /* PAGE_HANDLER_H */