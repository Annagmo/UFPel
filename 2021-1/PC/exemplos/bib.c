#include "bib.h"

int fatorial(int n)
{

	if ((n == 1) || (n == 0))
		return 1;
	else
		return n * fatorial(n - 1);

}
