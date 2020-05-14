#ifndef __ERRNO_H__
#define __ERRNO_H__

#define MAX_SYMB_NUM 256
#define REQ_STR_SIZE 10 
#define DOT_POS_FRT 2
#define DOT_POS_SCD 5
#define MIN_MONTH_NUM 0
#define MAX_MONTH_NUM 12
#define MIN_DAY_NUM 0
#define MIN_YEAR_NUM 1000
#define MAX_YEAR_NUM 2019
#define FEB_LEAP_DAYS 29
#define FEB_NORM_DAYS 28
#define FEB_NUM 1

#define R_I 1
#define W_I -1
#define LAST_EL 2
#define DEL_OK 1
#define DEL_SKIP -1

#define NO_ERR 0
#define INPUT_ERR -1
#define KEY_EXISTS 2
#define KEY_ERR -2
#define FILE_ERR -3
#define DEL_ERR -4
#define AVE_ERR -5
#define INV_MEM_ERR -6

#define EQ 1
#define NOT_EQ -1
#define TEST_PASSED 1
#define TEST_FAILED -1
#define ALL_TESTS_PASSED 0
#define NOT_ALL_TESTS_PASSED -1

#endif
