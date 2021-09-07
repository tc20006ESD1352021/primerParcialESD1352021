/*
 * File:   newcunittest2.c
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

void testTransponerMatriz() {
    int** transpuesta;
    int** matrix;
    int i;
    char* nombre_archivo = "peliculasFavoritasESD135_2021.csv";
    matrix = (int **) malloc(60 * sizeof (int*));
    for (i = 0; i < 60; i++) {
        matrix[i] = (int *) malloc(6 * sizeof (int));
    }
    transpuesta = (int **) malloc(6 * sizeof (int*));
    for (i = 0; i < 6; i++) {
        transpuesta[i] = (int *) malloc(60 * sizeof (int));
    }
    leerCSV(nombre_archivo, matrix);
    transponerMatriz(transpuesta, matrix);
    CU_ASSERT_EQUAL(transpuesta[0][0], 0);
    CU_ASSERT_EQUAL(transpuesta[1][0], 1);
    CU_ASSERT_EQUAL(transpuesta[2][0], 0);
    CU_ASSERT_EQUAL(transpuesta[3][0], 1);
    CU_ASSERT_EQUAL(transpuesta[4][0], 1);
    CU_ASSERT_EQUAL(transpuesta[5][0], 0);
    
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest1", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testTransponerMatriz", testTransponerMatriz))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
