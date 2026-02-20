#include "Header.h"
void base3Division(int number, int8_t* Ptr_numberToAddOne) {
    int base3 = 3;
    int quotient = 0;
    if (number < 0) {
        number = number * NEG;
        while (number != ZERO || quotient != ZERO) {
            if (number >= base3) {
                number = number - base3;
                quotient++;
            }
            else {
                if (number == 2) {
                    *Ptr_numberToAddOne = POS;
                    Ptr_numberToAddOne++;
                    number = quotient + POS;
                    quotient = 0;
                }
                else if (number == 1) {
                    *Ptr_numberToAddOne = NEG;
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
    else {
        while (number != ZERO || quotient != ZERO) {
            if (number >= base3) {
                number = number - base3;
                quotient++;
            }
            else {
                if (number == 2) {
                    *Ptr_numberToAddOne = NEG;
                    Ptr_numberToAddOne++;
                    number = quotient + POS;
                    quotient = 0;
                }
                else if (number == 1) {
                    *Ptr_numberToAddOne = POS;
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

void TrinaryAddition(int8_t* Ptr_numberToAddOne, int8_t* Ptr_numberToAddTwo, int8_t* TwoNumbersAdded) {
    int IteratorNumberOne = 0;
    int IteratorNumberTwo = 0;  
    int CarryOut = 0;

    for (IteratorNumberOne; IteratorNumberOne < TRIT_WIDTH; IteratorNumberOne++) {
        int Sum = 0;

        Sum = *Ptr_numberToAddOne + *Ptr_numberToAddTwo + CarryOut;
        
        switch (Sum) {
        case NEGATIVE_THREE:
            CarryOut = NEG;
            TwoNumbersAdded[IteratorNumberOne] = ZERO;
            break;
        case NEGATIVE_TWO:
            CarryOut = NEG;
            TwoNumbersAdded[IteratorNumberOne] = POS;
            break;
        case NEGATIVE_ONE:
            CarryOut = ZERO;
            TwoNumbersAdded[IteratorNumberOne] = NEG;
            break;
        case ZERO:
            CarryOut = ZERO;
            TwoNumbersAdded[IteratorNumberOne] = ZERO;
            break;
        case POSITIVE_ONE:
            CarryOut = ZERO;
            TwoNumbersAdded[IteratorNumberOne] = POS;
            break;
        case POSITIVE_TWO:
            CarryOut = POS;
            TwoNumbersAdded[IteratorNumberOne] = NEG;
            break;
        case POSITIVE_THREE:
            CarryOut = POS;
            TwoNumbersAdded[IteratorNumberOne] = ZERO;
            break;
        default:
            printf("Failed to add two bits");
            break;
        }
        Ptr_numberToAddOne++;
        Ptr_numberToAddTwo++;
    }

    printf("\nBoth Numbers Added: ");

    for (int i = 0; i < TRIT_WIDTH; i++) {
        printf("%d,", TwoNumbersAdded[i]);
    }
}