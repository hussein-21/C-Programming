#include <stdio.h>

// Function prototypes
int inputDeposit(int currentbalance);
int inputWithdrawal(int currentbalance);
int displayBalance(int currentbalance);
char displaymenu();

int main() {
    int currentbalance = 0;
    char choice, anothertransaction;

    do {
        // Display the menu and get user's choice
        choice = displaymenu();

        // Process the user's choice using a switch statement
        switch (choice) {
            case 'D':
            case 'd':
                // If deposit, call inputDeposit and update the balance
                currentbalance += inputDeposit(currentbalance);
                break;

            case 'W':
            case 'w':
                // If withdrawal, call inputWithdrawal and update the balance
                currentbalance -= inputWithdrawal(currentbalance);
                break;

            case 'B':
            case 'b':
                // If display balance, call displayBalance
                displayBalance(currentbalance);
                break;

            case 'Q':
            case 'q':
                // If quit, display a thank you message
                printf("Thank you.\n");
                break;

            default:
                // If an invalid choice, display an error message
                printf("Invalid choice.\n");
                break;
        }

        // Ask if the user wants to perform another transaction
        printf("Would you like to make another transaction? (Y/N): ");
        scanf(" %c", &anothertransaction);

    } while (anothertransaction == 'Y' || anothertransaction == 'y');

    // Display a thank you message before exiting
    printf("Thank you.\n");
    return 0;
}

int inputDeposit(int currentbalance) {
    int depositamount;
    // Prompt user for deposit amount and read input
    printf("Enter deposit amount: ");
    scanf("%d", &depositamount);
    return depositamount; // Return the entered deposit amount
}

int inputWithdrawal(int currentbalance) {
    int withdrawamount;
    // Prompt user for withdrawal amount and read input
    printf("Enter withdrawal amount: ");
    scanf("%d", &withdrawamount);
    return withdrawamount; // Return the entered withdrawal amount
}

int displayBalance(int currentbalance) {
    // Display the current balance to the user
    printf("Your current balance is: %d\n", currentbalance);
    return currentbalance;
}

char displaymenu() {
    char choice;
    // Display the menu options and prompt user for choice
    printf("\nWelcome to HFC Federal Credit Union!\n");
    printf("Please select from the following menu:\n");
    printf("D: Make a deposit\n");
    printf("W: Make a withdrawal\n");
    printf("B: Check your account balance\n");
    printf("Q: To quit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    return choice; // Return the user's choice
}
