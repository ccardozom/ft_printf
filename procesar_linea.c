#include "printf.h"

void    procesar_linea(valores **bag)
{
    int i;

    i = -1;
    while ((*bag)->str[++i])
    {
        if ((*bag)->str[i] == '%')
        {
            reiniciar(bag);
            i = i + eliminar((*bag)->str + i + 1, bag);
        }
        else
            (*bag)->len = (*bag)->len + write(1, &(*bag)->str[i], 1);
    }
}