#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "Derive_The_Key.h"

uint32_t convertStrToInt(char *);
uint32_t solvePartialKey(uint32_t);

int main(int argc, char *argv[]){ //shift to main.c

        if (!(strcmp("--help", argv[1]))) {
          printf("Help Documentation\n");
          return 0;
        }

        char *seedPoolChar = argv[1]; //the seedpool is the 2nd argument (1st is the program itself)
        uint32_t seedPool;
        sscanf(seedPoolChar,"%x",&seedPool);
        uint32_t partialKey = solvePartialKey(seedPool);
        printf("The partial key is : 0x%04X\n", partialKey);

        return 0;
}
