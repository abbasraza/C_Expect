#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "c_expect.h"
#include "tests.h"

struct test tests[] = {
						{"test1", test1},
						{"test2", test2}
					  };

uint8_t tests_executed;
uint8_t tests_passed;
uint8_t tests_failed;
uint8_t conditions_executed;
uint8_t conditions_passed;
uint8_t conditions_failed;

void test_condition(uint8_t result, uint8_t expected, const char * file, int line) 
{
	++conditions_executed;
	if (result == expected)
	{
	 	++conditions_passed;
		printf("Test at %s:%d passed\n", file, line);
	}
	else
	{
		++conditions_failed;
		printf("Test at %s:%d failed\n", file, line);
	}
}

int main()
{

	uint8_t i = 0;
	for (i = 0; i < sizeof(tests) / sizeof(struct test); ++i)
	{
		if (tests[i].fptr)
		{
			printf("\n\n################# Executing test named:%s\n", tests[i].name);
			++tests_executed;
			tests[i].fptr();
			printf("Test:%s conditions executed :%d\n", tests[i].name, conditions_executed);
			printf("Test:%s conditions passed :%d\n", tests[i].name, conditions_passed);
			printf("Test:%s conditions failed :%d\n", tests[i].name, conditions_failed);
			
			if (conditions_failed)
			{
				printf("################# Test:%s FAILED\n\n", tests[i].name);
				++tests_failed;
			}
			else
			{
				printf("################### Test:%s PASSED\n\n", tests[i].name);
				++tests_passed;
			}
			conditions_executed = 0;
			conditions_passed = 0;
			conditions_failed = 0;
		}
	}

	printf("\n###### SUMMARY ######\n");
	printf("Total tests executed = %d\n", tests_executed);
	printf("Total tests passed = %d\n", tests_passed);
	printf("Total tests failed = %d\n", tests_failed);

	if (tests_failed)
	{
		printf("TEST SUIT FAILED\n");
		exit(1);
	}

	printf("TEST SUIT PASSED\n");
	exit(0);
}
