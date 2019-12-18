#include "printf.h"

void    verificar_flags(valores **bag)
{
    int     i;
    int     cont;

    i = -1;
    cont = 0;
    while ((*bag)->resul[++i] && (*bag)->resul[i] != '.')
    {
        if ((*bag)->resul[i] == '-')
        {
            (*bag)->menos = 1;
            cont++;
        }
        if ((*bag)->resul[i] == '0' && ((!ft_isdigit((*bag)->resul[i - 1])
            && (*bag)->resul[i -1] != '.') || (*bag)->resul[i - 1] == '0'))
        {
            (*bag)->zero = 1;
            cont++;
        }
    }
    if (cont != 0)
        (*bag)->resul = (*bag)->resul + cont;
}