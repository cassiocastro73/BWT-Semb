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


int runLengthEncoding(char* input) 
{
    int length = strlen(input);
    if (length == 0) 
    {
        printf("String vazia.\n");
        return -1;
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
    return 0;
    //runLengthDecoding(output);
}

int compare_string(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;

    return strcmp(str1, str2);
}
 
/**
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
   
    for(int i = 0; i < len; i++) {
        char lastChar = vetor_aux[len - 1];
        for (int j = len - 1; j > 0; j--) {
            vetor_aux[j] = vetor_aux[j - 1];
        }
        vetor_aux[0] = lastChar;
        strncpy(matriz_bwt[i], vetor_aux, len);
        matriz_bwt[i][len] = '\0';
        ponteiros[i] = matriz_bwt[i];
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
    for(int i = 0 ; i < len ; i++)
    {
       pega_ultima_coluna[i] = ponteiros[i][len-1]; 
    }

    #ifdef DEBUG
        File.write("\n","texto.txt");
        File.write("\n","texto.txt");
        File.write("Resultado BWT (Captura da ultima coluna apos a organização):","texto.txt");
        File.write("\n","texto.txt");
        File.write(pega_ultima_coluna,"texto.txt");
    #endif

    runLengthEncoding(pega_ultima_coluna);
    return 0;
}