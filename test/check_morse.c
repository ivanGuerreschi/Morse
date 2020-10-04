/* check_morse.c
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

#include <check.h>
#include <stdbool.h>
#include <stdlib.h>
#include "alphanumeric-morse.h"

START_TEST (test_morse_create)
{
  alphanumeric_morse_t *alphanumeric_morse = init_struct ();

  ck_assert_str_eq (alphanumeric_morse[0].morse_code, ".-");  
  ck_assert_str_eq (alphanumeric_morse[0].alphanumeric_code, "a");  
}
END_TEST

START_TEST (test_morse_alphanumeric_code)
{
  alphanumeric_morse_t *alphanumeric_morse = init_struct ();

  ck_assert_int_eq (exist_alphanumeric_code (alphanumeric_morse, "a"), 1);
  ck_assert_int_eq (exist_alphanumeric_code (alphanumeric_morse, "aa"), 0);

}
END_TEST

START_TEST (test_morse_morse_code)
{
  alphanumeric_morse_t *alphanumeric_morse = init_struct ();

  ck_assert_int_eq (exist_morse_code (alphanumeric_morse, ".-"), 1);
  ck_assert_int_eq (exist_alphanumeric_code (alphanumeric_morse, "....._"), 0);

}
END_TEST

START_TEST (test_morse_translate_morse_code)
{
  alphanumeric_morse_t *alphanumeric_morse = init_struct ();
  char **translate = translate_morse_code(alphanumeric_morse, "..-");   
  ck_assert_str_eq (translate[0], "u");
}
END_TEST

Suite *morse_suite (void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create ("Morse");

  /* Core test case */
  tc_core = tcase_create ("Core");

  tcase_add_test (tc_core, test_morse_create);
  tcase_add_test (tc_core, test_morse_alphanumeric_code);
  tcase_add_test (tc_core, test_morse_morse_code);
  tcase_add_test (tc_core, test_morse_translate_morse_code);
  suite_add_tcase (s, tc_core);

  return s;
}

int main (void)
{
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = morse_suite();
  sr = srunner_create (s);

  srunner_run_all (sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed (sr);
  srunner_free (sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
