#include <stdlib.h>
#include <stdio.h>

void print_out(const char* a, const int b)
{
    printf("a is\"%s\" and b is %i\n", a, b);
}

int main()
{
	printf("Hello world\n");

	char* a = "Hello";
	char* b = " world!";
	//printf(a, b,"\n");

	char* f="Kecske";
	const int k = 5;

	print_out(f, k);

	return 0;
}