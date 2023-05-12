#include <stdio.h>

#define SUCESS 0

/*! @brief Essa função tem como objetivo fazer um print do que você por dentro
*   @param[in] Frase é a frase que irá ser imprimida no termial
*   @return não existem parametros de retorno
*/
void mostra_frase(char *frase)
{
    printf("%s", frase);
}

int main(int argc, char **argv)
{
    printf("Hello World!\n");
    return SUCESS;
}