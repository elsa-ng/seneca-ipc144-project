/*
 * Milestone 3
 * IPC 144 - Section Q
 * Name: Wai Chi Ng
 * Student ID: 140634163
 * Email: wcng1@myseneca.ca
 * 144_ms3.c
 * Date: March 27, 2017
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Define statements:
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100

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
// Tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// App interface
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

// Function Prototypes Milestone 3:
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

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

// Clears buffer
void flushKeyboard(void) {

	while (getchar() != '\n') {
		;
	}
}

void pause(void) {

	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

// Validates and returns a valid integer 
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

// Returns a valid integer within specified range
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

// Validates and returns a valid floating-point value
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

// Returns a valid floating-point value within specified range
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

// Returns 1 if input is Y or y
// Returns 0 if input is N or n
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

// Displays menu and return the option chosen
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

// Returns 1 if quantity is low
int isLowQuantity(struct Item item) {
	
	int result = 0;

	if (item.quantity <= item.minQuantity) {
		result = 1;
	}

	return result;
}

// Accepts and stores input into a struct and returns struct back to caller
struct Item itemEntry(int sku) {
	
	struct Item newEntry;
	
	newEntry.sku = sku;

	printf("%13s%d", "SKU: ", newEntry.sku);
	printf("\n");

	printf("%13s", "Name: ");
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

// Displays item in either LINEAR or FORM format
void displayItem(struct Item item, int linear) {
	
	char taxYN[4];

	if (item.isTaxed == 1) {
		strcpy(taxYN, "Yes");
	}
	else {
		strcpy(taxYN, "No");
	}

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

// Lists items in linear format with the grand total at the very bottom
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

// Searches for an item based on SKU received
// Returns 1 and current index is assigned to the index if found
// Return 0 if no match found
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) {
	
	int i, result = 0;

	for (i = 0; i < NoOfRecs && result == 0; i++) {
		if (item[i].sku == sku) {
			*index = i;
			result = 1;
		}
	}

	return result;
}

// Validates and locates SKU
// Displays info using FORM format if SKU is found
// Displays error message if SKU is not found
void search(const struct Item item[], int NoOfRecs) {

	int skuNO, searchIndex = 0, found;

	printf("Please enter the SKU: ");
	skuNO = getIntLimited(SKU_MIN, SKU_MAX);

	found = locateItem(item, NoOfRecs, skuNO, &searchIndex);
	if (found == 1) {
		displayItem(item[searchIndex], FORM);
	}
	else {
		printf("Item not found!\n");
	}
}

// Overwrites an item record if the answer is 1
void updateItem(struct Item* itemptr) {

	struct Item update;
	int answer;

	printf("Enter new data:\n");
	update = itemEntry(itemptr->sku);
	
	printf("Overwrite old data? (Y)es/(N)o: ");
	answer = yes();

	if (answer == 1) {
		itemptr->isTaxed = update.isTaxed;
		itemptr->minQuantity = update.minQuantity;
		strcpy(itemptr->name, update.name);
		itemptr->price = update.price;
		itemptr->quantity = update.quantity;
		itemptr->sku = update.sku;
		printf("--== Updated! ==--\n");
	}
	else {
		printf("--== Aborted! ==--\n");
	}
}

// Displays error message if array is full
// Adds new item to the end of item array after confirmation if not full
void addItem(struct Item item[], int *NoOfRecs, int sku) {

	struct Item newEntry;
	int answer;

	if (*NoOfRecs == MAX_ITEM_NO) {
		printf("Can not add new item; Storage Full!\n");
	}
	else {
		newEntry = itemEntry(sku);
		
		printf("Add Item? (Y)es/(N)o: ");
		answer = yes();

		if (answer == 1) {
			item[*NoOfRecs].sku = newEntry.sku;
			item[*NoOfRecs].isTaxed = newEntry.isTaxed;
			item[*NoOfRecs].minQuantity = newEntry.minQuantity;
			strcpy(item[*NoOfRecs].name, newEntry.name);
			item[*NoOfRecs].price = newEntry.price;
			item[*NoOfRecs].quantity = newEntry.quantity;

			*NoOfRecs = *NoOfRecs + 1;

			printf("--== Added! ==--\n");
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
}

// Validates and locates SKU
// If found then prompts the user to choose to update or abort
// Calls the addItem() if no SKU is found
void addOrUpdateItem(struct Item item[], int* NoOfRecs) {

	int skuNO, searchIndex = 0, found, answer;

	printf("Please enter the SKU: ");
	skuNO = getIntLimited(SKU_MIN, SKU_MAX);
	found = locateItem(item, *NoOfRecs, skuNO, &searchIndex);
	
	if (found == 1) {
		displayItem(item[searchIndex], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		answer = yes();

		if (answer == 1) {
			updateItem(&item[searchIndex]);
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
	else {
		addItem(item, NoOfRecs, skuNO);
	}
}

// Validates and locates SKU
// Displays item in FORM format if found
// Aborts the operation if numItem is 0
// Updates item quantity depending on whether the operation is to stock or check out
void adjustQuantity(struct Item item[], int NoOfRecs, int stock) {

	int skuNO, searchIndex = 0, found, maxItem, numItem;
	char stockOrCheck[12];

	printf("Please enter the SKU: ");
	skuNO = getIntLimited(SKU_MIN, SKU_MAX);
	found = locateItem(item, NoOfRecs, skuNO, &searchIndex);

	if (found == 1) {
		displayItem(item[searchIndex], FORM);

		if (stock == STOCK) {
			strcpy(stockOrCheck, "to stock");
			maxItem = MAX_QTY - item[searchIndex].quantity;
		}
		else {
			strcpy(stockOrCheck, "to checkout");
			maxItem = item[searchIndex].quantity;
		}

		printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", stockOrCheck, maxItem);
		numItem = getIntLimited(0, maxItem);

		if (numItem == 0) {
			printf("--== Aborted! ==--\n");
		}
		else if (stock == STOCK) {
			item[searchIndex].quantity = item[searchIndex].quantity + numItem;
			printf("--== Stocked! ==--\n");
		}
		else {
			item[searchIndex].quantity = item[searchIndex].quantity - numItem;
			printf("--== Checked out! ==--\n");
			if (isLowQuantity(item[searchIndex]) == 1) {
				printf("Quantity is low, please reorder ASAP!!!\n");
			}
		}
	}
	else {
		printf("SKU not found in storage!\n");
	}
}