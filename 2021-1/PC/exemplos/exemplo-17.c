#include <stdio.h>
int main()
{
	char s[256] = "", str[256] = "";

	scanf("%[aeiou]", s);
	printf("String (s): %s\n", s);
	scanf("%[^A-Z]", str);
	printf("String (str): %s\n", str);
	return 0;
}
