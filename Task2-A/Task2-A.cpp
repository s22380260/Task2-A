#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rand(int begin, int end)
{
    srand(time(0));
    return rand() % ((end - begin) + 1) + begin;
}

void mode1()
{
    printf("I've guessed a number in range [1, 1000]. Can you guess it?\n");

    int guess = rand(1, 1000);
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
    printf("Please, guess a number in [1, 1000] and tell the number is (<), (=), (>)\n");

    int guess;
    char ans;
    int begin = 0, end = 1000;

    while (true)
    {
        guess = rand(begin, end);

        printf("My guess is: %d\n", rand(begin, end));

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
    printf("Select mode: ");

    int iMode;
    scanf_s(" %d", &iMode);
    printf("\n");

    switch (iMode)
    {
    case 1:
        mode1();
        break;
    case 2:
        mode2();
        break;
    default:
        printf("Unknown mode\n");
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