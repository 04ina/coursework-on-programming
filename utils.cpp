#include <stdlib.h>
#include <string.h>
#include "headers/RelFile.h" 

const char *const forkNames[] = {
	[MAIN_FORK] = "main",
	[FSM_FORK] = "fsm",
	[VM_FORK] = "vm",
	[INIT_FORK] = "init",
};

unsigned int
strToUint(const char *str)
{
    char **endptr;
    unsigned int uintv = 0;

    uintv = (unsigned int) strtoul(str, endptr, 2);
    if (endptr == NULL)
        throw "str to uint convertation error"; 

    return uintv;
}

ForkType
StrToForkType(const char *forkName)
{
	int	forkNum;

	for (forkNum = MAIN_FORK; forkNum <= INIT_FORK; forkNum++)
		if (strcmp(forkNames[forkNum], forkName) == 0)
			return (ForkType) forkNum;

    throw "str to ForkType convertation error"; 
	return INVALID_FORK;
}
