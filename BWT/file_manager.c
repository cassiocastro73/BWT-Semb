#include "file_manager.h"
#include "string.h"

char file_text[MAX_FILE_SIZE];

/** @brief Reads a file and returns its contents 
 *  @param[in] file_name The name of the file to be read
 *  @return @p Success if the reading was successful, otherwise, it returns @p ERROR
*/
uint8_t read_file(char *file_name)
{
    size_t file_size = 0;
   
    FILE *arch;
    arch = fopen("texto.txt","rb");
    if(arch == NULL )
    {
#ifdef DEBUG
    printf("Arquivo não encontrado/corrompido\n");
#endif
        return FILE_READ_ERROR;
    }
#ifdef DEBUG
    printf("Executando procedimento de captura de tamanho de arquivo...\n " );
#endif
    fseek(arch,0,SEEK_END);
    file_size = ftell(arch);
    fclose(arch);
#ifdef DEBUG
        printf("o arquivo tem [%ld] caracteres \n", file_size);
#endif
    arch = fopen("texto.txt","rb");
   
    fread(file_text,sizeof(char),file_size,arch);
#ifdef DEBUG
    char verify;
    for(int i = 0; i < file_size; i++)
    {
        verify = file_text[i];
        printf("%c", verify);
    }
#endif
    fclose(arch);
    return FILE_READ_SUCESS;
}

/** @brief Write input data to a txt file
 *  @param[in] input_text data string to be written to txt file
 *  @param[in] file_name file to store the data
 *  @return WRITE_SUCESS if writing was successful, otherwise WRITE_ERROR
*/
uint8_t write_file( char* input_text, char * file_name)
{
    size_t string_size = strlen(input_text);
    FILE *file;
    file = fopen(file_name,"a");

    if(file == NULL)
    {
        return FILE_WRITE_ERROR;
    }

    fwrite(input_text,sizeof(char),string_size,file);
    fclose(file);
    #ifdef DEBUG
        read_file(file_name);
    #endif
    return FILE_WRITE_SUCESS;
}


file_manager_t File =
{
    .read = read_file,
    .write = write_file
};