#include <stdio.h>
#include <stdint.h>
#define MAX_BIT_VALUE 65536 //seedPool has a maximum of 16bits.


static uint8_t findY3(uint8_t x3, uint8_t x0){
	return x3 & x0; //obtaining y3
}


static uint8_t findY2(uint32_t seedPool){
	uint32_t y2 = 0;
	for(uint32_t i = 1; i < MAX_BIT_VALUE; i*=2){ //going through seedPool bit by bit
		uint8_t toAdd = !(seedPool & i); //add 1 for every 0 in seedPool
		if(toAdd){
			y2 += toAdd;
		}
	}
	return y2;
}

static uint8_t findY1(uint8_t x1){
	//Linear Feedback Shift Register function. (To-do)
	for(int i = 0; i < 4; ++i){
		uint8_t x1_0 = x1 & 0x1;
		uint8_t x1_3 = (x1 & 0x8) >> 3;
		uint8_t untouchedPart = (x1 & 0xE) >> 1; //shift bits 1 through 3 right to positions 0 through 2.
		x1 = ((x1_0 ^ x1_3) << 3) + untouchedPart; //the new x1_3 is the original x1_3 xor x1_0

	}
	return x1;
}

static uint8_t findY0(uint8_t x0, uint8_t x1, uint8_t x2, uint8_t x3){
	return (x0 + x1 + x2 + x3) * 17 % 16; //To-Do
}

uint32_t solvePartialKey(uint32_t seedPool){
	uint8_t findY3(uint8_t, uint8_t);
	uint8_t findY2(uint32_t);
	uint8_t findY1(uint8_t);
	uint8_t findY0(uint8_t, uint8_t, uint8_t, uint8_t);


	uint8_t x0 = seedPool & 0xF; //1st nibble of the seedpool
	uint8_t x1 = (seedPool & 0xF0) >> 4; //2nd nibble of the seedpool
	uint8_t x2 = (seedPool & 0xF00) >> 8; //3rd nibble of the seedpool
	uint8_t x3 = (seedPool & 0xF000) >> 12; //4th nibble of the seedpool

	//solve for y0-3 by calling the functions above.
	uint8_t y0 = findY0(x0, x1, x2, x3);
	uint8_t y1 = findY1(x1);
	uint8_t y2 = findY2(seedPool);
	uint8_t y3 = findY3(x0, x3);

	uint32_t partial_key = y0 + (y1 << 4) + (y2 << 8) + (y3 << 12);
	return partial_key;
}
