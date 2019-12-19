#include "printf.h"

void    putnbr_prec_len(valores **bag, int len)
{
    int diff;

    diff = 0;
    if ((*bag)->precision > len)
    {
        diff = (*bag)->precision - len;
        putzeros(diff);
        (*bag)->len += diff;
    }
}