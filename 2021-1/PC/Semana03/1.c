#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	char s1[50] = "jack",s2[50] = "jill",s3[50]; //*sptr;
	printf("%c%s ", toupper(s1[0]), &s1[1]);
	printf("%s ",strcpy( s3, s2 ) );
	printf("%s ",strcat(strcat(strcpy(s3,s1), " and "), s2 ) );
	printf("%lu ",strlen( s1 ) + strlen( s2 ) );
	printf("%lu ",strlen( s3 ) );
	
	return 0;
}
