#include <stdio.h>
#include <stdint.h>
#include "FileManager/file_manager.h"
#define SUCESS 0

uint8_t main(uint8_t argc, char **argv)
{
    //mostra_alguma_coisa("Hello");
    File.read("texto.txt");
    return SUCESS;
}

/*! @brief Essa função tem como objetivo fazer um print do que você por dentro
*   @param[in] Frase é a frase que irá ser imprimida no termial
*   @return não existem parametros de retorno
*/
void mostra_frase(char *frase)
{
    printf("%s", frase);
}