#include <stdio.h>
#include <stdlib.h>

int i = 0;
int initial_accn = 12345678;

typedef struct {
    char name[100];
    int age;
    int adhaar_no;
    int mobile_no;
    int acc_no;
    float balance;
} BANKSYS;

void read_accounts(BANKSYS accounts[]) {
    if (i < 10) { // Maximum of 10 accounts
        printf("Enter details for account %d\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", accounts[i].name);
        printf("Enter age: ");
        scanf("%d", &accounts[i].age);
        printf("Enter Aadhaar number: ");
        scanf("%d", &accounts[i].adhaar_no);
        printf("Enter mobile number: ");
        scanf("%d", &accounts[i].mobile_no);
        accounts[i].acc_no = initial_accn++;
        accounts[i].balance = 0.0;
        i++;
        printf("Account created successfully! Your account number is %d\n", accounts[i - 1].acc_no);
    } else {
        printf("Max accounts created.\n");
    }
}

void display_details(BANKSYS accounts[], int acc_index) {
    printf("User account number: %d\n", accounts[acc_index].acc_no);
    printf("Name of user: %s\n", accounts[acc_index].name);
    printf("Age of user: %d\n", accounts[acc_index].age);
    printf("Mobile number of user: %d\n", accounts[acc_index].mobile_no);
    printf("Aadhaar details of user: %d\n", accounts[acc_index].adhaar_no);
    printf("User balance: %.2f\n", accounts[acc_index].balance);
}

void deposit(BANKSYS accounts[]) {
    int temp;
    printf("Enter account number: ");
    scanf("%d", &temp);

    for (int j = 0; j < i; j++) {
        if (accounts[j].acc_no == temp) {
            printf("Enter amount to deposit: ");
            float amount;
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
    printf("Account not found.\n");
}

void withdraw(BANKSYS accounts[]) {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    if (scanf("%d", &accountNumber) != 1) {
        printf("Error: Invalid account number input.\n");
        return;
    }

    for (int j = 0; j < i; j++) {
        if (accounts[j].acc_no == accountNumber) {
            printf("Enter amount to withdraw: ");
            if (scanf("%lf", &amount) != 1 || amount <= 0) {
                printf("Error: Withdrawal amount must be a positive number.\n");
                return;
            }
            if (accounts[j].balance < amount) {
                printf("Error: Insufficient balance.\n");
                return;
            }
            accounts[j].balance -= amount;
            printf("Withdrawal successful! New balance: %.2f\n", accounts[j].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    BANKSYS accounts[10];
    int choice;
    
    while (1) {
        printf("\n****************Welcome to Inhouse Banking system******************\n");
        printf("Enter the choices:\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }

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
            case 4: {
                int acc_no;
                printf("Enter account number to display details: ");
                scanf("%d", &acc_no);
                int found = 0;
                for (int j = 0; j < i; j++) {
                    if (accounts[j].acc_no == acc_no) {
                        display_details(accounts, j);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Account not found.\n");
                }
                break;
            }
            case 5:
                printf("Exiting the system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
