#include "s21_math.h"

long double s21_exp(double x) {
    long double res = 0;
    if (s21_isnan(x))
        res = NaN;
    else if (x == -INF)
        res = 0;
    return res;
}