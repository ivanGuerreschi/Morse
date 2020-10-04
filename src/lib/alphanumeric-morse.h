/* alphanumeric-morse.h
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

#ifndef LIBALPHANUMERIC_MORSE_H
#define LIBALPHANUMERIC_MORSE_H

#define ELEMENTS 36

typedef struct
{
  char morse_code[6];
  char alphanumeric_code[2];
} alphanumeric_morse_t;

alphanumeric_morse_t *init_struct (void);
bool exist_alphanumeric_code (alphanumeric_morse_t *alphanumeric_morse,
                              const char *alphanumeric_code);
bool exist_morse_code (alphanumeric_morse_t *alphanumeric_morse,
                       const char *morse_code);

char *translate_morse_code (alphanumeric_morse_t *alphanumeric_morse,
                            const char *morse_code);

#endif /* LIBALPHANUMERIC_MORSE_H */
