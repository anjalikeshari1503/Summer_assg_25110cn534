#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function prototypes
void displayMenu();
void clearScreen();
void getString(char *str, const char *prompt);
void reverseString(char *str);
void concatenateStrings();
void compareStrings();
void copyString();
void stringLength();

int main() {
    int choice;
    char str1[MAX_LEN];

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }
        // Consume newline character left in buffer
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                getString(str1, "Enter a string to find its length: ");
                printf("Length of the string: %zu\n", strlen(str1));
                break;
            case 2:
                copyString();
                break;
            case 3:
                concatenateStrings();
                break;
            case 4:
                compareStrings();
                break;
            case 5:
                getString(str1, "Enter a string to reverse: ");
                reverseString(str1);
                printf("Reversed string: %s\n", str1);
                break;
            case 6:
                printf("Exiting String OS. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar(); 
    }
    return 0;
}

// Windows-specific screen clearing
void clearScreen() {
    system("cls");
}

// Displays the Main Menu
void displayMenu() {
    clearScreen();
    printf("===================================\n");
    printf("       STRING OPERATING SYSTEM     \n");
    printf("===================================\n");
    printf("1. Find String Length\n");
    printf("2. Copy String\n");
    printf("3. Concatenate Strings\n");
    printf("4. Compare Strings\n");
    printf("5. Reverse String\n");
    printf("6. Check Palindrome\n");
    printf("7. Exit\n");
    printf("===================================\n");
}

// Safely reads a string including spaces
void getString(char *str, const char *prompt) {
    printf("%s", prompt);
    fgets(str, MAX_LEN, stdin);
    // Remove trailing newline character if present
    str[strcspn(str, "\n")] = '\0';
}

// Copies one string to another
void copyString() {
    char source[MAX_LEN], destination[MAX_LEN];
    getString(source, "Enter the source string: ");
    strcpy(destination, source);
    printf("Source String: %s\n", source);
    printf("Copied String: %s\n", destination);
}

// Concatenates two strings
void concatenateStrings() {
    char str1[MAX_LEN * 2], str2[MAX_LEN];
    getString(str1, "Enter the first string: ");
    getString(str2, "Enter the second string: ");
    strcat(str1, str2);
    printf("Concatenated Result: %s\n", str1);
}

// Compares two strings
void compareStrings() {
    char str1[MAX_LEN], str2[MAX_LEN];
    getString(str1, "Enter the first string: ");
    getString(str2, "Enter the second string: ");
    int result = strcmp(str1, str2);
    
    if (result == 0) {
        printf("Both strings are identical.\n");
    } else if (result > 0) {
        printf("The first string is lexicographically larger.\n");
    } else {
        printf("The second string is lexicographically larger.\n");
    }
}

// Reverses a string in-place
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

