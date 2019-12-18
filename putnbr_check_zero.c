#include "printf.h"

int     putnbr_check_zero(valores **bag)
{
    int num;

    num = va_arg((*bag)->ap, int);
    if (num == 0 && (*bag)->precision != -1)
    {
        putnbr_printf_0(bag);
        return (0);
    }
    return (num);
}