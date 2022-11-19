#include <stdio.h>
//tamanho dos tipos
int main()
{
	char c;
	unsigned char uc;
	int i;
	unsigned int ui;
	float f;
	double d;

	printf("char %lu\n", sizeof(c));
	printf("unsigned char %lu\n", sizeof(uc));
	printf("int %lu\n", sizeof(i));
	printf("unsigned int %lu\n", sizeof(ui));
	printf("float %lu\n", sizeof(f));
	printf("double %lu", sizeof(d));

/*
sizeof sabe o tamanho da variável em bytes.

%lu é:
u is a specifier meaning "unsigned decimal integer".

l is a length modifier meaning "long".
*/
	return 0;
}
