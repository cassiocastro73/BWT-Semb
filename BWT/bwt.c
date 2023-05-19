/*! @brief
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
#include "file_manager.h"
int comparar_strings(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;

    return strcmp(str1, str2);
}

int compare(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

void sort_string_alphabetically(char *str) {
    // Copia a string original para uma nova variável
    char matriz_qsort[strlen(str)][strlen(str)];

    char sortedStr[strlen(str)];
    strcpy(sortedStr, str);

    // Ordena a nova string em ordem alfabética
    qsort(sortedStr, strlen(sortedStr), sizeof(char), compare);
    // File.write("\n","texto.txt");
    // File.write(sortedStr,"texto.txt");

    printf("%s\n", sortedStr);
}

// uint8_t bwt(char *input_text)
// {
//     int len = strlen(input_text);
//     char vetor_aux[len];
//     char matriz_bwt[len][len];
//     char matriz_sort[len][len];
//     strcpy(vetor_aux,input_text);
//     char pega_coluna[len];
   
//     for(int i = 0; i < len-1 ; i++)
//     {
//         char lastChar = vetor_aux[len - 1];
//         for (int j = len - 1; j > 0; j--) 
//         {
//             vetor_aux[j] = vetor_aux[j - 1];
//         }
//         vetor_aux[0] = lastChar;
//         strcpy(matriz_bwt[i],vetor_aux);
       
//     }
//     // Ordena as linhas da matriz
//     qsort(matriz_bwt, len+1, sizeof(char*), comparar_strings);
//     return 0;
// }


//  File.write(matriz_bwt[i],"texto.txt");
//         File.write("\n","texto.txt");
#define MAX_LENGTH 2000
uint8_t bwt(char *input_text) {
    int len = strlen(input_text);
    char matriz_bwt[MAX_LENGTH][MAX_LENGTH];
    char *ponteiros[MAX_LENGTH];
    char vetor_aux[MAX_LENGTH];
    strcpy(vetor_aux, input_text);

    for(int i = 0; i < len; i++) {
        char lastChar = vetor_aux[len - 1];
        for (int j = len - 1; j > 0; j--) {
            vetor_aux[j] = vetor_aux[j - 1];
        }
        vetor_aux[0] = lastChar;
        strncpy(matriz_bwt[i], vetor_aux, len);
        matriz_bwt[i][len] = '\0';
        ponteiros[i] = matriz_bwt[i];
        File.write("\n","texto.txt");
        File.write(ponteiros[i],"texto.txt");
    }

    // Ordena as linhas da matriz
    qsort(ponteiros, len, sizeof(char*), comparar_strings);
    File.write("\n","texto.txt");
    File.write("\n","texto.txt");
    char pega_ultima_coluna[len];
    for(int i = 0 ; i < len-1 ; i++)
    {
        pega_ultima_coluna[i] = ponteiros[i][len-1];
        printf("%s\n",ponteiros[i]);
       
    }
     File.write(pega_ultima_coluna,"texto.txt");
    
    return 0;
}