#include <stdbool.h>
#include "c_expect.h"

void test2(void)
{
	expect(1, true);
	expect(1, true);
}
