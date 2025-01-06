#include "headers/AdvString.h"
#include "headers/FSMPage.h"
#include "headers/Page.h"
#include "headers/PageHandler.h"
#include "headers/PageHeader.h"
#include "headers/RawPage.h"
#include "headers/RelFile.h"
#include "headers/VMPage.h"

int
main(void)
{
    /*
     * AdvString example 
     */    
    String str = String(10);

    /*
     * RelFile and RawPage examples
     */

    RelFile relFile = RelFile(1247, FSM_FORK);
    relFile.openForRead();

    RawPage rawPage = RawPage();
    relFile.readRawPage(0, rawPage.data);

    relFile.close();

    RawPage rawPage2 = RawPage();
    rawPage2.read(1247, FSM_FORK, 0);

    /*
     * Page and PageHeaders examples
     */
    Page page = Page(1247, FSM_FORK, 0);

    printf("%hd", page.header->data.pd_pagesize_version);

    /*
     * VMPage and FSMPage examples:
     */

    VMPage vmPage = VMPage(1247, VM_FORK, 0);
    FSMPage fsmPage = FSMPage(1247, FSM_FORK, 0);

    vmPage.printRawData(stdout);
    printf("\n-------------\n");
    fsmPage.printRawData(stdout);

    printf("\n");

    /*
     * Динамический массив объектов класса FSMPage
     */
    FSMPage *fsmPages = new FSMPage[] {{1247, FSM_FORK, 0},
                                        {1247, FSM_FORK, 1},
                                        {1247, FSM_FORK, 2},
                                        {1247, FSM_FORK, 3}};
    for (int i = 0; i < 4; i++)
    {
        fsmPages[i].printRawData(stdout);
    }

    /*
     * Массив динамических объектов класса FSMPage
     */

    FSMPage *fsmPages_2[4];
    fsmPages_2[0] = new FSMPage(1247, FSM_FORK, 0);
    fsmPages_2[1] = new FSMPage(1247, FSM_FORK, 1);
    fsmPages_2[2] = new FSMPage(1247, FSM_FORK, 2);
    fsmPages_2[3] = new FSMPage(1247, FSM_FORK, 3);

    for (int i = 0; i < 4; i++)
    {
        fsmPages_2[i]->printRawData(stdout);
    }


    /*
     * Page handler example:
     */
    PageHandler pageHandler = PageHandler();

    pageHandler.setOutput(stdout);
    pageHandler.setInput(stdin);

    pageHandler.printRawFSMPage(1247, FSM_FORK, 0);
    printf("\n-------------\n");
    pageHandler.printRawVMPage(1247, FSM_FORK, 0);

    return 0;
}