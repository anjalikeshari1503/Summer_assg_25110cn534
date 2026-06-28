#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
    int accountNumber;
    char name[50];
    float balance;
};

// Function prototypes
void createAccount(struct BankAccount *acc);
void depositMoney(struct BankAccount *acc);
void withdrawMoney(struct BankAccount *acc);
void checkBalance(struct BankAccount acc);

int main() {
    struct BankAccount account;
    account.accountNumber = 0; // Indicates no account exists initially
    account.balance = 0.0;
    
    int choice;

    do {
        printf("\n=== Bank Management System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&account);
                break;
            case 2:
                depositMoney(&account);
                break;
            case 3:
                withdrawMoney(&account);
                break;
            case 4:
                checkBalance(account);
                break;
            case 5:
                printf("\nExiting system. Thank you!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void createAccount(struct BankAccount *acc) {
    printf("\nEnter Account Number: ");
    scanf("%d", &acc->accountNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", acc->name); // Reads string with spaces
    printf("Enter Initial Deposit: ");
    scanf("%f", &acc->balance);
    printf("\nAccount created successfully for %s!\n", acc->name);
}

void depositMoney(struct BankAccount *acc) {
    if (acc->accountNumber == 0) {
        printf("\nPlease create an account first!\n");
        return;
    }
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        acc->balance += amount;
        printf("Successfully deposited $%.2f. New Balance: $%.2f\n", amount, acc->balance);
    } else {
        printf("Invalid amount. Deposit must be greater than 0.\n");
    }
}

void withdrawMoney(struct BankAccount *acc) {
    if (acc->accountNumber == 0) {
        printf("\nPlease create an account first!\n");
        return;
    }
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("Successfully withdrawn $%.2f. New Balance: $%.2f\n", amount, acc->balance);
    } else if (amount > acc->balance) {
        printf("Insufficient balance.\n");
    } else {
        printf("Invalid amount. Withdrawal must be greater than 0.\n");
    }
}

void checkBalance(struct BankAccount acc) {
    if (acc.accountNumber == 0) {
        printf("\nPlease create an account first!\n");
        return;
    }
    printf("\nAccount Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.name);
    printf("Available Balance: $%.2f\n", acc.balance);
}