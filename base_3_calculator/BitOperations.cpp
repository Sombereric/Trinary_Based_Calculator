#include "Header.h"
void base3Division(int number, int8_t* Ptr_numberToAddOne) {
	int base3 = 3;
	int quotient = 0;
	bool numberNegative = false;
	if (number < 0) {
		number = number * NEG;
		numberNegative = true;
	}
	while (number != ZERO || quotient != ZERO) {
		if (number >= base3) {
			number = number - base3;
			quotient++;
		}
		else {
			if (number == 2) {
				if (numberNegative) {
					*Ptr_numberToAddOne = POS;
				}
				else {
					*Ptr_numberToAddOne = NEG;
				}
				Ptr_numberToAddOne++;
				number = quotient + POS;
				quotient = 0;
			}
			else if (number == 1) {
				if (numberNegative) {
					*Ptr_numberToAddOne = NEG;
				}
				else {
					*Ptr_numberToAddOne = POS;
				}
				Ptr_numberToAddOne++;
				number = quotient;
				quotient = 0;
			}
			else if (number == 0) {
				*Ptr_numberToAddOne = ZERO;
				Ptr_numberToAddOne++;
				number = quotient;
				quotient = 0;
			}
		}
	}
}

int base3ToDecimal(int8_t* Ptr_numberToAddOne)
{
	int result = 0;
	for (int i = 0; i < TRIT_WIDTH; i++) {
		result += *Ptr_numberToAddOne * pow(3, i);
		Ptr_numberToAddOne++;
	}
	printf("\n result %d: ", result);
	return result;
}

void bitFlipper(int8_t* Ptr_numberToAddOne) {
	for (int i = 0; i < TRIT_WIDTH; i++) {
		if (*Ptr_numberToAddOne == NEG) {
			*Ptr_numberToAddOne = POS;
		}
		else if (*Ptr_numberToAddOne == POS) {
			*Ptr_numberToAddOne = NEG;
		}
		Ptr_numberToAddOne++;
	}
}

void TrinaryAddition(int8_t* Ptr_numberToAddOne, int8_t* Ptr_numberToAddTwo, int8_t* TwoNumbersAdded) {

	int CarryOut = 0;

	// Preserve starting pointers (prevent pointer drift bug)
	int8_t* startA = Ptr_numberToAddOne;
	int8_t* startB = Ptr_numberToAddTwo;

	// Clear output array first (VERY IMPORTANT)
	clearTrit(TwoNumbersAdded);

	for (int i = 0; i < TRIT_WIDTH; i++) {

		int Sum = startA[i] + startB[i] + CarryOut;

		switch (Sum) {

		case NEGATIVE_THREE:
			CarryOut = NEG;
			TwoNumbersAdded[i] = ZERO;
			break;

		case NEGATIVE_TWO:
			CarryOut = NEG;
			TwoNumbersAdded[i] = POS;
			break;

		case NEGATIVE_ONE:
			CarryOut = ZERO;
			TwoNumbersAdded[i] = NEG;
			break;

		case ZERO:
			CarryOut = ZERO;
			TwoNumbersAdded[i] = ZERO;
			break;

		case POSITIVE_ONE:
			CarryOut = ZERO;
			TwoNumbersAdded[i] = POS;
			break;

		case POSITIVE_TWO:
			CarryOut = POS;
			TwoNumbersAdded[i] = NEG;
			break;

		case POSITIVE_THREE:
			CarryOut = POS;
			TwoNumbersAdded[i] = ZERO;
			break;

		default:
			printf("Failed to add two bits\n");
			break;
		}
	}

	// Final carry propagation (very important for correctness)
	if (CarryOut != 0) {
		if (TRIT_WIDTH - 1 >= 0)
			TwoNumbersAdded[TRIT_WIDTH - 1] += CarryOut;
	}

	printf("\nBoth Numbers Added: ");

	for (int i = 0; i < TRIT_WIDTH; i++) {
		printf("%d,", TwoNumbersAdded[i]);
	}
}

void multipleTritsNEG(int8_t* Ptr_numberToAddOne) {
	for (int i = 0; i < TRIT_WIDTH; i++) {
		Ptr_numberToAddOne[i] *= NEG;
	}
}

void shiftValueToRightOne(int8_t* arr, int shift)
{
	int8_t temp[TRIT_WIDTH];

	for (int i = 0; i < TRIT_WIDTH; i++)
		temp[i] = arr[i];

	clearTrit(arr);

	for (int i = 0; i < TRIT_WIDTH - shift; i++)
		arr[i + shift] = temp[i];
}

void setFirstNumberEqualToSecond(int8_t* Ptr_numberToAddOne, int8_t* Ptr_numberToAddTwo) {
	for (int i = 0; i < TRIT_WIDTH; i++) {
		Ptr_numberToAddOne[i] = Ptr_numberToAddTwo[i];
	}
}

void clearTrit(int8_t* Ptr_numberToAddOne) {
	for (int i = 0; i < TRIT_WIDTH; i++) {
		Ptr_numberToAddOne[i] = ZERO;
	}
}