#ifndef BWT_H
#define BWT_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "file_manager.h"

#define MAX_LENGTH 2000
uint8_t bwt(char *input_text);


#endif /* BWT_H */