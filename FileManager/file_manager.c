#include "file_manager.h"

#define FILE_READ_ERROR  (1)
#define FILE_READ_SUCESS (0)
#define valor "olamundo1aaaaaaaaaaaaaabbbbbeeee1"


/** @brief Reads a file and returns its contents 
 *  @param[in] file_name The name of the file to be read
 *  @return @p Success if the reading was successful, otherwise, it returns @p ERROR
*/
uint8_t read_file(char *file_name)
{
    size_t file_size = 0;
    
    FILE *arq;
    arq = fopen("texto.txt","rb");


    if(arq == NULL )
    {
        printf("Arquivo nao existe");
    }

    /* Verifica o tamanho do arquivo */
    fseek(arq,0,SEEK_END);
    file_size = ftell(arq);
    fclose(arq);
    printf(" o tamanho do arquivo é : %ld \n",file_size);
    /* Cria o leitor do arquivo baseado no valor adquirido*/
    arq = fopen("texto.txt","rb");
    char file_text[file_size];
    fread(file_text,sizeof(char),file_size,arq);
    printf("%s", file_text);
    fclose(arq);

    return 0;
}

file_manager_t File =
{
    .read = read_file,
};