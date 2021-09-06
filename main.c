#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    int **matrix, i, j;

    matrix = (int **) malloc(60 * sizeof (int*));
    for (i = 0; i < 60; i++) {
        matrix[i] = (int *) malloc(6 * sizeof (int));
    }

    leerCSV("peliculasFavoritasESD135_2021.csv", matrix);
    for (i = 0; i < 60; i++) {
        for (j = 0; j < 6; j++) {

            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    return (EXIT_SUCCESS);
}

void leerCSV(char nombre_archivo[], int** M) {

    FILE* archivo;
    char c[60];
    archivo = fopen(nombre_archivo, "r");
    int **matrix, i, contador = 0;

    matrix = (int **) malloc(60 * sizeof (int*));
    for (i = 0; i < 60; i++) {
        matrix[i] = (int *) malloc(6 * sizeof (int));
    }
    //8
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

void transponerMatriz(int **V) {

    int **arrayAyuda;
    int i, j, aux = 0;

    arrayAyuda = (int *) malloc(6 * sizeof (int));
    for (i = 0; i < 6; i++) {
        arrayAyuda[i] = (int *) malloc(60 * sizeof (int));

    }

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 60; j++) {
            arrayAyuda[i][j] = V[j][i];
        }
    }

    free(V);

    V = (int *) malloc(60 * sizeof (int));
    for (i = 0; i < 60; i++) {
        V[i] = (int *) malloc(6 * sizeof (int));
    }

    for (i = 0; i < 60; i++) {
        for (j = 0; j < 6; j++) {
            V[i][j] = arrayAyuda[i][j];
        }
    }
    free(arrayAyuda);
    return;

}