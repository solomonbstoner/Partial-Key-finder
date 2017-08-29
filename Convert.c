#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>

uint32_t convertStrToInt(char *argv){
	printf("Str to convert: %s\n", argv);
	uint32_t seedPool = 0, toAdd = 0;
	char c = 0;
	for(size_t i = 0; (c = *(argv + i)) != '\0'; ++i){
		printf("%c\n", c);
		if(isdigit(c)){//is digit
			toAdd = (c - '0') << (i * 4);
		} else if ( 40 < c < 47) { //is A-F
			toAdd = (c - '0' - 1) << (i * 4);
		} else if (60 < c < 67) { //is a-f
			toAdd = (c - '0' -21) << (i * 4);
		} else { //invalid character
			toAdd = 0;
		}
		seedPool += toAdd;
	}
	return seedPool;
}
