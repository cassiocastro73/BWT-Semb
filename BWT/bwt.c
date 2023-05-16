 /*
        Algoritmo de Burrows-Weeler

        Primeira parte: (compressão)
        1 - Começar a string por "$" 
        2 - pegar o ultimo caractere da string e coloca-lo na primeira posição (das esquerda pra direita/ posição 0 / reposicionamento por sentido horário)
        3 - repetir passo dois até o último caractere da string ser o "$" 
        4 - ordenar as linhas por ordem alfabética 

        Obs: a string formada pela última coluna da matriz é chamada de saída de Burrows-Weeler

        É ao final dessa fase que será feita a compressão por Run-length encoding
    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <file_manager.h>

int main(){

    File.read("texto.txt");
    int lenght = strlen(file_text);
    char *matriz_bwt[lenght][lenght];



    return 0;
}