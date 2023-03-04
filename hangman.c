
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LEN 20

char *words[MAX_WORDS] = {"apple", "banana", "cherry", "date", "elderberry",
                          "fig", "grape", "honeydew", "kiwi", "lemon"};

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Select a random word from the list
    int idx = rand() % MAX_WORDS;
    char *word = words[idx];
    int len = strlen(word);

    // Create a buffer to store the current state of the word
    char buffer[MAX_WORD_LEN];
    memset(buffer, '_', len);
    buffer[len] = '\0';

    // Initialize the number of guesses
    int num_guesses = 0;

    // Start the game loop
    while (1)
    {
        // Print the current state of the word
        printf("Word: %s\n", buffer);

        // Ask the user to guess a letter
        printf("Guess a letter: ");
        char guess;
        scanf(" %c", &guess);

        // Check if the letter is in the word
        int found = 0;
        for (int i = 0; i < len; i++)
        {
            if (word[i] == guess)
            {
                buffer[i] = guess;
                found = 1;
            }
        }

        // Increment the number of guesses
        num_guesses++;

        // Check if the game is over
        if (strcmp(buffer, word) == 0)
        {
            printf("Congratulations, you won!\n");
            break;
        }
        else if (num_guesses == 6)
        {
            printf("Sorry, you lost! The word was %s.\n", word);
            break;
        }

        // Print the hangman
        switch (num_guesses)
        {
        case 1:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 2:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 3:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 4:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 5:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 6:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        default:
            break;
        }

        // Print a newline to separate the hangman from the next prompt
        printf("\n");

        // If the letter was not found, inform the user
        if (!found)
        {
            printf("Sorry, '%c' is not in the word.\n", guess);
        }
    }

    return 0;
}