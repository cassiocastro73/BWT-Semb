#include <stdio.h>
#include <stdint.h>

#define SUCESS 0

void mostra_frase(char *frase);

uint8_t main(uint8_t argc, char **argv)
{
    if(argc > 1)
    {
        printf("%s \n", argv[1]);
    }
    else
    {
        printf("%d \n", argc);
    }
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