#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (){
    int secret_number, guess ,attempts=0 ;
    // Initialize random number generator 
    srand(time(0));
    // Generate a random number between 1 to 100 
    secret_number = rand() % 100 + 1;
    printf("Welcome to the Number Guesing Game.\n");
    printf("Guess a number between 1 to 100 .\n");
    do {
        printf("Enter your guess.\n");
        scanf("%d",&guess);
        attempts ++ ;
    
    if(guess < secret_number){
        printf("Your guess is Too Low! Try Again.\n");
    }
    else if (guess > secret_number){
        printf("Tour guess is Too High! Try Again.\n");
    }
        else{
            printf("Congratulations!You guessed correctly in %d attempts.",attempts);
        }
    }
    while(secret_number!=guess);
    return 0;

}