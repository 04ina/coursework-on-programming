/*------------------------------------------------------------------------- 
 *
 * MainPage.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "Page.h"
#include "stdlib.h"

/*
 * Класс, представляющий собой страницу соответствующего слоя 
 */
class MainPage: public Page
{
    public:
        MainPage(unsigned int relOid, PageNumber pageNumber): Page(relOid, MAIN_FORK, pageNumber) {}

        /* 
         * Вывод сырой информации о странице 
         */
        void printRawData();
};

#endif  