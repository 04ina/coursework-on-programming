#include "headers/AdvString.h"
#include "headers/FSMPage.h"
#include "headers/Page.h"
#include "headers/PageHandler.h"
#include "headers/PageHeader.h"
#include "headers/RawPage.h"
#include "headers/RelFile.h"
#include "headers/VMPage.h"

#include <getopt.h>
#include <string.h>

#define MAX_PATH_SIZE 256

const char *const forkNames[] = {
	[MAIN_FORK] = "main",
	[FSM_FORK] = "fsm",
	[VM_FORK] = "vm",
	[INIT_FORK] = "init",
};

static void 
help(void);

static ForkType 
StrToForkType(const char *forkName);

unsigned int
strToUint(const char *str);

int
main(int argc, char *argv[])
{
    char c;
    String path(MAX_PATH_SIZE); 

    unsigned int relOid;
    PageNumber pageNumber;
    ForkType fork;

    bool haveRelOid = false;
    bool haveRelPageNumber = false;
    bool haveFork = false;

    bool needHeader = false;
    bool needRaw = false;
    bool need_pg_lsn = false;
    bool need_pd_checksum = false;
    bool need_pg_flags = false;
    bool need_pd_lower = false;
    bool need_pd_upper = false;
    bool need_pd_special = false;
    bool need_pd_pagesize_version = false;
    bool need_pd_prune_xid = false;

    static struct option long_options[] = 
    {
		{"oid", required_argument, NULL, 'o'},
		{"fork", required_argument, NULL, 'f'},
		{"number", required_argument, NULL, 'n'},
		{"header", no_argument, NULL, 'H'},
		{"raw", no_argument, NULL, 'r'},
		{"pg_lsn", no_argument, NULL, 'l'},
		{"pd_checksum", no_argument, NULL, 'c'},
		{"pg_flags", no_argument, NULL, 'a'},
		{"pd_lower", no_argument, NULL, 'w'},
		{"pd_upper", no_argument, NULL, 'u'},
		{"pd_special", no_argument, NULL, 's'},
		{"pd_pagesize_version", no_argument, NULL, 'p'},
		{"pd_prune_xid", no_argument, NULL, 'x'},
		{NULL, 0, NULL, 0}
	};


	if (argc > 1)
	{
		if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
		{
            help();
			exit(0);
		}
	}

    while ((c = getopt_long(argc, argv, "o:f:n:H:r:l:c:a:w:u:s:p:x", long_options, NULL)) != -1)
    {
        switch(c)
        {
            case 'o': 
                relOid = strToUint(optarg);

                haveRelOid = true;
                break;
            case 'f':
                try 
                {
                    fork = StrToForkType(optarg);
                } 
                catch (...) 
                {
                    printf("error: Указано недопустимое значение слоя отношения. Допустимые значения: main, vm, fsm, init\n");
                    exit(0);
                }

                haveFork = true;
                break;
            case 'n':
                pageNumber = (PageNumber) strToUint(optarg);

                haveRelPageNumber = true;
                break;
            case 'H': 
                needHeader = true;
                break;
            case 'r': 
                needRaw = true;
                break;
            case 'l': 
                need_pg_lsn = true;
                break;
            case 'c': 
                need_pd_checksum = true;
                break;
            case 'a': 
                need_pg_flags = true;
                break;
            case 'w': 
                need_pd_lower = true;
                break;
            case 'u': 
                need_pd_upper = true;
                break;
            case 's': 
                need_pd_special = true;
                break;
            case 'p': 
                need_pd_pagesize_version = true;
                break;
            case 'x': 
                need_pd_prune_xid = true;
                break;


        }
    }

    if ((haveRelOid == false) ||
        (haveFork == false) ||
        (haveRelPageNumber == false))
    {
        if (haveRelOid == false) 
        {
            printf("error: Параметр oid является обязательным\n");
        }

        if (haveFork == false) 
        {
            printf("error: Параметр fork является обязательным\n");
        }

        if (haveRelPageNumber == false) 
        {
            printf("error: Параметр number является обязательным\n");
        }

        printf("\nДля помощи используйте параметр --help\n");

        exit(0);
    }
    
    PageHandler handler;
    handler.setInput(stdin);
    handler.setInput(stdout);

    if (needRaw == true)
    {
        handler.printRawPage(relOid, fork, pageNumber);
    }

    if (needHeader == true)
    {
        handler.printHeader(relOid, fork, pageNumber);
    }

    if (need_pg_lsn == true)
    {
        handler.print_pg_lsn(relOid, fork, pageNumber);
    }

    if (need_pd_checksum == true)
    {
        handler.print_pd_checksum(relOid, fork, pageNumber);
    }

    if (need_pg_flags == true)
    {
        handler.print_pg_flags(relOid, fork, pageNumber);
    }

    if (need_pd_lower == true)
    {
        handler.print_pd_lower(relOid, fork, pageNumber);
    }

    if (need_pd_upper == true)
    {
        handler.print_pd_upper(relOid, fork, pageNumber);
    }

    if (need_pd_special == true)
    {
        handler.print_pd_special(relOid, fork, pageNumber);
    }

    if (need_pd_pagesize_version == true)
    {
        handler.print_pd_pagesize_version(relOid, fork, pageNumber);
    }

    if (need_pd_prune_xid == true)
    {
        handler.print_pd_prune_xid(relOid, fork, pageNumber);
    }

    return 0;
}

static void
help(void)
{
	printf("page_inspect позволяет изучать содержимое страниц main, vm, fsm и init файлов СУБД PostgreSQL. \n");
	printf("\n");
	printf("-h or --help - мануал\n");
	printf("-o or --oid - oid отношения, страницу которого необходимо изучить (обязательный параметр)\n");
	printf("-f or --fork - fork, в котором находится необходимая страница (обязательный параметр)\n");
	printf("-n or --number - Номер необходимой страницы (обязательный параметр)\n");
	printf("-H or --header - Вывод загаловка страницы\n");
	printf("-r or --raw - Вывод необработанного содержимого страницы\n");
	printf("-l or --pg_lsn - Вывод pg_lsn\n");
	printf("-c or --pd_checksum - Вывод pd_checksum\n");
	printf("-a or --pg_flags - Вывод pg_flags\n");
	printf("-w or --pd_lower - Вывод pd_lower\n");
	printf("-u or --pd_upper - Вывод pd_upper\n");
	printf("-s or --pd_special - Вывод \n");
	printf("-p or --pd_pagesize_version - Вывод pd_pagesize_version\n");
	printf("-x or --pd_prune_xid - Вывод pd_prune_xid\n");
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

unsigned int
strToUint(const char *str)
{
    unsigned int uintv = 0;

    uintv = (unsigned int) atoi(str);

    return uintv;
}