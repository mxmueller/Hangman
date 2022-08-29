// Linked list operations in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define ERR_MESSAGE__NO_MEM "Not enough memory!"
#define allocator(element, type) _allocator(element, sizeof(type))

void clear_screen()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
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

// ---

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
    insertIntoNode(&head, "A");
    insertIntoNode(&head, "E");
    insertIntoNode(&head, "L");
    insertIntoNode(&head, "C");
    insertIntoNode(&head, "G");

    char *demo = "HERBST"; /* This 11 chars long, excluding the 0-terminator. */
    char s1[20];            // declaration of char array
    memset(s1, '\0', sizeof(s1));

    for (int pos = 0; pos < strlen(demo); pos++)
    {
        if (searchNode(&head, demo[pos]))
        {
            char *newString;

            newString = append(s1, demo[pos]);
            strcpy(s1, newString);
            strcat(s1, " ");
            /* dealloc */
            free(newString);
            newString = NULL;
        }
        else
        {
            strcat(s1, "_ ");
        }
    }
    printf("The concatenated string is : %s", s1);

    // for (int i = 0; i < strlen(demo); i++)
    // {

    //     // printf("%i", i);
    //     // printf("%s", "\n");
    //     // printf("%s", &demo[i]);
    //     // printf("%s", "\n");
    //     printf("%c", demo[i]);
    //     printf("%s", "\n");

    //     if (searchNode(&head, demo[i]))
    //     {

    //         printf("%c", demo[i]);
    //         printf("%s", "\n");
    //     }
    // }

    return 0;
}

// void sequence()
// {
//     if (*callback == 0)
//     {
//         puts("Bitte nur einen Buchstaben eingeben");
//         puts("Bitte erneut versuchen.");
//     }
//     else if (searchNode(&head, callback))
//     {
//         puts("Berreits vorhanden");
//         puts("Bitte erneut versuchen.");
//     }
//     else
//     {
//         puts("Eingabe erfolgreich!");

//         printf("List: ");
//         printNode(head);
//         printf("%s", "\n");
//     }

//     flush(stdin);
//     pressEnterToContinue();
//     clear_screen();
//     sequence();
// }