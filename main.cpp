#include "headers/AdvString.h"
#include "headers/FSMPage.h"
#include "headers/Page.h"
#include "headers/PageHandler.h"
#include "headers/PageHeader.h"
#include "headers/RawPage.h"
#include "headers/RelFile.h"
#include "headers/VMPage.h"
#include "headers/utils.h"

#include <getopt.h>
#include <string.h>

static void help(void);

#define MAX_PATH_SIZE 256

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

    static struct option long_options[] = 
    {
		{"oid", required_argument, NULL, 'o'},
		{"fork", required_argument, NULL, 'f'},
		{"number", required_argument, NULL, 'n'},
		{"header", no_argument, NULL, 'H'},
		{"raw", no_argument, NULL, 'r'},
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

    while ((c = getopt_long(argc, argv, "o:f:n:H:r", long_options, NULL)) != -1)
    {
        switch(c)
        {
            case 'o': 
                try 
                {
                    relOid = strToUint(optarg);
                } 
                catch (...) 
                {
                    printf("error: Параметр --oid не соответствует типу unsigned int\n");
                    exit(0);
                }

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
                try 
                {
                    pageNumber = (PageNumber) strToUint(optarg);
                } 
                catch (...) 
                {
                    printf("error: Параметр --number не соответствует типу unsigned int\n");
                    exit(0);
                }

                haveRelPageNumber = true;
                break;
            case 'H': 
                needHeader = true;
                break;
            case 'r': 
                needRaw = true;
                break;
        }
    }

    if ((haveRelOid == false) ||
        (haveFork == false) ||
        (haveRelPageNumber == false))
    {

        if (haveRelOid == false) 
        {
            printf("Параметр oid является обязательным\n");
        }

        if (haveFork == false) 
        {
            printf("Параметр fork является обязательным\n");
        }

        if (haveRelPageNumber == false) 
        {
            printf("Параметр number является обязательным\n");
        }

        exit(0);
    }
    
    PageHandler handler;
    handler.setInput(stdin);
    handler.setInput(stdout);
    

    if (needRaw == true)
    {
        handler.printRawPage(relOid, fork, pageNumber);
    }

    if (needRaw == true)
    {
        handler.printRawPage(relOid, fork, pageNumber);
    }

    return 0;
}

/*
    String str = String(10);


    RelFile relFile = RelFile(1247, FSM_FORK);
    relFile.openForRead();

    RawPage rawPage = RawPage();
    relFile.readRawPage(0, rawPage.data);

    relFile.close();

    RawPage rawPage2 = RawPage();
    rawPage2.read(1247, FSM_FORK, 0);

    Page page = Page(1247, FSM_FORK, 0);

    printf("%hd", page.header->data.pd_pagesize_version);


    VMPage vmPage = VMPage(1247, VM_FORK, 0);
    FSMPage fsmPage = FSMPage(1247, FSM_FORK, 0);

    vmPage.printRawData(stdout);
    printf("\n-------------\n");
    fsmPage.printRawData(stdout);

    printf("\n");

    FSMPage *fsmPages = new FSMPage[] {{1247, FSM_FORK, 0},
                                        {1247, FSM_FORK, 1},
                                        {1247, FSM_FORK, 2},
                                        {1247, FSM_FORK, 3}};
    for (int i = 0; i < 4; i++)
    {
        fsmPages[i].printRawData(stdout);
    }


    FSMPage *fsmPages_2[4];
    fsmPages_2[0] = new FSMPage(1247, FSM_FORK, 0);
    fsmPages_2[1] = new FSMPage(1247, FSM_FORK, 1);
    fsmPages_2[2] = new FSMPage(1247, FSM_FORK, 2);
    fsmPages_2[3] = new FSMPage(1247, FSM_FORK, 3);

    for (int i = 0; i < 4; i++)
    {
        fsmPages_2[i]->printRawData(stdout);
    }


    PageHandler pageHandler = PageHandler();

    pageHandler.setOutput(stdout);
    pageHandler.setInput(stdin);

    pageHandler.printRawFSMPage(1247, FSM_FORK, 0);
    printf("\n-------------\n");
    pageHandler.printRawVMPage(1247, FSM_FORK, 0);
*/

static void
help(void)
{
	printf("help");
}
