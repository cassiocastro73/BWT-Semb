#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
//#define DEBUG
#include <stdio.h>
#include <stdint.h>

#define MAX_FILE_SIZE    (1000)
#define FILE_READ_ERROR   (1)
#define FILE_READ_SUCESS  (0)
#define FILE_WRITE_SUCESS (0)
#define FILE_WRITE_ERROR  (1)


typedef uint8_t (*file_read_t)  (const char *);
typedef uint8_t (*file_write_t) (const char *,const char *);

typedef struct
{
    file_read_t read;
    file_write_t write;
}file_manager_t;

extern file_manager_t File;
extern char file_text[MAX_FILE_SIZE];


#endif /* FILE_MANAGER_H */