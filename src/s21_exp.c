#include "s21_math.h"

long double s21_exp(double x) {
  double result = 1.0;
  if (s21_isnan(x) || x == s21_INF) {
    result = x;
  } else if (x == -s21_INF) {
    return 0.0;
  } else {
    double term = 1.0;
    int i = 1;
    while (s21_fabs(term) >= s21_EPS) {
      term *= x / i;
      result += term;
      i++;
    }
  }
  return result;
}