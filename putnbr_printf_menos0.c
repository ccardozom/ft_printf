#include "printf.h"

void    putnbr_printf_menos0(t_valores **bag)
{
    int		diff;
	int		number;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	diff = ft_nbrlen(number);
	if ((*bag)->width > diff)
	{
		diff = (*bag)->width - diff;
		putspaces(diff);
		(*bag)->len += diff;
	}
	ft_putnbrprintf(number, bag);
}