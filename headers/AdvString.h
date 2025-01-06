/*------------------------------------------------------------------------- 
 *
 * AdvString.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef ADV_STRING_H 
#define ADV_STRING_H

#include <stdlib.h>

class String
{
    public:
        size_t size;
        char *ptr;

        String(size_t size);
        ~String(void);
};

#endif  /* ADV_STRING_H */