#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_abs) {
  /*
  ck_assert_int_eq(abs(37), s21_abs(37));
  ck_assert_int_eq(abs(-45), s21_abs(-45));
  ck_assert_int_eq(abs(0), s21_abs(0));
  */
  ck_assert_int_eq(s21_abs(21), abs(21));
  ck_assert_int_eq(s21_abs(-21), abs(-21));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(+0), abs(+0));
  ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(test_fabs) {
  /*
  ck_assert_double_eq(fabsl(37.542), s21_fabs(37.542));
  ck_assert_double_eq(fabsl(-45.286), s21_fabs(-45.286));
  ck_assert_double_eq(fabsl(0.0), s21_fabs(0.0));
  ck_assert_double_nan(s21_fabs(NAN));
  ck_assert_double_infinite(s21_fabs(INFINITY));
  ck_assert_double_eq(fabsl(-INFINITY), s21_fabs(-INFINITY));
  */
  ck_assert_ldouble_eq(s21_fabs(0.000001), fabs(0.000001));
  ck_assert_ldouble_eq(s21_fabs(-21.000345), fabs(-21.000345));
  ck_assert_ldouble_eq(s21_fabs(-2147483600.543), fabs(-2147483600.543));
  ck_assert_ldouble_eq(s21_fabs(2147483600.4857), fabs(2147483600.4857));
  double a = -5.53151413431;
  ck_assert_ldouble_eq(s21_fabs(a), fabs(a));
  a = NAN;
  ck_assert_ldouble_nan(s21_fabs(a));
  ck_assert_ldouble_nan(fabs(a));
  a = s21_INF;
  ck_assert_ldouble_infinite(s21_fabs(a));
  ck_assert_ldouble_infinite(fabs(a));
  a = -9519359135915.53151413431;
  ck_assert_ldouble_eq_tol(s21_fabs(a), fabs(a), s21_EPS);
  ck_assert_ldouble_nan(s21_fabs(NAN));
  ck_assert_ldouble_nan(fabs(NAN));
  ck_assert_ldouble_eq(s21_fabs(-15.01), fabs(-15.01));
  ck_assert_ldouble_eq(s21_fabs(15.01), fabs(15.01));
  ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_double_eq(ceill(37.542), s21_ceil(37.542));
  ck_assert_double_eq(ceill(-45.286), s21_ceil(-45.286));
  ck_assert_double_eq(ceill(0.0), s21_ceil(0.0));
  ck_assert_double_nan(s21_ceil(NAN));
  ck_assert_double_infinite(s21_ceil(INFINITY));
  ck_assert_double_eq(ceill(-INFINITY), s21_ceil(-INFINITY));
  ck_assert_double_eq(ceill(10009.00123), s21_ceil(10009.00123));
  ck_assert_double_eq(ceill(-10009.555), s21_ceil(-10009.555));
  ck_assert_double_eq(ceill(-0.10009), s21_ceil(-0.10009));
  ck_assert_double_eq(ceill(-1e-23), s21_ceil(-1e-23));

  /*
   ck_assert_ldouble_eq(s21_ceil(-15.01), ceil(-15.01));
   ck_assert_ldouble_eq(s21_ceil(15.01), ceil(15.01));
   ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY));
   ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
   ck_assert_ldouble_eq(s21_ceil(-0.12), ceil(-0.12));
   ck_assert_ldouble_infinite(s21_ceil(INFINITY));
   ck_assert_ldouble_infinite(ceil(INFINITY));
   ck_assert_ldouble_nan(s21_ceil(NAN));
   ck_assert_ldouble_nan(ceil(NAN));
   ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
   ck_assert_ldouble_eq(s21_ceil(0.0), ceil(0.0));
   ck_assert_ldouble_eq(s21_ceil(21.21), ceil(21.21));
   ck_assert_ldouble_eq(s21_ceil(21.91), ceil(21.91));
   ck_assert_ldouble_eq(s21_ceil(-21.21), ceil(-21.21));
   ck_assert_ldouble_eq(s21_ceil(-21.91), ceil(-21.91));
   ck_assert_ldouble_eq(s21_ceil(DBL_MAX), ceil(DBL_MAX));
   double num = NAN;
   long double orig_res = ceil(num), our_res = s21_ceil(num);
   int suc = 0;
   if (isnan(orig_res) && isnan(our_res)) suc = 1;
   ck_assert_int_eq(1, suc);
   */
}
END_TEST

