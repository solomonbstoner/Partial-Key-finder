#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>

#define SEEDPOOL_SIZE 4 //the number of hex digits in the seedpool

uint32_t convertStrToInt(char *argv){
	uint32_t seedPool = 0, toAdd = 0;
	char c = 0;
	for(size_t i = 0; i < SEEDPOOL_SIZE && (c = *(argv + i)) != '\0'; ++i){
		if(isdigit(c)){ //is digit
			toAdd = (c - '0');
		} else { //not a digit
			c = toupper(c);
			switch(c){
				case 'A':
					toAdd = 0xA;
					break;
				case 'B':
					toAdd = 0xB;
					break;
				case 'C':
					toAdd = 0xC;
					break;
				case 'D':
					toAdd = 0xD;
					break;
				case 'E':
					toAdd = 0xE;
					break;
				case 'F':
					toAdd = 0xF;
					break;
				default:
					toAdd = 0;
			}
		}
		seedPool += toAdd << ((SEEDPOOL_SIZE - 1 - i) * 4); //we start from the MSB to LSB, and shift the bits to its proper position

	}
	return seedPool;
}
