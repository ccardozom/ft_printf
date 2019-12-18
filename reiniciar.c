#include "printf.h"

void    reiniciar(valores **bag)
{
    (*bag)->menos = 0;
    (*bag)->zero = 0;
    (*bag)->width = 0;
    (*bag)->precision = -1;
}