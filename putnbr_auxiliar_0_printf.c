#include "printf.h"

void    putnbr_auxiliar_0_printf(valores **bag, int *diff)
{
    if ((*bag)->precision > 0)
    {
        *diff = (*bag)->precision;
        putzeros(*diff);
        (*bag)->len += *diff;
    }
}