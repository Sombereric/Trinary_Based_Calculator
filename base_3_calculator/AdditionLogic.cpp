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

void multiplcationMenu() {
	double userChoice1 = 0;
	double userChoice2 = 0;

	int8_t numberToAddOne[TRIT_WIDTH] = {};
	int8_t numberToAddTwo[TRIT_WIDTH] = {};
	int8_t numberPartialNumberOne[TRIT_WIDTH] = {};
	int8_t numberPartialNumberTwo[TRIT_WIDTH] = {};
	int8_t BlankTrit[TRIT_WIDTH] = {};
	int8_t TwoNumbersAdded[TRIT_WIDTH] = {};

	int8_t* Ptr_numberToAddOne = numberToAddOne;
	int8_t* Ptr_numberToAddTwo = numberToAddTwo;
	int8_t* Ptr_numberPartialNumberOne = numberPartialNumberOne;
	int8_t* Ptr_numberPartialNumberTwo = numberPartialNumberTwo;
	int8_t* Ptr_BlankTrit = BlankTrit;
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

	clearTrit(Ptr_numberPartialNumberTwo);

	for (int i = 0; i < TRIT_WIDTH; i++) {

		if (numberToAddTwo[i] == ZERO) {
			continue;
		}	

		// partial = A
		setFirstNumberEqualToSecond(Ptr_numberPartialNumberOne, Ptr_numberToAddOne);

		// negate if B[i] == -1
		if (numberToAddTwo[i] == NEG){
			multipleTritsNEG(Ptr_numberPartialNumberOne);
		}
			
		// shift by index position
		shiftValueToRightOne(Ptr_numberPartialNumberOne, i );

		// accumulator += partial
		TrinaryAddition(Ptr_numberPartialNumberOne, Ptr_numberPartialNumberTwo, Ptr_TwoNumbersAdded);

		// move accumulator forward (safe copy only)
		memcpy(Ptr_numberPartialNumberTwo,Ptr_TwoNumbersAdded,TRIT_WIDTH * sizeof(int8_t));

		clearTrit(Ptr_numberPartialNumberOne);
	}

	int result = base3ToDecimal(Ptr_TwoNumbersAdded);

	printf("\nPress enter to return to menu");

	getchar();

	return;
}