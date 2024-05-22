#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int i = 0;
int initial_accn = 123456789;
int num_accounts=0;

typedef struct {
    char name[100];
    int age;
    long long int adhaar_no;
    int mobile_no;
    int acc_no;
    float balance;
} BANKSYS;

void read_accounts(BANKSYS accounts[]) {
    if (i < 10) {
        printf("Enter details for account %d\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", accounts[i].name);
        getchar();  // To consume the newline character left by scanf

        printf("Enter age: ");
        scanf("%d", &accounts[i].age);
        getchar();

        printf("Enter adhaar no: ");
        scanf("%lld", &accounts[i].adhaar_no);
        getchar();

        printf("Enter mobile number: ");
        scanf("%d", &accounts[i].mobile_no);
        getchar();

        accounts[i].acc_no = initial_accn++;

        printf("account created succesfully with account no : %d",accounts[i].acc_no);
        accounts[i].balance = 0.0;  // Initialize balance to 0
        i++;
        num_accounts++;




    } else {
        printf("Max accounts created.\n");
    }
}

void display_details(BANKSYS accounts[]) {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int j = 0; j < i; j++) {
        if (accounts[j].acc_no == accountNumber) {
            printf("\nUser account number: %d\n", accounts[j].acc_no);
            printf("Name of user: %s\n", accounts[j].name);
            printf("Age of user: %d\n", accounts[j].age);
            printf("Mobile number of user: %d\n", accounts[j].mobile_no);
            printf("Aadhar details of user: %lld\n", accounts[j].adhaar_no);
            printf("User balance: %.2f\n", accounts[j].balance);
            return;
        }
    }
    printf("Account number not found.\n");
}

void deposit(BANKSYS accounts[]) {
    int temp;
    printf("Enter account number: ");
    scanf("%d", &temp);

    for (int j = 0; j < i; j++) {
        if (accounts[j].acc_no == temp) {
            printf("Account number found.\n");
            float amount;
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if (amount > 0) {
                accounts[j].balance += amount;
                printf("Deposit successful! New balance: %.2f\n", accounts[j].balance);
            } else {
                printf("Invalid deposit amount.\n");
            }
            return;
        }
    }
    printf("Account number not found.\n");
}

void withdraw(BANKSYS accounts[]) {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int j = 0; j < i; j++) {
        if (accounts[j].acc_no == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > 0 && accounts[j].balance >= amount) {
                accounts[j].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[j].balance);
            } else {
                printf("Error: Insufficient balance or invalid withdrawal amount.\n");
            }
            return;
        }
    }
    printf("Account number not found.\n");
}
void sortaccno(BANKSYS accounts[]) {
    for (int i = 0; i < num_accounts - 1; i++) {
        for (int j = i + 1; j < num_accounts; j++) {
            if (accounts[i].acc_no < accounts[j].acc_no) {
                BANKSYS temp = accounts[i];
                accounts[i] = accounts[j];
                accounts[j] = temp;
            }
        }
    }
    printf("Accounts sorted in descending order of account numbers.\n");
    printf("Account Number\tName\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%d\t\t%s\n", accounts[i].acc_no, accounts[i].name);
    }
}
void sortname(BANKSYS accounts[]) {
    for (int i = 0; i < num_accounts - 1; i++) {
        for (int j = i + 1; j < num_accounts; j++) {
            if (strcmp(accounts[i].name, accounts[j].name) > 0) {
                BANKSYS temp = accounts[i];
                accounts[i] = accounts[j];
                accounts[j] = temp;
            }
        }
    
    }
    printf("Accounts sorted in ascending order of names.\n");
    printf("Account Number\tName\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%d\t\t%s\n", accounts[i].acc_no
        , accounts[i].name);
    }
}

int main() {
    BANKSYS accounts[10];
    int choice;

    printf("****************Welcome to Inhouse Banking system******************\n");

    while (1) {
        printf("\nEnter the choices:\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display details\n");
        printf("5.sort accounts by account number(descending order)\n");
        printf("6. sort accounts by account name(ascending order)\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read_accounts(accounts);
                break;
            case 2:
                deposit(accounts);
                break;
            case 3:
                withdraw(accounts);
                break;
            case 4:
                display_details(accounts);
                break;
            case 5:
                sortaccno(accounts);
            case 6:
                sortname(accounts);
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}





