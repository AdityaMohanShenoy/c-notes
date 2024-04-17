#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define INITIAL_ACCOUNT_NUMBER 12345678 // Starting account number

typedef struct Account {
    unsigned long long int accountNumber;
    float balance;
    char name[50];
    unsigned long long int adhaar;
    unsigned long long int mobile;
    int age;
} ACCOUNT;

int findIndex(ACCOUNT accounts[], int numAccounts, unsigned long long int accountNumber);

void createAccount(ACCOUNT accounts[], int *numAccounts, char name[], unsigned long long int adhaar, unsigned long long int mobile, int age, unsigned long long int *initialaccountnumber);

void deposit(ACCOUNT accounts[], int numAccounts, unsigned long long int accountNumber, float amount);

void withdraw(ACCOUNT accounts[], int numAccounts, unsigned long long int accountNumber, float amount);

void display(ACCOUNT accounts[], int numAccounts, unsigned long long int accountNumber);

int main() {
    ACCOUNT accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    unsigned long long int initialaccountnumber = INITIAL_ACCOUNT_NUMBER;
    int choice;
    char name[100];
    unsigned long long int adhaar;
    unsigned long long int mobile;
    int age;
    unsigned long long int accountNumber;
    float amount;

    printf("Welcome to PESU Banking System\n");
    do {
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
                getchar(); // Consume the newline character left in the buffer
                fgets(name, sizeof(name), stdin); // Read the entire line, including spaces
                name[strcspn(name, "\n")] = '\0'; // Remove the trailing newline character
                printf("Enter your Adhaar Number: ");
                scanf("%llu", &adhaar);
                printf("Enter your Mobile Number: ");
                scanf("%llu", &mobile);
                printf("Enter your Age: ");
                scanf("%d", &age);
                createAccount(accounts, &numAccounts, name, adhaar, mobile, age, &initialaccountnumber);
                printf("Account created successfully. Account Number: %llu\n", accounts[numAccounts - 1].accountNumber);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%llu", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accounts, numAccounts, accountNumber, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%llu", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accounts, numAccounts, accountNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%llu", &accountNumber);
                display(accounts, numAccounts, accountNumber);
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


void createAccount(ACCOUNT accounts[], int *numAccounts, char name[], unsigned long long int adhaar, unsigned long long int mobile, int age, unsigned long long int *initialaccountnumber) {
    int acnumber = *numAccounts;

    strcpy(accounts[acnumber].name, name);
    accounts[acnumber].adhaar = adhaar;
    accounts[acnumber].accountNumber = *initialaccountnumber;
    accounts[acnumber].balance = 0;
    accounts[acnumber].mobile = mobile;
    accounts[acnumber].age = age;

    (*numAccounts)++;
    (*initialaccountnumber)++;
}

void deposit(ACCOUNT accounts[], int numAccounts, unsigned long long int accountNumber, float amount) {
    int indexvalue = findIndex(accounts, numAccounts, accountNumber);

    if (indexvalue == -1) {
        printf("Account Doesn't exist, Please create an account :)\n");
        return;
    }

    accounts[indexvalue].balance += amount;
    printf("Amount Deposited: %.2f\n", amount);
    printf("Updated Balance: %.2f\n", accounts[indexvalue].balance);
}



void withdraw(ACCOUNT accounts[], int numAccounts, unsigned long long int accountNumber, float amount) {
    int indexvalue = findIndex(accounts, numAccounts, accountNumber);

    if (indexvalue == -1) {
        printf("Account Doesn't exist, Please create an account :)\n");
        return;
    }

    if (accounts[indexvalue].balance < amount) {
        printf("Insufficient Balance\n");
        return;
    }

    accounts[indexvalue].balance -= amount;
    printf("Amount Successfully withdrawn: %.2f\n", amount);
}


   
void display(ACCOUNT accounts[], int numAccounts, unsigned long long int accountNumber)
{
    int indexvalue = findIndex(accounts, numAccounts, accountNumber);

    if (indexvalue == -1) {
        printf("Account Doesn't exist, Please create an account :)\n");
        return;
    }

    printf("Account Holder Name: %s\n", accounts[indexvalue].name);
    printf("Account Number: %llu\n", accounts[indexvalue].accountNumber);
    printf("Aadhaar Number: %llu\n", accounts[indexvalue].adhaar);
    printf("Mobile Number: %llu\n", accounts[indexvalue].mobile);
    printf("Current Balance: %.2f\n", accounts[indexvalue].balance);
}
int findIndex(ACCOUNT accounts[], int numAccounts, unsigned long long int accountNumber) {
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accountNumber) {
            return i; // Return the index if the account number is found
        }
    }
    return -1; // Return -1 if the account number is not found
}


