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
 * Класс, представляющий собой страницу FSM слоя
 */
class FSMPage: public Page
{
    public:
        FSMPage(unsigned int relOid, ForkType fork, PageNumber pageNumber): Page(relOid, fork, pageNumber) {}

        /* 
         * Вывод сырой информации о странице 
         */
        void printRawData(FILE *output);
};

#endif  /* FSMPAGE_H*/