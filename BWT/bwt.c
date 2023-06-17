/*! Docxygen-based File writing pattern
* @file bwt.c
* @fn runLengthEncoding
* @fn copyStringToMatrixColumn
* @fn printStringMatrix
* @fn shiftStringMatrix
* @fn deleteMatrixColumn
* @fn matrixFormatting
* @fn preencherMatrizEmColunas
* @fn addElementToStringMatrix
* @brief Algoritmo de Burrows-Weeler
*
* First part: (compression)
* 1 - Start the string with "$"
* 2 - take the last character of the string and place it in the first position (from left to right / position 0 / repositioning clockwise)
* 3 - repeat step two until the last character of the string is "$"
* 4 - sort the lines in alphabetical order
* 5 - the string formed by the last column of the matrix is ​​called the Burrows-Weeler output
*
* It is at the end of this phase that compression will be performed using Run-length encoding.
*/



#include "bwt.h"
#define DEBUG

/**
 * @brief This function performs data decompression based on the RLE (Run Length Encoder) method.
 * @param[in] input the input string
*/
void runLengthDecoding(char* input) 
{
    int length = strlen(input);
    
    if (length == 0) 
    {
        printf("String vazia.\n");
        return;
    }
    
    char output[length + 1];
    int outputIndex = 0;
    
    for (int i = 0; i < length; i++)
    {
        char currentChar = input[i];
        
        if (currentChar >= '0' && currentChar <= '9') 
        {
            int count = currentChar - '0';
            while (input[i + 1] >= '0' && input[i + 1] <= '9') 
            {
                count = count * 10 + (input[i + 1] - '0');
                i++;
            }
            for (int j = 0; j < count; j++) 
                output[outputIndex++] = input[i + 1];
            
        } 
        else 
            output[outputIndex++] = currentChar;
    }
    
    output[outputIndex] = '\0';
}

/**
 * @brief This function performs data compression based on the RLE (Run Length Encoder) method.
 * @param[in] input the input string
*/
void runLengthEncoding(char* input) 
{
    int length = strlen(input);
    if (length == 0) 
    {
        printf("String vazia.\n");
        return;
    }

    char currentChar = input[0];
    int count = 1;
    char output[length * 2 + 1];  // Tamanho máximo do vetor de saída

    int outputIndex = 0;

    for (int i = 1; i <= length; i++) 
    {
        if (input[i] == currentChar) 
            count++;
        else 
        {
            if (count > 1) 
                outputIndex += sprintf(output + outputIndex, "%c%d", currentChar, count);
            else 
                output[outputIndex++] = currentChar;
            currentChar = input[i];
            count = 1;
        }
    }

    output[outputIndex] = '\0';
    #ifdef DEBUG
        File.write("\n","texto.txt");
        File.write("\n","texto.txt");
        File.write("Resultado do RL(Encoder):","texto.txt");
        File.write("\n","texto.txt");
        File.write(output,"texto.txt");
    #endif
    printf("Result: %s\n", output);
    runLengthDecoding(output);
}

/**
 * @brief Does the string comparison and returns depending on the comparison
 * @param[in] a String A
 * @param[in] b String B
 * @return 0 if are equal. -1 if A is 
*/
int compare_string(const void* a, const void* b)
{
    /*Gets the strings passed as a parameter, using casting for the string type*/
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
    #ifdef DEBUG
        printf("%s + %s \n",str1,str2);
    #endif
    /*Returns the string comparison function from the string.h library*/
    return strcmp(str1, str2);
}
 
/** TODO: TROCAR OS NOMES DAS VARIÁVEIS
 * @brief The bwt method is the main algorithm in the code.
 *        How it's done all the procedures listed in the header.
 * @param[in] input_text It's the string with the text file
 * @return Writes to the file and returns 0 if successful. Returns -1 on failure
*/
int8_t bwt(char *input_text) 
{
    int len = strlen(input_text);
    if(len <= 0)
        return -1;
    char matriz_bwt[len][len];
    char vetor_aux[len];
    
    strcpy(vetor_aux, input_text);

    File.write("\n","texto.txt");
    File.write("Permutação BWT:","texto.txt");
    File.write("\n","texto.txt");

    char *ponteiros[MAX_LENGTH];
    for(int i = 0; i < len; i++) 
    {
        char lastChar = vetor_aux[len - 1];
        for (int j = len - 1; j > 0; j--) 
        {
            vetor_aux[j] = vetor_aux[j - 1];
        }
        vetor_aux[0] = lastChar;
        strncpy(matriz_bwt[i], vetor_aux, len);
        matriz_bwt[i][len] = '\0';
        ponteiros[i] = matriz_bwt[i];
       
        if(i < len-1)
        {
            File.write(ponteiros[i],"texto.txt");
        }
        File.write("\n","texto.txt");
    }

    qsort(ponteiros, len, sizeof(char*), compare_string);

    #ifdef DEBUG  
        File.write("\n","texto.txt");
        File.write("\n","texto.txt");
        File.write("Organização da Matriz em ordem alfabetica:","texto.txt");
        File.write("\n","texto.txt");
        for(int i = 0 ; i < len ; i++)
        {
            File.write(ponteiros[i],"texto.txt");
            File.write("\n","texto.txt");
        }
    #endif
    char pega_ultima_coluna[len];
    char pega_primeira_coluna[len];
    for(int i = 0 ; i < len ; i++)
    {
       pega_ultima_coluna[i] = ponteiros[i][len-1]; 
    }
    for(int i = 0 ; i < len ; i++)
    {
       pega_primeira_coluna[i] = ponteiros[i][0];
    }

    #ifdef DEBUG
        File.write("\n","texto.txt");
        File.write("\n","texto.txt");
        File.write("Resultado BWT (Captura da ultima coluna apos a organização):","texto.txt");
        File.write("\n","texto.txt");
        File.write(pega_ultima_coluna,"texto.txt");
    #endif
    printf("Esse é o resultado do bwt:%s \n",pega_ultima_coluna);
    runLengthEncoding(pega_ultima_coluna);
    preencherMatrizEmColunas(ponteiros,pega_ultima_coluna,pega_primeira_coluna);
    
    return 0;
}

