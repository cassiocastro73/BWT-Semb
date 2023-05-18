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

uint8_t bwt(char *input_text)
{
    int len = strlen(input_text);
    char vetor_aux[len];
    char matriz_bwt[len][len];
    strcpy(vetor_aux,input_text);
   
    for(int i = 0; i < len-1 ; i++)
    {
        char lastChar = vetor_aux[len - 1];
        for (int j = len - 1; j > 0; j--) 
        {
            vetor_aux[j] = vetor_aux[j - 1];
        }
        vetor_aux[0] = lastChar;
        strcpy(matriz_bwt[i],vetor_aux);
        File.write("\n","texto.txt");
        File.write(vetor_aux,"texto.txt");

        for(int k = 0 ; k < 10 ; k++)
        {
            for(int l = 0; l < len-1 ; l++)
            {
                printf("%c", matriz_bwt[k][l]);
            }
        }

       
    }
    
    // char matriz_transformada[len];
    // for(int i = 0 ; i < len ; i++)
    // {
    //     matriz_transformada[i] = matriz_bwt[i][len-1];
    // }


// void move_last_character_to_front(char *str) {
//     int len = strlen(str);
//     if (len > 0) {
//         char lastChar = str[len - 1];
//         for (int i = len - 1; i > 0; i--) {
//             str[i] = str[i - 1];
//         }
//         str[0] = lastChar;
//     }
// }
     return 0;
}
