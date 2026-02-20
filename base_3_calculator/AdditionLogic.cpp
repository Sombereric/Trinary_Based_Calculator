#include "Header.h"

void additionMenu() {
	bool runner = true;
	double userChoice1 = 0;
	double userChoice2 = 0;
	
	int8_t numberToAddOne[9] = {};
	int8_t numberToAddTwo[9] = {};

	int8_t* Ptr_numberToAddOne = numberToAddOne;
	int8_t* Ptr_numberToAddTwo = numberToAddTwo;

	system("cls");

	printf("\nEnter First number: ");
	userChoice1 = getUserNumber();


	printf("\nEnter second number: ");
	userChoice2 = getUserNumber();

	base3Division(userChoice1, Ptr_numberToAddOne);
	base3Division(userChoice2, Ptr_numberToAddTwo);

	printf("\nFirst Number: ");
	for (int i = 0; i <= 8; i++) {
		printf("%d,", numberToAddOne[i]);
	}

	printf("\nSecond Number: ");
	for (int i = 0; i <= 8; i++) {
		printf("%d,", numberToAddTwo[i]);
	}

	Ptr_numberToAddOne = numberToAddOne;
	Ptr_numberToAddTwo = numberToAddTwo;

	TrinaryAddition(Ptr_numberToAddOne, Ptr_numberToAddTwo);

	printf("\nPress enter to return to menu");

	getchar();

	return;
}