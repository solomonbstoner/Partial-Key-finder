#include <stdio.h>
#include <stdint.h>
#define MAX_BIT_VALUE 65536 //seedPool has a maximum of 16bits.

int main(int argc, char *argv[]){
	uint32_t convert(char*);
	uint32_t solvePartialKey(uint32_t);

	char *seedPoolChar = argv[1]; //the seedpool is the 2nd argument (1st is the program itself)
	uint32_t seedPool = convert(seedPoolChar); //convert string into values

	uint32_t partialKey = solvePartialKey(seedPool);



}


static uint32_t findY3(uint32_t x3, uint32_t x0){
	return x3 & x0; //obtaining y3
}


static uint32_t findY2(uint32_t seedPool){
	uint32_t y2 = 0;
	for(size_t i = 0; i < MAX_BIT_VALUE; i*=2){ //going through seedPool bit by bit
		y2 += !(seedPool & i); //add 1 for every 0 in seedPool
	}
}

static uint32_t findY1(uint32_t x1){
	//Linear Feedback Shift Register function. (To-do)
}

static uint32_t findY0(uint32_t x0, uint32_t x1, uint32_t x2, uint32_t x3){
	return (x0 + x1 + x2 + x3) * 17 % 16;
}

uint32_t solvePartialKey(uint32_t seedPool){
	static uint32_t findY3(uint32_t, uint32_t);
	static uint32_t findY2(uint32_t);
	static uint32_t findY1(uint32_t);
	static uint32_t findY0(uint32_t, uint32_t, uint32_t, uint32_t);


	uint32_t x0 = seedPool & 0xF;
	uint32_t x1 = seedPool & 0xF0;
	uint32_t x2 = seedPool & 0xF00;
	uint32_t x3 = seedPool & 0xF000;

	//solve for y0-3 by calling the functions above.
}

uint32_t convert(char* string){
	return 1; //define this function
}
