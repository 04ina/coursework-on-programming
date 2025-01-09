/*------------------------------------------------------------------------- 
 *
 * RelFile.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef REL_FILE_H 
#define REL_FILE_H

#include <stdio.h>
#include <stdbool.h>
#include "AdvString.h"

typedef int RelOid;

/*
 * Виды слоев отношения
 */
typedef enum ForkType {
    MAIN_FORK,
    FSM_FORK,
    VM_FORK,
    INIT_FORK,
    INVALID_FORK,
} ForkType;

/*
 * Класс, представляющий собой определенный файл отношения
 */
class RelFile
{
    public:
        FILE        *file;
        RelOid      relOid;
        ForkType    fork;

        RelFile(RelOid relOid, ForkType fork);

        /* 
         * Чтение сырой страницы из файла 
         */
        bool readRawPage(unsigned int pageNumber, char *rawPage);

        /*
         * Открытие файла для чтения 
         */
        void openForRead(void);

        /*
         * Закрытие файла 
         */
        void close(void);

    private:
        void getParseName(String *fileName);
};

#endif  /* REL_FILE_H */