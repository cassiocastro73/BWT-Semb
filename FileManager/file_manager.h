#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdio.h>
#include <stdint.h>

uint8_t mostra_alguma_coisa(char *valor);

typedef uint8_t (*file_read_t)(char *);
typedef uint8_t (*file_write_t)(char *,char *);

typedef struct
{
    file_read_t read;
    file_write_t write;
}file_manager_t;

extern file_manager_t File;



#endif /* FILE_MANAGER_H */