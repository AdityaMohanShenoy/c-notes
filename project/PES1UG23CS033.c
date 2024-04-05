#include <stdio.h>
#include<string.h>

// Constants
#define MAX_ACCOUNTS 10
#define INITIAL_ACCOUNT_NUMBER 12345678 // Starting account number

// Function prototypes
void createAccount(unsigned long long int accountNumbers[], float accountBalances[], char names[][25],unsigned long long int adhaars[],unsigned long long int mobiles[],int ages[],int *numAccounts,char name[],unsigned long long int adhaar,unsigned long long int mobile,int age);
void deposit(unsigned long long int accountNumbers[], float accountBalances[], int numAccounts, int accountNumber, float amount);
void withdraw(unsigned long long int accountNumbers[], float accountBalances[], int numAccounts, int accountNumber, float amount);
void display(unsigned long long int accountNumbers[], float accountBalances[], char names[][25],unsigned long long int adhaars[],unsigned long long int mobiles[],int ages[],int numAccounts, int accountNumber);

int main() {
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
                    scanf("%s",name);
					printf("Enter your Adhaar Number: ");
                    scanf("%llu",&adhaar);
					printf("Enter your Mobile Number: ");
                    scanf("%llu",&mobile);
					printf("Enter your Age: ");
                    scanf("%d",&age);
                    createAccount(accountNumbers,accountBalances,names,adhaars,mobiles,ages,&numAccounts,name,adhaar,mobile,age);
                    printf("Account created successfully. Account Number: %d\n", accountNumbers[numAccounts - 1]);
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
                display(accountNumbers, accountBalances, names,adhaars,mobiles,ages,numAccounts, accountNumber);
                break;
            case 5:
                printf("Thank You for using PESU Banking Systeam\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void createAccount(unsigned long long int accountNumbers[], float accountBalances[], char names[][25],unsigned long long int adhaars[],unsigned long long int mobiles[],int ages[],int *numAccounts,char name[],unsigned long long int adhaar,unsigned long long int mobile,int age)
{
	//ToDo:Complete the code
}

void deposit(unsigned long long int accountNumbers[], float accountBalances[], int numAccounts, int accountNumber, float amount)
{
	//ToDo:Complete the code
}

void withdraw(unsigned long long int accountNumbers[], float accountBalances[], int numAccounts, int accountNumber, float amount) 
{
	//ToDo:Complete the code
}

void display(unsigned long long int accountNumbers[], float accountBalances[], char names[][25],unsigned long long int adhaars[],unsigned long long int mobiles[],int ages[],int numAccounts, int accountNumber)
{
	//ToDo:Complete the code
}