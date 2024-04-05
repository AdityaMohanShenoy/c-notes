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
                    scanf("%s",name);
					printf("Enter your Adhaar Number: ");
                    scanf("%llu",&adhaar);
					printf("Enter your Mobile Number: ");
                    scanf("%llu",&mobile);
					printf("Enter your Age: ");
                    scanf("%d",&age);
                    createAccount(accountNumbers,accountBalances,names,adhaars,mobiles,ages,&numAccounts,name,adhaar,mobile,age,&initialaccountnumber);
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

void createAccount(unsigned long long int accountNumbers[], float accountBalances[], char names[][25],unsigned long long int adhaars[],unsigned long long int mobiles[],int ages[],int *numAccounts,char name[],unsigned long long int adhaar,unsigned long long int mobile,int age,int *initialaccountnumber)
{
    int acnumber = *numAccounts;
	//account number : for first its 1 so acnumber gives it 
    char names[MAX_ACCOUNTS][25];
    unsigned long long int adhaars[acnumber]=adhaar;
    unsigned long long int accountNumbers[acnumber]=*initialaccountnumber;
    float accountBalances[acnumber]= 0;
    unsigned long long int mobiles[acnumber] = mobile;
    int ages[acnumber]=age;
    (*numAccounts)++;
    (*initialaccountnumber)++;
    
 
}

void deposit(unsigned long long int accountNumbers[], float accountBalances[], int numAccounts, int accountNumber, float amount)
{
	//ToDo:Complete the code
    //to check if the entered account number is present in the accounts array and get its index 
    int findIndex(unsigned long long int accountNumbers[],int size , int accountNumber) 
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
    int indexvalue=findIndex(unsigned long long int accountNumbers[],int MAX_ACCOUNTS , int accountNumber);

    if(indexvalue == -1)
    {
        printf("Account Doesnt exit , Please create an account :)");
       
    }

    accountBalances[indexvalue]+=amount;
    
}

void withdraw(unsigned long long int accountNumbers[], float accountBalances[], int numAccounts, int accountNumber, float amount) 
{
	//ToDo:Complete the code
    int findIndex(unsigned long long int accountNumbers[],int size , int accountNumber)
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

    int indexvalue=findIndex(unsigned long long int accountNumbers[],int MAX_ACCOUNTS , int accountNumber);

    if(indexvalue == -1)
    {
        printf("Account Doesnt exit , Please create an account :)");
    }

    if (accountBalances[indexvalue]<amount)
    {
        printf("Insufficient Balance ");
    }

    accountBalances[indexvalue]=accountBalances[indexvalue]-amount;
    

    
}

void display(unsigned long long int accountNumbers[], float accountBalances[], char names[][25],unsigned long long int adhaars[],unsigned long long int mobiles[],int ages[],int numAccounts, int accountNumber)
{
	//ToDo:Complete the code
        int findIndex(unsigned long long int accountNumbers[],int size , int accountNumber)
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

    int indexvalue=findIndex(unsigned long long int accountNumbers[],int MAX_ACCOUNTS , int accountNumber);

    if(indexvalue == -1)
    {
        printf("Account Doesnt exit , Please create an account :)");
    }

    printf("The name associated with this account is : %s\n",names[indexvalue]);
    printf("The adhaar number associated with this account is : %llu\n",adhaars[indexvalue]);
    printf("The mobile number  associated with this account is : %llu\n",mobiles[indexvalue]);
    printf("The age associated with this account is : %d\n",ages[indexvalue]);
    printf("The balance associated with this account is : %f\n",accountBalances[indexvalue]);
    



}