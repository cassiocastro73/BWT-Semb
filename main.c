#include <stdio.h>
#include <stdint.h>
//#include "file_manager.h"
#include "BWT/bwt.h"
#include "BWT/file_manager.h"
#define SUCESS 0

uint8_t main(uint8_t argc, char **argv)
{
    File.read("texto.txt");
    bwt(file_text);
    return SUCESS;
}



