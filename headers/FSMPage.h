/*------------------------------------------------------------------------- 
 *
 * FSMPage.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef FSMPAGE_H
#define FSMPAGE_H

#include "Page.h"
#include "stdlib.h"

/*
 * Класс, представляющий собой страницу соответствующего слоя 
 */
class FSMPage: public Page
{
    public:
        FSMPage(unsigned int relOid, PageNumber pageNumber): Page(relOid, FSM_FORK, pageNumber) {}

        /* 
         * Вывод сырой информации о странице 
         */
        void printRawData();
};

#endif  /* FSMPAGE_H*/