#include <stdio.h>
#include <string.h>

// Constants
#define MAX_ACCOUNTS 10
#define INITIAL_ACCOUNT_NUMBER 12345678 // Starting account number

// Function prototypes
int findIndex(unsigned long long int accountNumbers[], int size, unsigned long long int accountNumber);
void createAccount(unsigned long long int accountNumbers[], float accountBalances[], char names[][25], unsigned long long int adhaars[], unsigned long long int mobiles[], int ages[], int *numAccounts, char name[], unsigned long long int adhaar, unsigned long long int mobile, int age, int *initialaccountnumber);
void deposit(unsigned long long int accountNumbers[], float accountBalances[], int numAccounts, unsigned long long int accountNumber, float amount);
void withdraw(unsigned long long int accountNumbers[], float accountBalances[], int numAccounts, unsigned long long int accountNumber, float amount);
void display(unsigned long long int accountNumbers[], float accountBalances[], char names[][25], unsigned long long int adhaars[], unsigned long long int mobiles[], int ages[], int numAccounts, unsigned long long int accountNumber);

int main() {
    int initialaccountnumber = INITIAL_ACCOUNT_NUMBER;
    unsigned long long int accountNumbers[MAX_ACCOUNTS];
    float accountBalances[MAX_ACCOUNTS];
    char names[MAX_ACCOUNTS][25];
    unsigned long long int adhaars[MAX_ACCOUNTS];
    unsigned long long int mobiles[MAX_ACCOUNTS];
    int ages[MAX_ACCOUNTS];
    unsigned long long int accountNumber;
    char name[25];
    unsigned long long int adhaar;
    unsigned long long int mobile;
    int age;
    int numAccounts = 0;
    int choice;
    float amount;

    printf("Welcome to PESU Banking System\n");
    do {
        // Display menu
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your Name: ");
                scanf("%s", name);
                printf("\n");
                fflush(stdin);
                printf("Enter your Adhaar Number: ");
                scanf("%llu", &adhaar);
                printf("\n");
                fflush(stdin);
                printf("Enter your Mobile Number: ");
                scanf("%llu", &mobile);
                printf("\n");
                fflush(stdin);
                printf("Enter your Age: ");
                scanf("%d", &age);
                printf("\n");
                fflush(stdin);
                createAccount(accountNumbers, accountBalances, names, adhaars, mobiles, ages, &numAccounts, name, adhaar, mobile, age, &initialaccountnumber);
                printf("Account created successfully. Account Number: %llu\n", accountNumbers[numAccounts - 1]);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%llu", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accountNumbers, accountBalances, numAccounts, accountNumber, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%llu", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accountNumbers, accountBalances, numAccounts, accountNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%llu", &accountNumber);
                display(accountNumbers, accountBalances, names, adhaars, mobiles, ages, numAccounts, accountNumber);
                break;
            case 5:
                printf("Thank You for using PESU Banking System\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void createAccount(unsigned long long int accountNumbers[], float accountBalances[], char names[][25], unsigned long long int adhaars[], unsigned long long int mobiles[], int ages[], int *numAccounts, char name[], unsigned long long int adhaar, unsigned long long int mobile, int age, int *initialaccountnumber) {
    int acnumber = *numAccounts;

    strcpy(names[acnumber], name);
    adhaars[acnumber] = adhaar;
    accountNumbers[acnumber] = *initialaccountnumber;
    accountBalances[acnumber] = 0;
    mobiles[acnumber] = mobile;
    ages[acnumber] = age;
    (*numAccounts)++;
    (*initialaccountnumber)++;
}

void deposit(unsigned long long int accountNumbers[], float accountBalances[], int numAccounts, unsigned long long int accountNumber, float amount) {
    int indexvalue = findIndex(accountNumbers, MAX_ACCOUNTS, accountNumber);

    if (indexvalue == -1) {
        printf("Account Doesnt exist, Please create an account :)\n");
        return;
    }

    accountBalances[indexvalue] += amount;
}

void withdraw(unsigned long long int accountNumbers[], float accountBalances[], int numAccounts, unsigned long long int accountNumber, float amount) {
    int indexvalue = findIndex(accountNumbers, MAX_ACCOUNTS, accountNumber);

    if (indexvalue == -1) {
        printf("Account Doesnt exist, Please create an account :)\n");
        return;
    }

    if (accountBalances[indexvalue] < amount) {
        printf("Insufficient Balance\n");
        return;
    }

    accountBalances[indexvalue] -= amount;
}

void display(unsigned long long int accountNumbers[], float accountBalances[], char names[][25], unsigned long long int adhaars[], unsigned long long int mobiles[], int ages[], int numAccounts, unsigned long long int accountNumber) {
    int indexvalue = findIndex(accountNumbers, MAX_ACCOUNTS, accountNumber);

    if (indexvalue == -1) {
        printf("Account Doesnt exist, Please create an account :)\n");
        return;
    }

    printf("Account Number: %llu\n", accountNumbers[indexvalue]);
    printf("Name: %s\n", names[indexvalue]);
    printf("Adhaar Number: %llu\n", adhaars[indexvalue]);
    printf("Mobile Number: %llu\n", mobiles[indexvalue]);
    printf("Age: %d\n", ages[indexvalue]);
    printf("Balance: %.2f\n", accountBalances[indexvalue]);
}

int findIndex(unsigned long long int accountNumbers[], int size, unsigned long long int accountNumber)
{
    for (int i = 0; i < size; ++i)
    {
        if (accountNumbers[i] == accountNumber)
        {
            return i; // Return the index if the value is found
        }
    }
    return -1; // Return -1 if the value is not found
}
