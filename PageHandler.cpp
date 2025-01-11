#include "headers/PageHandler.h"
#include "headers/VMPage.h"
#include "headers/FSMPage.h"
#include "headers/MainPage.h"
#include "headers/InitPage.h"

#include <stdlib.h>
#include <stdio.h>

/*
 * Print headers
 */
static void 
PrintFSMPageHeader(unsigned int relOid, PageNumber pageNumber)
{
    FSMPage fsmPage = FSMPage(relOid, pageNumber);
    fsmPage.header->print_all();

}

static void 
PrintVMPageHeader(unsigned int relOid, PageNumber pageNumber)
{
    VMPage vmPage = VMPage(relOid, pageNumber);
    vmPage.header->print_all();
}

static void 
PrintMainPageHeader(unsigned int relOid, PageNumber pageNumber)
{
    MainPage mainPage = MainPage(relOid, pageNumber);
    mainPage.header->print_all();
}

static void 
PrintInitPageHeader(unsigned int relOid, PageNumber pageNumber)
{
    InitPage initPage = InitPage(relOid, pageNumber);
    initPage.header->print_all();
}

/*
 * Print raw page
 */
static void 
PrintFSMPageRaw(unsigned int relOid, PageNumber pageNumber)
{
    FSMPage fsmPage = FSMPage(relOid, pageNumber);
    fsmPage.printRawData();

}

static void 
PrintVMPageRaw(unsigned int relOid, PageNumber pageNumber)
{
    VMPage vmPage = VMPage(relOid, pageNumber);
    vmPage.printRawData();
}

static void 
PrintMainPageRaw(unsigned int relOid, PageNumber pageNumber)
{
    MainPage mainPage = MainPage(relOid, pageNumber);
    mainPage.printRawData();
}

static void 
PrintInitPageRaw(unsigned int relOid, PageNumber pageNumber)
{
    InitPage initPage = InitPage(relOid, pageNumber);
    initPage.printRawData();
}

/*
 * Print pg_lsn
 */
static void 
PrintFSMPage_pg_lsn(unsigned int relOid, PageNumber pageNumber)
{
    FSMPage fsmPage = FSMPage(relOid, pageNumber);
    fsmPage.header->print_pg_lsn();

}

static void 
PrintVMPage_pg_lsn(unsigned int relOid, PageNumber pageNumber)
{
    VMPage vmPage = VMPage(relOid, pageNumber);
    vmPage.header->print_pg_lsn();
}

static void 
PrintMainPage_pg_lsn(unsigned int relOid, PageNumber pageNumber)
{
    MainPage mainPage = MainPage(relOid, pageNumber);
    mainPage.header->print_pg_lsn();
}

static void 
PrintInitPage_pg_lsn(unsigned int relOid, PageNumber pageNumber)
{
    InitPage initPage = InitPage(relOid, pageNumber);
    initPage.header->print_pg_lsn();
}

/*
 * Print pd_checksum
 */
static void 
PrintFSMPage_pd_checksum(unsigned int relOid, PageNumber pageNumber)
{
    FSMPage fsmPage = FSMPage(relOid, pageNumber);
    fsmPage.header->print_pd_checksum();

}

static void 
PrintVMPage_pd_checksum(unsigned int relOid, PageNumber pageNumber)
{
    VMPage vmPage = VMPage(relOid, pageNumber);
    vmPage.header->print_pd_checksum();
}

static void 
PrintMainPage_pd_checksum(unsigned int relOid, PageNumber pageNumber)
{
    MainPage mainPage = MainPage(relOid, pageNumber);
    mainPage.header->print_pd_checksum();
}

static void 
PrintInitPage_pd_checksum(unsigned int relOid, PageNumber pageNumber)
{
    InitPage initPage = InitPage(relOid, pageNumber);
    initPage.header->print_pd_checksum();
}

/*
 * Print pg_flags
 */
static void 
PrintFSMPage_pg_flags(unsigned int relOid, PageNumber pageNumber)
{
    FSMPage fsmPage = FSMPage(relOid, pageNumber);
    fsmPage.header->print_pg_flags();

}

static void 
PrintVMPage_pg_flags(unsigned int relOid, PageNumber pageNumber)
{
    VMPage vmPage = VMPage(relOid, pageNumber);
    vmPage.header->print_pg_flags();
}

static void 
PrintMainPage_pg_flags(unsigned int relOid, PageNumber pageNumber)
{
    MainPage mainPage = MainPage(relOid, pageNumber);
    mainPage.header->print_pg_flags();
}

static void 
PrintInitPage_pg_flags(unsigned int relOid, PageNumber pageNumber)
{
    InitPage initPage = InitPage(relOid, pageNumber);
    initPage.header->print_pg_flags();
}

/*
 * Print pd_lower
 */
static void 
PrintFSMPage_pd_lower(unsigned int relOid, PageNumber pageNumber)
{
    FSMPage fsmPage = FSMPage(relOid, pageNumber);
    fsmPage.header->print_pd_lower();

}

