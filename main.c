#include <stdio.h>
#include <stdint.h>
#include "BWT/bwt.h"
#include "BWT/file_manager.h"
//#define RLE_ISOLADO
#define BWT_RUN
#define SUCESS (0)

#ifdef RLE_ISOLADO
void runLengthEncodingIsolado(char* input) 
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
    File.write("\n","texto.txt");
    File.write("\n","texto.txt");
    File.write(output,"texto.txt");

    printf("Result: %s\n", output);
}

uint8_t main(uint8_t argc, char **argv)
{
    File.read("texto.txt");
    runLengthEncodingIsolado("$Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris a felis ut lorem porttitor tristique a ac nulla. Aliquam gravida auctor ipsum, vitae gravida odio congue ut. Curabitur sed scelerisque eros. Fusce dictum quam nec purus faucibus, a consequat dolor vestibulum. Maecenas nec felis eget diam mattis dignissim a a mauris. Etiam gravida tristique augue, id consectetur tortor mollis eu. Sed fringilla ipsum nec est gravida, vitae interdum neque bibendum.Donec nec ex quis justo varius lobortis id non mi. Phasellus at dolor arcu. Sed tempus justo at turpis finibus, in tristique erat tincidunt. Vivamus egestas magna a tellus aliquam vestibulum. Nulla non aliquet massa. Fusce a turpis vestibulum, gravida sapien id, semper urna. Etiam et nisi tortor. Curabitur et velit at metus luctus efficitur. Pellentesque at pharetra leo, at faucibus nunc. Donec fringilla felis nec vestibulum vestibulum. Quisque feugiat erat at dapibus consectetur. Nam interdum erat eu ligula fermentum, a posuere leo pharetra. Maecenas interdum justo et ipsum tincidunt varius. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; In pharetra justo sit amet nisi cursus, a semper nunc aliquam. Fusce tincidunt rutrum odio, a feugiat nulla. Duis vulputate metus vitae magna dignissim, sed facilisis orci lobortis. Nunc feugiat magna nec mi laoreet, et scelerisque lacus finibus. Curabitur sagittis felis ut arcu laoreet, eu fermentum orci eleifend. Sed dignissim gravida mi id facilisis. Aenean sed bibendum neque. Suspendisse fringilla ipsum non gravida pharetra. Suspendisse nec metus enim. Vestibulum vel faucibus metus, eget eleifend nisi. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas  Integer fermentum fringilla dui at elementum. Nulla non interdum urna. Aliquam aliquam felis nec nunc ultricies, eget lobortis mi tempus. Integer eu libero vel arcu aliquet elementum. Nunc varius viverra urna, vel aliquet ligula condimentum ac");
    return SUCESS;
}

#endif

#ifdef BWT_RUN

uint8_t main(int argc, char **argv)
{
    File.read("texto.txt");
    bwt(file_text);
    return SUCESS;
}



#endif


