#include "Header.h"

int main(void) {
	bool menuRunning = true;

	while (menuRunning) {
		mainMenuDisplay();
		int userChoice = getUserNumber();

		switch (userChoice) {
		case (addition):
			additionMenu();
			break;
		case (subtraction):
			break;
		case (divison):
			break;
		case (multiplication):
			break;
		case (exitProgram):
			menuRunning = false;
			break;
		default:
			printf("invalid user input. 1-4 only");
			break;
		}
	}
	return 1;
}

void mainMenuDisplay()
{
	system("cls");
	printf("__Calculator_Menu__\n");
	printf("1.Addition\n");
	printf("2.Subtract\n");
	printf("3.division\n");
	printf("4.multiplication\n");
	printf("5.Exit Program\n");
	printf("Please Enter a choice: ");
}

// FUNCTION : getUserNumber
// DESCRIPTION :
// gets user input and attempts to turn it into a readable number
// PARAMETERS :
//	N/A
// RETURNS :
// int userInput: returns the user input number or a -1 for error to allow menu to fail
int getUserNumber()
{
	int userInput = 0;
	int const BUFFER_SIZE = 50;
	char inputBuffer[BUFFER_SIZE];
	//where user input is obtained
	fgets(inputBuffer, BUFFER_SIZE, stdin);

	//used to catch overflow
	if (strlen(inputBuffer) == BUFFER_SIZE - 1)
	{
		inputOverflowRemover();
	}

	//checks if the input is a number anything higher than the highest case number is already handled
	//deal with decimal numbers
	if (sscanf_s(inputBuffer, "%d", &userInput) < 1)
	{
		//sets the number to an error
		userInput = -1;
	}
	return userInput;
}

//
// FUNCTION : inputOverflowRemover
// DESCRIPTION :
// Used to empty out the file stream
// PARAMETERS :
// Does not take any arguments
// RETURNS :
// void
void inputOverflowRemover()
{
	//used to gather all extra inputted data to contain function overflow
	int overflowCollector = getchar();
	while (overflowCollector != EOF && overflowCollector != '\n')
	{
		overflowCollector = getchar();
	}
	return;
}