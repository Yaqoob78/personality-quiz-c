#include <stdio.h>

int main()
{
    char name[100];
    char choice, choice2, choice3;

    printf("Hi!\n");
    printf("Enter your name: ");
    scanf("%s", name);  // gets name
    getchar(); // consume leftover newline from previous input

    printf("\nYou seem excited! Be careful, I will reveal something about you.\n");
    printf("Let's begin with a few questions.\n\n");

    printf("Choose a number:\n"
           "a - 3\n"
           "b - 7\n"
           "c - 9\n"
           "d - 11\n"
           "Enter your choice: ");
    scanf(" %c", &choice);  // space before %c handles any leftover newline

    printf("\nPick a place:\n"
           "a - Beach\n"
           "b - Forest\n"
           "c - City\n"
           "d - Mountain\n"
           "Enter your choice: ");
    scanf(" %c", &choice2); // same fix

    printf("\nPick one:\n"
           "a - Fight a horse-sized duck\n"
           "b - Fight 100 duck-sized horses\n"
           "c - Be invisible in school\n"
           "d - Wake up with duck voice\n"
           "Enter your choice: ");
    scanf(" %c", &choice3); // same fix

    printf("\n");

    // Decision logic
    if (choice == 'a' && choice2 == 'a' && choice3 == 'a')
    {
        printf("You are extrovert, who loves attention and likes to be around people. Feel depressed when alone.\n");
    }
    else if (choice == 'b' && choice2 == 'b' && choice3 == 'b')
    {
        printf("You are a deep thinker, like to stay alone, feel uncomfortable in crowd and like to stay alone.\n");
    }
    else if (choice == 'c' && choice2 == 'c' && choice3 == 'c')
    {
        printf("You are a funny person, you love entertainment & like to be playful, chill behaviour.\n");
    }
    else if (choice == 'd' && choice2 == 'd' && choice3 == 'd')
    {
        printf("You are a paradox — feel something but show something else. You fear a lot of things.\n");
    }
    else if (choice == 'b' && choice2 == 'b' && choice3 == 'c')
    {
        printf("You are the thoughtful introvert, like to observe, dream about a lot of things.\n");
    }
    else if (choice == 'b' && choice2 == 'a' && choice3 == 'd')
    {
        printf("You try to be funny, take a lot of tension & think a lot about yourself.\n");
    }
    else if (choice == 'c' && choice2 == 'b' && choice3 == 'c')
    {
        printf("You are a mystic thinker, deep down want meaning and peace, you like nature and travelling.\n");
    }
    else if (choice == 'a' && choice2 == 'a' && choice3 == 'c')
    {
        printf("You are a silent storm. You are misunderstood but clever, also a little bit selfish.\n");
    }
    else if (choice == 'b' && choice2 == 'b' && choice3 == 'd')
    {
        printf("You are a meme genius — try to lighten the environment and make people happy, but deep down think a lot about yourself.\n");
    }
    else if (choice == 'a' && choice2 == 'b' && choice3 == 'c')
    {
        printf("You are an escape artist — try to do things hiding from others, very clever.\n");
    }
    else if (choice == 'c' && choice2 == 'a' && choice3 == 'd')
    {
        printf("You are unexpected — love animals and like to play games.\n");
    }
    else if (choice == 'd' && choice2 == 'b' && choice3 == 'c')
    {
        printf("You are a dark horse but clever as a fox — you think logically.\n");
    }
    else if (choice == 'b' && choice2 == 'c' && choice3 == 'd')
    {
        printf("You are wild energy — love nature, humorous and sharp, but sometimes lazy.\n");
    }
    else if (choice == 'a' && choice2 == 'd' && choice3 == 'b')
    {
        printf("You’re not going with the usual picks — I like that! You’re trying to be unique. Keep things interesting!\n");
    }
    else
    {
        printf("Interesting combination! You're unique.\n");
    }

    return 0;
}