START_TEST(test_floor) {
  /*
  ck_assert_double_eq(floorl(37.542), s21_floor(37.542));
  ck_assert_double_eq(floorl(-45.286), s21_floor(-45.286));
  ck_assert_double_eq(floorl(0.0), s21_floor(0.0));
  ck_assert_double_nan(s21_floor(NAN));
  ck_assert_double_infinite(s21_floor(INFINITY));
  ck_assert_double_eq(floorl(-INFINITY), s21_floor(-INFINITY));
  ck_assert_double_eq(floorl(10009.00123), s21_floor(10009.00123));
  ck_assert_double_eq(floorl(-10009.555), s21_floor(-10009.555));
  ck_assert_double_eq(floorl(-0.10009), s21_floor(-0.10009));
  ck_assert_double_eq(floorl(-1e-23), s21_floor(-1e-23));
  */
  ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0));
  ck_assert_ldouble_eq(s21_floor(21.21), floor(21.21));
  ck_assert_ldouble_eq(s21_floor(21.91), floor(21.91));
  ck_assert_ldouble_eq(s21_floor(-21.21), floor(-21.21));
  ck_assert_ldouble_eq(s21_floor(-21.91), floor(-21.91));
  ck_assert_ldouble_infinite(s21_floor(INFINITY));
  ck_assert_ldouble_infinite(floor(INFINITY));
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
  ck_assert_ldouble_eq(s21_floor(0), floor(0));
  ck_assert_ldouble_eq(s21_floor(-15.01), floor(-15.01));
  ck_assert_ldouble_eq(s21_floor(15.01), floor(15.01));
  ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
  double num = NAN;
  long double orig_res = floor(num), our_res = s21_floor(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
  ck_assert_ldouble_eq(s21_floor(-0), floor(-0));
}
END_TEST

START_TEST(test_exp) {
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_infinite(s21_exp(INFINITY));
  ck_assert_double_eq(expl(-INFINITY), s21_exp(-INFINITY));
  ck_assert_double_eq(expl(0), s21_exp(0));
  ck_assert_double_eq_tol(expl(1), s21_exp(1), s21_EPS);
  for (double k = -21; k < 21; k += 1) {
    ck_assert_double_eq_tol(s21_exp(k), expl(k), s21_EPS);
  }
  for (double k = -5; k < 5; k += 0.00573) {
    ck_assert_double_eq_tol(s21_exp(k), expl(k), s21_EPS);
  }
  for (double k = -15; k < 15; k += 0.123) {
    ck_assert_double_eq_tol(s21_exp(k), expl(k), s21_EPS);
  }
}
END_TEST

