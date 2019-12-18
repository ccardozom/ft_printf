#include "printf.h"

void    verificar_precision(valores **bag)
{
    int i;
    int cont;

    i = -1;
    cont = 0;
    while ((*bag)->resul[++i])
    {
        if ((*bag)->resul[i] == '.')
        {
            i++;
            cont++;
            (*bag)->precision = 0;
            if ((*bag)->resul[i] == '*')
            {
                if (((*bag)->precision = (int)va_arg((*bag)->ap, int)) < 0)
                    (*bag)->precision = -1;
                cont++;
            }
            while (ft_isdigit((*bag)->resul[i]))
			{
				(*bag)->precision = ((*bag)->precision * 10)
					+ ((*bag)->resul[i++] - '0');
				cont++;
			}
        }
        
    }
    (*bag)->resul = (*bag)->resul + cont;
}