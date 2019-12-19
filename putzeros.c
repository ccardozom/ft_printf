#include "printf.h"

void    putzeros(int nzeros)
{
    if (nzeros > 0)
        while (nzeros)
        {
            ft_putchar('0');
            nzeros--;
        }
}