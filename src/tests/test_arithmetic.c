#include "test_core.h"

START_TEST(TEST_SUM1) {
  matrix_t x;
  matrix_t y;
  matrix_t result_test;
  matrix_t result_sum;
  s21_create_matrix(1, 1, &x);
  s21_create_matrix(1, 1, &y);
  s21_create_matrix(1, 1, &result_test);
  x.matrix[0][0] = 38.12389;
  y.matrix[0][0] = -129.4910;
  result_test.matrix[0][0] = -91.36711;
  int RESULT_CODE = s21_sum_matrix(&x, &y, &result_sum);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_sum), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_sum);
}
END_TEST
START_TEST(TEST_SUM2) {
  matrix_t x;
  matrix_t y;
  matrix_t result_test;
  matrix_t result_sum;
  double values_x[4] = {121239.113, 2401.12392, -348901.2, 2389014};
  double values_y[4] = {109428035910.10189, -19872409.1489, 3, 140912.5};
  double values_result[4] = {109428157149.21489, -19870008.02498, -348898.2,
                             2529926.5};
  s21_create_matrix(2, 2, &x);
  s21_create_matrix(2, 2, &y);
  s21_create_matrix(2, 2, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_y, &y);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_sum_matrix(&x, &y, &result_sum);

  // printf("\n================================================================================================================\n");
  // printf("                                                    TEST_SUM2 \n");
  // printf("matrix x: \n");
  // s21_print_matrix(&x);
  // printf("\nmatrix y: \n");
  // s21_print_matrix(&y);
  // printf("\nmatrix test: \n");
  // s21_print_matrix(&result_test);
  // printf("\nmatrix sum: \n");
  // s21_print_matrix(&result_sum);
  // printf("\nRESULT_CODE = %d\n", RESULT_CODE);
  // printf("================================================================================================================\n");

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_sum), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_sum);
}
END_TEST
START_TEST(TEST_SUM3) {
  matrix_t x;
  matrix_t y;
  matrix_t result_test;
  matrix_t result_sum;
  double values_x[9] = {121239.122013, 2401.12392,   -348901.2, 2389014,
                        912039.12389,  129034.23400, 0,         1203,
                        9000000.123};
  double values_y[9] = {
      109428035910.1024189, -19872409.1489, 3, 140912.5, 0, 12930124, 1942.3489,
      102.234891,           10230912.1};
  double values_result[9] = {
      109428157149.2244319, -19870008.02498, -348898.2, 2529926.5,
      912039.12389,         13059158.234,    1942.3489, 1305.234891,
      19230912.223};
  s21_create_matrix(3, 3, &x);
  s21_create_matrix(3, 3, &y);
  s21_create_matrix(3, 3, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_y, &y);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_sum_matrix(&x, &y, &result_sum);

  // printf("\n================================================================================================================\n");
  // printf("                                                    TEST_SUM3 \n");
  // printf("matrix x: \n");
  // s21_print_matrix(&x);
  // printf("\nmatrix y: \n");
  // s21_print_matrix(&y);
  // printf("\nmatrix test: \n");
  // s21_print_matrix(&result_test);
  // printf("\nmatrix sum: \n");
  // s21_print_matrix(&result_sum);
  // printf("\nRESULT_CODE = %d\n", RESULT_CODE);
  // printf("================================================================================================================\n");

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_sum), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_sum);
}
END_TEST
START_TEST(TEST_SUM4) {
  matrix_t test;
  int RESULT_CODE = s21_sum_matrix(NULL, &test, &test);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);
}
END_TEST
START_TEST(TEST_SUM5) {
  matrix_t x;
  matrix_t y;
  matrix_t result;
  s21_create_matrix(2, 2, &x);
  s21_create_matrix(2, 1, &y);
  int RESULT_CODE = s21_sum_matrix(&x, &y, &result);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_CALCULATION);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
}
END_TEST
START_TEST(TEST_SUM6) {
  matrix_t x;
  matrix_t y;
  matrix_t result;
  s21_create_matrix(10, 10, &x);
  s21_create_matrix(10, 10, &y);
  x.rows = 0;
  int RESULT_CODE = s21_sum_matrix(&x, &y, &result);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);

  x.rows = 10;
  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
}
END_TEST
START_TEST(TEST_SUM7) {
  matrix_t x;
  matrix_t y;
  matrix_t result_test;
  matrix_t result_sum;
  double values_x[6] = {1, 2, 3, 4, 5, 6};
  double values_y[6] = {2, 3, 4, 5, 6, 7};
  double values_result[6] = {3, 5, 7, 9, 11, 13};
  s21_create_matrix(3, 2, &x);
  s21_create_matrix(3, 2, &y);
  s21_create_matrix(3, 2, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_y, &y);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_sum_matrix(&x, &y, &result_sum);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_sum), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_sum);
}

