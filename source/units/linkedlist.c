// Linked list operations in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

void clear_screen()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

// ---

const int max_length = 150;
char input[max_length];

// Create a node
struct Node
{
    char value[max_length];
    struct Node *next;
};

struct Node *head = NULL;

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
void printNode(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %s ", node->value);
        node = node->next;
    }
}

// Driver program
int main()
{
}

void pressEnterToContinue(void)
{
    printf("Press [Enter] to continue . . .");
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