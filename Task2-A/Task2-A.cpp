#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rand_number(int begin, int end)
{
    srand(time(0));
    return rand() % ((end - begin) + 1) + begin;
}

void mode1()
{
    printf("\nI've guessed a number in range [1, 1000]. Can you guess it?\n");

    int guess = rand_number(1, 1000);
    int ans;

#ifdef _DEBUG
    printf(" => %d\n", guess);
#endif

    while (true)
    {
        scanf_s(" %d", &ans);

        if (ans == guess)
        {
            printf("You've won!\n");
            break;
        }
        else if (ans < guess)
        {
            printf("I guessed a higher number (<)\n");
        }
        else
        {
            printf("I guessed a lower number (<)\n");
        }
    }
}

void mode2()
{
    printf("\nPlease, guess a number in [1, 1000] and tell the number is (<), (=), (>)\n");

    int guess;
    char ans;
    int begin = 0, end = 1000;

    while (true)
    {
        guess = rand_number(begin, end);

        printf("My guess is: %d\n", guess);

        scanf_s(" %c", &ans);

        if (ans == '=')
        {
            printf("I've won!\n");
            break;
        }
        else if (ans == '<')
        {
            end = guess;
        }
        else if (ans == '>')
        {
            begin = guess;
        }
        else
        {
            printf("Unsupported symbol\n");
        }
    }
}

void bootstrap()
{
    printf("\nSelect mode: ");

    int mode;
    scanf_s(" %d", &mode);
    printf("\n");

    switch (mode)
    {
    case 1:
        mode1();
        break;
    case 2:
        mode2();
        break;
    default:
        printf("Unknown mode\n");
        bootstrap();
        break;
    }
}

int main()
{
    printf("Task 2 - Guess a number\n");
    printf("Available modes:\n");
    printf(" 1 - I will come up with a number and you'll guess it\n");
    printf(" 2 - I will guess a number which you've guessed\n");
    
    bootstrap();
}
