#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

int main() {
    char words[MAX_WORDS][MAX_LENGTH];
    char temp[MAX_LENGTH];
    int n;

    //  Get the number of words from the user
    printf("Enter the number of words to sort: ");
    if (scanf("%d", &n) != 1 || n > MAX_WORDS) {
        printf("Invalid number of words.\n");
        return 1;
    }
    //  Read the words using scanf
    printf("Enter %d words (separated by spaces or enters):\n", n);
    for (int i = 0; i < n; i++) {
        // %49s prevents the buffer overfow for MAX_LENGTH of 50 
        scanf("%49s", words[i]); 
    }

    //  Sort the words by length using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare lengths of adjacent words
            if (strlen(words[j]) > strlen(words[j + 1])) {
                // Swap the words using strcpy
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
    //  Print the sorted list
    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

