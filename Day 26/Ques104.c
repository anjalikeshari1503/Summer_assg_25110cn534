#include <stdio.h>
#include <string.h>

int main()
{
    char questions[5][200] =
    {
        "Q1. What is the capital of India?\n   a) Mumbai  b) Delhi  c) Kolkata  d) Chennai",
        "Q2. Which of the following is the programming language?\n   a) HTML  b) HTTP c) Java d) JPEG",
        "Q3. How many days in a leap year?\n   a) 365  b) 366  c) 364  d) 367",
        "Q4. What is 8 x 7?\n   a) 54  b) 56  c) 58  d) 60",
        "Q5. Which planet is closest to Sun?\n   a) Earth  b) Venus  c) Mercury  d) Mars"
    };

    char answers[5] = {'b', 'c', 'b', 'b', 'c'};
    char userAnswer;
    int score = 0;
    int i;

    printf("=== Welcome to the Quiz Application ===\n\n");

    for (i = 0; i < 5; i++)
    {
        printf("%s\n", questions[i]);
        printf("Your answer: ");
        scanf(" %c", &userAnswer);

        if (userAnswer == answers[i])
        {
            printf("Correct!\n\n");
            score++;
        }
        else
        {
            printf("Wrong! Correct answer is '%c'\n\n", answers[i]);
        }
    }

    printf("=== Quiz Over ===\n");
    printf("Your Score = %d / 5\n", score);

    if (score == 5)
    {
        printf("Excellent! Perfect score!\n");
    }
    else if (score >= 3)
    {
        printf("Good job! Keep it up.\n");
    }
    else
    {
        printf("Better luck next time!\n");
    }

    return 0;
}