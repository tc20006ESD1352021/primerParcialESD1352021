/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   encabezado.h
 * Author: Inmer Arana y Moisés Tejada
 */

#ifndef ENCABEZADO_H
#define ENCABEZADO_H

void leerCSV(char nombre_archivo[], int** M);

void transponerMatriz(int **transpuesta, int **matrix);

void multiplicarMatriz(int **matrix, int **transpuesta, int **arrayApoyo);

#endif /* ENCABEZADO_H */