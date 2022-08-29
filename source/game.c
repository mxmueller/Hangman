#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
 
// * outsourced text messages and ascii art *
#include "resources/messages.c"
#include "resources/ascii.c"
#include "resources/words/words.c"

// * config *
#define ERR_MESSAGE__NO_MEM "Not enough memory!"
#define allocator(element, type) _allocator(element, sizeof(type))

const int max_length = 15;
const int max_lives = 10;

// * globals *
char input[max_length];
char *frontend;

int main()
{
    void game();
    game();
    return 0;
}

void clear()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

void enter(void)
{
    puts(status_messages[8]);
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

/** Allocator function (safe alloc) */
void *_allocator(size_t element, size_t typeSize)
{
    void *ptr = NULL;
    /* check alloc */
    if ((ptr = calloc(element, typeSize)) == NULL)
    {
        printf(ERR_MESSAGE__NO_MEM);
        exit(1);
    }
    /* return pointer */
    return ptr;
}

/** Append function (safe mode) */
char *append(const char *input, const char c)
{
    char *newString, *ptr;

    /* alloc */
    newString = allocator((strlen(input) + 2), char);
    /* Copy old string in new (with pointer) */
    ptr = newString;
    for (; *input; input++)
    {
        *ptr = *input;
        ptr++;
    }
    /* Copy char at end */
    *ptr = c;
    /* return new string (for dealloc use free().) */
    return newString;
}

int compare(char a[], char b)
{
    int flag = 0, i = 0;              // integer variables declaration
    while (a[i] != '\0' && b != '\0') // while loop
    {
        if (a[i] != b)
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0)
        return 0;
    else
        return 1;
}

int ran() {
	int i;
	int k;
 
	i = 15;
	k = 0;
	srand((unsigned)time(NULL));
	k = rand() % i;
	return k;
}

const char *wordGen()
{
    return words[ran()];
}

int wordMesure(const char *w)
{
    return strlen(w);
}

struct Node
{
    char value[max_length];
    struct Node *next;
};

struct Node *head = NULL;

void insertNode(struct Node **head_ref, char new_value[max_length])
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

int searchNodeAlternate(struct Node **head_ref, char key)
{
    struct Node *current = *head_ref;

    while (current != NULL)
    {
        int compare(char[], char);

        int c = compare(&current->value[0], key); // calling compare() function
        if (c == 0)
            return 1;

        current = current->next;
    }
    return 0;
}

char *getAndFilterInput()
{
    printf("\n");
    printf("%s", status_messages[13]);
    printNode(head);
    printf("\n \n");
    printf("%s", status_messages[14]);
    scanf("%s", input);
    printf("\n");

    int il; // * == input_length
    il = 0;

    for (int s = 0; s < strlen(input); s++)
    {
        if (input[s] == ' ')
        {
            puts(error_messages[2]);
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

    if (il >= 2 || input[0] == '\n')
    {
        strcpy(input, "\0");
    }

    puts(ascii_divider[0]);

    return input;
}

typedef struct
{
    char wanted_word[max_length];
    int remaining_lives;
    int attempts;
} Meta;

Meta Runtime;

Meta set(
    Meta *runtime,
    const char *wanted_word,
    int remaining_lives,
    int attempts)
{
    strcpy(runtime->wanted_word, wanted_word);
    runtime->remaining_lives = remaining_lives;
    runtime->attempts = attempts;
    return *runtime;
}

Meta get()
{
    return Runtime;
}

void hangman(s)
{
    void straightLines();

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
        straightLines(1);
        break;
    case 1:
        printf("%s", ascii_hangman_part[1]);
        printf("%s", ascii_hangman_part[3]);
        printf("%s", ascii_hangman_part[5]);
        printf("%s", ascii_hangman_part[6]);
        straightLines(1);
        break;
    case 2:
        printf("%s", ascii_hangman_part[1]);
        printf("%s", ascii_hangman_part[3]);
        printf("%s", ascii_hangman_part[5]);
        straightLines(2);
        break;
    case 3:
        printf("%s", ascii_hangman_part[1]);
        printf("%s", ascii_hangman_part[3]);
        printf("%s", ascii_hangman_part[4]);
        straightLines(2);
        break;
    case 4:
        printf("%s", ascii_hangman_part[1]);
        printf("%s", ascii_hangman_part[3]);
        printf("%s", ascii_hangman_part[1]);
        straightLines(2);
        break;
    case 5:
        printf("%s", ascii_hangman_part[1]);
        printf("%s", ascii_hangman_part[3]);
        straightLines(3);

        break;
    case 6:
        printf("%s", ascii_hangman_part[1]);
        straightLines(4);
        break;
    case 7:
        straightLines(5);
        break;
    case 8:
        straightLines(5);
        break;
    case 9:
        printf("%s", "\n\n\n");
        break;
    default:
        break;
    }

    if (s <= 9)
    {
        printf("%s", ascii_hangman_part[8]);
    }
}

void straightLines(n) // helper
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%s", ascii_hangman_part[2]);
    }
}

