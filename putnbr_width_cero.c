#include "printf.h"

void    putnbr_width_zeros(t_valores **bag, int len, int neg)
{
    int diff;

    diff = 0;
    if ((*bag)->precision > len)
        diff = (*bag)->width - (*bag)->precision - neg;
    else
        diff = (*bag)->width - len - neg;
    if (diff >= 0)
    {
        if ((*bag)->precision != -1)
            putspaces(diff);
        else
        {
            if (neg)
            {
                ft_putchar('-');
                (*bag)->len += 1;
            }
            putzeros(diff);
        }
        (*bag)->len += diff;
    }
}