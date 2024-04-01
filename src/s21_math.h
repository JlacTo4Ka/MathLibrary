#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_PI 3.14159265358979323846
#define S21_E 2.71828182845904523536028747
#define S21_NAN 0.0 / 0.0
#define S21_POS_INF +1.0 / 0.0
#define S21_NEG_INF -1.0 / 0.0
#define S21_POS_ZERO 0 / +1.0
#define S21_NEG_ZERO 0 / -1.0
#define S21_LN2 0.693147180559945309417232

#define MAX_LIM 709
#define MIN_LIM -33

#define ACCURACY 0.000001

int s21_abs(int digit);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);

long double two_pi(double x);

long double s21_cos(double x);
long double s21_sin(double x);
long double s21_ceil(double x);

long double s21_exp(double x);
long double s21_exp_dop(double x);
long double s21_sqrt_n(double base, double exp);
long double s21_pow(double base, double exp);
long double simple_fraction(double base);
long double s21_trunc(double base);

long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);

long double s21_sqrt(double x);
long double s21_tan(double x);

long double factorial(int x);
long double int_pow(double x, int exp);

#endif  // S21_MATH_H
