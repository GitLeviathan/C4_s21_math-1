#include "s21_math.h"

long double s21_fmod(double x, double y) {
  
  if (s21_isnan(x) || s21_isnan(y))
    return NaN;

  if (y <= 0.0 || s21_isinf(y))
    return NaN;

  if (s21_isinf(x))
    return x;

  long double quotient = x / y;
  long double int_part = (long long)quotient;

  return x - (int_part * y);
}