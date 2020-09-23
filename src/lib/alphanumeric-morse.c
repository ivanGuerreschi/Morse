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

#include "alphanumeric-morse.h"

alphanumeric_morse_t
*init_struct (void)
{
  static alphanumeric_morse_t alphanumeric_morse[] =
  {
    {".-", 'a'},
    {"-...", 'b'},
    {"-.-.", 'c'},
    {"-..", 'd'},
    {".", 'e'},
    {"..-.", 'f'},
    {"--.", 'g'},
    {"....", 'h'},
    {"..", 'i'},
    {".---", 'j'},
    {"-.-", 'k'},
    {".-..", 'l'},
    {"--", 'm'},
    {"-.", 'n'},
    {"---", 'o'},
    {".--.", 'p'},
    {"--.-", 'q'},
    {"-.-", 'r'},
    {"...", 's'},
    {"-", 't'},
    {"..-", 'u'},
    {"...-", 'v'},
    {".--", 'w'},
    {"-..-", 'x'},
    {"-.--", 'y'},
    {"--..", 'z'},
    {"-----", '0'},
    {".----", '1'},
    {"..---", '2'},
    {"...--", '3'},
    {"....-", '4'},
    {".....", '5'},
    {"-....", '6'},
    {"--...", '7'},
    {"---..", '8'},
    {"----.", '9'},
  };

  return alphanumeric_morse;
}

