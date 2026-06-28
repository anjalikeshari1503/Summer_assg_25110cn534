#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "library_data.dat"

// Structure to store book data
struct Book {
    int id;
    char title[100];
    char author[50];
    int is_issued; 
};

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search for a Book");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit Application");
        printf("\n=================================");
        printf("\nEnter choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type. Please enter a number.\n");
            clearBuffer();
            continue;
        }
        clearBuffer(); // Clear the newline left by scanf

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: 
                printf("\nExiting application. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid selection! Please enter a option between 1 and 6.\n");
        }
    }
    return 0;
}

// Safely clear trailing inputs from stdin
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add a record to the binary file
void addBook() {
    struct Book b;
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append-binary mode
    
    if (fp == NULL) {
        printf("\nError opening local database file!\n");
        return;
    }

    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &b.id);
    clearBuffer();

    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; // Strip newline character

    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    b.is_issued = 0; // Default status: Available

    fwrite(&b, sizeof(struct Book), 1, fp);
    fclose(fp);
    
    printf("\nBook recorded successfully!\n");
}

// Function to print all stored records
void displayBooks() {
    struct Book b;
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read-binary mode

    if (fp == NULL) {
        printf("\nNo records found. Please add a book first.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-15s\n", "Book ID", "Title", "Author", "Availability");
    printf("-----------------------------------------------------------------------------\n");

    while (fread(&b, sizeof(struct Book), 1, fp) == 1) {
        printf("%-10d %-30s %-25s %-15s\n", 
               b.id, b.title, b.author, 
               b.is_issued ? "Issued" : "Available");
    }
    fclose(fp);
}

// Function to search records by ID
void searchBook() {
    struct Book b;
    int searchId, found = 0;
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);

    while (fread(&b, sizeof(struct Book), 1, fp) == 1) {
        if (b.id == searchId) {
            printf("\nBook Found!");
            printf("\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n", 
                   b.id, b.title, b.author, b.is_issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) {
        printf("\nBook with ID %d could not be found.\n", searchId);
    }
}

// Function to flag a book as issued (Updates the file)
void issueBook() {
    struct Book b;
    int targetId, found = 0;
    FILE *fp = fopen(FILE_NAME, "r+b"); // Open for read/write in binary

    if (fp == NULL) {
        printf("\nDatabase missing or empty.\n");
        return;
    }

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &targetId);

    while (fread(&b, sizeof(struct Book), 1, fp) == 1) {
        if (b.id == targetId) {
            found = 1;
            if (b.is_issued == 1) {
                printf("\nThis book is already issued to someone else.\n");
            } else {
                b.is_issued = 1;
                // Move file indicator back to rewrite this specific record block
                fseek(fp, -sizeof(struct Book), SEEK_CUR);
                fwrite(&b, sizeof(struct Book), 1, fp);
                printf("\nBook issued successfully!\n");
            }
            break;
        }
    }
    fclose(fp);
    if (!found) printf("\nBook ID not found.\n");
}

// Function to flag an issued book back to available
void returnBook() {
    struct Book b;
    int targetId, found = 0;
    FILE *fp = fopen(FILE_NAME, "r+b");

    if (fp == NULL) {
        printf("\nDatabase missing or empty.\n");
        return;
    }

    printf("\nEnter Book ID to return: ");
    scanf("%d", &targetId);

    while (fread(&b, sizeof(struct Book), 1, fp) == 1) {
        if (b.id == targetId) {
            found = 1;
            if (b.is_issued == 0) {
                printf("\nThis book is already in the stock.\n");
            } else {
                b.is_issued = 0;
                fseek(fp, -sizeof(struct Book), SEEK_CUR);
                fwrite(&b, sizeof(struct Book), 1, fp);
                printf("\nBook returned safely and stock updated!\n");
            }
            break;
        }
    }
    fclose(fp);
    if (!found) printf("\nBook ID not found.\n");
}
