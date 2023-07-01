#include "s21_math.h"

long double s21_floor(double x) {
    if (!s21_isnan(x) && !s21_isinf(x) && (x - (long int) x != 0)) {
        if (x < 0) x = (long int) x - 1;
        else x = (long int) x;
    }
    return x;
}