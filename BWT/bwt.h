#ifndef BWT_H
#define BWT_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "file_manager.h"
#define MAX_LENGTH 2000

typedef int8_t (*fn_callback_bwt_compress)(char *);
typedef int8_t (*fn_callback_bwt_descompress)(char** , char *, char *);

typedef struct 
{
    fn_callback_bwt_compress compress;
    fn_callback_bwt_descompress descompress;
}bwt_t;

int8_t bwt(char *input_text);
///////////////////////////////////////////////////////////////////////////////
void copyStringToMatrixColumn(char **matrix, const char* string, int column);
void printStringMatrix(char **matrix);
void shiftStringMatrix(char **matrix,int size, char *newElement);
void shiftMatrixRight(char **matrix, int size) ;
void deleteMatrixColumn(char **matrix, int column, int size);
///////////////////////////////////////////////////////////////////////////////
void matrixFormatting(void);
void preencherMatrizEmColunas(char** matrix_sorted, char *bwt_column, char *bwt_first_column);
void addElementToStringMatrix(char **matrix,  char* newElement);
///////////////////////////////////////////////////////////////////////////////

#endif /* BWT_H */