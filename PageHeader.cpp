#include "headers/PageHeader.h"

#include "stdlib.h"

/*
 * вывести весь заголовок
 */
void
PageHeader::print_all(void)
{
    printf("pg_lsn: %lld\n", data.pg_lsn);
    printf("pd_checksum: %hd\n", data.pd_checksum);
    printf("pg_flags: %hd\n", data.pg_flags);
    printf("pd_lower: %hd\n", data.pd_lower);
    printf("pd_upper: %hd\n", data.pd_upper);
    printf("pd_special: %hd\n", data.pd_special);
    printf("pd_pagesize_version: %hd\n", data.pd_pagesize_version);
    printf("pd_prune_xid: %d\n", data.pd_prune_xid);
}

/*
 * вывести pg_lsn
 */
void
PageHeader::print_pg_lsn(void)
{
    printf("pg_lsn: %lld\n", data.pg_lsn);
}

/*
 * вывести pd_checksum
 */
void
PageHeader::print_pd_checksum(void)
{
    printf("pd_checksum: %hd\n", data.pd_checksum);
}

/*
 * вывести pg_flags
 */
void
PageHeader::print_pg_flags(void)
{
    printf("pg_flags: %hd\n", data.pg_flags);
}

/*
 * вывести pd_lower
 */
void
PageHeader::print_pd_lower(void)
{
    printf("pd_lower: %hd\n", data.pd_lower);
}

/*
 * вывести pd_upper
 */
void
PageHeader::print_pd_upper(void)
{
    printf("pd_upper: %hd\n", data.pd_upper);
}

/*
 * вывести pd_special
 */
void
PageHeader::print_pd_special(void)
{
    printf("pd_special: %hd\n", data.pd_special);
}

/*
 * вывести pd_pagesize_version
 */
void
PageHeader::print_pd_pagesize_version(void)
{
    printf("pd_pagesize_version: %hd\n", data.pd_pagesize_version);
}

/*
 * вывести pd_prune_xid
 */
void
PageHeader::print_pd_prune_xid(void)
{
    printf("pd_prune_xid: %d\n", data.pd_prune_xid);
}