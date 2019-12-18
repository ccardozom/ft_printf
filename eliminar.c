#include "printf.h"

int     eliminar(char *format, valores **bag)
{
    int     len;

    (*bag)->resul = ft_strldup(format);
    len = ft_strlen((*bag)->resul);
    verificar_flags(bag);
    verificar_width(bag);
    verificar_precision(bag);
    verificar_conversion(bag);
    procesar_datos(bag);
    return (len);

}