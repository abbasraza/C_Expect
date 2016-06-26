#include <stdbool.h>
#include "c_expect.h"

void test1(void)
{
	expect(1, true);
	expect(0, true);
}