static void 
PrintVMPage_pd_lower(unsigned int relOid, PageNumber pageNumber)
{
    VMPage vmPage = VMPage(relOid, pageNumber);
    vmPage.header->print_pd_lower();
}

static void 
PrintMainPage_pd_lower(unsigned int relOid, PageNumber pageNumber)
{
    MainPage mainPage = MainPage(relOid, pageNumber);
    mainPage.header->print_pd_lower();
}

static void 
PrintInitPage_pd_lower(unsigned int relOid, PageNumber pageNumber)
{
    InitPage initPage = InitPage(relOid, pageNumber);
    initPage.header->print_pd_lower();
}

/*
 * Print pd_upper
 */
static void 
PrintFSMPage_pd_upper(unsigned int relOid, PageNumber pageNumber)
{
    FSMPage fsmPage = FSMPage(relOid, pageNumber);
    fsmPage.header->print_pd_upper();

}

static void 
PrintVMPage_pd_upper(unsigned int relOid, PageNumber pageNumber)
{
    VMPage vmPage = VMPage(relOid, pageNumber);
    vmPage.header->print_pd_upper();
}

static void 
PrintMainPage_pd_upper(unsigned int relOid, PageNumber pageNumber)
{
    MainPage mainPage = MainPage(relOid, pageNumber);
    mainPage.header->print_pd_upper();
}

static void 
PrintInitPage_pd_upper(unsigned int relOid, PageNumber pageNumber)
{
    InitPage initPage = InitPage(relOid, pageNumber);
    initPage.header->print_pd_upper();
}

/*
 * Print pd_special
 */
static void 
PrintFSMPage_pd_special(unsigned int relOid, PageNumber pageNumber)
{
    FSMPage fsmPage = FSMPage(relOid, pageNumber);
    fsmPage.header->print_pd_special();

}

static void 
PrintVMPage_pd_special(unsigned int relOid, PageNumber pageNumber)
{
    VMPage vmPage = VMPage(relOid, pageNumber);
    vmPage.header->print_pd_special();
}

static void 
PrintMainPage_pd_special(unsigned int relOid, PageNumber pageNumber)
{
    MainPage mainPage = MainPage(relOid, pageNumber);
    mainPage.header->print_pd_special();
}

static void 
PrintInitPage_pd_special(unsigned int relOid, PageNumber pageNumber)
{
    InitPage initPage = InitPage(relOid, pageNumber);
    initPage.header->print_pd_special();
}

/*
 * Print pd_pagesize_version
 */
static void 
PrintFSMPage_pd_pagesize_version(unsigned int relOid, PageNumber pageNumber)
{
    FSMPage fsmPage = FSMPage(relOid, pageNumber);
    fsmPage.header->print_pd_pagesize_version();

}

static void 
PrintVMPage_pd_pagesize_version(unsigned int relOid, PageNumber pageNumber)
{
    VMPage vmPage = VMPage(relOid, pageNumber);
    vmPage.header->print_pd_pagesize_version();
}

static void 
PrintMainPage_pd_pagesize_version(unsigned int relOid, PageNumber pageNumber)
{
    MainPage mainPage = MainPage(relOid, pageNumber);
    mainPage.header->print_pd_pagesize_version();
}

static void 
PrintInitPage_pd_pagesize_version(unsigned int relOid, PageNumber pageNumber)
{
    InitPage initPage = InitPage(relOid, pageNumber);
    initPage.header->print_pd_pagesize_version();
}

/*
 * Print pd_prune_xid
 */
static void 
PrintFSMPage_pd_prune_xid(unsigned int relOid, PageNumber pageNumber)
{
    FSMPage fsmPage = FSMPage(relOid, pageNumber);
    fsmPage.header->print_pd_prune_xid();

}

static void 
PrintVMPage_pd_prune_xid(unsigned int relOid, PageNumber pageNumber)
{
    VMPage vmPage = VMPage(relOid, pageNumber);
    vmPage.header->print_pd_prune_xid();
}

static void 
PrintMainPage_pd_prune_xid(unsigned int relOid, PageNumber pageNumber)
{
    MainPage mainPage = MainPage(relOid, pageNumber);
    mainPage.header->print_pd_prune_xid();
}

static void 
PrintInitPage_pd_prune_xid(unsigned int relOid, PageNumber pageNumber)
{
    InitPage initPage = InitPage(relOid, pageNumber);
    initPage.header->print_pd_prune_xid();
}

/*
 * Init output and input
 */
void 
PageHandler::setOutput(FILE *output)
{
    this->output = output;
}

void 
PageHandler::setInput(FILE *input)
{
    this->input = input;
}

/*
 * handlers 
 */
bool 
PageHandler::printRawPage(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    switch (fork) 
    {
        case FSM_FORK:
            PrintFSMPageRaw(relOid, pageNumber);
            break;
        case VM_FORK:
            PrintVMPageRaw(relOid, pageNumber);
            break;
        case MAIN_FORK:
            PrintMainPageRaw(relOid, pageNumber);
            break;
        case INIT_FORK:
            PrintInitPageRaw(relOid, pageNumber);
            break;
    }   

    return true;
}

