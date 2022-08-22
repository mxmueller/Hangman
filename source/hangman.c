#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
// outsourced text messages and ascii art
#include "resources/messages.c"
#include "resources/ascii.c"

void clear_screen()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

char *gen_word()
{
    char *demo, *gen;
    demo = "Samstag";
    gen = demo;
    return gen;
}

int mesure_word(const char *w)
{
    return strlen(w);
}

// & messages to interact with user
void publish_opening()
{
    printf("%s", status_messages[0]);
    printf("%s", status_messages[1]);
    printf("%s", status_messages[0]);

    sleep(1);
    clear_screen();

    printf("%s", ascii_headline_part[0]);
    printf("%s", ascii_headline_part[1]);
    printf("%s", ascii_headline_part[2]);
    printf("%s", ascii_headline_part[3]);
    printf("%s", ascii_headline_part[4]);
    printf("%s", ascii_headline_part[5]);
    printf("%s", ascii_headline_part[6]);
    printf("%s", ascii_headline_part[7]);

    printf("%s", credit_messages[0]);
    printf("%s", credit_messages[1]);

    printf("%s", status_messages[8]);
}

int publish_new_game(l)
{
    void publish_hangman_status();

    printf("\n");
    printf("%s", status_messages[4]);
    printf("%d", l);
    printf("\n");
    printf("%s", status_messages[9]);

    for (size_t i = 0; i < l; i++)
    {
        printf("%s", "_ ");
        if (i == l - 1)
        {
            printf("\n\n");
        }
    }
    return 1;
}

void publish_dashboard(l, t)
{
    printf("%s", status_messages[10]);
    printf("%d", l);
    printf("\n");
    printf("%s", status_messages[11]);
    printf("%d", t);
    printf("\n");
}

void publish_hangman_status(s)
{
    void print_straight_lines();

    // * 10 possible outcomes, because player has 10 lives.
    // * So each state/case gives a different ascii art.
    // * (Starts with 10, if the there is only one left player loses)

    if (s <= 7)
    {
        printf("%s", ascii_hangman_part[0]);
    }

    switch (s)
    {
    case 0:
        printf("%s", ascii_hangman_part[1]);
        printf("%s", ascii_hangman_part[3]);
        printf("%s", ascii_hangman_part[5]);
        printf("%s", ascii_hangman_part[7]);
        print_straight_lines(1);
        break;
    case 1:
        printf("%s", ascii_hangman_part[1]);
        printf("%s", ascii_hangman_part[3]);
        printf("%s", ascii_hangman_part[5]);
        printf("%s", ascii_hangman_part[6]);
        print_straight_lines(1);
        break;
    case 2:
        printf("%s", ascii_hangman_part[1]);
        printf("%s", ascii_hangman_part[3]);
        printf("%s", ascii_hangman_part[5]);
        print_straight_lines(2);
        break;
    case 3:
        printf("%s", ascii_hangman_part[1]);
        printf("%s", ascii_hangman_part[3]);
        printf("%s", ascii_hangman_part[4]);
        print_straight_lines(2);
        break;
    case 4:
        printf("%s", ascii_hangman_part[1]);
        printf("%s", ascii_hangman_part[3]);
        printf("%s", ascii_hangman_part[1]);
        print_straight_lines(2);
        break;
    case 5:
        printf("%s", ascii_hangman_part[1]);
        printf("%s", ascii_hangman_part[3]);
        print_straight_lines(3);

        break;
    case 6:
        printf("%s", ascii_hangman_part[1]);
        print_straight_lines(4);
        break;
    case 7:
        print_straight_lines(5);
        break;
    case 8:
        print_straight_lines(5);
        break;
    case 9:

        break;
    default:
        printf("%s", error_messages[2]);
        break;
    }

    if (s <= 10)
    {
        printf("%s", ascii_hangman_part[8]);
    }
}

void print_straight_lines(n) // helper
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%s", ascii_hangman_part[2]);
    }
}

int main()
{
    const char *word = gen_word();
    const int length = mesure_word(word);

    if (load_status_messages() &&
        load_error_messages() &&
        load_credit_messages() &&
        load_ascii_art())
    {
        publish_opening();
        while (1)
        {
            if (getchar() == '\n')
            {
                printf("%s", status_messages[2]);
                sleep(2);
                clear_screen();

                // & start game
                if (publish_new_game(length))
                {
                    publish_dashboard(10, 0);
                    char input[150];
                    scanf("%s", input);                
                    }
                break;
            }
        }
        return 0;
    }
    return 0;
}
