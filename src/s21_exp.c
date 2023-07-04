#include "s21_math.h"

long double s21_exp(double x) {
  double result = 1.0;
  if (s21_isnan(x) || x == INF) {
    result = x;
  } else if (x == -INF) {
    return 0.0;
  } else {
    double term = 1.0;

    for (int i = 1; i <= 10; ++i) {
        term *= x / i;
        result += term;
    }
  }

  return result;
}