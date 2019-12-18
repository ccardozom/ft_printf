#include "printf.h"

void    putnbr_width_prec(valores **bag, int len, int neg)
{
    int diff;

    diff = 0;
    if ((*bag)->width > len)
    {
        if ((*bag)->precision > len)
            diff = (*bag)->width - (*bag)->precision - neg;
        else
            diff = (*bag)->width - len - neg;
        putspaces(diff);
    }
}