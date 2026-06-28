#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 5

// Structure to hold ticket information
struct Ticket {
    int ticketId;
    char passengerName[50];
    int row;
    int col;
};

// Global seat map matrix (0 = Available, 1 = Booked)
int seats[ROWS][COLS] = {0};
int ticketCounter = 1000;

// Function Prototypes
void displaySeats();
void bookTicket();
void cancelTicket();

int main() {
    int choice;

    while (1) {
        printf("\n===== TICKET BOOKING SYSTEM =====\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Exit System\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                printf("Exiting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

// Function to display the grid layout of seats
void displaySeats() {
    printf("\n--- SEAT LAYOUT ([0] = Free, [X] = Booked) ---\n   ");
    for (int j = 0; j < COLS; j++) {
        printf(" Col%d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("Row%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 0) {
                printf("[ 0 ]  ");
            } else {
                printf("[ X ]  ");
            }
        }
        printf("\n");
    }
}

// Function to process a new ticket reservation
void bookTicket() {
    struct Ticket newTicket;
    int targetRow, targetCol;

    printf("\nEnter Passenger Name: ");
    scanf(" %[^\n]s", newTicket.passengerName); // Reads string with spaces

    displaySeats();

    printf("Enter Row Number (1-%d): ", ROWS);
    scanf("%d", &targetRow);
    printf("Enter Column Number (1-%d): ", COLS);
    scanf("%d", &targetCol);

    // Convert from 1-based index to 0-based index
    int r = targetRow - 1;
    int c = targetCol - 1;

    // Validation boundary checks
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
        printf("Error: Invalid seat selection.\n");
        return;
    }

    if (seats[r][c] == 1) {
        printf("Error: Seat is already occupied!\n");
    } else {
        seats[r][c] = 1; // Mark as booked
        newTicket.ticketId = ++ticketCounter;
        newTicket.row = targetRow;
        newTicket.col = targetCol;

        printf("\n Booking Successful!\n");
        printf("Passenger: %s\n", newTicket.passengerName);
        printf("Ticket ID: %d\n", newTicket.ticketId);
        printf("Assigned Seat: Row %d, Col %d\n", newTicket.row, newTicket.col);
    }
}

// Function to cancel an existing reservation
void cancelTicket() {
    int targetRow, targetCol;
    
    printf("\nEnter the Row of the ticket to cancel: ");
    scanf("%d", &targetRow);
    printf("Enter the Column of the ticket to cancel: ");
    scanf("%d", &targetCol);

    int r = targetRow - 1;
    int c = targetCol - 1;

    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
        printf("Error: Invalid seat location.\n");
        return;
    }

    if (seats[r][c] == 0) {
        printf("Notice: This seat is already empty.\n");
    } else {
        seats[r][c] = 0; // Free up seat
        printf("Success: Booking at Row %d, Col %d has been canceled.\n", targetRow, targetCol);
    }
}
