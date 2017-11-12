/**************************
* Milestone 1
* IPC 144 - Section Q
* Name: Wai Chi Ng
* Student ID: 140634163
* Email: wcng1@myseneca.ca
* 144_ms1.c
* Date: March 13, 2017
**************************/

#include <stdio.h>
// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);


// code your functions here:
void welcome(void) {
	
	printf("---=== Grocery Inventory System ===---\n\n");

}

void printTitle(void) {
	
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");

}

void printFooter(double gTotal) {
	
	printf("--------------------------------------------------------+----------------\n");

	if (gTotal > 0) {
		printf("\t\t\t\t\t   Grand Total: |%12.2lf\n", gTotal);
		//printf("					   Grand Total: |%12.2lf\n", gTotal);
	}
	
}
// clears buffer
void flushKeyboard(void) {
	
	while (getchar() != '\n') {
		;
	}

}

void pause(void) {
	
	printf("Press <ENTER> to continue...");
	flushKeyboard();

}

// validate and return a valid integer 
int getInt(void) {
	
	int value;
	char NL;

	do {
		scanf("%d%c", &value, &NL);

		if (NL != '\n') {
			flushKeyboard();
			printf("Invalid integer, please try again: ");
		}
	} while (NL != '\n');
	
	return value;

}

// return a valid integer within specified range
int getIntLimited(int lowerLimit, int upperLimit) {
	
	int value, tryAgain = 1;

	do {
		value = getInt();

		if (value < lowerLimit || value > upperLimit) {
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		}
		else {
			tryAgain = 0;
		}
	} while (tryAgain == 1);
	
	return value;

}
// validate and return a valid floating-point value
double getDouble(void) {
	
	double value;
	char NL;

	do {
		scanf("%lf%c", &value, &NL);

		if (NL != '\n') {
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}
	} while (NL != '\n');

	return value;
}

// return a valid floating-point value within specified range
double getDoubleLimited(double lowerLimit, double upperLimit) {
	
	int tryAgain = 1;
	double value;
	
	do {
		value = getDouble();

		if (value < lowerLimit || value > upperLimit) {
			printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
		}
		else {
			tryAgain = 0;
		}
	} while (tryAgain == 1);

	return value;

}

// interate until input is Y or y or N or n
// return 1 if input is Y or y
// return 0 if input is N or n
int yes(void) {
	
	int answer;
	char YN;

	do {
		YN = getchar();

		if (YN == 'Y' || YN == 'y') {
			answer = 1;
		}
		else if (YN == 'N' || YN == 'n'){
			answer = 0;
		}
		else {
			printf("Only (Y)es or (N)o are acceptable: ");
		}

		flushKeyboard();

	} while (YN != 'Y' && YN != 'y' && YN != 'N' && YN != 'n');
	
	return answer;

}

// display menu options and return the chosen menu option
int menu(void) {
	
	int option;

	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");

	option = getIntLimited(0, 7);

	return option;

}

void GroceryInventorySystem(void) {
	
	int choice, exit = 0;

	welcome();
	
	do {
		choice = menu();

		switch (choice) {
		case 1:
			printf("List Items under construction!\n");
			pause();
			break;
		case 3:
			printf("Checkout Item under construction!\n");
			pause();
			break;
		case 4:
			printf("Stock Item under construction!\n");
			pause();
			break;
		case 5:
			printf("Add/Update Item under construction!\n");
			pause();
			break;
		case 6:
			printf("Delete Item under construction!\n");
			pause();
			break;
		case 7:
			printf("Search by name under construction!\n");
			pause();
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			exit = yes();
			break;
		case 2:
		default:
			printf("Search Items under construction!\n");
			pause();
		}

	} while (exit == 0 || choice != 0);

}