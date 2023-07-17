#include "test_core.h"

START_TEST(TEST_CREATE_MATRIX1) {
  matrix_t result;
  int rows = 0;
  int columns = 1;
  int RESULT_CODE = s21_create_matrix(rows, columns, &result);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);
}
END_TEST
START_TEST(TEST_CREATE_MATRIX2) {
  int rows = 10;
  int columns = 10;
  int RESULT_CODE = s21_create_matrix(rows, columns, NULL);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);
}
END_TEST

START_TEST(TEST_REMOVE_MATRIX1) { s21_remove_matrix(NULL); }
END_TEST
START_TEST(TEST_REMOVE_MATRIX2) {
  matrix_t test;
  s21_create_matrix(10, 10, &test);
  s21_remove_matrix(&test);

  ck_assert_ptr_eq(test.matrix, NULL);
  ck_assert_int_eq(test.rows, 0);
  ck_assert_int_eq(test.columns, 0);
}
END_TEST

Suite *st_matrix(void) {
  Suite *s = suite_create("st_matrix");
  TCase *tc = tcase_create("matrix_tc");

  tcase_add_test(tc, TEST_CREATE_MATRIX1);
  tcase_add_test(tc, TEST_CREATE_MATRIX2);

  tcase_add_test(tc, TEST_REMOVE_MATRIX1);
  tcase_add_test(tc, TEST_REMOVE_MATRIX2);

  suite_add_tcase(s, tc);
  return s;
}