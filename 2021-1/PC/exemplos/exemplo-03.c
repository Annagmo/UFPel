#include <stdio.h>
#include <float.h>

int main()
{
	printf("Storage size for float : %ld \n", sizeof(long double)); //no terminal aqui dá um warning que tinha que ser %ld ao invés de %d
	printf("Minimum float positive value: %LE\n", LDBL_MIN); //LDBL_MIN = long double min
	printf("Maximum float positive value: %LE\n", LDBL_MAX); //LDBL_MAX = long double max
	printf("Precision value: %d\n", LDBL_DIG); //LDBL_DIG = quantos dígitos precisam

	return 0;
}
/*
%ld = long unsigned int

% l L = long

  e E = converts floating-point number to the decimal exponent notation. 

    x prints an unsigned number in hexadecimal.
    o prints an unsigned number in octal.
    u prints an unsigned number in decimal.
    d prints a signed number in decimal.
    i prints a signed number in decimal.


          --
Integer   |	short signed 	%d or %I
          | short unsigned 	%u
          | long signed 	%ld
          | long unsigned 	%lu
          | unsigned hexadecimal 	%x
          | unsigned octal 	%o
          --

          --
Real 	  | float 	%f
          | double 	%lf
          | Character 	signed character 	%c
          | unsigned character 	%c
          --

String 		%s
*/

