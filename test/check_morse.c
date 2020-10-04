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

  ck_assert_str_eq (translate_morse_code (alphanumeric_morse, ".-"), "a");
  ck_assert_str_eq (translate_morse_code (alphanumeric_morse, "....._"), "a");

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
