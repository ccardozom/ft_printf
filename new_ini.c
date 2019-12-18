#include "printf.h"

valores     *new_ini(const char *format)
{
    valores     *new_bag;

    if(!(new_bag = malloc(sizeof(valores))))
        return (NULL);
    new_bag->str = (char*)format;
    new_bag->len = 0;
    return (new_bag);
}