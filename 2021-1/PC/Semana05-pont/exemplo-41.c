#include <stdio.h>
#include <string.h>
void inverte(char *s);

int main()
{
	char *msg = "Eu gosto de C";
	inverte(msg);
	return 0;
}

void inverte(char *s)
{
	int i;
	for (i = strlen(s) - 1; i >= 0; i--)
		putchar(s[i]);
}
