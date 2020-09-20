#include <stdlib.h>
#include "morse.h"

morse_t
*all_verbs (void)
{
  morse_t *morse = calloc (20, sizeof (morse_t));
  
  return morse;
}

char
*translate_morse_code (const char *morse)
{
   return "";
}
