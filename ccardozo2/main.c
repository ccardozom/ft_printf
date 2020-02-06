#include "printf.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	int number = 5;
	char *pointer = "little";
	int a;
	int b;

	a = printf("Here is a number-%100.4d-and a-%10s-word.\n", number, pointer);
	printf("\n");
	b = ft_printf("Here is a number-%100.4d-and a-%10s-word.\n", number, pointer);
	printf("\nORIGINAL: %d -- TUYO: %d\n", a, b);
}
