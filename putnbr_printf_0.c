#include "printf.h"

void    putnbr_printf_0(valores **bag)
{
    int diff;

    diff = 0;
    if ((*bag)->menos == 1)
    {
        putnbr_auxiliar_0_printf(bag, &diff);
        putnbr_width_prec(bag, diff, 0);
    }
    else
    {
        putnbr_width_prec(bag, diff, 0);
        putnbr_auxiliar_0_printf(bag, &diff);
    }
    
}