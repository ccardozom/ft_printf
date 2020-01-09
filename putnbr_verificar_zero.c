#include "printf.h"

void    putnbr_printf_zero(t_valores **bag)
{
    int     num;
    int     neg;
    int     len;

    if ((num = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
        return ;
    len = ft_nbrlenprec(num);
    neg = (num < 0) ? 1 : 0;
    if ((*bag)->width > len)
    {
        ft_putchar('-');
        (*bag)->len += 1; 
    }
    putnbr_prec_len(bag, len);
    ft_putnbrprintfprec(num, bag);
}