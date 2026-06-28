#include <stdio.h>
int main (){
    int choice ;
    float balance =10000.0 ,amount ;
    do{
        printf("\n==ATM MENU==\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money \n");
        printf("4. EXIT\n");

        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Current Balance:%.2f\n",balance);
                    break ;

            case 2: printf("Enter amount to deposit :");
                    scanf("%f",&amount);
                    balance += amount ;
                    printf("Rs.%.2f deposited successfully.\n",amount);
                    printf("Total balance in your account is %.2f",balance);
                    break ;

            case 3 : printf("Enter the amount to withdraw :");
                     scanf("%f",&amount);
                     if(amount<=balance){
                        balance-= amount ;
                        printf("Please collect your cash\n");
                        printf("Remaining balance:Rs.%.2f\n",balance);
                     }
                     else{
                        printf("Insufficient balance.\n");
                     }        
                     break ;

            case 4: printf("Thank you for using ATM.\n");
                    break ;
             
            default : printf("Invalid choice . Please try again.\n");        

        }

    }while (choice!=4);
    return 0;
}