START_TEST(TEST_SUB1) {
  matrix_t x;
  matrix_t y;
  matrix_t result_test;
  matrix_t result_sub;
  s21_create_matrix(1, 1, &x);
  s21_create_matrix(1, 1, &y);
  s21_create_matrix(1, 1, &result_test);
  x.matrix[0][0] = 38.12389;
  y.matrix[0][0] = -129.4910;
  result_test.matrix[0][0] = 167.61489;
  int RESULT_CODE = s21_sub_matrix(&x, &y, &result_sub);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_sub), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_sub);
}
END_TEST
START_TEST(TEST_SUB2) {
  matrix_t x;
  matrix_t y;
  matrix_t result_test;
  matrix_t result_sub;
  double values_x[4] = {121239.113, 2401.12392, -348901.2, 2389014};
  double values_y[4] = {109910.10189, -19872409.1489, 3, 140912.5};
  double values_result[4] = {11329.01111, 19874810.27282, -348904.2, 2248101.5};
  s21_create_matrix(2, 2, &x);
  s21_create_matrix(2, 2, &y);
  s21_create_matrix(2, 2, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_y, &y);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_sub_matrix(&x, &y, &result_sub);

  // printf("\n================================================================================================================\n");
  // printf("                                                    TEST_SUB2 \n");
  // printf("matrix x: \n");
  // s21_print_matrix(&x);
  // printf("\nmatrix y: \n");
  // s21_print_matrix(&y);
  // printf("\nmatrix test: \n");
  // s21_print_matrix(&result_test);
  // printf("\nmatrix sum: \n");
  // s21_print_matrix(&result_sub);
  // printf("\nRESULT_CODE = %d\n", RESULT_CODE);
  // printf("================================================================================================================\n");

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_sub), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_sub);
}
END_TEST
START_TEST(TEST_SUB3) {
  matrix_t x;
  matrix_t y;
  matrix_t result_test;
  matrix_t result_sub;
  double values_x[9] = {121239.122013, 2401.12392,   -348901.2, 2389014,
                        912039.12389,  129034.23400, 0,         1203,
                        9000000.123};
  double values_y[9] = {
      109428035910.1024189, -19872409.1489, 3, 140912.5, 0, 12930124, 1942.3489,
      102.234891,           10230912.1};
  double values_result[9] = {
      -109427914670.9804059, 19874810.27282, -348904.2,  2248101.5,
      912039.12389,          -12801089.766,  -1942.3489, 1100.765109,
      -1230911.977};
  s21_create_matrix(3, 3, &x);
  s21_create_matrix(3, 3, &y);
  s21_create_matrix(3, 3, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_y, &y);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_sub_matrix(&x, &y, &result_sub);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_sub), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_sub);
}
END_TEST
START_TEST(TEST_SUB4) {
  matrix_t test;
  int RESULT_CODE = s21_sub_matrix(NULL, &test, &test);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);
}
END_TEST
START_TEST(TEST_SUB5) {
  matrix_t x;
  matrix_t y;
  matrix_t result;
  s21_create_matrix(2, 2, &x);
  s21_create_matrix(2, 1, &y);
  int RESULT_CODE = s21_sub_matrix(&x, &y, &result);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_CALCULATION);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
}
END_TEST
START_TEST(TEST_SUB6) {
  matrix_t x;
  matrix_t y;
  matrix_t result;
  s21_create_matrix(10, 10, &x);
  s21_create_matrix(10, 10, &y);
  x.rows = 0;
  int RESULT_CODE = s21_sub_matrix(&x, &y, &result);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);

  x.rows = 10;
  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
}
END_TEST
START_TEST(TEST_SUB7) {
  matrix_t x;
  matrix_t y;
  matrix_t result_test;
  matrix_t result_sum;
  double values_x[6] = {1, 2, 3, 4, 5, 6};
  double values_y[6] = {2, 3, 4, 5, 6, 7};
  double values_result[6] = {-1, -1, -1, -1, -1, -1};
  s21_create_matrix(3, 2, &x);
  s21_create_matrix(3, 2, &y);
  s21_create_matrix(3, 2, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_y, &y);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_sub_matrix(&x, &y, &result_sum);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_sum), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_sum);
}