/**
 * @brief BWT Decompressor performs data decompression to return the original input
 * @param[in] matrix_sorted The sorted bwt matrix
 * @param[in] bwt_column The last column of the sorted matrix (BWT)
 * @param[in] bwt_first_column The first column of the sorted array
*/
void preencherMatrizEmColunas(char** matrix_sorted, char *bwt_column, char *bwt_first_column) {
    /*Initialization of rows and columns that will compose the matrix*/
    int numLines = 0;
    int numColumns = 0;
    /*At this moment we assign the value to the size of the rows and columns*/
    numColumns = strlen(matrix_sorted[0]);
    numLines =  numColumns;
    printf("\n");
    /*Based on bwt we copy the first and last matrix to the decompression matrix*/
    copyStringToMatrixColumn(matrix_sorted,bwt_column,0);
    copyStringToMatrixColumn(matrix_sorted,bwt_first_column,1);
    File.write("\n","texto.txt");
    /*We clear the array and leave only the two copied values*/
    for(int i = numColumns; i > 1; i--)
    {
        deleteMatrixColumn(matrix_sorted,i,numColumns);
    }
    matrixFormatting();
    
    #ifdef DEBUG
    /*We send the values ​​of the matrix to the text file (procedure only for debug)*/
        for (int i = 0; i < numColumns; i++) 
        {
            File.write("\n","texto.txt");
            File.write(matrix_sorted[i],"texto.txt");
        }
        matrixFormatting();
    #endif
    /** !@brief 
    *    Here the process of organization in alphabetical order of the passed columns is carried out.
    *    First, the array is sorted in alphabetical order. @p Line_253
    *    After that, the sorted elements are shifted to the right. @p Line_254
    *    With that, the bwt string is added again to do these previous
    *    processes again, until it is completely sorted  @p Line_255
    */
    for(int i = 0; i < numColumns ;i++ )
    {
        qsort(matrix_sorted,numColumns,sizeof(char*),compare_string);
        shiftMatrixRight(matrix_sorted,numColumns);
        copyStringToMatrixColumn(matrix_sorted,bwt_column,0);
        //printStringMatrix(matrix_sorted);
    }
    /*! @brief The last organization is made so that it is possible to have 
    the input string in the first line (with this the return is proved [Decompression])*/
    qsort(matrix_sorted,numColumns,sizeof(char*),compare_string);
    #ifdef DEBUG
    /*We send the values ​​of the matrix to the text file (procedure only for debug)*/
        File.write("\n","texto.txt");
        for (int i = 0; i < numColumns; i++) 
        {
            File.write("\n","texto.txt");
            File.write(matrix_sorted[i],"texto.txt");
        }
        matrixFormatting();
    #endif
    /*Display the reordered Matrix data in the terminal*/
    //printStringMatrix(matrix_sorted);
}

#include <stdio.h>
#include <string.h>

/**
 * @brief Copy a string to a matrix
 * @param[in] matrix The array where the string will be stored
 * @param[in] string String that will be copied to array
 * @param[in] column the column where the string will be inserted
*/
void copyStringToMatrixColumn(char **matrix, const char* string, int column) 
{
    int length = strlen(string);
    // int numRows = strlen(matrix[0]);
    //int copyLength = (length < numRows) ? length : numRows;
    for (int i = 0; i < length; i++) 
    {
        matrix[i][column] = string[i];
    }
}

/**
 * @brief 
 * @param[in] matrix The Matrix that will be displayed
*/
void printStringMatrix(char **matrix) 
{
    size_t rows = strlen(matrix[0]);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < rows; j++) 
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Shifts data in an matrix to the right
 * @param[in] matrix Matrix of data to be shifted
 * @param[in] size Number of elements inside the Matrix
*/
void shiftMatrixRight(char **matrix, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = size - 1; j > 0; j--) 
        {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][0] = ' '; 
    }
    
    for (int i = 0; i < size; i++) 
    {
        File.write("\n","texto.txt");
        File.write(matrix[i],"texto.txt");
    }
    matrixFormatting();
}

/**
 * @brief Delete a column from the matrix
 * @param[in] matrix The array that has the deleted column
 * @param[in] column The column that will have the data deleted
 * @param[in] size   The size of the column to be deleted
*/
void deleteMatrixColumn(char **matrix, int column, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = column; j < size - 1; j++) 
        {
            matrix[i][j] = matrix[i][j + 1];
        }
        matrix[i][size - 1] = ' '; 
    }
}

/**
 * @brief Skips a line and writes a line 
 *        in the text file to improve the
 *        separation of elements within the text
*/
void matrixFormatting(void)
{
    File.write("\n","texto.txt");
    File.write("-----------------------","texto.txt");
}

/**
 * @brief Sends a sentence to the text file,
 *        where it will be displayed isolated 
 *        from other elements in the text
 * @param[in] msg The message that will be written in the text
*/
void send_text_msg(const char * msg)
{
    File.write("\n","texto.txt");
    File.write("\n","texto.txt");
    File.write("Resultado BWT (Captura da ultima coluna apos a organização):","texto.txt");
    File.write("\n","texto.txt");
}