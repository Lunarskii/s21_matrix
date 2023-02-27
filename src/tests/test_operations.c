#include "test_core.h"

START_TEST(TEST_EQ_MATRIX1) {
  int RESULT_CODE = s21_eq_matrix(NULL, NULL);

  ck_assert_int_eq(RESULT_CODE, FAILURE);
}
END_TEST
START_TEST(TEST_EQ_MATRIX2) {
  matrix_t x;
  matrix_t y;
  s21_create_matrix(10, 10, &x);
  s21_create_matrix(10, 10, &y);
  x.rows = 0;
  int RESULT_CODE = s21_eq_matrix(&x, &y);

  ck_assert_int_eq(RESULT_CODE, FAILURE);

  x.rows = 10;
  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
}
END_TEST
START_TEST(TEST_EQ_MATRIX3) {
  matrix_t x;
  matrix_t y;
  s21_create_matrix(10, 10, &x);
  s21_create_matrix(10, 9, &y);
  int RESULT_CODE = s21_eq_matrix(&x, &y);

  ck_assert_int_eq(RESULT_CODE, FAILURE);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
}
END_TEST
START_TEST(TEST_EQ_MATRIX4) {
  matrix_t x;
  matrix_t y;
  double values[4] = {1.1921650, 2, 3, 4};
  s21_create_matrix(2, 2, &x);
  s21_create_matrix(2, 2, &y);
  s21_setMatrix(values, &x);
  s21_setMatrix(values, &y);
  int RESULT_CODE = s21_eq_matrix(&x, &y);

  ck_assert_int_eq(RESULT_CODE, SUCCESS);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
}
END_TEST
START_TEST(TEST_EQ_MATRIX5) {
  matrix_t x;
  matrix_t y;
  double values_x[4] = {1.1921650, 2, 3, 4};
  double values_y[4] = {1.1921651, 2, 3, 4};
  s21_create_matrix(2, 2, &x);
  s21_create_matrix(2, 2, &y);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_y, &y);
  int RESULT_CODE = s21_eq_matrix(&x, &y);

  ck_assert_int_eq(RESULT_CODE, FAILURE);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
}
END_TEST
START_TEST(TEST_EQ_MATRIX6) {
  matrix_t x;
  matrix_t y;
  double values_x[4] = {1.19216501, 2, 3, 4};
  double values_y[4] = {1.19216502, 2, 3, 4};
  s21_create_matrix(2, 2, &x);
  s21_create_matrix(2, 2, &y);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_y, &y);
  int RESULT_CODE = s21_eq_matrix(&x, &y);

  ck_assert_int_eq(RESULT_CODE, SUCCESS);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
}
END_TEST

START_TEST(TEST_TRANSPOSE1) {
  matrix_t result;
  int RESULT_CODE = s21_transpose(NULL, &result);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);
}
END_TEST
START_TEST(TEST_TRANSPOSE2) {
  matrix_t x;
  matrix_t result;
  s21_create_matrix(10, 10, &x);
  x.rows = 0;
  int RESULT_CODE = s21_transpose(&x, &result);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);

  x.rows = 10;
  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_TRANSPOSE3) {
  matrix_t x;
  matrix_t result_tr;
  matrix_t result_test;
  double values_x[6] = {1, 2, 3, 4, 5, 6};
  double values_result[6] = {1, 4, 2, 5, 3, 6};
  s21_create_matrix(2, 3, &x);
  s21_create_matrix(3, 2, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_transpose(&x, &result_tr);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_tr), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&result_tr);
  s21_remove_matrix(&result_test);
}
END_TEST
START_TEST(TEST_TRANSPOSE4) {
  matrix_t x;
  matrix_t result_tr;
  matrix_t result_test;
  double values_x[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double values_result[9] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
  s21_create_matrix(3, 3, &x);
  s21_create_matrix(3, 3, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_transpose(&x, &result_tr);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_tr), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&result_tr);
  s21_remove_matrix(&result_test);
}
END_TEST
START_TEST(TEST_TRANSPOSE5) {
  matrix_t x;
  matrix_t result_tr;
  matrix_t result_test;
  double values_x[6] = {1, 2, 3, 4, 5, 6};
  double values_result[6] = {1, 3, 5, 2, 4, 6};
  s21_create_matrix(3, 2, &x);
  s21_create_matrix(2, 3, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_transpose(&x, &result_tr);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_tr), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&result_tr);
  s21_remove_matrix(&result_test);
}
END_TEST