bool 
PageHandler::printHeader(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    switch (fork) 
    {
        case FSM_FORK:
            PrintFSMPageHeader(relOid, pageNumber);
            break;
        case VM_FORK:
            PrintVMPageHeader(relOid, pageNumber);
            break;
        case MAIN_FORK:
            PrintMainPageHeader(relOid, pageNumber);
            break;
        case INIT_FORK:
            PrintInitPageHeader(relOid, pageNumber);
            break;
    }   

    return true;
}

bool 
PageHandler::print_pg_lsn(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    switch (fork) 
    {
        case FSM_FORK:
            PrintFSMPage_pg_lsn(relOid, pageNumber);
            break;
        case VM_FORK:
            PrintVMPage_pg_lsn(relOid, pageNumber);
            break;
        case MAIN_FORK:
            PrintMainPage_pg_lsn(relOid, pageNumber);
            break;
        case INIT_FORK:
            PrintInitPage_pg_lsn(relOid, pageNumber);
            break;
    }   

    return true;
}

bool 
PageHandler::print_pd_checksum(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    switch (fork) 
    {
        case FSM_FORK:
            PrintFSMPage_pd_checksum(relOid, pageNumber);
            break;
        case VM_FORK:
            PrintVMPage_pd_checksum(relOid, pageNumber);
            break;
        case MAIN_FORK:
            PrintMainPage_pd_checksum(relOid, pageNumber);
            break;
        case INIT_FORK:
            PrintInitPage_pd_checksum(relOid, pageNumber);
            break;
    }   

    return true;
}

bool 
PageHandler::print_pg_flags(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    switch (fork) 
    {
        case FSM_FORK:
            PrintFSMPage_pg_flags(relOid, pageNumber);
            break;
        case VM_FORK:
            PrintVMPage_pg_flags(relOid, pageNumber);
            break;
        case MAIN_FORK:
            PrintMainPage_pg_flags(relOid, pageNumber);
            break;
        case INIT_FORK:
            PrintInitPage_pg_flags(relOid, pageNumber);
            break;
    }   

    return true;
}

bool 
PageHandler::print_pd_lower(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    switch (fork) 
    {
        case FSM_FORK:
            PrintFSMPage_pd_lower(relOid, pageNumber);
            break;
        case VM_FORK:
            PrintVMPage_pd_lower(relOid, pageNumber);
            break;
        case MAIN_FORK:
            PrintMainPage_pd_lower(relOid, pageNumber);
            break;
        case INIT_FORK:
            PrintInitPage_pd_lower(relOid, pageNumber);
            break;
    }   

    return true;
}

bool 
PageHandler::print_pd_upper(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    switch (fork) 
    {
        case FSM_FORK:
            PrintFSMPage_pd_upper(relOid, pageNumber);
            break;
        case VM_FORK:
            PrintVMPage_pd_upper(relOid, pageNumber);
            break;
        case MAIN_FORK:
            PrintMainPage_pd_upper(relOid, pageNumber);
            break;
        case INIT_FORK:
            PrintInitPage_pd_upper(relOid, pageNumber);
            break;
    }   

    return true;
}

bool 
PageHandler::print_pd_special(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    switch (fork) 
    {
        case FSM_FORK:
            PrintFSMPage_pd_special(relOid, pageNumber);
            break;
        case VM_FORK:
            PrintVMPage_pd_special(relOid, pageNumber);
            break;
        case MAIN_FORK:
            PrintMainPage_pd_special(relOid, pageNumber);
            break;
        case INIT_FORK:
            PrintInitPage_pd_special(relOid, pageNumber);
            break;
    }   

    return true;
}

bool 
PageHandler::print_pd_pagesize_version(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    switch (fork) 
    {
        case FSM_FORK:
            PrintFSMPage_pd_pagesize_version(relOid, pageNumber);
            break;
        case VM_FORK:
            PrintVMPage_pd_pagesize_version(relOid, pageNumber);
            break;
        case MAIN_FORK:
            PrintMainPage_pd_pagesize_version(relOid, pageNumber);
            break;
        case INIT_FORK:
            PrintInitPage_pd_pagesize_version(relOid, pageNumber);
            break;
    }   

    return true;
}
bool 
PageHandler::print_pd_prune_xid(unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    switch (fork) 
    {
        case FSM_FORK:
            PrintFSMPage_pd_prune_xid(relOid, pageNumber);
            break;
        case VM_FORK:
            PrintVMPage_pd_prune_xid(relOid, pageNumber);
            break;
        case MAIN_FORK:
            PrintMainPage_pd_prune_xid(relOid, pageNumber);
            break;
        case INIT_FORK:
            PrintInitPage_pd_prune_xid(relOid, pageNumber);
            break;
    }   

    return true;
}
