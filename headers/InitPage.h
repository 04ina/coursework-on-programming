/*------------------------------------------------------------------------- 
 *
 * InitPage.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef INITPAGE_H
#define INITPAGE_H

#include "Page.h"
#include "stdlib.h"

/*
 * Класс, представляющий собой страницу соответствующего слоя 
 */
class InitPage: public Page
{
    public:
        InitPage(unsigned int relOid, PageNumber pageNumber): Page(relOid, INIT_FORK, pageNumber) {}

        /* 
         * Вывод сырой информации о странице 
         */
        void printRawData();
};

#endif  