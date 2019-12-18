#include "printf.h"

void    procesar_datos(valores **bag)
{
    if ((*bag)->conversion == 'd' || (*bag)->conversion == 'i')
        putnbr_printf(bag);
}