START_TEST(test_log) {
  ck_assert_double_nan(s21_log(NAN));
  ck_assert_double_infinite(s21_log(INFINITY));
  ck_assert_double_nan(s21_log(-INFINITY));
  ck_assert_double_eq(logl(0), s21_log(0));
  for (double k = 1; k < 100; k += 13.2) {
    ck_assert_double_eq_tol(s21_log(k), logl(k), s21_EPS);
  }
  for (double k = 0.1; k < 4; k += 0.24) {
    ck_assert_double_eq_tol(s21_log(k), logl(k), s21_EPS);
  }
  for (double k = 0.1; k < 10000; k += 123) {
    ck_assert_double_eq_tol(s21_log(k), logl(k), s21_EPS);
  }
  /*for (double k = 0.000005; k < 1; k *= 5) {
    ck_assert_double_eq_tol(s21_log(k), logl(k), s21_EPS);
  }*/
}
END_TEST
START_TEST(test_pow) {
  for (double k = -9; k <= 9; k += 1.7) {
    for (double g = -5; g < 5; g += 1) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, s21_EXP);
      }
      a = s21_pow(g, k);
      b = pow(g, k);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, s21_EXP);
      }
    }
  }
  for (double k = -1e-1; k <= 1; k += 1.1e-1) {
    for (double g = -2.55; g < 2; g += 1.1) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, s21_EPS);
      }
      a = s21_pow(g, k);
      b = pow(g, k);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, s21_EPS);
      }
    }
  }
  ck_assert_double_eq(pow(1, 0), s21_pow(1, 0));
  ck_assert_double_eq(pow(0, 0), s21_pow(0, 0));
  ck_assert_double_eq(pow(0, -1), s21_pow(0, -1));
  ck_assert_double_eq(pow(0, 1), s21_pow(0, 1));
  ck_assert_double_eq(pow(INFINITY, 0), s21_pow(INFINITY, 0));
  ck_assert_double_eq(pow(INFINITY, -1), s21_pow(INFINITY, -1));
  ck_assert_double_eq(pow(0, INFINITY), s21_pow(0, INFINITY));
  ck_assert_double_nan(s21_pow(0, NAN));
  ck_assert_double_nan(s21_pow(NAN, NAN));
  ck_assert_double_eq(pow(INFINITY, INFINITY), s21_pow(INFINITY, INFINITY));
  ck_assert_double_eq(pow(INFINITY, -INFINITY), s21_pow(INFINITY, -INFINITY));
  ck_assert_double_eq(pow(-INFINITY, -INFINITY), s21_pow(-INFINITY, -INFINITY));
  ck_assert_double_nan(s21_pow(NAN, INFINITY));
  ck_assert_double_nan(s21_pow(NAN, -INFINITY));
  ck_assert_double_eq(pow(2, INFINITY), s21_pow(2, INFINITY));
  ck_assert_double_eq(pow(0.5, INFINITY), s21_pow(0.5, INFINITY));
  ck_assert_double_eq(pow(2, -INFINITY), s21_pow(2, -INFINITY));
  ck_assert_double_eq(pow(0.5, -INFINITY), s21_pow(0.5, -INFINITY));
  ck_assert_double_eq(pow(-2, -INFINITY), s21_pow(-2, -INFINITY));
  ck_assert_double_eq(pow(-2, INFINITY), s21_pow(-2, INFINITY));
}

START_TEST(test_sin) {
  ck_assert_double_eq_tol(sinl(0), s21_sin(0), s21_EPS);
  ck_assert_double_eq_tol(sinl(1), s21_sin(1), s21_EPS);
  ck_assert_double_eq_tol(sinl(-1), s21_sin(-1), s21_EPS);
  ck_assert_double_eq_tol(sinl(13), s21_sin(13), s21_EPS);
  ck_assert_double_eq_tol(sinl(-26), s21_sin(-26), s21_EPS);
  ck_assert_double_nan(s21_sin(s21_NAN));
  ck_assert_double_nan(s21_sin(-s21_NAN));
  ck_assert_double_nan(s21_sin(s21_INF));
  ck_assert_double_nan(s21_sin(-s21_INF));
  ck_assert_double_eq_tol(sinl(s21_PI), s21_sin(s21_PI), s21_EPS);
  ck_assert_double_eq_tol(sinl(-s21_PI), s21_sin(-s21_PI), s21_EPS);
  ck_assert_double_eq_tol(sinl(s21_EXP), s21_sin(s21_EXP), s21_EPS);
  ck_assert_double_eq_tol(sinl(-s21_EXP), s21_sin(-s21_EXP), s21_EPS);
}
END_TEST

int main() {
  printf("pow = %Lf", s21_pow(-2, INFINITY));
  Suite *suite = suite_create("Test Suite");
  TCase *tc = tcase_create("Test Cases");
  tcase_add_test(tc, test_abs);
  tcase_add_test(tc, test_fabs);
  tcase_add_test(tc, test_ceil);
  tcase_add_test(tc, test_floor);
  tcase_add_test(tc, test_exp);
  tcase_add_test(tc, test_log);
  tcase_add_test(tc, test_pow);
  tcase_add_test(tc, test_sin);
  suite_add_tcase(suite, tc);

  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}