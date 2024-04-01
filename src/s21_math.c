#include "s21_math.h"

long double MATH_PI = 3.14159265358979323846;
long double MATH_EXP = 2.718281828459045235360;

int s21_abs(int digit) {
  if (digit < 0) digit = -digit;
  return digit;
}

long double s21_atan(double x) {
  long double answer = 0.0;
  int is_range = (x > -1 && x < 1);
  if (x == S21_POS_INF) {
    answer = MATH_PI / 2;
  } else if (x == S21_NEG_INF) {
    answer = -MATH_PI / 2;
  }
  if (x != x) {
    answer = x;
  }
  if (x == 1) {
    answer = MATH_PI / 4;
  } else if (x == -1) {
    answer = -MATH_PI / 4;
  } else {
    answer = is_range ? x : 1.0 / x;
    int n = 1;
    do {
      double a = int_pow(-1, n);
      double b = int_pow(x, (1 + 2 * n) * (is_range ? 1 : -1));
      double c = 1 + 2 * n;
      answer += a * b / c;
      n++;
    } while (n < 7000);
    if (x > 1) {
      answer = MATH_PI / 2 - s21_atan(1 / x);
    } else if (x < -1) {
      answer = -MATH_PI / 2 - s21_atan(1 / x);
    }
  }
  return answer;
}

long double s21_acos(double x) {
  long double answer = 0.0;
  if (x == 0) {
    answer = MATH_PI / 2;
  } else if (x > 0) {
    answer = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x < 0) {
    answer = MATH_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  }
  return answer;
}

long double s21_asin(double x) {
  long double answer = 0.0;
  if (x == S21_POS_INF || x == 1) {
    answer = MATH_PI / 2;
  } else if (x == S21_NEG_INF || x == -1) {
    answer = -MATH_PI / 2;
  } else
    answer = s21_atan(x / s21_sqrt(1 - x * x));
  return answer;
}

long double s21_ceil(double x) {
  if (x == (int)x) return x;
  if (x >= 0) return (long double)(int)x + 1.0;
  return (long double)(int)x;
}

long double two_pi(double x) {
  long double result = x;

  while (!(result >= -2 * MATH_PI && result <= 2 * MATH_PI)) {
    if (result < 0) {
      result += 2 * MATH_PI;
    } else {
      result -= 2 * MATH_PI;
    }
  }

  return result;
}

long double s21_cos(double x) {
  long double result = 0.0;

  for (int n = 0; n < 100; n++) {
    result += ((int_pow(-1, n) * int_pow(two_pi(x), 2 * n)) / factorial(2 * n));
  }

  return result;
}

long double s21_sin(double x) {
  long double result = 0.0;
  int sing = 1;
  x = two_pi(x);
  for (int n = 1; n < 100; n++) {
    result += sing * (int_pow(x, 2 * n - 1) / factorial(2 * n - 1));
    sing *= -1;
  }

  return result;
}

long double s21_exp_dop(double x) {
  long double result = 0;
  int n = 0;

  while (1) {
    long double step = (long double)int_pow(s21_fabs(x), n) / factorial(n);
    if (step > 1e-16) {
      result += step;

    } else {
      break;
    }
    n++;
  }
  if (x < 0) return 1 / result;
  return result;
}

long double s21_exp(double x) {
  if (x <= 23) {
    return s21_exp_dop(x);
  } else {
    long double res_teylor_23 = s21_exp_dop(23);
    long double result = res_teylor_23;
    int b = (int)x / 23;
    double a = x - (b * 23);
    for (int i = 1; i < b; i++) {
      result *= res_teylor_23;
    }
    result *= s21_exp_dop(a);
    return result;
  }
}

long double s21_fabs(double x) {
  if (x < 0) x = -x;
  return x;
}

long double s21_floor(double x) {
  long double answer;
  if (x < 0 && (long double)((long long int)x) != x)
    answer = (long double)((long long int)x - 1);
  else if (x < 0 && (long double)((long long int)x) == x)
    answer = (long double)((long long int)x);
  else
    answer = (long double)((long long int)x);
  return answer;
}

long double s21_fmod(double x, double y) {
  if (y == 0.0) {
    return 0.0 / 0.0;
  }
  int digit = x / y;
  long double result = x - digit * y;
  return result;
}

long double s21_log(double x) {
  long double result = 0.0;
  if (x <= 0) result = -1.0 / 0.0;
  while (x > 1) {
    x = x / MATH_EXP;
    result++;
  }

  if (x > 0 && x <= 1) {
    for (int n = 0; n < 10000; n++) {
      result += (int_pow(-1, n) * int_pow(x - 1, n + 1)) / (n + 1);
    }
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double answer = 0.0;
  if (!exp || base == 1 ||
      (base == -1 && (exp == S21_POS_INF || exp == S21_NEG_INF)))
    answer = 1;
  else if (exp == S21_POS_INF) {
    if (s21_fabs(base) > 1)
      answer = S21_POS_INF;
    else if (s21_fabs(base) > 0 && s21_fabs(base) < 1)
      answer = S21_POS_ZERO;
  } else if (exp == S21_NEG_INF) {
    if (s21_fabs(base) > 1)
      answer = S21_POS_ZERO;
    else if (s21_fabs(base) > 0 && s21_fabs(base) < 1)
      answer = S21_POS_INF;
  } else if (base == S21_NEG_INF) {
    if ((s21_fmod(exp, 2.0) == 0) && exp < 0)
      answer = S21_POS_ZERO;
    else if ((s21_abs(s21_fmod(exp, 2.0)) == 1) && exp < 0)
      answer = S21_NEG_ZERO;
    else if ((s21_fmod(exp, 2.0) == 0) && exp > 0)
      answer = S21_NEG_INF;
    else if ((s21_abs(s21_fmod(exp, 2.0)) == 1) && exp > 0)
      answer = S21_POS_INF;
  } else if (base == S21_POS_INF) {
    if (exp < 0)
      answer = S21_POS_ZERO;
    else if (exp > 0)
      answer = S21_POS_INF;
  } else if (base < 0 && exp != (long long int)exp)
    answer = 0.0 / 0.0;
  else
    answer = s21_exp(s21_log(base) * exp);
  return answer;
}

long double s21_sqrt(double x) {
  long double answer = 0.0;
  if (x < 0) {
    answer = 0.0 / 0.0;
  }

  int start = 0, end = x;
  int mid;

  while (start <= end) {
    mid = (start + end) / 2;
    if ((double)mid * mid == x) {
      answer = mid;
      break;
    }

    if (mid * mid < x) {
      answer = start;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  double increment = 0.1;
  for (int i = 0; i < 6; i++) {
    while (answer * answer <= x) {
      answer += increment;
    }
    answer = answer - increment;
    increment /= 10;
  }
  return answer;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double factorial(int x) {
  long double result = 1;
  for (int i = 1; i <= x; i++) {
    result *= i;
  }

  return result;
}

long double int_pow(double base, int exp) {
  long double answer;
  if (exp == 0) {
    answer = 1;
  } else {
    answer = base;
    for (int i = 1; i < exp; i++) {
      answer *= base;
    }
  }
  return answer;
}
