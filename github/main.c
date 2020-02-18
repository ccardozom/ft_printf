#include "printf.h"
#include <stdio.h>

int		main()
{
	/* int number = 5;
	char *pointer = "little"; */
	int a;
	int b;

	a = printf("p2 %.10s\n", "cccc");
	printf("\n");
	b = ft_printf("p2 %.10s\n", "cccc");
	printf("\nORIGINAL: %d -- TUYO: %d\n", a, b);
	
}