START_TEST(TEST_MULT_NUMBER1) {
  matrix_t test;
  int RESULT_CODE = s21_mult_number(NULL, 10, &test);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);
}
END_TEST
START_TEST(TEST_MULT_NUMBER2) {
  matrix_t x;
  matrix_t result;
  s21_create_matrix(10, 10, &x);
  x.rows = 0;
  int RESULT_CODE = s21_mult_number(&x, 10, &result);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);

  x.rows = 10;
  s21_remove_matrix(&x);
}
END_TEST
START_TEST(TEST_MULT_NUMBER3) {
  matrix_t x;
  double y = 3.12890;
  matrix_t result_test;
  matrix_t result_mult;
  double values_x[4] = {121239.113, 2401.12392, -348901.2, 2389014};
  double values_result[4] = {379345.0606657, 7512.876633288, -1091676.96468,
                             7474985.9046};
  s21_create_matrix(2, 2, &x);
  s21_create_matrix(2, 2, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_mult_number(&x, y, &result_mult);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_mult), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_mult);
}
END_TEST
START_TEST(TEST_MULT_NUMBER4) {
  matrix_t x;
  double y = 3901.904;
  matrix_t result_test;
  matrix_t result_mult;
  double values_x[9] = {121239.122013, 2401.12392,   -348901.2, 2389014,
                        912039.12389,  129034.23400, 0,         1203,
                        9000000.123};
  double values_result[9] = {473063415.139012752,
                             9368955.02794368,
                             -1361378987.8848,
                             9321703282.656,
                             3558689105.66288656,
                             503479193.781536,
                             0,
                             4693990.512,
                             35117136479.934192};
  s21_create_matrix(3, 3, &x);
  s21_create_matrix(3, 3, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_mult_number(&x, y, &result_mult);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_mult), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_mult);
}
END_TEST

