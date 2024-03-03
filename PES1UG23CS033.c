/*CASE STUDY 1- Create  a banking application which accepts customer information  */
#include <stdio.h>
#include <math.h>
int main(){


    unsigned long long int adhaar_number;
    unsigned long long int phone_number;
    char name[100];
    unsigned long long int account_number;
    float balance = 0.00 ;
    unsigned long long int account_numberincr;
    int amount;
    int choice;

    printf("---------------Welcome To PES BANK OF PES----------------------------\n");

    printf("Enter your name :");
    scanf("%s",&name);

    printf("\nEnter your phone number:");
    scanf("%llu",&phone_number);

    printf("\nEnter your adhaar number :");
    scanf("%llu",&adhaar_number);

    account_numberincr = 1234567890;
    account_number=account_numberincr++;

    printf("Acoount crated and account number is : %llu\n",account_number);

  

    do
    {
        printf("1.Deposit\n2.Withdrw\n3.print details\n4.exit\n");
        scanf("\n%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the amount to be deposited\n");
            scanf("%d",&amount);
            if (amount>0)
            {
                balance=balance+amount;
                printf("%d amount deposited successfuly and new balance is %.2f\n",amount,balance);
            }
            else
            {
                printf("Invalid amount entered\n");
            }
            break;
        
        case 2:
            printf("Enter the amount to be witdrawn\n");
            scanf("%d",&amount);
            if (amount>balance)
            {
                printf("Inscufficient balance");
            }
            else
            {
                balance= balance-amount;
                printf("%d amount has been succesfully withdrawn and the balance remaining is %.2f\n",amount,balance);
            }
            break;
        case 3:
            printf("Acocunt number : %llu\nName : %s\nPhone number : %llu\nAdhaar Number : %llu\nBalance: %.2f\n",account_number,name,phone_number,adhaar_number,balance);
            break;
        case 4 :
            printf("Thnak You for Using me ! \n");
            break;
        default:
            printf("Invalid input\n");
            break;
        }
}while (choice!=4);
}

