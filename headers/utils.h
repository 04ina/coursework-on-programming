/*------------------------------------------------------------------------- 
 *
 * utils.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef UTILS_H 
#define UTILS_H

#include "RelFile.h" 

unsigned int strToUint(const char *str);

ForkType StrToForkType(const char *forkName);

#endif  /* UTILS_H */ 