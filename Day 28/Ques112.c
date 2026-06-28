#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store a single contact's records
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

const char* FILE_NAME = "contacts.dat";

// Function Prototypes
void addContact();
void listContacts();
void searchContact();
void deleteContact();
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store a single contact's records
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

const char* FILE_NAME = "contacts.dat";

// Function Prototypes
void addContact();
void listContacts();
void searchContact();
void deleteContact();
void listContacts() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo contact logs found. Add a contact first!\n");
        return;
    }

    struct Contact c;
    printf("\n==================== SAVED CONTACTS ====================\n");
    printf("%-25s %-15s %-25s\n", "Name", "Phone", "Email");
    printf("--------------------------------------------------------\n");

    while (fread(&c, sizeof(struct Contact), 1, file) == 1) {
        printf("%-25s %-15s %-25s\n", c.name, c.phone, c.email);
    }
    printf("========================================================\n");
    fclose(file);
}
void searchContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo contacts to search!\n");
        return;
    }

    char searchName[50];
    struct Contact c;
    int found = 0;

    printf("\nEnter the exact name to search: ");
    scanf(" %[^\n]", searchName);

    while (fread(&c, sizeof(struct Contact), 1, file) == 1) {
        // Use strcasecmp for Unix/Linux or stricmp for Windows
        if (strcasecmp(c.name, searchName) == 0) { 
            printf("\n--- Contact Found ---\n");
            printf("Name : %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            printf("Email: %s\n", c.email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo matching contact entry matches '%s'.\n", searchName);
    }
    fclose(file);
}
void deleteContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo contacts found to perform deletions!\n");
        return;
    }

    char targetName[50];
    struct Contact c;
    int found = 0;

    printf("\nEnter name of the contact to delete: ");
    scanf(" %[^\n]", targetName);

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("System file handling error!\n");
        fclose(file);
        return;
    }

    while (fread(&c, sizeof(struct Contact), 1, file) == 1) {
        if (strcasecmp(c.name, targetName) == 0) {
            found = 1; // Skip writing this entry to drop it
        } else {
            fwrite(&c, sizeof(struct Contact), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);
        printf("\nContact successfully removed!\n");
    } else {
        remove("temp.dat"); // Clear the temporary file
        printf("\nNo contact matching '%s' was found.\n", targetName);
    }
}
int main() {
    int choice;

    while (1) {
        printf("\n*** CONTACT MANAGEMENT SYSTEM ***\n");
        printf("1. Add New Contact\n");
        printf("2. List All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit Application\n");
        printf("Select an action (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection. Terminating application.\n");
            break;
        }

        switch (choice) {
            case 1: addContact(); break;
            case 2: listContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("\nExiting system... Goodbye!\n"); exit(0);
            default: printf("\nInvalid selection! Choose between 1 and 5.\n");
        }
    }
    return 0;
}