START_TEST(TEST_CALC_COMPLEMENTS1) {
  int RESULT_CODE = s21_calc_complements(NULL, NULL);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);
}
END_TEST
START_TEST(TEST_CALC_COMPLEMENTS2) {
  matrix_t x;
  matrix_t y;
  s21_create_matrix(10, 10, &x);
  x.rows = 0;
  int RESULT_CODE = s21_calc_complements(&x, &y);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);

  x.rows = 10;
  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_CALC_COMPLEMENTS3) {
  matrix_t x;
  matrix_t y;
  s21_create_matrix(10, 9, &x);
  int RESULT_CODE = s21_calc_complements(&x, &y);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_CALCULATION);

  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_CALC_COMPLEMENTS4) {
  matrix_t x;
  matrix_t result_calc;
  matrix_t result_test;
  s21_create_matrix(1, 1, &x);
  s21_create_matrix(1, 1, &result_test);
  x.matrix[0][0] = 984.1238;
  result_test.matrix[0][0] = 984.1238;
  int RESULT_CODE = s21_calc_complements(&x, &result_calc);

  ck_assert_int_eq(s21_eq_matrix(&result_calc, &result_test), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&result_calc);
  s21_remove_matrix(&result_test);
}
END_TEST
START_TEST(TEST_CALC_COMPLEMENTS5) {
  matrix_t x;
  matrix_t result_calc;
  matrix_t result_test;
  double values_x[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double values_result[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  s21_create_matrix(3, 3, &x);
  s21_create_matrix(3, 3, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_result, &result_test);

  int RESULT_CODE = s21_calc_complements(&x, &result_calc);

  ck_assert_int_eq(s21_eq_matrix(&result_calc, &result_test), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&result_calc);
  s21_remove_matrix(&result_test);
}
END_TEST

START_TEST(TEST_DETERMINANT1) {
  int RESULT_CODE = s21_determinant(NULL, NULL);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);
}
END_TEST
START_TEST(TEST_DETERMINANT2) {
  matrix_t x;
  double y;
  s21_create_matrix(10, 10, &x);
  x.rows = 0;
  int RESULT_CODE = s21_determinant(&x, &y);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);

  x.rows = 10;
  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_DETERMINANT3) {
  matrix_t x;
  double y;
  s21_create_matrix(10, 9, &x);
  int RESULT_CODE = s21_determinant(&x, &y);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_CALCULATION);

  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_DETERMINANT4) {
  matrix_t x;
  double result_calc;
  double result_test = 984.1238;
  s21_create_matrix(1, 1, &x);
  x.matrix[0][0] = 984.1238;
  int RESULT_CODE = s21_determinant(&x, &result_calc);

  ck_assert_double_eq(result_calc, result_test);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_DETERMINANT5) {
  matrix_t x;
  double result_test = -347879921061.47;
  double result_calc;
  double values_x[9] = {18248.2488, 91293.124898, 300.1,  390.1123, 44.5, 0,
                        1,          1238.4,       9999.99};
  s21_create_matrix(3, 3, &x);
  s21_setMatrix(values_x, &x);

  int RESULT_CODE = s21_determinant(&x, &result_calc);

  ck_assert_double_eq_tol(result_test, result_calc, 1e6);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_DETERMINANT6) {
  matrix_t x;
  double result_test = -40;
  double result_calc;
  double values_x[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  s21_create_matrix(3, 3, &x);
  s21_setMatrix(values_x, &x);

  int RESULT_CODE = s21_determinant(&x, &result_calc);

  ck_assert_double_eq(result_test, result_calc);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_DETERMINANT7) {
  matrix_t x;
  double result_test = -1369800;
  double result_calc;
  double values_x[25] = {1,  2,  3,   4, 5,  6,  7,  8,  9,  10, 11, 12, 49,
                         14, 15, 161, 7, 18, 19, 20, 64, 48, 1,  2,  3};
  s21_create_matrix(5, 5, &x);
  s21_setMatrix(values_x, &x);

  int RESULT_CODE = s21_determinant(&x, &result_calc);

  ck_assert_double_eq(result_test, result_calc);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_DETERMINANT8) {
  matrix_t x;
  double result_test = 17187;
  double result_calc;
  double values_x[4] = {9, 2, 96, 1931};
  s21_create_matrix(2, 2, &x);
  s21_setMatrix(values_x, &x);

  int RESULT_CODE = s21_determinant(&x, &result_calc);

  ck_assert_double_eq(result_test, result_calc);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
}
END_TEST

START_TEST(TEST_INVERSE1) {
  int RESULT_CODE = s21_inverse_matrix(NULL, NULL);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);
}
END_TEST
START_TEST(TEST_INVERSE2) {
  matrix_t x;
  matrix_t y;
  s21_create_matrix(10, 10, &x);
  x.rows = 0;
  int RESULT_CODE = s21_inverse_matrix(&x, &y);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);

  x.rows = 10;
  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_INVERSE3) {
  matrix_t x;
  matrix_t y;
  s21_create_matrix(10, 9, &x);
  int RESULT_CODE = s21_inverse_matrix(&x, &y);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_CALCULATION);

  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_INVERSE4) {
  matrix_t x;
  matrix_t result_inv;
  matrix_t result_test;
  s21_create_matrix(1, 1, &x);
  s21_create_matrix(1, 1, &result_test);
  x.matrix[0][0] = 42.12849;
  result_test.matrix[0][0] = 1 / 42.12849;
  int RESULT_CODE = s21_inverse_matrix(&x, &result_inv);

  ck_assert_double_eq(s21_eq_matrix(&result_inv, &result_test), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_inv);
}
END_TEST
START_TEST(TEST_INVERSE5) {
  matrix_t x;
  matrix_t result_inv;
  matrix_t result_test;
  double values_x[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double values_result[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  s21_create_matrix(3, 3, &x);
  s21_create_matrix(3, 3, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_inverse_matrix(&x, &result_inv);

  ck_assert_double_eq(s21_eq_matrix(&result_inv, &result_test), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_inv);
}
END_TEST
START_TEST(TEST_INVERSE6) {
  matrix_t x;
  matrix_t result_inv;
  double values_x[25] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                         14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
  s21_create_matrix(5, 5, &x);
  s21_setMatrix(values_x, &x);
  int RESULT_CODE = s21_inverse_matrix(&x, &result_inv);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_CALCULATION);

  s21_remove_matrix(&x);
}
END_TEST

Suite *st_operations(void) {
  Suite *s = suite_create("st_operations");
  TCase *tc = tcase_create("operations_tc");

  tcase_add_test(tc, TEST_EQ_MATRIX1);
  tcase_add_test(tc, TEST_EQ_MATRIX2);
  tcase_add_test(tc, TEST_EQ_MATRIX3);
  tcase_add_test(tc, TEST_EQ_MATRIX4);
  tcase_add_test(tc, TEST_EQ_MATRIX5);
  tcase_add_test(tc, TEST_EQ_MATRIX6);

  tcase_add_test(tc, TEST_TRANSPOSE1);
  tcase_add_test(tc, TEST_TRANSPOSE2);
  tcase_add_test(tc, TEST_TRANSPOSE3);
  tcase_add_test(tc, TEST_TRANSPOSE4);
  tcase_add_test(tc, TEST_TRANSPOSE5);

  tcase_add_test(tc, TEST_CALC_COMPLEMENTS1);
  tcase_add_test(tc, TEST_CALC_COMPLEMENTS2);
  tcase_add_test(tc, TEST_CALC_COMPLEMENTS3);
  tcase_add_test(tc, TEST_CALC_COMPLEMENTS4);
  tcase_add_test(tc, TEST_CALC_COMPLEMENTS5);

  tcase_add_test(tc, TEST_DETERMINANT1);
  tcase_add_test(tc, TEST_DETERMINANT2);
  tcase_add_test(tc, TEST_DETERMINANT3);
  tcase_add_test(tc, TEST_DETERMINANT4);
  tcase_add_test(tc, TEST_DETERMINANT5);
  tcase_add_test(tc, TEST_DETERMINANT6);
  tcase_add_test(tc, TEST_DETERMINANT7);
  tcase_add_test(tc, TEST_DETERMINANT8);

  tcase_add_test(tc, TEST_INVERSE1);
  tcase_add_test(tc, TEST_INVERSE2);
  tcase_add_test(tc, TEST_INVERSE3);
  tcase_add_test(tc, TEST_INVERSE4);
  tcase_add_test(tc, TEST_INVERSE5);
  tcase_add_test(tc, TEST_INVERSE6);

  suite_add_tcase(s, tc);
  return s;
}