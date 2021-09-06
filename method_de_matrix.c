#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "encabezado.h"

void leerCSV(char nombre_archivo[], int** M) {
    FILE* archivo;
    char c[60];
    archivo = fopen(nombre_archivo, "r");
    int **matrix, i, contador = 0;

    matrix = (int **) malloc(60 * sizeof (int*));
    for (i = 0; i < 60; i++) {
        matrix[i] = (int *) malloc(6 * sizeof (int));
    }

    i = 0;
    int aux, j = 0;
    char aux2;
    fscanf(archivo, " %[^\n]", c);

    do {
        fscanf(archivo, " %[^\n]", c);
        for (j = 8; j < 19; j += 2) {
            aux2 = c[j];
            aux = aux2 - 48;
            matrix[i][contador] = aux;
            contador++;
        }
        i++;
        contador = 0;
    } while (i < 60);
    i = 0;

    do {
        for (j = 0; j < 6; j++) {
            M[i][j] = matrix[i][j];
        }
        i++;
    } while (i < 60);
    free(matrix);
}

void transponerMatriz(int **transpuesta, int **matrix) {

    int i, j;

    for (i = 0; i < 60; i++) {
        for (j = 0; j < 6; j++) {

            transpuesta[j][i] = matrix[i][j];
        }

    }
}

void multiplicarMatriz(int **matrix, int **transpuesta, int **arrayApoyo) {
    int i, j, conta1, conta2;


    for (i = 0; i < 60; i++) {
        conta1++;
        for (j = 0; j < 60; j++) {
            conta2++;

            arrayApoyo[i][j] = (matrix[i][0] * transpuesta[0][j] +
                    matrix[i][1] * transpuesta[1][j] +
                    matrix[i][2] * transpuesta[2][j] +
                    matrix[i][3] * transpuesta[3][j] +
                    matrix[i][4] * transpuesta[4][j] +
                    matrix[i][5] * transpuesta[5][j]);
        }
    }
}

const char* integrantes(){
    return "AA20047, TC20006";
}