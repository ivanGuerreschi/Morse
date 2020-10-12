/* alphanumeric-morse.c
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
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "alphanumeric-morse.h"

alphanumeric_morse_t
*init_struct (void)
{
  static alphanumeric_morse_t alphanumeric_morse[] =
  {
    {"", ""},
    {".-", "a"},
    {"-...", "b"},
    {"-.-.", "c"},
    {"-..", "d"},
    {".", "e"},
    {"..-.", "f"},
    {"--.", "g"},
    {"....", "h"},
    {"..", "i"},
    {".---", "j"},
    {"-.-", "k"},
    {".-..", "l"},
    {"--", "m"},
    {"-.", "n"},
    {"---", "o"},
    {".--.", "p"},
    {"--.-", "q"},
    {"-.-", "r"},
    {"...", "s"},
    {"-", "t"},
    {"..-", "u"},
    {"...-", "v"},
    {".--", "w"},
    {"-..-", "x"},
    {"-.--", "y"},
    {"--..", "z"},
    {"-----", "0"},
    {".----", "1"},
    {"..---", "2"},
    {"...--", "3"},
    {"....-", "4"},
    {".....", "5"},
    {"-....", "6"},
    {"--...", "7"},
    {"---..", "8"},
    {"----.", "9"},
  };

  return alphanumeric_morse;
}

bool
exist_alphanumeric_code (alphanumeric_morse_t *alphanumeric_morse,
			 const char *alphanumeric_code)
{
  bool compare = false;

  for (int i = 0; i < ELEMENTS; i++)
    {
      if (strcmp (alphanumeric_morse[i].alphanumeric_code,
		  alphanumeric_code) == 0)
	compare = true;
    }  
  
  return compare;
}

bool
exist_morse_code (alphanumeric_morse_t *alphanumeric_morse,
		  const char *morse_code)
{
  bool compare = false;

  for (int i = 0; i < ELEMENTS; i++)
    {
      if (strcmp (alphanumeric_morse[i].morse_code,
		  morse_code) == 0)
	compare = true;
    }  
  
  return compare;
}

char
**translate_morse_code(alphanumeric_morse_t *alphanumeric_morse,
		       char morse_code[])
{
  char **translate = calloc (BUFSIZ, sizeof (char));
  if (translate == NULL)
    {
      perror ("Error allocation failed");
      exit (0);
    }
  
  char delim[] = " ";
  char *token = strtok (morse_code, delim); 
  int i = 0;
  int n = 0;  
  
  alphanumeric_morse = init_struct ();

  while (token != NULL)
    {
      translate[i] =  malloc (50);
      if (translate[i] == NULL)
	{
	  perror ("Error allocation failed");
	  exit (0);
	}
      
      strcpy (translate[i], token);
      token = strtok (NULL, delim);
      i++;
    }  

  for (int j = 0; j < ELEMENTS; j++)
    {
      if (strcmp (translate[n], alphanumeric_morse[j].morse_code) == 0)
	{
	  strcpy (translate[n], alphanumeric_morse[j].alphanumeric_code);
	  if (n < i - 1)
	    {
	      n++;
	      j = 0;
	    }
	  else
	    break;
	}
    }
   
  return translate;
}
