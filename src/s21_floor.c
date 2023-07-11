#include "s21_math.h"

long double s21_floor(double x) {
  long double result = x;
  if (!s21_isnan(x) && !s21_isinf(x)) {
    result = (long int)result - (result < (long int)result);
  }
  return result;
}