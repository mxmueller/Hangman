#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
// outsourced text messages and ascii art
#include "resources/messages.c"
#include "resources/ascii.c"

// config
const int max_length = 15;
const int max_lives = 10;

char input[max_length];

struct Node
{
    char value[max_length];
    struct Node *next;
};

struct Node *head = NULL;

typedef struct
{
    char wanted_word[max_length];
    int word_length;
    int remaining_lives;
    int attempts;
} Meta;

Meta Runtime; // ? == getter

Meta reset(Meta *runtime)
{
    strcpy(runtime->wanted_word, "");
    runtime->word_length = 0;
    runtime->remaining_lives = 0;
    runtime->attempts = 0;
    return *runtime;
}

Meta set(Meta *runtime, char *ww, int wl, int rl, int a)
{
    strcpy(runtime->wanted_word, ww);
    runtime->word_length = wl;
    runtime->remaining_lives = rl;
    runtime->attempts = a;
    return *runtime;
}

Meta get()
{
    return Runtime;
}

void insertIntoNode(struct Node **head_ref, char new_value[max_length])
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(new_node->value, new_value);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(struct Node **head_ref, char key[max_length])
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->value == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->value != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void printNode(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %s ", node->value);
        node = node->next;
    }
}

int searchNode(struct Node **head_ref, char key[max_length])
{
    struct Node *current = *head_ref;

    while (current != NULL)
    {
        if (strcmp(current->value, key) == 0)
            return 1;
        current = current->next;
    }
    return 0;
}

void clear_screen()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

void pressEnterToContinue(void)
{
    fflush(stdout);
    getchar();
}

void flush(FILE *in)
{
    int ch;
    do
    {
        ch = fgetc(in);
    } while (ch != EOF && ch != '\n');
    clearerr(in);
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
    flush(stdin);
    pressEnterToContinue();
}

void dashboard()
{
    printf("\n");
    puts(ascii_divider[0]);
    printf("\n");
    printf("%s", status_messages[4]);
    printf("%d", get().word_length);
    printf("\n");
    printf("%s", status_messages[9]);

    for (size_t i = 0; i < get().word_length; i++)
    {
        printf("%s", "_ ");
        if (i == get().word_length - 1)
        {
            printf("\n\n");
        }
    }

    printf("%s", status_messages[10]);
    printf("%d", get().attempts);
    printf("\n");
    printf("%s", status_messages[11]);
    printf("%d", get().remaining_lives);
    printf("\n \n");
    puts(ascii_divider[0]);
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
            if (getchar() == '\n') // enter
            {
                // ! game starts here:
                clear_screen();

                reset(&Runtime);
                set(&Runtime, "Dienstag", 7, 10, 0);
                //void sequence();
                //sequence();
                break;
            }
        }
        return 0;
    }
    return 0;
}

char *getAndFilterInput()
{
    printf("%s", "Eingabe: ");
    scanf("%s", input);
    int il; // * == input_length
    il = 0;

    for (int s = 0; s < strlen(input); s++)
    {
        if (input[s] == ' ')
        {
            puts("Error1leer\n");
            break;
        }
        if (!isalpha(input[s]))
        {
            strcpy(input, "\0");
        }
        il++;
    }

    if (il == 1 &&
        il < 2 &&
        il > 0 &&
        il != ' ')
    {
        int i;
        for (i = 0; input[i] != '\0'; i++)
        {
            if (input[i] >= 'a' && input[i] <= 'z')
            {
                input[i] = input[i] - 32;
            }
        }
    }

    if (il >= 2)
    {
        strcpy(input, "\0");
    }



    return input;
}

void sequence()
{
    dashboard();

    char callback[max_length];
    strcpy(callback, getAndFilterInput());

    clear_screen();

    if (*callback == 0)
    {
        puts("Bitte nur einen Buchstaben eingeben");
        puts("Bitte erneut versuchen.");
    }
    else if (searchNode(&head, callback))
    {
        puts("Berreits vorhanden");
        puts("Bitte erneut versuchen.");
    }
    else
    {
        puts("Eingabe erfolgreich!");
        insertIntoNode(&head, callback);

        printf("List: ");
        printNode(head);
        printf("%s", "\n");
    }

    flush(stdin);
    pressEnterToContinue();
    clear_screen();
    sequence();
}