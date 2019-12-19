#include "printf.h"

void    ft_putnbr_base(int nb, char *str, valores **bag)
{
    unsigned int    nbr;

    nbr = nb;
    if (nbr >= 16)
        ft_putnbr_base(nbr / 16, str, bag);
    ft_putchar(str[nbr % 16]);
    (*bag)->len++;
}