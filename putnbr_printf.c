#include "printf.h"

void    putnbr_printf(valores **bag)
{
    if ((*bag)->menos == 1)
        putnbr_printf_menos1(bag);
    else if ((*bag)->menos == 0)
    {
        if ((*bag)->zero == 1)
            putnbr_printf_zeros(bag);
        else if ((*bag)->precision > -1)
            putnbr_printf_precision(bag);
        else
            putnbr_printf_menos0(bag);        
    }
}