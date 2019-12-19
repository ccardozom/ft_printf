#include "printf.h"

void    ft_putnbrprintfprec(int nb, valores **bag)
{
    unsigned int    i;

    i = nb;
    if (nb < 0)
        i = i * -1;
    if (nb >= 10)
        ft_putnbrprintfprec(i / 10, bag);
    ft_putchar(i % 10 + '0');
    (*bag)->len += 1;
}