#include "s21_math.h"

long double s21_log(double x) {
  if (x < 0.0 || s21_isnan(x) || x == -INF)
    return NaN;
  if (x == INF)
    return INF;
  if (x == 0)
    return -INF;

  long double log = 0.0;
  int count = 0;
  double res = 0.0;
  double comparison = 0.0;
  while (x >= S21_M_E) {
      x /= S21_M_E;
      count++;
    }
    for (int i = 0; i < 100; i++) {
      comparison = res;
      res = comparison +
            2 * (x - s21_exp(comparison)) / (x + s21_exp(comparison));
    }
    log = res + count;

  return log;
}