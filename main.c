#include <stdio.h>
#include <stdint.h>
#include "FileManager/file_manager.h"
#define SUCESS 0

uint8_t main(uint8_t argc, char **argv)
{
    uint8_t read_ret = File.read("texto.txt");
    printf("%s \n",file_text);
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