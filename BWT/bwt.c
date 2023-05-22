/*! @brief 
* @file bwt.c
* @fn runLengthEncoding
* @fn 
* Algoritmo de Burrows-Weeler
*
* Primeira parte: (compressão)
* 1 - Começar a string por "$" 
* 2 - pegar o ultimo caractere da string e coloca-lo na primeira posição (das esquerda pra direita/ posição 0 / reposicionamento por sentido horário)
* 3 - repetir passo dois até o último caractere da string ser o "$" 
* 4 - ordenar as linhas por ordem alfabética 
*
* Obs: a string formada pela última coluna da matriz é chamada de saída de Burrows-Weeler
*
* É ao final dessa fase que será feita a compressão por Run-length encoding
*/

#include "bwt.h"
char RLE_ENCODER[200];
#define DEBUG
///////////////////////////////////////////////////////////////////////////////
void copyStringToMatrixColumn(char **matrix, const char* string, int column);
void printStringMatrix(char **matrix);
void shiftStringMatrix(char **matrix,int size, char *newElement);
void shiftMatrixRight(char **matrix, int size) ;
void deleteMatrixColumn(char **matrix, int column, int size);
///////////////////////////////////////////////////////////////////////////////

void preencherMatrizEmColunas(char** matriz, char *bwt_final, char *bwt_first_column);
void addElementToStringMatrix(char **matrix,  char* newElement);

void runLengthDecoding(char* input) {
    int length = strlen(input);
    
    if (length == 0) {
        printf("String vazia.\n");
        return;
    }
    
    char output[length + 1];  // Tamanho máximo do vetor de saída
    int outputIndex = 0;
    
    for (int i = 0; i < length; i++) {
        char currentChar = input[i];
        
        if (currentChar >= '0' && currentChar <= '9') 
        {
            int count = currentChar - '0';
            while (input[i + 1] >= '0' && input[i + 1] <= '9') 
            {
                count = count * 10 + (input[i + 1] - '0');
                i++;
            }
            for (int j = 0; j < count; j++) 
                output[outputIndex++] = input[i + 1];
            
        } 
        else 
            output[outputIndex++] = currentChar;
    }
    
    output[outputIndex] = '\0';
    #ifdef DEBUG
        File.write("\n","texto.txt");
        File.write("\n","texto.txt");
        File.write("Resultado do RL(Decoder):","texto.txt");
        File.write("\n","texto.txt");
        File.write(output,"texto.txt");
    #endif
    printf("Decoded Result: %s\n", output);
}


void runLengthEncoding(char* input) 
{
    int length = strlen(input);
    if (length == 0) 
    {
        printf("String vazia.\n");
        return;
    }

    char currentChar = input[0];
    int count = 1;
    char output[length * 2 + 1];  // Tamanho máximo do vetor de saída

    int outputIndex = 0;

    for (int i = 1; i <= length; i++) 
    {
        if (input[i] == currentChar) 
            count++;
        else 
        {
            if (count > 1) 
                outputIndex += sprintf(output + outputIndex, "%c%d", currentChar, count);
            else 
                output[outputIndex++] = currentChar;
            currentChar = input[i];
            count = 1;
        }
    }

    output[outputIndex] = '\0';
    #ifdef DEBUG
        File.write("\n","texto.txt");
        File.write("\n","texto.txt");
        File.write("Resultado do RL(Encoder):","texto.txt");
        File.write("\n","texto.txt");
        File.write(output,"texto.txt");
    #endif
    printf("Result: %s\n", output);
    runLengthDecoding(output);
}

int compare_string(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
   // printf("%s + %s \n",str1,str2);
    return strcmp(str1, str2);
}
 
