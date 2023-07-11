#include "s21_math.h"
#include <math.h>
#include <stdio.h>

long double s21_pow(double base, double exponent) {
  if (s21_isnan(base) || s21_isnan(exponent))
    return s21_NAN;  // NaN^x or x^NaN = NaN

  if (base == 1.0)
    return 1.0;  // 1 raised to any power is 1

  if (exponent == 0.0)
    return 1.0;  // Any number raised to power 0 is 1

  if (exponent == 1.0)
    return base;  // Any number raised to power 1 is itself

  if (base == INFINITY) {
    if (exponent > 0.0)
      return INFINITY;  // infinity^positive = infinity
    else
      return 0.0;  // infinity^negative = 0
  }

  if (base == -INFINITY) {
    if (exponent > 0.0) {
      if (s21_floor(exponent) == exponent && (long long)exponent % 2 == 1)
        return -INFINITY;  // (-infinity)^odd = -infinity
      else
        return INFINITY;  // (-infinity)^even = infinity
    } else {
      if (s21_floor(exponent) == exponent && (long long)exponent % 2 == 1)
        return -0.0;  // (-infinity)^odd = -0
      else
        return 0.0;  // (-infinity)^even = 0
    }
  }
  if (base < 0.0) {
    if (exponent == -INFINITY)
        return 0.0;
    else if (exponent == INFINITY)
        return INFINITY;
  }

  return exp(exponent * log(base));  // Compute power using exponentiation identity
}


/*long double s21_pow(double base, double exponent) {
  if (base == 0.0) {
    if (exponent == 0.0)
      return 1.0;  // 0^0 = 1 by convention
    else if (exponent > 0.0)
      return 0.0;  // 0^positive = 0
    else
      return INFINITY;  // 0^negative = infinity
  }

  if (base == 1.0)
    return 1.0;  // 1 raised to any power is 1

  if (s21_isnan(base) || s21_isnan(exponent))
    return NAN;  // NaN^x or x^NaN = NaN

  if (exponent == 0.0)
    return 1.0;  // Any number raised to power 0 is 1

  if (exponent == 1.0)
    return base;  // Any number raised to power 1 is itself

  if (base == INFINITY) {
    if (exponent > 0.0)
      return INFINITY;  // infinity^positive = infinity
    else
      return 0.0;  // infinity^negative = 0
  }

  if (base == -INFINITY) {
    if (exponent > 0.0) {
      if (s21_floor(exponent) == exponent && (long long)exponent % 2 == 1)
        return -INFINITY;  // (-infinity)^odd = -infinity
      else
        return INFINITY;  // (-infinity)^even = infinity
    } else {
      if (s21_floor(exponent) == exponent && (long long)exponent % 2 == 1)
        return -0.0;  // (-infinity)^odd = -0
      else
        return 0.0;  // (-infinity)^even = 0
    }
  }

  return exp(exponent * log(base));  // Compute power using exponentiation identity
}*/
