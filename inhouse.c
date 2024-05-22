#include<stdio.h>
#include<stdlib.h>
int i =0;
int initial_accn=123456789;

typedef struct 
{
    char name[100];
    int age;
    int adhaar_no;
    int mobile_no;
    int acc_no;
    float balance;
}BANKSYS;

void read_accounts(BANKSYS accounts[])
 {
    if(i<11)
    {
        printf("Enter details for account %d\n");
        printf("Enter Name : ");
        scanf("%s", accounts[i].name);
        printf("\n");
        getchar();
        printf("Enter age: ");
        scanf("%d", &accounts[i].age);
        printf("\n");
        getchar();
        printf("Enter adhaar no ");
        scanf("%lf", &accounts[i].adhaar_no);
        printf("\n");
        getchar();
        printf("Enter mobile number ");
        scanf("%d",&accounts[i].mobile_no);
        accounts[i].acc_no=initial_accn++;
        i++;
        }
    else
    {
        printf("Max accounts created ");
    }
 }   
 void display_details(BANKSYS accounts[])
{
    printf("User account number: %d \n",accounts[i].acc_no);
    printf("Name of user : %s\n",accounts[i].name);
    printf("Age of user : %s\n",accounts[i].age);
    printf("Mobile number of user : %s\n",accounts[i].mobile_no);
    printf("Aadhar details of user : %s\n",accounts[i].adhaar_no);
    printf("User balance: %d \n",accounts[i].balance);
    
}
void deposit(BANKSYS accounts[])
{
    int temp;
    printf("Enter account number: ");
    scanf("%d", &temp);
    accounts->balance = 0.0;
    

    for(int j = 0; j < i; j++){
        if (accounts[j].acc_no == temp) {
            printf("account number found");
            float amount;
            printf("\nEnter amount to deposit: ");
            scanf("%f", &amount);
    
    if (amount > 0) {
        accounts->balance += amount;
        printf("Deposit successful! New balance: %.2f\n", accounts->balance);
    }
     else {
        printf("Invalid deposit amount.\n");
    }
        }}}

void withdraw(BANKSYS accounts[]) 
{
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    if (scanf("%d", &accountNumber) != 1) {
        printf("Error: Invalid account number input.\n");
    
    }

    for(int j = 0; j < i; j++){
        if (accounts[j].acc_no == accountNumber) {
            printf("Enter amount to withdraw: ");
            if(scanf("%lf", &amount) != 1 || amount <= 0) {
                printf("Error: Withdrawal amount must be a positive number.\n");
                
            }
            if(accounts[i].balance < amount) {
                printf("Error: Insufficient balance.\n");
                
            }
            accounts[i].balance -= amount;
            printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            
            }   
        }  
    }
 
  

int main()
{
    BANKSYS accounts[10];
    int choice;
    printf("****************Welcome to Inhouse Banking system******************\n");
    printf("Enter the choices : \n");
    printf("1.Create account\n");
    printf("2.Deposit\n");
    printf("3.withdraw\n");
    printf("Display details \n");
    fflush(stdin);
    scanf("%d",choice);
    switch(choice)
    {
        case(1):read_accounts(accounts);
        case(2):deposit(accounts);
        case(3):withdraw(accounts);
        case(4):display_details(accounts);
                
    }
}




