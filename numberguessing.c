#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lower = 1, upper = 100; // Define fixed lower and upper bounds
    int x, guess, count = 0, flag = 0;
    int total_chances;

    // Randomly generate the target number
    srand(time(0));
    x = (rand() % (upper - lower + 1)) + lower;

    // Calculate the total chances allowed
    total_chances = (int)ceil(log(upper - lower + 1) / log(2));

    printf("\n\tYou've only %d chances to guess the "
           "integer!\n\n",
           total_chances);

    // Automated guesses in a fixed sequence
    for (guess = lower; count < total_chances; count++) {
        printf("Try %d: Guess = %d\n", count + 1, guess);

        if (x == guess) {
            printf(
                "Congratulations! You found the number %d in %d tries!\n",
                x, count + 1);
            flag = 1;
            break;
        }
        else if (x > guess) {
            printf("You guessed too small!\n");
            guess++; // Increment the guess for the next iteration
        }
        else if (x < guess) {
            printf("You guessed too high!\n");
            guess--; // Decrement the guess for the next iteration
        }
    }

    if (!flag) {
        printf("\nThe number was %d\n", x);
        printf("\tBetter Luck Next Time!\n");
    }

    return 0;
}