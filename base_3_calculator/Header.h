#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define TRIT_WIDTH 12

typedef enum MainMenuItems {
	addition = 1,
	subtraction,
	divison,
	multiplication,
	exitProgram,
}MainMenuItems;

typedef enum Trit {
	NEG = -1,
	ZERO = 0,
	POS = 1
} Trit;

typedef enum Trit_Addition {
	NEGATIVE_THREE = -3,
	NEGATIVE_TWO = -2,
	NEGATIVE_ONE = -1,
	NEUTERAL_ZERO = 0,
	POSITIVE_ONE = 1,
	POSITIVE_TWO = 2,
	POSITIVE_THREE = 3,
} Trit_Addition;

//prototypes
void inputOverflowRemover();
int getUserNumber();
void mainMenuDisplay();
void additionMenu();
void subtractionMenu();

//bitoperations prototypes
void base3Division(int number, int8_t* Ptr_numberToAddOne);
void TrinaryAddition(int8_t* Ptr_numberToAddOne, int8_t* Ptr_numberToAddTwo, int8_t* TwoNumbersAdded);
int base3ToDecimal(int8_t* Ptr_numberToAddOne);
void bitFlipper(int8_t* Ptr_numberToAddOne);

//https://en.wikipedia.org/wiki/Three-valued_logic