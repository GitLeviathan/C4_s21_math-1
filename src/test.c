#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_abs) {
  ck_assert_int_eq(abs(85), s21_abs(85));
  ck_assert_int_eq(abs(-42), s21_abs(-42));
  ck_assert_int_eq(abs(0), s21_abs(0));
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_double_eq(fabs(37.542), s21_fabs(37.542));
  ck_assert_double_eq(fabs(-45.286), s21_fabs(-45.286));
  ck_assert_double_eq(fabs(0.0), s21_fabs(0.0));
  ck_assert_double_nan(fabs(NAN));
  ck_assert_double_nan(s21_fabs(NAN));
  ck_assert_double_eq(fabs(INFINITY), s21_fabs(INFINITY));
  ck_assert_double_eq(fabs(-INFINITY), s21_fabs(-INFINITY));
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_double_eq(ceil(37.542), s21_ceil(37.542));
  ck_assert_double_eq(ceil(-45.286), s21_ceil(-45.286));
  ck_assert_double_eq(ceil(0.0), s21_ceil(0.0));
  ck_assert_double_nan(ceil(NAN));
  ck_assert_double_nan(s21_ceil(NAN));
  ck_assert_double_eq(ceil(INFINITY), s21_ceil(INFINITY));
  ck_assert_double_eq(ceil(-INFINITY), s21_ceil(-INFINITY));
  ck_assert_double_eq(ceil(10009.00123), s21_ceil(10009.00123));
  ck_assert_double_eq(ceil(-10009.555), s21_ceil(-10009.555));
  ck_assert_double_eq(ceil(-0.10009), s21_ceil(-0.10009));
  ck_assert_double_eq(ceil(-1e-23), s21_ceil(-1e-23));
}
END_TEST

START_TEST(test_floor) {
  ck_assert_double_eq(floor(37.542), s21_floor(37.542));
  ck_assert_double_eq(floor(-45.286), s21_floor(-45.286));
  ck_assert_double_eq(floor(0.0), s21_floor(0.0));
  ck_assert_double_nan(floor(NAN));
  ck_assert_double_nan(s21_floor(NAN));
  ck_assert_double_eq(floor(INFINITY), s21_floor(INFINITY));
  ck_assert_double_eq(floor(-INFINITY), s21_floor(-INFINITY));
  ck_assert_double_eq(floor(10009.00123), s21_floor(10009.00123));
  ck_assert_double_eq(floor(-10009.555), s21_floor(-10009.555));
  ck_assert_double_eq(floor(-0.10009), s21_floor(-0.10009));
  ck_assert_double_eq(floor(-1e-23), s21_floor(-1e-23));
}
END_TEST

START_TEST(test_exp) {
  ck_assert_double_nan(exp(NAN));
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_eq(exp(INFINITY), s21_exp(INFINITY));
  ck_assert_double_eq(exp(-INFINITY), s21_exp(-INFINITY));
  for (double k = -21; k < 21; k += 1) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

int main() {
  Suite *suite = suite_create("Test Suite");
  TCase *tc = tcase_create("Test Cases");
  tcase_add_test(tc, test_abs);
  tcase_add_test(tc, test_fabs);
  tcase_add_test(tc, test_ceil);
  tcase_add_test(tc, test_floor);
  tcase_add_test(tc, test_exp);
  suite_add_tcase(suite, tc);

  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}