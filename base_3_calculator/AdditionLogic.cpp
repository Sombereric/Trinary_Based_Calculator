#include "Header.h"

void additionMenu() {
	double userChoice1 = 0;
	double userChoice2 = 0;
	
	int8_t numberToAddOne[TRIT_WIDTH] = {};
	int8_t numberToAddTwo[TRIT_WIDTH] = {};
	int8_t TwoNumbersAdded[TRIT_WIDTH] = {};

	int8_t* Ptr_numberToAddOne = numberToAddOne;
	int8_t* Ptr_numberToAddTwo = numberToAddTwo;
	int8_t* Ptr_TwoNumbersAdded = TwoNumbersAdded;

	system("cls");

	printf("\nEnter First number: ");
	userChoice1 = getUserNumber();


	printf("\nEnter second number: ");
	userChoice2 = getUserNumber();

	base3Division(userChoice1, Ptr_numberToAddOne);
	base3Division(userChoice2, Ptr_numberToAddTwo);

	printf("\nFirst Number: ");
	for (int i = 0; i < TRIT_WIDTH; i++) {
		printf("%d,", numberToAddOne[i]);
	}

	printf("\nSecond Number: ");
	for (int i = 0; i < TRIT_WIDTH; i++) {
		printf("%d,", numberToAddTwo[i]);
	}

	Ptr_numberToAddOne = numberToAddOne;
	Ptr_numberToAddTwo = numberToAddTwo;

	TrinaryAddition(Ptr_numberToAddOne, Ptr_numberToAddTwo, Ptr_TwoNumbersAdded);

	int result = base3ToDecimal(Ptr_TwoNumbersAdded);

	printf("\nPress enter to return to menu");

	getchar();

	return;
}

void subtractionMenu() {
	double userChoice1 = 0;
	double userChoice2 = 0;

	int8_t numberToAddOne[TRIT_WIDTH] = {};
	int8_t numberToAddTwo[TRIT_WIDTH] = {};
	int8_t TwoNumbersAdded[TRIT_WIDTH] = {};

	int8_t* Ptr_numberToAddOne = numberToAddOne;
	int8_t* Ptr_numberToAddTwo = numberToAddTwo;
	int8_t* Ptr_TwoNumbersAdded = TwoNumbersAdded;

	system("cls");

	printf("\nEnter First number: ");
	userChoice1 = getUserNumber();


	printf("\nEnter second number: ");
	userChoice2 = getUserNumber();

	base3Division(userChoice1, Ptr_numberToAddOne);
	base3Division(userChoice2, Ptr_numberToAddTwo);

	printf("\nFirst Number: ");
	for (int i = 0; i < TRIT_WIDTH; i++) {
		printf("%d,", numberToAddOne[i]);
	}

	printf("\nSecond Number: ");
	for (int i = 0; i < TRIT_WIDTH; i++) {
		printf("%d,", numberToAddTwo[i]);
	}

	Ptr_numberToAddOne = numberToAddOne;
	Ptr_numberToAddTwo = numberToAddTwo;

	bitFlipper(Ptr_numberToAddTwo);

	printf("\nSecond Number Reversed: ");
	for (int i = 0; i < TRIT_WIDTH; i++) {
		printf("%d,", numberToAddTwo[i]);
	}

	TrinaryAddition(Ptr_numberToAddOne, Ptr_numberToAddTwo, Ptr_TwoNumbersAdded);

	int result = base3ToDecimal(Ptr_TwoNumbersAdded);

	printf("\nPress enter to return to menu");

	getchar();

	return;
}