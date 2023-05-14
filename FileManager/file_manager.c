#include "file_manager.h"

#define FILE_READ_ERROR  (1)
#define FILE_READ_SUCESS (0)


/** @brief Reads a file and returns its contents 
 *  @param[in] file_name The name of the file to be read
 *  @return @p Success if the reading was successful, otherwise, it returns @p ERROR
*/
uint8_t read_file(char *file_name)
{
    FILE *arq;
    arq = fopen("texto.txt","a");
    return arq == NULL ? FILE_READ_ERROR : FILE_READ_SUCESS;
}

file_manager_t File =
{
    .read = read_file,
};