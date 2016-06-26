#ifndef _C_EXPECT_H
#define _C_EXPECT_H

#include <stdlib.h>

struct test
{
	char * name;
	void (*fptr)(void);
};

void test_condition(uint8_t result, uint8_t expected, const char * file, int line);
#define expect(result, expected) test_condition(result, expected, __FUNCTION__, __LINE__)

#endif

