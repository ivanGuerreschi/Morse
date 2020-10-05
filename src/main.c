/* main.c
   Copyright (C) 2020 Ivan Guerreschi

This file is part of morse.

Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>

morse is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

morse is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with morse. If not, see <http://www.gnu.org/licenses/>. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "include/menu.h"
#include "alphanumeric-morse.h"

void print_all_alphanumeric_morse (alphanumeric_morse_t *alphanumeric_morse);

int
main (int argc, char *argv[])
{
  alphanumeric_morse_t *alphanumeric_morse = init_struct ();
  int menu = 0;
   
  while (true)
    {
      menu = print_menu ();

      switch (menu)
        {
        case 1:
          exit (1);
          break;

        case 2:
          print_all_alphanumeric_morse (alphanumeric_morse);	   	 
          break;

        case 3:
          puts ("Enter Alphanumeric code");
          char alphanumeric[BUFSIZ];

          if (fgets (alphanumeric, sizeof (alphanumeric), stdin) == NULL)
            fprintf (stderr, "Fail to read the input stream\n");
          else
            alphanumeric[strcspn (alphanumeric, "\r\n")] = 0;

          puts (exist_alphanumeric_code (alphanumeric_morse, alphanumeric)
                ? "The Alphanumeric exists"
                : "The Alphanumeric does not exist");
          break;
        }
    }

  return 0;
}

void
print_all_alphanumeric_morse (alphanumeric_morse_t *am)
{
  for (int i = 0; i < ELEMENTS; i++)
    printf ("Morse: %s Alphanumeric: %s\n", am[i].morse_code, am[i].alphanumeric_code);
}

