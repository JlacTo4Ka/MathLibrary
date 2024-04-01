#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_math.h"

// gcc -o tests tests.c s21_math.c -lcheck

static void assert_ldouble_eq(long double a, long double b) {
  char buf_a[50];
  char buf_b[50];

  snprintf(buf_a, sizeof(buf_a), "%.16Lf", a);
  snprintf(buf_b, sizeof(buf_b), "%.16Lf", b);
  if (isnan(a) && isnan(b)) {
    ck_assert_msg(1, "%s: %Lf == %Lf", "FAIL", a, b);
  } else if (strncmp(buf_a, buf_b, 16) == 0) {
    ck_assert_msg(1, "%s: %Lf == %Lf", "FAIL", a, b);
  } else {
    ck_assert_msg(fabsl(a - b) < 1e-6, "%s: %Lf == %Lf", "FAIL", a, b);
  }
}

START_TEST(test_abs) {
  ck_assert_int_eq(s21_abs(100), abs(100));
  ck_assert_int_eq(s21_abs(-100), abs(-100));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(test_acos) {
  ck_assert_ldouble_eq_tol(s21_acos(0.1), acos(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.9), acos(0.9), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.2), acos(0.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.1), acos(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.9), acos(-0.9), 1e-6);
  ck_assert_float_nan(s21_acos(100));
}
END_TEST

START_TEST(test_asin) {
  ck_assert_ldouble_eq_tol(s21_asin(0.1), asin(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.9), asin(0.9), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.2), asin(0.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.1), asin(-0.1), 1e-6);
  assert_ldouble_eq(s21_asin(-9), asin(-9));
  ck_assert_float_nan(s21_asin(9));
  ck_assert_ldouble_eq_tol(s21_asin(0.1), asin(0.1), 1e-6);
}
END_TEST

START_TEST(test_atan) {
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.2), atan(0.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-2), atan(-2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(100), atan(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-50), atan(-50), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(21), atan(21), 1e-6);
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_ldouble_eq_tol(s21_ceil(100.1), ceil(100.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(100.6), ceil(100.6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(0), ceil(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-100.1), ceil(-100.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-100.6), ceil(-100.6), 1e-6);
}
END_TEST

START_TEST(test_cos) {
  ck_assert_ldouble_eq_tol(s21_cos(1000.233), cos(1000.233), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(100), cos(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.2), cos(0.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-1000.233), cos(-1000.233), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-100), cos(-100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0.2), cos(-0.2), 1e-6);
}
END_TEST

START_TEST(test_exp) {
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.3), exp(0.3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0.3), exp(-0.3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-23), exp(-23), 1e-6);
  assert_ldouble_eq(s21_exp(27), exp(27));
  assert_ldouble_eq(s21_exp(100), exp(100));
  ck_assert_ldouble_eq_tol(s21_exp(-24), exp(-24), 1e-6);
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_ldouble_eq_tol(s21_fabs(100.12), fabs(100.12), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-100.12), fabs(-100.12), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.12), fabs(-0.12), 1e-6);
}
END_TEST