void welcome()
{
    clear();

    puts(ascii_headline_part[0]);
    puts(ascii_headline_part[1]);
    puts(ascii_headline_part[2]);
    puts(ascii_headline_part[3]);
    puts(ascii_headline_part[4]);
    puts(ascii_headline_part[5]);
    puts(ascii_headline_part[6]);
    puts(ascii_headline_part[7]);
    puts(credit_messages[0]);
    puts(credit_messages[1]);

    enter();
    clear();
}

void dashboard()
{
    puts(ascii_dashboard_part[0]);
    puts(ascii_dashboard_part[1]);
    puts(ascii_dashboard_part[2]);
    puts(ascii_dashboard_part[3]);
    puts(ascii_divider[0]);
    printf("%s", status_messages[4]);
    printf("%d", wordMesure(get().wanted_word));
    printf("\n");
    printf("%s", status_messages[9]);
    printf("%s", frontend);
    printf("\n");
    printf("%s", status_messages[10]);
    printf("%d", get().attempts);
    printf("\n");
    printf("%s", status_messages[11]);
    printf("%d", get().remaining_lives);
    printf("\n");
    printf("%s", ascii_divider[0]);
}

char empty[20] = "_";
char const *underscore = " _";
void game()
{
    if (loadMessages() && loadAscii())
        welcome();

    set(&Runtime, wordGen(), max_lives, 0);

    for (size_t i = 1; i < wordMesure(get().wanted_word); i++)
    {
        strncat(empty, underscore, 20);
    }

    frontend = empty;

    void sequence();
    sequence(0);
}

void sequence(config)
{
    char s1[128];
    char sw[128];
    int win = 1;

    strcpy(sw, get().wanted_word);
    memset(s1, '\0', sizeof(s1));

    for (int pos = 0; pos < strlen(sw); pos++)
    {
        if (searchNodeAlternate(&head, sw[pos]))
        {
            char *s2;

            s2 = append(s1, sw[pos]);
            strcpy(s1, s2);
            strcat(s1, " ");
            /* dealloc */
            free(s2);
            s2 = NULL;
        }
        else
        {
            strcat(s1, "_ ");
            win = 0;
        }
    }

    if (win)
    {
        clear();
        void win();
        win();
    }

    strcpy(frontend, s1);
    dashboard();

    if (!config)
    {
        enter();
    }
    if (config)
    {
        fflush(stdin);
        enter();
    }

    clear();

    char callback[max_length];
    strcpy(callback, getAndFilterInput());

    if (*callback == 0)
    {
        puts(error_messages[1]);
        puts(error_messages[4]);
    }
    else if (searchNode(&head, callback))
    {
        puts(error_messages[0]);
        puts(error_messages[4]);
    }
    else
    {
        puts(status_messages[15]);

        char *ret;
        ret = strstr(get().wanted_word, callback);

        if (ret)
        {
            puts(status_messages[16]);
        }
        else
        {
            puts(status_messages[17]);

            if (get().remaining_lives != 0)
            {
                set(&Runtime,
                    get().wanted_word,
                    get().remaining_lives - 1,
                    get().attempts);
            }

            printf("%s", "\n");
            hangman(get().remaining_lives);
            printf("%s", "\n");

            if (get().remaining_lives == 0)
            {
                puts(status_messages[18]);
                fflush(stdin);
                enter();
                clear();
                main();
            }
        }
        insertNode(&head, callback);
    }
    puts(ascii_divider[0]);

    fflush(stdin);
    enter();
    clear();

    set(&Runtime,
        get().wanted_word,
        get().remaining_lives,
        get().attempts + 1);

    sequence(1);
}

void win() 
{
    puts("Gewonnen!!");
    puts("Beenden:");
    fflush(stdin);
    enter();
    exit(0);
}