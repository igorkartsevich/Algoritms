#include "SimpleRecursion.h"

int getFibonachi(int memberPrev, int member, int counter) {
	if (--counter == 0) return member;
	else getFibonachi(member, member + memberPrev, counter);
}

int SimpleRecursion::findRecursionFibonacci(int n)
{
	int zeroFibonaci = 0;
	int firstFibonachi = 1;
	return getFibonachi(zeroFibonaci, firstFibonachi, n);
}
