/*
 * File:   newcunittest.c
 * Author: Inmer Arana y Moisés Tejada
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../encabezado.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testLeerCSV() {
    char* nombre_archivo = "peliculasFavoritasESD135_2021.csv";
    int **matrix;
    int i;
    matrix = (int **) malloc(60 * sizeof (int*));
    for (i = 0; i < 60; i++) {
        matrix[i] = (int *) malloc(6 * sizeof (int));
    }
    leerCSV(nombre_archivo, matrix);
    CU_ASSERT_EQUAL(matrix[0][0], 0);
    CU_ASSERT_EQUAL(matrix[0][1], 1);
    CU_ASSERT_EQUAL(matrix[0][2], 0);
    CU_ASSERT_EQUAL(matrix[0][3], 1);
    CU_ASSERT_EQUAL(matrix[0][4], 1);
    CU_ASSERT_EQUAL(matrix[0][5], 0);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testLeerCSV", testLeerCSV))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
