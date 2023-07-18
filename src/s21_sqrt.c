#include "s21_math.h"

long double s21_sqrt(double x) {
  if (__builtin_signbit(x)) 
    return S21_NAN;
  if (S21_IS_INF(x)) 
    return S21_INF;
  return s21_pow(x, 0.5);
}
