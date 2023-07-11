#ifndef S21_MATH_H_
#define S21_MATH_H_

#include <stdbool.h>

#define s21_INF (1.0 / 0.0)
#define s21_NAN (0.0 / 0.0)
#define s21_EPS 1e-6
#define s21_EXP 2.718281828459045
#define s21_PI 3.141592653589793

int s21_isnan(double x);
int s21_isinf(double x);

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  // S21_MATH_H_