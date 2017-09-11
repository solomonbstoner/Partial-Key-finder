#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "Derive_The_Key.h"

uint32_t convertStrToInt(char *);
uint32_t solvePartialKey(uint32_t);

int main(int argc, char *argv[]){ //shift to main.c

        if (!(strcmp("--help", argv[1]))) {
          printf("Partial-Key-finder.\n\
          Usage:\n\
          \t./partialKey <16-bit hex seed pool>\n\n\
          Example:\n\
          \t./partialKey 0xFEDA\n\n\
          Description:\n\
          \tThis program outputs a 16-bit partial key decrypted from the 16-bit seedpool given as input. \
          Both output and input are base-16.\n");
          return 0;
        }

        char *seedPoolChar = argv[1]; //the seedpool is the 2nd argument (1st is the program itself)
        uint32_t seedPool;
        sscanf(seedPoolChar,"%x",&seedPool);
        uint32_t partialKey = solvePartialKey(seedPool);
        printf("The partial key is : 0x%04X\n", partialKey);

        return 0;
}
