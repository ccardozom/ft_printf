#include "printf.h"

void    verificar_width(valores **bag)
{
    int i;
    int cont;

    i = 0;
    cont = 0;
    while ((*bag)->resul[++i] && (*bag)->resul[i] != '.')
    {
        if ((*bag)->resul[i] == '*')
        {
            if (((*bag)->width = (int)va_arg((*bag)->ap, int)) < 0)
            {
                (*bag)->menos = 1;
                (*bag)->width = (*bag)->width * -1; 
            }
            cont++;
        }
        else if (ft_isdigit((*bag)->resul[i]))
        {
            (*bag)->width = ((*bag)->width * 10) + ((*bag)->resul[i] - '0');
            cont++;
        }
        i++;
    }
    if (cont != 0)
        (*bag)->resul = (*bag)->resul + cont;
}