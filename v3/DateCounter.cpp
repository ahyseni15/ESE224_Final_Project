#include "DateCounter.h"

int DateCounter::getTime()
{
	return clock() / CLOCKS_PER_SEC / dayLength;
}