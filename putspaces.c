#include "printf.h"

void    putspaces(int nspaces)
{
    if (nspaces > 0)
        while (nspaces)
        {
            ft_putchar(' ');
            nspaces--;
        }
}