START_TEST(TEST_MULT_MATRIX1) {
  matrix_t test;
  int RESULT_CODE = s21_mult_matrix(NULL, &test, &test);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);
}
END_TEST
START_TEST(TEST_MULT_MATRIX2) {
  matrix_t x;
  matrix_t y;
  matrix_t result;
  s21_create_matrix(10, 10, &x);
  s21_create_matrix(10, 10, &y);
  x.rows = 0;
  int RESULT_CODE = s21_mult_matrix(&x, &y, &result);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_MATRIX);

  x.rows = 10;
  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
}
END_TEST
START_TEST(TEST_MULT_MATRIX3) {
  matrix_t x;
  matrix_t y;
  matrix_t result;
  s21_create_matrix(2, 3, &x);
  s21_create_matrix(2, 3, &y);
  int RESULT_CODE = s21_mult_matrix(&x, &y, &result);

  ck_assert_int_eq(RESULT_CODE, INCORRECT_CALCULATION);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
}
END_TEST
START_TEST(TEST_MULT_MATRIX4) {
  matrix_t x;
  matrix_t y;
  matrix_t result_test;
  matrix_t result_mult;
  double values_x[6] = {1.2, 2.4, 3.6, 4.8, 6.0, 7.2};
  double values_y[6] = {3.5, 7.0, 10.5, 14.0, 17.5, 21.0};
  double values_result[9] = {92.4, 117.6, 205.8, 268.8};
  s21_create_matrix(2, 3, &x);
  s21_create_matrix(3, 2, &y);
  s21_create_matrix(2, 2, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_y, &y);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_mult_matrix(&x, &y, &result_mult);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_mult), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_mult);
}
END_TEST
START_TEST(TEST_MULT_MATRIX5) {
  matrix_t x;
  matrix_t y;
  matrix_t result_test;
  matrix_t result_mult;
  double values_x[9] = {1.2, 2.4, 3.6, 4.8, 6.0, 7.2, 8.4, 9.6, 10.8};
  double values_y[9] = {3.5, 7.0, 10.5, 14.0, 17.5, 21.0, 24.5, 28.0, 31.5};
  double values_result[9] = {126,   151.2, 176.4, 277.2, 340.2,
                             403.2, 428.4, 529.2, 630};
  s21_create_matrix(3, 3, &x);
  s21_create_matrix(3, 3, &y);
  s21_create_matrix(3, 3, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_y, &y);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_mult_matrix(&x, &y, &result_mult);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_mult), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_mult);
}
END_TEST
START_TEST(TEST_MULT_MATRIX6) {
  matrix_t x;
  matrix_t y;
  matrix_t result_test;
  matrix_t result_mult;
  double values_x[6] = {1.2, 2.4, 3.6, 4.8, 6.0, 7.2};
  double values_y[6] = {3.5, 7.0, 10.5, 14.0, 17.5, 21.0};
  double values_result[9] = {37.8,  50.4,  63,  79.8, 109.2,
                             138.6, 121.8, 168, 214.2};
  s21_create_matrix(3, 2, &x);
  s21_create_matrix(2, 3, &y);
  s21_create_matrix(3, 3, &result_test);
  s21_setMatrix(values_x, &x);
  s21_setMatrix(values_y, &y);
  s21_setMatrix(values_result, &result_test);
  int RESULT_CODE = s21_mult_matrix(&x, &y, &result_mult);

  ck_assert_int_eq(s21_eq_matrix(&result_test, &result_mult), SUCCESS);
  ck_assert_int_eq(RESULT_CODE, OK);

  s21_remove_matrix(&x);
  s21_remove_matrix(&y);
  s21_remove_matrix(&result_test);
  s21_remove_matrix(&result_mult);
}
END_TEST

Suite *st_arithmetic(void) {
  Suite *s = suite_create("st_arithmetic");
  TCase *tc = tcase_create("arithmetic_tc");

  tcase_add_test(tc, TEST_SUM1);
  tcase_add_test(tc, TEST_SUM2);
  tcase_add_test(tc, TEST_SUM3);
  tcase_add_test(tc, TEST_SUM4);
  tcase_add_test(tc, TEST_SUM5);
  tcase_add_test(tc, TEST_SUM6);
  tcase_add_test(tc, TEST_SUM7);

  tcase_add_test(tc, TEST_SUB1);
  tcase_add_test(tc, TEST_SUB2);
  tcase_add_test(tc, TEST_SUB3);
  tcase_add_test(tc, TEST_SUB4);
  tcase_add_test(tc, TEST_SUB5);
  tcase_add_test(tc, TEST_SUB6);
  tcase_add_test(tc, TEST_SUB7);

  tcase_add_test(tc, TEST_MULT_NUMBER1);
  tcase_add_test(tc, TEST_MULT_NUMBER2);
  tcase_add_test(tc, TEST_MULT_NUMBER3);
  tcase_add_test(tc, TEST_MULT_NUMBER4);

  tcase_add_test(tc, TEST_MULT_MATRIX1);
  tcase_add_test(tc, TEST_MULT_MATRIX2);
  tcase_add_test(tc, TEST_MULT_MATRIX3);
  tcase_add_test(tc, TEST_MULT_MATRIX4);
  tcase_add_test(tc, TEST_MULT_MATRIX5);
  tcase_add_test(tc, TEST_MULT_MATRIX6);

  suite_add_tcase(s, tc);
  return s;
}