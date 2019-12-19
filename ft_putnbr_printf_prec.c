
#include "printf.h"

static void		putnbr_printf_precision(valores **bag)
{
	int		len;
	int		number;
	int		neg;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrlenprec(number);
	neg = (number < 0) ? 1 : 0;
	putnbr_width_prec(bag, len, neg);
	if (neg)
	{
		ft_putchar('-');
		(*bag)->len += 1;
	}
	putnbr_prec_len(bag, len);
	ft_putnbrprintfprec(number, bag);
}
