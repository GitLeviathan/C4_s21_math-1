#include "s21_math.h"

long double s21_log(double x) {
  if (x < 0.0 || s21_isnan(x) || x == -s21_INF) return s21_NAN;

  if (x == s21_INF) return s21_INF;

  if (x == 0) return -s21_INF;
  if (x == 1.0) return 0.0;

  long double log = 0.0;
  int count = 0;
  double res = 0.0;
  double comparison = 0.0;
  while (x >= s21_EXP) {
    x /= s21_EXP;
    count++;
  }
  for (int i = 0; i < 100; i++) {
    comparison = res;
    res =
        comparison + 2 * (x - s21_exp(comparison)) / (x + s21_exp(comparison));
  }
  log = res + count;

  return log;
}