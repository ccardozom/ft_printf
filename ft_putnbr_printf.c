
#include "printf.h"

void		ft_putnbrprintf(int nb, valores **bag)
{
	unsigned int	i;

	i = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		i = i * -1;
		(*bag)->len += 1;
	}
	if (i >= 10)
		ft_putnbrprintf(i / 10, bag);
	ft_putchar(i % 10 + '0');
	(*bag)->len += 1;
}