/** TODO: TROCAR OS NOMES DAS VARIÁVEIS
 * @brief Building...
 * @param[in] input_text Building...
 * @return Building...
*/
uint8_t bwt(char *input_text) {
    int len = strlen(input_text);
    char matriz_bwt[MAX_LENGTH][MAX_LENGTH];
    char *ponteiros[MAX_LENGTH];
    char vetor_aux[MAX_LENGTH];
    strcpy(vetor_aux, input_text);
    File.write("\n","texto.txt");
    File.write("Permutação BWT:","texto.txt");
    File.write("\n","texto.txt");
    for(int i = 0; i < len; i++) {
        char lastChar = vetor_aux[len - 1];
        for (int j = len - 1; j > 0; j--) {
            vetor_aux[j] = vetor_aux[j - 1];
        }
        vetor_aux[0] = lastChar;
        strncpy(matriz_bwt[i], vetor_aux, len);
        matriz_bwt[i][len] = '\0';
        ponteiros[i] = matriz_bwt[i];
       
        if(i < len-1)
        {
            File.write(ponteiros[i],"texto.txt");
        }
        File.write("\n","texto.txt");
    }

    qsort(ponteiros, len, sizeof(char*), compare_string);

    #ifdef DEBUG  
        File.write("\n","texto.txt");
        File.write("\n","texto.txt");
        File.write("Organização da Matriz em ordem alfabetica:","texto.txt");
        File.write("\n","texto.txt");
        for(int i = 0 ; i < len ; i++)
        {
            File.write(ponteiros[i],"texto.txt");
            File.write("\n","texto.txt");
        }
    #endif
    char pega_ultima_coluna[len];
    char pega_primeira_coluna[len];
    for(int i = 0 ; i < len ; i++)
    {
       pega_ultima_coluna[i] = ponteiros[i][len-1]; 
    }
    for(int i = 0 ; i < len ; i++)
    {
       pega_primeira_coluna[i] = ponteiros[i][0];
    }

    #ifdef DEBUG
        File.write("\n","texto.txt");
        File.write("\n","texto.txt");
        File.write("Resultado BWT (Captura da ultima coluna apos a organização):","texto.txt");
        File.write("\n","texto.txt");
        File.write(pega_ultima_coluna,"texto.txt");
    #endif

    runLengthEncoding(pega_ultima_coluna);
    preencherMatrizEmColunas(ponteiros,pega_ultima_coluna,pega_primeira_coluna);
    
    return 0;
}




void preencherMatrizEmColunas(char** matriz, char *bwt_final, char *bwt_first_column) {
    int numLinhas = 0;
    int numColunas = 0;
    int contador_adicao = 0;
    // Calcular o número de linhas e colunas usando strlen na primeira linha
    numColunas = strlen(matriz[0]);
    numLinhas =  numColunas;
    printf("\n");
    copyStringToMatrixColumn(matriz,bwt_final,0);
    copyStringToMatrixColumn(matriz,bwt_first_column,1);
    
    for(int i = numColunas; i > 1; i--)
    {
        deleteMatrixColumn(matriz,i,numColunas);
    }
    
    for(int i = 0; i < numColunas ;i++ )
    {
        qsort(matriz,numColunas,sizeof(char*),compare_string);
        shiftMatrixRight(matriz,numColunas);
        copyStringToMatrixColumn(matriz,bwt_final,0);
        printStringMatrix(matriz);
    }
    qsort(matriz,numColunas,sizeof(char*),compare_string);
   
    printStringMatrix(matriz);

}



#include <stdio.h>
#include <string.h>


void copyStringToMatrixColumn(char **matrix, const char* string, int column) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        matrix[i][column] = string[i];
    }
}

void printStringMatrix(char **matrix) {
    size_t rows = strlen(matrix[0]);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void shiftMatrixRight(char **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > 0; j--) {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][0] = ' ';  // Preenche a primeira coluna com um espaço em branco
    }
}

void deleteMatrixColumn(char **matrix, int column, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = column; j < size - 1; j++) {
            matrix[i][j] = matrix[i][j + 1];
        }
        matrix[i][size - 1] = ' ';  // Preenche a última coluna com um espaço em branco
    }
}