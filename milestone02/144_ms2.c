/*
 * Milestone 2
 * IPC 144 - Section Q
 * Name: Wai Chi Ng
 * Student ID: 140634163
 * Email: wcng1@myseneca.ca
 * 144_ms2.c
 * Date: March 20, 2017
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Define statements:
#define LINEAR 1
#define FORM 0

// Constant TAX value:
const double TAX = 0.13;

// Item structure:
struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};

// Function Prototypes Milestone 1:
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

// Function Prototypes Milesone 2:
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

// Function Implementations Milestone 1:
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
		printf("                                           Grand Total: |%12.2lf\n", gTotal);
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
		else if (YN == 'N' || YN == 'n') {
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

// Function Implementations Milestone 2:
double totalAfterTax(struct Item item) {
	
	double totalPrice = 0;

	if (item.isTaxed != 0) {
		totalPrice = item.price * item.quantity * (1+TAX);
	}
	else {
		totalPrice = item.price * item.quantity;
	}

	return totalPrice;
}

//Determie if the inventory is low in stock
int isLowQuantity(struct Item item) {
	
	int result = 0;

	if (item.quantity <= item.minQuantity) {
		result = 1;
	}

	return result;
}

//Receives an SKU as its parameter, prompts user for inputs
//User inputs are stored and the entire struct is returned back to to the caller
struct Item itemEntry(int sku) {
	
	struct Item newEntry;
	
	newEntry.sku = sku;

	printf("%13s%d", "SKU: ", newEntry.sku);
	printf("\n");

	printf("%13s", "Name: ");
	
	//the & is removed to avoid compiler warning on Matrix
	scanf("%20[^\n]", newEntry.name);
	flushKeyboard();

	printf("%13s", "Price: "); 
	newEntry.price = getDouble();
	
	printf("%13s", "Quantity: ");
	newEntry.quantity = getInt();

	printf("%13s", "Minimum Qty: ");
	newEntry.minQuantity = getInt();

	printf("%13s", "Is Taxed: ");
	newEntry.isTaxed = yes();

	return newEntry;
}

//Item is displayed in either linear or form format
void displayItem(struct Item item, int linear) {
	
	char taxYN[4];

	//strcpy() is called from the string library to update the char array post initialization
	//strcpy() greatly reduces the amount of code necessary to carry out the instructions
	if (item.isTaxed == 1) {
		strcpy(taxYN, "Yes");
	}
	else {
		strcpy(taxYN, "No");
	}

	//based on the flag, the result is either displayed in a linear format or a form format
	if (linear == LINEAR) {
			printf("|%3d|%-20s|%8.2lf|%5s|%4d |%4d |%12.2lf|", 
				item.sku, item.name, item.price, taxYN, item.quantity, item.minQuantity, totalAfterTax(item));

			if (isLowQuantity(item) == 1) {
				printf("***\n");
			}
			else {
				printf("\n");
			}
	}
	else {
		printf("%13s%d\n", "SKU: ", item.sku);
		printf("%13s%s\n", "Name: ", item.name);
		printf("%13s%.2lf\n", "Price: ", item.price);
		printf("%13s%d\n", "Quantity: ", item.quantity);
		printf("%13s%d\n", "Minimum Qty: ", item.minQuantity);
		printf("%13s%s\n", "Is Taxed: ", taxYN);

		if (isLowQuantity(item) == 1) {
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}
}

//Receives # of items to be displayed as the second parameter, and 
//Displays the items in a linear format with the grand total at the very bottom
void listItems(const struct Item item[], int noOfItems) {
	
	int i;
	double grandTotal = 0;

	printTitle();
	
	for (i = 0; i < noOfItems; i++) {
		printf("%-4d", i + 1);
		displayItem(item[i], LINEAR);
		grandTotal = grandTotal + totalAfterTax(item[i]);
	}
	
	printFooter(grandTotal);
}

//Search for an item based on the sku received
//If a match is found then the current index will be returned
//If a match is NOT found, then the function will return 0
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) {
	
	int i, result = 0;

	for (i = 0; i < NoOfRecs; i++) {
		if (item[i].sku == sku) {
			*index = i;
			result = 1;
		}
	}

	return result;
}

