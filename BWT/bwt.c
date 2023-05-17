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


uint8_t bwt(char *input_text)
{
    // Crio o marcador de inicio da string
    char init_markup[1] = "$";
    // Verificando o tamanho do texto
    size_t input_size = strlen(input_text)+1; 
   
    // crio o auxiliar que ira armazenar o marcador+stringoriginal
    char input_aux[input_size+1]; 
    /* Essa parte copia os dados da entrada para uma variavel auxiliar*/
    stpcpy(input_aux,init_markup);
    strcat(input_aux,input_text);
    /* Criando a matriz que irá manipular o auxiliar com seus valores*/
    // criando uam matriz de strings baseado no tamanho do texto
    char matriz_bwt[input_size][input_size]; 
    char vetor_aux[input_size];
    stpcpy(matriz_bwt[0],input_aux);
    printf("%s \n",matriz_bwt[0]);
  
   
    for(int i = 1 ; i < input_size; i ++)
    {
        vetor_aux[i-1] =  matriz_bwt[0][input_size-i];
    }
    // Procedimento que pega o vetor inverso e joga cada posição em matriz[1] em diante
    int count = 0;
    int indice_proxima = 1;
    int string_atual = input_size;
    for(int i = 1; i < input_size; i ++)
    {
        matriz_bwt[i][count] = vetor_aux[count]; // [1][0]
        int k = 0;
        for(int j = indice_proxima ; j < input_size; j++ )
        {
            matriz_bwt[i][j] = matriz_bwt[0][k];
            k++;
        }
        count++;
        indice_proxima++;
        strcpy(matriz_bwt[i+1],matriz_bwt[i]);
    }
    // for(int i = 0; i < input_size ; i++)
    // {
    //     for(int j = 0; j < input_size ; j++)
    //     {
    //           printf("%c ", matriz_bwt[i][j] );
    //     }
    //    printf("\n");
    //     // File.write(matriz_bwt[i],"texto.txt");
    // }
    //printf("%s \n", matriz_bwt[36]);
    // for(int j = 0; j < input_size ; j++)
    // {
    //       printf("%c ", matriz_bwt[36][j] );
    // }
   
    return 0;
}



/*
char init_markup[1] = "$";
    size_t input_size = strlen(input_text) + 1;
    printf("%ld \n", input_size);
    char input_aux[input_size + 1];
    stpcpy(input_aux, init_markup);
    strcat(input_aux, input_text);

    char** matriz_bwt = (char**)malloc(input_size * sizeof(char*));
    for (int i = 0; i < input_size; i++) {
        matriz_bwt[i] = (char*)malloc(input_size * sizeof(char));
    }

    stpcpy(matriz_bwt[0], input_aux);

    char vetor_aux[input_size];
    for (int i = 1; i < input_size; i++) {
        vetor_aux[i - 1] = matriz_bwt[0][input_size - i];
    }

    int count = 0;
    int indice_proxima = 1;
    int string_atual = input_size;

    for (int i = 1; i < input_size - 1; i++) {
        matriz_bwt[i][count] = vetor_aux[count];
        int k = 0;
        for (int j = indice_proxima; j < input_size; j++) {
            matriz_bwt[i][j] = matriz_bwt[0][k];
            k++;
        }
        count++;
        indice_proxima++;
    }

    for (int i = 0; i < input_size; i++) {
        for (int j = 0; j < input_size; j++) {
            printf("%c ", matriz_bwt[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < input_size; i++) {
        free(matriz_bwt[i]);
    }
    free(matriz_bwt);

    return 0;
}
*/