START_TEST(test_floor) {
  ck_assert_ldouble_eq_tol(s21_floor(100.1), floor(100.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(100.6), floor(100.6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(0), floor(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(-100.1), floor(-100.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(-100.6), floor(-100.6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(-100.5), floor(-100.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(-100), floor(-100), 1e-6);
}
END_TEST

START_TEST(test_fmod) {
  ck_assert_ldouble_eq_tol(s21_fmod(100.0, 6.1), fmod(100.0, 6.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0.0, 0.1), fmod(0.0, 0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-100.0, 6.7), fmod(-100.0, 6.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-100.0, -6.1), fmod(-100.0, -6.1), 1e-6);
  ck_assert_float_nan(s21_fmod(0.0, 0.0));
}
END_TEST

START_TEST(test_log) {
  ck_assert_ldouble_eq_tol(s21_log(3), log(3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(0.1), log(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(100), log(100), 1e-6);
}
END_TEST

START_TEST(pow_test_1) {
  long double base = 1.25;
  long double exp = 0;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_2) {
  long double base = 1;
  long double exp = 1;
  long double result = s21_pow(base, exp);
  long double expected = powl(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_3) {
  long double base = 4.2525865;
  long double exp = 0.5656565;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_4) {
  long double base = 789.2525865;
  long double exp = 0.565;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_5) {
  long double base = 4.865;
  long double exp = S21_POS_INF;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert(isinf(result));
  ck_assert(isinf(expected));
}
END_TEST

START_TEST(pow_test_6) {
  long double base = -1;
  long double exp = S21_POS_INF;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_7) {
  long double base = -1;
  long double exp = S21_NEG_INF;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_8) {
  long double base = 0.5;
  long double exp = S21_POS_INF;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_9) {
  long double base = 3;
  long double exp = S21_NEG_INF;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_10) {
  long double base = S21_NEG_INF;
  long double exp = -2;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_11) {
  long double base = S21_NEG_INF;
  long double exp = -3;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_12) {
  long double base = S21_NEG_INF;
  long double exp = 2;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert(isinf(result));
  ck_assert(isinf(expected));
}
END_TEST

START_TEST(pow_test_13) {
  long double base = S21_POS_INF;
  long double exp = 3;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert(isinf(result));
  ck_assert(isinf(expected));
}
END_TEST

START_TEST(pow_test_14) {
  long double base = S21_NEG_INF;
  long double exp = -7;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_15) {
  long double base = S21_NEG_INF;
  long double exp = 7;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert(isinf(result));
  ck_assert(isinf(expected));
}
END_TEST

START_TEST(pow_test_16) {
  long double base = S21_POS_INF;
  long double exp = S21_NEG_INF;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_17) {
  long double base = -5;
  long double exp = S21_NEG_INF;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_18) {
  long double base = -5;
  long double exp = 5.5;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert(isnan(result));
  ck_assert(isnan(expected));
}
END_TEST

START_TEST(pow_test_19) {
  long double base = 0.5;
  long double exp = S21_NEG_INF;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert(isinf(result));
  ck_assert(isinf(expected));
}
END_TEST

START_TEST(pow_test_20) {
  long double base = S21_POS_INF;
  long double exp = -1;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(pow_test_21) {
  long double base = 113;
  long double exp = 4.252586;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_ldouble_eq_tol(result, expected, ACCURACY);
}
END_TEST

START_TEST(test_sin) {
  ck_assert_ldouble_eq_tol(s21_sin(1000.233), sin(1000.233), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(100), sin(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.2), sin(0.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-1000.233), sin(-1000.233), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-100), sin(-100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.2), sin(-0.2), 1e-6);
}
END_TEST

START_TEST(test_sqrt) {
  ck_assert_ldouble_eq_tol(s21_sqrt(100.123), sqrt(100.123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(100), sqrt(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
}
END_TEST

START_TEST(test_tan) {
  ck_assert_ldouble_eq_tol(s21_tan(1000.233), tan(1000.233), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(100), tan(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.2), tan(0.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-1000.233), tan(-1000.233), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-100), tan(-100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0.2), tan(-0.2), 1e-6);
}
END_TEST

Suite *s21_math_suit(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("MySuite");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_abs);
  tcase_add_test(tc_core, test_acos);
  tcase_add_test(tc_core, test_asin);
  tcase_add_test(tc_core, test_atan);
  tcase_add_test(tc_core, test_ceil);
  tcase_add_test(tc_core, test_cos);
  tcase_add_test(tc_core, test_exp);
  tcase_add_test(tc_core, test_fabs);
  tcase_add_test(tc_core, test_floor);
  tcase_add_test(tc_core, test_fmod);
  tcase_add_test(tc_core, test_log);
  tcase_add_test(tc_core, pow_test_1);
  tcase_add_test(tc_core, pow_test_2);
  tcase_add_test(tc_core, pow_test_3);
  tcase_add_test(tc_core, pow_test_4);
  tcase_add_test(tc_core, pow_test_5);
  tcase_add_test(tc_core, pow_test_6);
  tcase_add_test(tc_core, pow_test_7);
  tcase_add_test(tc_core, pow_test_8);
  tcase_add_test(tc_core, pow_test_9);
  tcase_add_test(tc_core, pow_test_10);
  tcase_add_test(tc_core, pow_test_11);
  tcase_add_test(tc_core, pow_test_12);
  tcase_add_test(tc_core, pow_test_13);
  tcase_add_test(tc_core, pow_test_14);
  tcase_add_test(tc_core, pow_test_15);
  tcase_add_test(tc_core, pow_test_16);
  tcase_add_test(tc_core, pow_test_17);
  tcase_add_test(tc_core, pow_test_18);
  tcase_add_test(tc_core, pow_test_19);
  tcase_add_test(tc_core, pow_test_20);
  tcase_add_test(tc_core, pow_test_21);
  tcase_add_test(tc_core, test_sin);
  tcase_add_test(tc_core, test_sqrt);
  tcase_add_test(tc_core, test_tan);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int failed_tests = 0;
  Suite *s;
  SRunner *sr;

  s = s21_math_suit();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  failed_tests = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (failed_tests == 0) ? 0 : 1;
}
